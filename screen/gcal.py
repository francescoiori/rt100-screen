"""Next event from the Google calendars signed in to Ubuntu.

GNOME Online Accounts already holds the Google login. This module asks
Evolution for those calendars over the session bus and keeps only the next
event's title and time. It does not store a token.
"""
from __future__ import annotations

import json
import os
import subprocess
import threading
import time
from datetime import datetime, timedelta, timezone
from zoneinfo import ZoneInfo

_mu = threading.Lock()
_state = {
    "event": None,
    "at": 0.0,
    "connected": False,
    "error": "",
}


def _bus(timeout: float, *args: str):
    try:
        out = subprocess.run(
            ["busctl", "--user", "--json=short", *args],
            capture_output=True, text=True, timeout=timeout)
    except (OSError, subprocess.TimeoutExpired):
        return None
    if out.returncode != 0 or not out.stdout:
        return None
    try:
        return json.loads(out.stdout).get("data")
    except ValueError:
        return None


def _strings(data) -> list[str]:
    found: list[str] = []
    if isinstance(data, str):
        found.append(data)
    elif isinstance(data, list):
        for item in data:
            found.extend(_strings(item))
    return found


def _sections(text: str) -> dict[str, dict[str, str]]:
    section = ""
    out: dict[str, dict[str, str]] = {}
    for line in text.splitlines():
        if line.startswith("[") and line.endswith("]"):
            section = line[1:-1]
            out.setdefault(section, {})
        elif "=" in line and "[" not in line.split("=", 1)[0]:
            key, value = line.split("=", 1)
            out.setdefault(section, {})[key] = value
    return out


def _source_paths() -> list[str]:
    try:
        out = subprocess.run(
            ["busctl", "--user", "tree", "org.gnome.evolution.dataserver.Sources5"],
            capture_output=True, text=True, timeout=3)
    except (OSError, subprocess.TimeoutExpired):
        return []
    paths = []
    for line in (out.stdout or "").splitlines():
        path = line.strip().split()[-1] if line.strip() else ""
        if "/SourceManager/Source" in path:
            paths.append(path)
    return paths


def _sources() -> dict[str, dict]:
    found = {}
    for path in _source_paths():
        uid = _bus(2, "get-property", "org.gnome.evolution.dataserver.Sources5", path,
                   "org.gnome.evolution.dataserver.Source", "UID")
        raw = _bus(2, "get-property", "org.gnome.evolution.dataserver.Sources5", path,
                   "org.gnome.evolution.dataserver.Source", "Data")
        if not isinstance(uid, str) or not isinstance(raw, str):
            continue
        parts = _sections(raw)
        data = parts.get("Data Source", {})
        calendar = parts.get("Calendar", {})
        found[uid] = {
            "name": data.get("DisplayName") or calendar.get("DisplayName") or "",
            "enabled": data.get("Enabled", "true") != "false",
            "parent": data.get("Parent", ""),
            "backend": calendar.get("BackendName") or data.get("BackendName") or parts.get("Data Source", {}).get("BackendName", ""),
            "selected": calendar.get("Selected", "true") != "false",
            "calendar": "Calendar" in parts,
            "host": parts.get("Authentication", {}).get("Host", ""),
        }
    return found


def _google_calendars(sources: dict[str, dict]) -> list[tuple[str, str]]:
    chosen = []
    for uid, src in sources.items():
        if not src["calendar"] or not src["enabled"] or not src["selected"]:
            continue
        if src["backend"] == "contacts":
            continue
        parent = sources.get(src["parent"]) or {}
        google = parent.get("backend") == "google" or "google" in src["host"]
        if not google:
            continue
        name = src["name"].lower()
        if "holiday" in name or "festiv" in name or "birthday" in name:
            continue
        chosen.append((uid, src["name"]))
    return chosen


def _google_account() -> str:
    """'on', 'off', or '' when no Google account is signed in."""
    try:
        out = subprocess.run(
            ["busctl", "--user", "tree", "org.gnome.OnlineAccounts"],
            capture_output=True, text=True, timeout=3)
    except (OSError, subprocess.TimeoutExpired):
        return ""
    paths = []
    for line in (out.stdout or "").splitlines():
        path = line.strip().split()[-1] if line.strip() else ""
        if "/OnlineAccounts/Accounts/account_" in path:
            paths.append(path)
    for path in paths:
        kind = _bus(2, "get-property", "org.gnome.OnlineAccounts", path,
                    "org.gnome.OnlineAccounts.Account", "ProviderType")
        if kind != "google":
            continue
        disabled = _bus(2, "get-property", "org.gnome.OnlineAccounts", path,
                        "org.gnome.OnlineAccounts.Account", "CalendarDisabled")
        return "off" if disabled else "on"
    return ""


def _unfold(text: str) -> list[str]:
    lines: list[str] = []
    for line in text.splitlines():
        if lines and line.startswith((" ", "\t")):
            lines[-1] += line[1:]
        else:
            lines.append(line)
    return lines


