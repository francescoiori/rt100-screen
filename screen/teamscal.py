"""Next meeting from the Microsoft 365 calendar behind Teams.

GNOME's own Microsoft app is not allowed to read calendars, so sign-in uses
Microsoft's Graph command-line app in the browser. A refresh token is kept in
the home directory. Only the next event's title and time leave this module.
"""
from __future__ import annotations

import base64
import hashlib
import json
import os
import secrets
import subprocess
import threading
import time
import urllib.error
import urllib.parse
import urllib.request
from datetime import datetime, timedelta
from http.server import BaseHTTPRequestHandler, HTTPServer

CLIENT_ID = "14d82eec-204b-4c2f-b7e8-296a70dab67e"
SCOPE = "https://graph.microsoft.com/Calendars.Read offline_access"
AUTH_URL = "https://login.microsoftonline.com/common/oauth2/v2.0/authorize"
TOKEN_URL = "https://login.microsoftonline.com/common/oauth2/v2.0/token"
GRAPH = "https://graph.microsoft.com/v1.0/me/calendarView"

TOKEN_PATH = os.path.join(os.path.expanduser("~"), ".config", "rt100screen-teams.json")
_mu = threading.Lock()
_state = {
    "token": None,
    "event": None,
    "events_at": 0.0,
    "error": "",
    "waiting": False,
    "auth_url": "",
}


def _load_token() -> dict | None:
    try:
        with open(TOKEN_PATH) as handle:
            data = json.load(handle)
        return data if isinstance(data, dict) and data.get("refresh_token") else None
    except (OSError, ValueError):
        return None


def _save_token(data: dict) -> None:
    os.makedirs(os.path.dirname(TOKEN_PATH), exist_ok=True)
    tmp = TOKEN_PATH + ".tmp"
    with open(tmp, "w") as handle:
        json.dump(data, handle)
        handle.write("\n")
    os.chmod(tmp, 0o600)
    os.replace(tmp, TOKEN_PATH)


def _post(url: str, fields: dict) -> dict:
    body = urllib.parse.urlencode(fields).encode()
    request = urllib.request.Request(url, data=body)
    with urllib.request.urlopen(request, timeout=15) as reply:
        return json.load(reply)


def _store(data: dict) -> None:
    previous = _state["token"] or {}
    token = {
        "access_token": data["access_token"],
        "refresh_token": data.get("refresh_token") or previous.get("refresh_token"),
        "expires_at": time.time() + int(data.get("expires_in") or 3600) - 60,
    }
    if token["refresh_token"]:
        _save_token(token)
    _state["token"] = token
    _state["error"] = ""
    _state["events_at"] = 0.0
    _state["waiting"] = False
    _state["auth_url"] = ""


def _explain(detail: str) -> str:
    text = detail.lower()
    if "aadsts65001" in text or "consent_required" in text:
        return "Approve calendar access in the browser window."
    if "aadsts90094" in text or "aadsts650052" in text or "admin" in text:
        return "Your work account blocked this. An admin has to allow it."
    if "aadsts50011" in text:
        return "Microsoft rejected the sign-in return address."
    if "access_denied" in text:
        return "Teams sign-in was cancelled."
    return "Teams sign-in did not finish."


def _access_token() -> str | None:
    with _mu:
        token = _state["token"]
        if token is None:
            token = _load_token()
            _state["token"] = token
        if token is None:
            return None
        if time.time() < token.get("expires_at", 0) and token.get("access_token"):
            return token["access_token"]
        refresh = token.get("refresh_token")
    if not refresh:
        return None
    try:
        data = _post(TOKEN_URL, {
            "client_id": CLIENT_ID,
            "grant_type": "refresh_token",
            "refresh_token": refresh,
            "scope": SCOPE,
        })
    except (OSError, ValueError, KeyError):
        with _mu:
            _state["error"] = "Teams needs signing in again"
            _state["token"] = None
        try:
            os.remove(TOKEN_PATH)
        except OSError:
            pass
        return None
    with _mu:
        _store(data)
        return _state["token"]["access_token"]