def _ical_text(value: str) -> str:
    value = value.replace("\\n", " ").replace("\\N", " ").replace("\\,", ",")
    value = value.replace("\\;", ";").replace("\\\\", "\\")
    return " ".join(value.split())


def _stamp(prop: str, value: str) -> tuple[datetime, bool] | None:
    all_day = "VALUE=DATE" in prop and "T" not in value[:9]
    if all_day:
        try:
            day = datetime.strptime(value[:8], "%Y%m%d")
        except ValueError:
            return None
        start = day.replace(tzinfo=datetime.now().astimezone().tzinfo)
        return start, True
    tz = None
    if "TZID=" in prop:
        name = prop.split("TZID=", 1)[1].split(";")[0]
        try:
            tz = ZoneInfo(name)
        except (KeyError, ValueError):
            tz = None
    try:
        if value.endswith("Z"):
            start = datetime.strptime(value[:15], "%Y%m%dT%H%M%S").replace(tzinfo=timezone.utc)
        else:
            start = datetime.strptime(value[:15], "%Y%m%dT%H%M%S")
            start = start.replace(tzinfo=tz or datetime.now().astimezone().tzinfo)
    except ValueError:
        return None
    return start, False


_WEEKDAYS = {"MO": 0, "TU": 1, "WE": 2, "TH": 3, "FR": 4, "SA": 5, "SU": 6}


def _rule_parts(rule: str) -> dict[str, str]:
    parts = {}
    for item in rule.split(";"):
        if "=" in item:
            key, value = item.split("=", 1)
            parts[key.upper()] = value
    return parts


def _on_day(start: datetime, day) -> datetime:
    local = start.astimezone()
    return datetime.combine(day, local.timetz())


def _next_occurrence(start: datetime, duration: timedelta, rule: str,
                     excluded: list[datetime], now: datetime, horizon: datetime) -> datetime | None:
    """Next start of a simple repeating event inside the window."""
    parts = _rule_parts(rule)
    freq = parts.get("FREQ", "")
    if freq not in ("DAILY", "WEEKLY", "MONTHLY", "YEARLY"):
        return None
    try:
        interval = max(1, int(parts.get("INTERVAL", "1") or "1"))
    except ValueError:
        interval = 1
    until = None
    if parts.get("UNTIL"):
        parsed = _stamp("DTSTART", parts["UNTIL"])
        until = parsed[0] if parsed else None
    try:
        count = int(parts["COUNT"]) if parts.get("COUNT") else None
    except ValueError:
        count = None
    days = [_WEEKDAYS[token[-2:]] for token in parts.get("BYDAY", "").split(",")
            if token[-2:] in _WEEKDAYS] if freq == "WEEKLY" else []
    if freq == "WEEKLY" and not days:
        days = [start.astimezone().weekday()]
    origin = start.astimezone().date()
    skipped = {item.astimezone().replace(second=0, microsecond=0) for item in excluded}
    day = now.astimezone().date()
    last = horizon.astimezone().date()
    while day <= last:
        if until and day > until.astimezone().date():
            return None
        candidate = _match_day(origin, start, day, freq, interval, days)
        if candidate is not None and candidate < horizon:
            ordinal = _occurrence_index(origin, candidate.date(), freq, interval, days)
            if count is not None and (ordinal is None or ordinal > count):
                candidate = None
            elif candidate.astimezone().replace(second=0, microsecond=0) in skipped:
                candidate = None
            elif candidate + duration > now:
                return candidate
        day += timedelta(days=1)
    return None


def _week_index(origin, day) -> int:
    origin_monday = origin - timedelta(days=origin.weekday())
    day_monday = day - timedelta(days=day.weekday())
    return (day_monday - origin_monday).days // 7


def _match_day(origin, start: datetime, day, freq: str, interval: int, weekdays: list[int]) -> datetime | None:
    if day < origin:
        return None
    if freq == "DAILY":
        if (day - origin).days % interval:
            return None
    elif freq == "WEEKLY":
        if day.weekday() not in weekdays:
            return None
        if _week_index(origin, day) % interval:
            return None
    elif freq == "MONTHLY":
        months = (day.year - origin.year) * 12 + (day.month - origin.month)
        if day.day != origin.day or months < 0 or months % interval:
            return None
    elif freq == "YEARLY":
        if (day.month, day.day) != (origin.month, origin.day):
            return None
        if (day.year - origin.year) % interval:
            return None
    return _on_day(start, day)


def _occurrence_index(origin, day, freq: str, interval: int, weekdays: list[int]) -> int | None:
    if freq == "DAILY":
        return (day - origin).days // interval + 1
    if freq == "WEEKLY":
        return _week_index(origin, day) // interval + 1
    if freq == "MONTHLY":
        months = (day.year - origin.year) * 12 + (day.month - origin.month)
        return months // interval + 1
    if freq == "YEARLY":
        return (day.year - origin.year) // interval + 1
    return None