def _event_from(item: dict) -> dict | None:
    start = (item.get("start") or {}).get("dateTime") or ""
    end = (item.get("end") or {}).get("dateTime") or ""
    if not start:
        return None
    try:
        begins = datetime.fromisoformat(start[:19])
        ends = datetime.fromisoformat(end[:19]) if end else begins
    except ValueError:
        return None
    if ends <= datetime.now():
        return None
    title = " ".join(str(item.get("subject") or "Busy").split())
    all_day = bool(item.get("isAllDay"))
    if all_day:
        when = begins.strftime("%a").upper() + " ALL DAY"
    else:
        when = begins.strftime("%a %H:%M").upper()
    return {
        "when": when,
        "title": title[:80],
        "start": begins.timestamp(),
        "all_day": all_day,
        "source": "Teams",
    }


def _refresh_events(token: str) -> None:
    with _mu:
        if time.time() - _state["events_at"] < 180:
            return
    now = datetime.now().astimezone()
    query = urllib.parse.urlencode({
        "startDateTime": now.isoformat(),
        "endDateTime": (now + timedelta(hours=36)).isoformat(),
        "$select": "subject,start,end,isAllDay",
        "$orderby": "start/dateTime",
        "$top": "8",
    })
    request = urllib.request.Request(
        GRAPH + "?" + query,
        headers={"Authorization": "Bearer " + token, "Prefer": 'outlook.timezone="Europe/London"'},
    )
    try:
        with urllib.request.urlopen(request, timeout=8) as reply:
            payload = json.load(reply)
    except urllib.error.HTTPError as exc:
        with _mu:
            _state["error"] = "Teams calendar refused the request" if exc.code in (401, 403) else "Teams calendar did not answer"
        return
    except (OSError, ValueError):
        return
    chosen = None
    for item in payload.get("value") or []:
        chosen = _event_from(item)
        if chosen:
            break
    with _mu:
        _state["event"] = chosen
        _state["events_at"] = time.time()
        _state["error"] = ""


def _graphical_env() -> dict:
    env = os.environ.copy()
    if env.get("DISPLAY") or env.get("WAYLAND_DISPLAY"):
        return env
    for name in ("gnome-shell", "Xorg", "Xwayland"):
        try:
            pid = subprocess.check_output(["pgrep", "-n", "-x", name], text=True).strip()
        except (OSError, subprocess.CalledProcessError):
            continue
        try:
            raw = open(f"/proc/{pid}/environ", "rb").read().split(b"\0")
        except OSError:
            continue
        for item in raw:
            if b"=" not in item:
                continue
            key, value = item.split(b"=", 1)
            name_s = key.decode("utf-8", "replace")
            if name_s in ("DISPLAY", "WAYLAND_DISPLAY", "XDG_RUNTIME_DIR", "DBUS_SESSION_BUS_ADDRESS"):
                env[name_s] = value.decode("utf-8", "replace")
        if env.get("DISPLAY") or env.get("WAYLAND_DISPLAY"):
            return env
    env.setdefault("DISPLAY", ":1")
    return env


def _open(url: str) -> bool:
    try:
        subprocess.Popen(
            ["xdg-open", url],
            env=_graphical_env(),
            stdout=subprocess.DEVNULL,
            stderr=subprocess.DEVNULL,
            start_new_session=True,
        )
    except OSError:
        return False
    return True


def _listen(redirect: str, verifier: str, server: HTTPServer) -> None:
    box: dict = {}

    class Handler(BaseHTTPRequestHandler):
        def do_GET(self):
            query = urllib.parse.parse_qs(urllib.parse.urlparse(self.path).query)
            box["code"] = (query.get("code") or [""])[0]
            box["error"] = (query.get("error_description") or query.get("error") or [""])[0]
            body = b"<html><body style='font-family:sans-serif'><p>You can close this tab.</p></body></html>"
            self.send_response(200)
            self.send_header("Content-Type", "text/html")
            self.send_header("Content-Length", str(len(body)))
            self.end_headers()
            self.wfile.write(body)

        def log_message(self, fmt: str, *args) -> None:
            return

    server.RequestHandlerClass = Handler
    deadline = time.time() + 180
    server.timeout = 1
    while time.time() < deadline and not box.get("code") and not box.get("error"):
        server.handle_request()
    server.server_close()
    code = box.get("code") or ""
    if not code:
        with _mu:
            if _state["waiting"]:
                _state["waiting"] = False
                _state["auth_url"] = ""
                _state["error"] = _explain(box["error"]) if box.get("error") else "Teams sign-in was not finished."
        return
    try:
        data = _post(TOKEN_URL, {
            "client_id": CLIENT_ID,
            "grant_type": "authorization_code",
            "code": code,
            "redirect_uri": redirect,
            "code_verifier": verifier,
            "scope": SCOPE,
        })
    except urllib.error.HTTPError as exc:
        detail = exc.read().decode("utf-8", "replace")
        with _mu:
            _state["waiting"] = False
            _state["auth_url"] = ""
            _state["error"] = _explain(detail)
        return
    except (OSError, ValueError, KeyError):
        with _mu:
            _state["waiting"] = False
            _state["auth_url"] = ""
            _state["error"] = "Teams sign-in did not finish."
        return
    if "access_token" not in data:
        with _mu:
            _state["waiting"] = False
            _state["error"] = "Teams sign-in did not finish."
        return
    with _mu:
        _store(data)
        token = _state["token"]["access_token"]
    _refresh_events(token)


def begin() -> None:
    """Open the browser so the work account can allow calendar access."""
    with _mu:
        if (_state["token"] or _load_token() or {}).get("refresh_token"):
            return
        url = _state["auth_url"]
        if _state["waiting"] and url:
            reopen = url
        else:
            reopen = ""
    if reopen:
        if not _open(reopen):
            with _mu:
                _state["error"] = "Could not open the browser."
        return
    verifier = secrets.token_urlsafe(64)
    challenge = base64.urlsafe_b64encode(hashlib.sha256(verifier.encode()).digest()).rstrip(b"=").decode()
    try:
        server = HTTPServer(("127.0.0.1", 0), BaseHTTPRequestHandler)
    except OSError:
        with _mu:
            _state["error"] = "Could not start the Teams sign-in."
        return
    port = server.server_address[1]
    redirect = f"http://localhost:{port}/"
    query = urllib.parse.urlencode({
        "client_id": CLIENT_ID,
        "response_type": "code",
        "redirect_uri": redirect,
        "response_mode": "query",
        "scope": SCOPE,
        "code_challenge": challenge,
        "code_challenge_method": "S256",
        "prompt": "select_account",
    })
    url = AUTH_URL + "?" + query
    with _mu:
        _state["waiting"] = True
        _state["auth_url"] = url
        _state["error"] = ""
    threading.Thread(target=_listen, args=(redirect, verifier, server), daemon=True).start()
    if not _open(url):
        with _mu:
            _state["error"] = "Could not open the browser."


def poll() -> None:
    """Refresh the calendar when a token exists. Safe to call every few seconds."""
    token = _access_token()
    if token:
        _refresh_events(token)


def next_event() -> dict | None:
    with _mu:
        event = _state["event"]
    return event if isinstance(event, dict) else None


def signin() -> dict:
    with _mu:
        signed_in = bool((_state["token"] or _load_token() or {}).get("refresh_token"))
        return {
            "signed_in": signed_in,
            "waiting": bool(_state["waiting"]) and not signed_in,
            "user_code": "",
            "url": "",
            "error": _state["error"],
        }