def _event_from(text: str) -> dict | None:
    summary = ""
    start = end = None
    all_day = False
    rule = ""
    excluded: list[datetime] = []
    for line in _unfold(text):
        if ":" not in line:
            continue
        prop, value = line.split(":", 1)
        name = prop.split(";", 1)[0].upper()
        if name == "STATUS" and value.strip().upper() == "CANCELLED":
            return None
        if name == "SUMMARY" and not summary:
            summary = _ical_text(value)
        elif name == "DTSTART" and start is None:
            parsed = _stamp(prop, value.strip())
            if parsed:
                start, all_day = parsed
        elif name == "DTEND" and end is None:
            parsed = _stamp(prop, value.strip())
            if parsed:
                end = parsed[0]
        elif name == "RRULE" and not rule:
            rule = value.strip()
        elif name == "EXDATE":
            for piece in value.split(","):
                parsed = _stamp(prop, piece.strip())
                if parsed:
                    excluded.append(parsed[0])
    if start is None:
        return None
    duration = (end - start) if end is not None else (timedelta(days=1) if all_day else timedelta(hours=1))
    now = datetime.now().astimezone()
    horizon = now + timedelta(hours=36)
    if rule:
        start = _next_occurrence(start, duration, rule, excluded, now, horizon)
        if start is None:
            return None
    elif start + duration <= now or start >= horizon:
        return None
    local = start.astimezone()
    when = local.strftime("%a").upper() + " ALL DAY" if all_day else local.strftime("%a %H:%M").upper()
    return {
        "when": when,
        "title": (summary or "Busy")[:80],
        "start": start.timestamp(),
        "all_day": all_day,
        "source": "Google",
    }


def _events_for(uid: str) -> list[dict] | None:
    opened = _bus(
        8, "call", "org.gnome.evolution.dataserver.Calendar8",
        "/org/gnome/evolution/dataserver/CalendarFactory",
        "org.gnome.evolution.dataserver.CalendarFactory", "OpenCalendar", "s", uid)
    flat = _strings(opened)
    if len(flat) < 2:
        return None
    path, bus = flat[0], flat[1]
    now = datetime.now(timezone.utc)
    end = now + timedelta(hours=36)
    sexp = '(occur-in-time-range? (make-time "%s") (make-time "%s"))' % (
        now.strftime("%Y%m%dT%H%M%SZ"), end.strftime("%Y%m%dT%H%M%SZ"))
    listed = _bus(
        12, "call", bus, path,
        "org.gnome.evolution.dataserver.Calendar", "GetObjectList", "s", sexp)
    if listed is None:
        return None
    found = []
    for text in _strings(listed):
        if "BEGIN:VEVENT" not in text:
            continue
        event = _event_from(text)
        if event:
            found.append(event)
    return found


def _refresh() -> None:
    account = _google_account()
    if account == "":
        with _mu:
            _state["event"] = None
            _state["connected"] = False
            _state["error"] = ""
            _state["at"] = time.time()
        return
    if account == "off":
        with _mu:
            _state["event"] = None
            _state["connected"] = False
            _state["error"] = "Turn on Calendar for the Google account in Ubuntu Settings."
            _state["at"] = time.time()
        return
    sources = _sources()
    calendars = _google_calendars(sources)
    if not calendars:
        with _mu:
            _state["event"] = None
            _state["connected"] = True
            _state["error"] = "No Google calendar is selected in the calendar app."
            _state["at"] = time.time()
        return
    chosen = None
    answered = False
    for uid, _name in calendars:
        events = _events_for(uid)
        if events is None:
            continue
        answered = True
        for event in events:
            if chosen is None or (event["all_day"], event["start"]) < (chosen["all_day"], chosen["start"]):
                chosen = event
    with _mu:
        _state["event"] = chosen
        _state["connected"] = True
        _state["error"] = "" if answered else "Google calendar did not answer."
        _state["at"] = time.time()


def poll() -> None:
    """Refresh when a Google account exists. Safe to call every few seconds."""
    with _mu:
        fresh = time.time() - _state["at"] < 180
    if fresh:
        return
    try:
        _refresh()
    except Exception:
        with _mu:
            _state["error"] = "Google calendar did not answer."
            _state["at"] = time.time()


def next_event() -> dict | None:
    with _mu:
        event = _state["event"]
    return dict(event) if isinstance(event, dict) else None


def status() -> dict:
    with _mu:
        return {
            "connected": bool(_state["connected"]),
            "pending": _state["at"] == 0.0,
            "error": _state["error"],
        }


def open_settings() -> None:
    """Open Ubuntu's Online Accounts page so a Google account can be added."""
    env = os.environ.copy()
    env.setdefault("DISPLAY", ":1")
    try:
        subprocess.Popen(
            ["gnome-control-center", "online-accounts"],
            env=env, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
            start_new_session=True)
    except OSError:
        with _mu:
            _state["error"] = "Could not open Ubuntu Settings."
