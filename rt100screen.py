"""Drive the RT100 screen in custom display mode (needs the re/custom firmware).

usage:
  rt100screen.py run [--pages clock,system,media,weather] [--seconds 10] [--no-notify]
  rt100screen.py settime | stock | stop | text "hello" | image picture.png
  rt100screen.py location CITY | location --lat LAT --lon LON --name CITY
  rt100screen.py agent --source Cursor          # used by the Cursor and Claude hooks
Add --dry-run to print packets instead of sending them. Only one sender may run.

Packets reach the screen through the keyboard's OLED-update passthrough:
vendor command 0x31 <count> makes the keyboard forward the next <count>
64-byte reports to the screen unchanged. A session must always be completed,
otherwise the keyboard keeps swallowing vendor commands.
"""
from __future__ import annotations

import argparse
import fcntl
import json
import math
import os
import shutil
import signal
import subprocess
import sys
import threading
import time
import unicodedata
import urllib.parse
import urllib.request
from dataclasses import dataclass
from datetime import datetime

import screenproto as sp

PASSTHROUGH = 0x31
NOOP = bytes([sp.PKT_DRAW]).ljust(sp.PACKET, b"\0")

BG = sp.hexcolor("0b0f1a")
FG = sp.hexcolor("f5f7fa")
ACCENT = sp.hexcolor("4fd1ff")
MUTED = sp.hexcolor("8b95a7")
TRACK = sp.hexcolor("1f2937")
GOOD, WARN, BAD = sp.hexcolor("7ee787"), sp.hexcolor("ffb454"), sp.hexcolor("ff6b6b")


# ---- link -------------------------------------------------------------------

class Link:
    def __init__(self, dry_run: bool = False, dongle: bool = False,
                 us_per_pixel: float = 6.0, packet_delay: float = 0.004) -> None:
        self.dry_run, self.us_per_pixel, self.packet_delay = dry_run, us_per_pixel, packet_delay
        self.path = None
        if not dry_run:
            import rt100
            self.rt100 = rt100
            self.path = rt100.find_vendor_hidraw((0x4011,) if dongle else (0x4010,))

    def send(self, packets: list[tuple[bytes, int]]) -> None:
        for start in range(0, len(packets), 0xFFFF):
            self._session(packets[start:start + 0xFFFF])

    def _session(self, packets: list[tuple[bytes, int]]) -> None:
        if not packets:
            return
        n = len(packets)
        if self.dry_run:
            print(f"0x31 count={n}")
            for p, px in packets:
                print(f"  {p.rstrip(b'\0').hex(' ')}  ({px} px)")
            return
        start = bytearray(sp.PACKET)
        start[0:3] = bytes([PASSTHROUGH, n & 0xFF, n >> 8])
        start[7] = (0xFF - sum(start[:7])) & 0xFF
        self.rt100.send(self.path, bytes(start))
        time.sleep(0.01)
        sent = 0
        try:
            for p, px in packets:
                self.rt100.send(self.path, p)
                sent += 1
                time.sleep(self.packet_delay + px * self.us_per_pixel / 1e6)
        finally:
            for _ in range(n - sent):
                self.rt100.send(self.path, NOOP)
                time.sleep(self.packet_delay)


# ---- widgets ----------------------------------------------------------------

@dataclass(frozen=True)
class Text:
    x: int
    y: int
    chars: int          # field width; text is padded so old text is overwritten
    s: str
    fg: int = FG
    scale: int = 2
    align: str = "left"
    bg: int = BG

    def draw(self, f: sp.Frame) -> None:
        s = ascii_only(self.s)[:self.chars]
        s = {"left": s.ljust, "right": s.rjust, "center": s.center}[self.align](self.chars)
        f.text(self.x, self.y, s, self.fg, self.bg, self.scale)


@dataclass(frozen=True)
class Bar:
    x: int
    y: int
    w: int
    h: int
    frac: float
    fg: int = ACCENT
    track: int = TRACK

    def draw(self, f: sp.Frame) -> None:
        filled = round(max(0.0, min(1.0, self.frac)) * self.w)
        f.fill(self.x, self.y, filled, self.h, self.fg)
        f.fill(self.x + filled, self.y, self.w - filled, self.h, self.track)


@dataclass(frozen=True)
class Rect:
    x: int
    y: int
    w: int
    h: int
    color: int

    def draw(self, f: sp.Frame) -> None:
        f.fill(self.x, self.y, self.w, self.h, self.color)


@dataclass(frozen=True)
class Icon:
    """1-bit icon, column-major, MSB first, drawn by the firmware's mono blit."""

    x: int
    y: int
    w: int
    h: int
    bits: bytes
    fg: int = FG
    bg: int = BG

    def draw(self, f: sp.Frame) -> None:
        f.mono(self.x, self.y, self.w, self.h, self.bits, self.fg, self.bg)


def ascii_only(s: str) -> str:
    return unicodedata.normalize("NFKD", s).encode("ascii", "ignore").decode()


def centered(chars: int, scale: int) -> int:
    return (sp.W - chars * sp.CHAR_W * scale) // 2


def title(s: str) -> Text:
    return Text(centered(13, 2), 12, 13, s.upper(), ACCENT, 2, "center")


def dots(index: int, count: int) -> dict:
    out, x0 = {}, (sp.W - (count * 14 - 6)) // 2
    for i in range(count):
        out[f"dot{i}"] = Rect(x0 + i * 14, 224, 8, 8, ACCENT if i == index else TRACK)
    return out


def level(frac: float) -> int:
    return GOOD if frac < 0.6 else WARN if frac < 0.85 else BAD


# ---- pages ------------------------------------------------------------------

def clock_page(now: datetime, _data=None) -> dict:
    return {
        "day": Text(centered(9, 2), 26, 9, now.strftime("%A").upper(), ACCENT, 2, "center"),
        "time": Text(centered(5, 5), 62, 5, now.strftime("%H:%M"), FG, 5),
        "sec": Bar(20, 154, 200, 4, now.second / 59),
        "date": Text(centered(11, 2), 174, 11, now.strftime("%d %b %Y").upper(), MUTED, 2, "center"),
    }


def system_stats() -> dict:
    import psutil
    temps = psutil.sensors_temperatures()
    temp = None
    for entry in temps.get("coretemp", []):
        if entry.label.startswith("Package"):
            temp = entry.current
    if temp is None and temps:
        temp = max(e.current for es in temps.values() for e in es)
    return {"cpu": psutil.cpu_percent(interval=None), "ram": psutil.virtual_memory().percent, "temp": temp}


def system_page(_now: datetime, s: dict) -> dict:
    w = {"title": title("system")}
    rows = [("cpu", "CPU", s["cpu"] / 100, f"{s['cpu']:.0f}%"),
            ("ram", "RAM", s["ram"] / 100, f"{s['ram']:.0f}%")]
    if s.get("temp") is not None:
        rows.append(("temp", "TEMP", (s["temp"] - 30) / 70, f"{s['temp']:.0f}C"))
    for i, (key, label, frac, value) in enumerate(rows):
        y = 50 + i * 56
        w[key + "_l"] = Text(16, y, 4, label, MUTED)
        w[key + "_v"] = Text(144, y, 5, value, FG, 2, "right")
        w[key + "_b"] = Bar(16, y + 34, 208, 10, frac, level(frac))
    return w


def _busctl(*args: str):
    out = subprocess.run(["busctl", "--user", "--json=short", *args],
                         capture_output=True, text=True, timeout=1)
    return json.loads(out.stdout)["data"] if out.returncode == 0 and out.stdout else None


def media_info() -> dict | None:
    try:
        names = _busctl("call", "org.freedesktop.DBus", "/org/freedesktop/DBus",
                        "org.freedesktop.DBus", "ListNames")
        players = [n for n in (names or [[]])[0] if n.startswith("org.mpris.MediaPlayer2.")]
        best = None
        for name in players:
            prop = lambda p: _busctl("get-property", name, "/org/mpris/MediaPlayer2",
                                     "org.mpris.MediaPlayer2.Player", p)
            status = prop("PlaybackStatus")
            if status not in ("Playing", "Paused"):
                continue
            meta = prop("Metadata") or {}
            get = lambda k: (meta.get(k) or {}).get("data")
            artist = get("xesam:artist")
            info = {"status": status, "title": get("xesam:title") or "",
                    "artist": ", ".join(artist) if isinstance(artist, list) else artist or "",
                    "length": get("mpris:length") or 0, "position": prop("Position") or 0}
            if best is None or status == "Playing":
                best = info
            if status == "Playing":
                break
        return best
    except (OSError, subprocess.TimeoutExpired, ValueError):
        return None


def wrap(s: str, width: int, lines: int) -> list[str]:
    words, out, cur = ascii_only(s).split(), [], ""
    for word in words:
        while len(word) > width:
            if cur:
                out.append(cur)
                cur = ""
            out.append(word[:width])
            word = word[width:]
        if len(cur) + len(word) + (1 if cur else 0) <= width:
            cur = f"{cur} {word}" if cur else word
        else:
            out.append(cur)
            cur = word
    if cur:
        out.append(cur)
    if len(out) > lines:
        out = out[:lines]
        out[-1] = out[-1][:width - 2] + ".."
    return out + [""] * (lines - len(out))


def media_page(_now: datetime, m: dict) -> dict:
    w = {"title": title("now playing")}
    for i, line in enumerate(wrap(m["title"], 13, 3)):
        w[f"t{i}"] = Text(16, 48 + i * 34, 13, line, FG)
    w["artist"] = Text(16, 156, 13, ascii_only(m["artist"]), WARN)
    w["status"] = Text(16, 190, 8, m["status"].upper(), MUTED, 1)
    if m["length"]:
        w["pos"] = Bar(16, 210, 208, 4, m["position"] / m["length"])
    return w


# ---- weather ----------------------------------------------------------------

CONFIG_PATH = os.path.join(os.path.expanduser("~"), ".config", "rt100screen.json")
LOCK_PATH = os.path.join(os.environ.get("XDG_RUNTIME_DIR", "/tmp"), "rt100screen.lock")
_stop = threading.Event()


def _grid() -> list[list[int]]:
    return [[0] * 32 for _ in range(32)]


def _disc(g: list[list[int]], cx: float, cy: float, r: float, v: int = 1) -> None:
    for y in range(32):
        for x in range(32):
            if (x - cx) ** 2 + (y - cy) ** 2 <= r * r:
                g[y][x] = v


def _cloud(g: list[list[int]], dy: int = 0) -> None:
    _disc(g, 12, 15 + dy, 6)
    _disc(g, 19, 13 + dy, 8)
    _disc(g, 25, 16 + dy, 5)
    for y in range(16 + dy, 23 + dy):
        for x in range(7, 29):
            if 0 <= y < 32:
                g[y][x] = 1


def _pack(g: list[list[int]]) -> bytes:
    acc = n = 0
    out = bytearray()
    for x in range(32):
        for y in range(32):
            acc = (acc << 1) | g[y][x]
            n += 1
            if n == 8:
                out.append(acc)
                acc = n = 0
    return bytes(out)


def _icon_sun() -> bytes:
    g = _grid()
    _disc(g, 15.5, 15.5, 5)
    for i in range(8):
        a = i * math.pi / 4
        for t in range(9, 15):
            x, y = round(15.5 + math.cos(a) * t), round(15.5 + math.sin(a) * t)
            for dx in (0, 1):
                for dy in (0, 1):
                    if 0 <= x + dx < 32 and 0 <= y + dy < 32:
                        g[y + dy][x + dx] = 1
    return _pack(g)


def _icon_partly() -> bytes:
    g = _grid()
    _disc(g, 10, 10, 4)
    for i in range(8):
        a = i * math.pi / 4
        for t in (7, 8, 9):
            x, y = round(10 + math.cos(a) * t), round(10 + math.sin(a) * t)
            if 0 <= x < 32 and 0 <= y < 32:
                g[y][x] = 1
    _cloud(g, 4)
    return _pack(g)


def _icon_cloud() -> bytes:
    g = _grid()
    _cloud(g, 0)
    return _pack(g)


def _icon_fog() -> bytes:
    g = _grid()
    for y in (6, 12, 18, 24):
        for x in range(4, 28):
            g[y][x] = g[y + 1][x] = 1
    return _pack(g)


def _icon_rain() -> bytes:
    g = _grid()
    _cloud(g, -6)
    for x in (10, 16, 22):
        for y in range(22, 30, 3):
            g[y][x] = g[y + 1][x] = 1
    return _pack(g)


def _icon_snow() -> bytes:
    g = _grid()
    _cloud(g, -6)
    for x, y in ((10, 24), (16, 27), (22, 24)):
        g[y][x] = g[y][x - 1] = g[y][x + 1] = g[y - 1][x] = g[y + 1][x] = 1
    return _pack(g)


def _icon_storm() -> bytes:
    g = _grid()
    _cloud(g, -8)
    for y, x0, x1 in ((18, 14, 22), (19, 13, 20), (20, 12, 18), (21, 15, 20),
                      (22, 14, 19), (23, 13, 17), (24, 12, 16), (25, 11, 15),
                      (26, 12, 16), (27, 13, 17), (28, 14, 18)):
        for x in range(x0, x1):
            if 0 <= x < 32:
                g[y][x] = 1
    return _pack(g)


ICONS = {"clear": _icon_sun(), "partly": _icon_partly(), "cloud": _icon_cloud(),
         "fog": _icon_fog(), "rain": _icon_rain(), "snow": _icon_snow(), "storm": _icon_storm()}
ICON_FG = {"clear": ACCENT, "partly": ACCENT, "cloud": FG, "fog": MUTED,
           "rain": ACCENT, "snow": FG, "storm": WARN}


def weather_kind(code: int) -> tuple[str, str]:
    if code == 0:
        return "clear", "CLEAR"
    if code in (1, 2):
        return "partly", "FAIR"
    if code == 3:
        return "cloud", "CLOUDY"
    if code in (45, 48):
        return "fog", "FOG"
    if 71 <= code <= 77 or code in (85, 86):
        return "snow", "SNOW"
    if code >= 95:
        return "storm", "STORM"
    if 51 <= code <= 67 or 80 <= code <= 82:
        return "rain", "RAIN"
    return "cloud", "CLOUDY"


def load_config() -> dict:
    try:
        with open(CONFIG_PATH) as f:
            data = json.load(f)
        return data if isinstance(data, dict) else {}
    except (OSError, ValueError):
        return {}


def geocode(name: str) -> list[dict]:
    url = "https://geocoding-api.open-meteo.com/v1/search?count=5&language=en&name=" + urllib.parse.quote(name)
    with urllib.request.urlopen(url, timeout=3) as r:
        data = json.load(r)
    return [{"name": h["name"], "admin": h.get("admin1") or "", "country": h.get("country") or "",
             "latitude": h["latitude"], "longitude": h["longitude"]}
            for h in data.get("results") or []]


def fetch_weather(lat: float, lon: float, name: str = "") -> dict | None:
    url = ("https://api.open-meteo.com/v1/forecast"
           f"?latitude={lat}&longitude={lon}&current=temperature_2m,weather_code"
           "&daily=temperature_2m_max,temperature_2m_min&timezone=auto&forecast_days=1")
    with urllib.request.urlopen(url, timeout=2) as r:
        data = json.load(r)
    kind, label = weather_kind(int(data["current"]["weather_code"]))
    return {"temp": round(data["current"]["temperature_2m"]), "kind": kind, "label": label,
            "hi": round(data["daily"]["temperature_2m_max"][0]),
            "lo": round(data["daily"]["temperature_2m_min"][0]), "place": name}


_weather_cache: dict = {"at": 0.0, "data": None}


def weather_info() -> dict | None:
    cfg = load_config()
    if "latitude" not in cfg or "longitude" not in cfg:
        return None
    now = time.monotonic()
    if _weather_cache["data"] is not None and now - _weather_cache["at"] < 900:
        return _weather_cache["data"]
    try:
        info = fetch_weather(float(cfg["latitude"]), float(cfg["longitude"]), str(cfg.get("name") or ""))
    except (OSError, ValueError, KeyError, TimeoutError):
        return _weather_cache["data"]
    _weather_cache.update(at=now, data=info)
    return info


def weather_page(_now: datetime, w: dict) -> dict:
    kind = w["kind"] if w["kind"] in ICONS else "cloud"
    return {
        "title": title("weather"),
        "icon": Icon(16, 56, 32, 32, ICONS[kind], ICON_FG.get(kind, FG)),
        "temp": Text(72, 60, 4, f"{w['temp']}C", FG, 4),
        "cond": Text(16, 128, 13, w["label"], FG, 2, "center"),
        "range": Text(16, 164, 13, f"HI {w['hi']} LO {w['lo']}", MUTED, 2, "center"),
        "place": Text(16, 202, 26, w["place"], MUTED, 1, "center"),
    }


# ---- notifications ----------------------------------------------------------

def _dbus_string(line: str) -> str | None:
    text = line.strip()
    if not text.startswith('string "'):
        return None
    out, esc, i = [], False, len('string "')
    while i < len(text):
        c = text[i]
        if esc:
            out.append({"n": "\n", "t": "\t", '"': '"', "\\": "\\"}.get(c, c))
            esc = False
        elif c == "\\":
            esc = True
        elif c == '"':
            return "".join(out)
        else:
            out.append(c)
        i += 1
    return None


class Notifications:
    """Latest desktop notification (app name and summary only; the body is ignored)."""

    def __init__(self) -> None:
        self._lock = threading.Lock()
        self._latest: tuple[float, str, str] | None = None
        self._active = False
        self._strings: list[str] = []
        threading.Thread(target=self._listen, daemon=True).start()

    def feed(self, line: str) -> None:
        if "member=Notify" in line and "org.freedesktop.Notifications" in line:
            self._active, self._strings = True, []
            return
        if not self._active:
            return
        stripped = line.strip()
        if (not stripped or line.startswith("method ") or line.startswith("signal ")
                or stripped.startswith(("array", "dict", "variant"))):
            self._active = False
            return
        value = _dbus_string(line)
        if value is None:
            return
        self._strings.append(value)
        if len(self._strings) == 3:  # app, icon, summary — stop before the body
            self._store(self._strings[0], self._strings[2])
            self._active = False

    def _store(self, app: str, summary: str) -> None:
        app, summary = app.strip(), summary.strip()
        if not app and not summary:
            return
        now = time.monotonic()
        with self._lock:
            prev = self._latest
            if prev and prev[1] == app and prev[2] == summary and now - prev[0] < 1.5:
                return
            self._latest = (now, app, summary)

    def current(self, hold: float = 10.0) -> dict | None:
        with self._lock:
            if self._latest and time.monotonic() - self._latest[0] < hold:
                return {"app": self._latest[1], "summary": self._latest[2]}
        return None

    def _listen(self) -> None:
        cmd = ["dbus-monitor", "--session",
               "type='method_call',interface='org.freedesktop.Notifications',member='Notify'"]
        if shutil.which("stdbuf"):
            cmd = ["stdbuf", "-oL", *cmd]
        try:
            proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, text=True)
        except OSError:
            return
        assert proc.stdout is not None
        for line in proc.stdout:
            self.feed(line)


AGENT_PATH = os.path.join(os.path.expanduser("~"), ".local", "state", "rt100screen", "agent.json")
AGENT_HOLD = 180
AGENT_LABEL = {"waiting": "WAITING", "needs-you": "NEEDS YOU", "error": "ERROR", "stopped": "STOPPED"}
AGENT_FG = {"waiting": WARN, "needs-you": BAD, "error": BAD, "stopped": MUTED}


def _project_name(payload: dict) -> str:
    for key in ("cwd", "workspace_root"):
        value = payload.get(key)
        if isinstance(value, str) and value:
            return os.path.basename(value.rstrip("/"))
    roots = payload.get("workspace_roots") or payload.get("workspaceRoots") or []
    if isinstance(roots, list) and roots and isinstance(roots[0], str):
        return os.path.basename(roots[0].rstrip("/"))
    return ""


def _short(text: str) -> str:
    text = " ".join(str(text).split())
    if not text or len(text) > 42 or "/" in text:
        return ""
    return text


def publish_agent(source: str, clear: bool = False, state: str = "", summary: str = "") -> None:
    """Record an agent event for the screen. Never raises: hooks must fail open."""
    try:
        raw = "" if sys.stdin.isatty() else sys.stdin.read()
        payload = json.loads(raw) if raw.strip() else {}
        if not isinstance(payload, dict):
            payload = {}
        event = str(payload.get("hook_event_name") or "")
        kind = str(payload.get("notification_type") or "").lower()
        status = str(payload.get("status") or payload.get("reason") or "").lower()
        if clear or event in ("UserPromptSubmit", "beforeSubmitPrompt"):
            state = "clear"
        elif kind == "auth_success":
            print('{"continue": true, "suppressOutput": true}')
            return
        elif not state:
            if "permission" in kind or "idle" in kind or "elicit" in kind:
                state = "needs-you"
            elif "error" in status or "fail" in status:
                state = "error"
            elif "abort" in status or "cancel" in status:
                state = "stopped"
            else:
                state = "waiting"
        if not summary:
            summary = _short(payload.get("message") or payload.get("title") or "") or _project_name(payload)
        os.makedirs(os.path.dirname(AGENT_PATH), exist_ok=True)
        tmp = AGENT_PATH + ".tmp"
        with open(tmp, "w") as f:
            json.dump({"source": source, "state": state, "summary": summary, "at": time.time()}, f)
        os.replace(tmp, AGENT_PATH)
        if state in AGENT_LABEL:
            subprocess.run(
                ["/usr/bin/gdbus", "call", "--session",
                 "--dest", "org.freedesktop.Notifications",
                 "--object-path", "/org/freedesktop/Notifications",
                 "--method", "org.freedesktop.Notifications.Notify",
                 source, "0", "", AGENT_LABEL[state].title(), summary or source,
                 "[]", "{}", "5000"],
                timeout=2, capture_output=True)
    except Exception:
        pass
    print('{"continue": true, "suppressOutput": true}')


def agent_status() -> dict | None:
    try:
        with open(AGENT_PATH) as f:
            data = json.load(f)
        if data.get("state") not in AGENT_LABEL:
            return None
        if time.time() - float(data.get("at", 0)) > AGENT_HOLD:
            return None
        return data
    except (OSError, ValueError, TypeError):
        return None


def agent_page(_now: datetime, a: dict) -> dict:
    state = a["state"] if a.get("state") in AGENT_LABEL else "waiting"
    w = {
        "title": title("agent"),
        "who": Text(16, 52, 13, str(a.get("source") or ""), ACCENT, 2, "center"),
        "state": Text(12, 96, 9, AGENT_LABEL[state], AGENT_FG[state], 3, "center"),
    }
    for i, line in enumerate(wrap(str(a.get("summary") or ""), 13, 2)):
        w[f"s{i}"] = Text(16, 168 + i * 32, 13, line, FG)
    return w


def notify_page(_now: datetime, n: dict) -> dict:
    w = {"title": title("notice"), "app": Text(16, 52, 13, n["app"], ACCENT)}
    for i, line in enumerate(wrap(n["summary"], 13, 3)):
        w[f"s{i}"] = Text(16, 96 + i * 36, 13, line, FG)
    return w


PAGES = {"clock": (clock_page, lambda: None),
         "system": (system_page, system_stats),
         "media": (media_page, media_info),
         "weather": (weather_page, weather_info)}


# ---- screen -----------------------------------------------------------------

class Screen:
    """Remembers what is on the panel and redraws only widgets that changed."""

    def __init__(self, link: Link) -> None:
        self.link, self.shown, self.page = link, {}, None

    def show(self, page: str, widgets: dict) -> None:
        f = sp.Frame()
        if page != self.page:
            f.fill(0, 0, sp.W, sp.H, BG)
            self.shown, self.page = {}, page
        for key, widget in widgets.items():
            if self.shown.get(key) != widget:
                widget.draw(f)
                self.shown[key] = widget
        self.link.send(f.packets())


def _request_stop(signum: int, _frame) -> None:
    if _stop.is_set():
        raise KeyboardInterrupt
    _stop.set()


def run(link: Link, pages: list[str], seconds: float, stay: bool, notify: bool = True) -> None:
    import psutil
    psutil.cpu_percent(interval=None)
    signal.signal(signal.SIGINT, _request_stop)
    signal.signal(signal.SIGTERM, _request_stop)
    notes = Notifications() if notify else None
    if "weather" in pages and "latitude" not in load_config():
        print("weather needs a location: rt100screen.py location CITY", flush=True)
    link.send(sp.Frame().begin(BG).packets())
    link.send([(sp.settime_packet(datetime.now()), 0)])
    screen, index, switched = Screen(link), 0, time.monotonic()
    try:
        while not _stop.is_set():
            note = notes.current() if notes else None
            agent = agent_status()
            if note:
                screen.show("notify", notify_page(datetime.now(), note))
            elif agent:
                screen.show("agent", agent_page(datetime.now(), agent))
            else:
                available = []
                for name in pages:
                    render, source = PAGES[name]
                    data = source()
                    if name in ("media", "weather") and data is None:
                        continue
                    available.append((name, render, data))
                if not available:
                    time.sleep(1)
                    continue
                if time.monotonic() - switched >= seconds:
                    index, switched = (index + 1) % len(available), time.monotonic()
                name, render, data = available[index % len(available)]
                widgets = render(datetime.now(), data)
                widgets.update(dots(index % len(available), len(available)))
                screen.show(name, widgets)
            time.sleep(max(0.05, 1 - (time.time() % 1)))
    finally:
        if not stay:
            link.send(sp.Frame().end().packets())


def acquire_lock():
    fh = open(LOCK_PATH, "a+")
    try:
        fcntl.flock(fh, fcntl.LOCK_EX | fcntl.LOCK_NB)
    except BlockingIOError:
        sys.exit("rt100screen is already running (rt100screen.py stop)")
    fh.seek(0)
    fh.truncate()
    fh.write(str(os.getpid()))
    fh.flush()
    return fh


def stop_running() -> None:
    try:
        pid = int(open(LOCK_PATH).read().strip() or 0)
        cmd = open(f"/proc/{pid}/cmdline", "rb").read()
    except (OSError, ValueError):
        sys.exit("rt100screen is not running")
    if b"rt100screen" not in cmd:
        sys.exit("rt100screen is not running")
    os.kill(pid, signal.SIGTERM)
    print("stopping; the screen returns to the stock UI")


def save_location(a) -> None:
    if a.lat is not None or a.lon is not None:
        if a.lat is None or a.lon is None:
            sys.exit("pass both --lat and --lon")
        if not (-90 <= a.lat <= 90 and -180 <= a.lon <= 180):
            sys.exit("latitude must be -90..90 and longitude -180..180")
        cfg = {"latitude": a.lat, "longitude": a.lon, "name": a.name}
    elif a.arg:
        try:
            hits = geocode(a.arg)
        except (OSError, ValueError, KeyError) as e:
            sys.exit(f"lookup failed: {e}")
        if len(hits) != 1:
            if not hits:
                sys.exit(f"no match for {a.arg!r}")
            print("Several matches. Re-run with the coordinates of the right one:")
            for h in hits:
                where = ", ".join(p for p in (h["name"], h["admin"], h["country"]) if p)
                print(f"  --lat {h['latitude']:.4f} --lon {h['longitude']:.4f} --name {h['name']!r}   {where}")
            return
        h = hits[0]
        cfg = {"latitude": h["latitude"], "longitude": h["longitude"], "name": a.name or h["name"]}
    else:
        sys.exit("usage: rt100screen.py location CITY")
    os.makedirs(os.path.dirname(CONFIG_PATH), exist_ok=True)
    with open(CONFIG_PATH, "w") as f:
        json.dump(cfg, f, indent=2)
        f.write("\n")
    print(f"saved {cfg['name']} ({cfg['latitude']:.3f}, {cfg['longitude']:.3f})")


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("action", choices=["run", "settime", "stock", "stop", "text", "image", "location", "agent"])
    ap.add_argument("arg", nargs="?")
    ap.add_argument("--pages", default="clock,system,media,weather")
    ap.add_argument("--seconds", type=float, default=10)
    ap.add_argument("--stay", action="store_true", help="keep custom mode on exit")
    ap.add_argument("--no-notify", action="store_true", help="ignore desktop notifications")
    ap.add_argument("--dongle", action="store_true", help="use the 2.4 GHz dongle")
    ap.add_argument("--us-per-pixel", type=float, default=6.0)
    ap.add_argument("--full", action="store_true", help="allow an image larger than 64px; this is slow")
    ap.add_argument("--lat", type=float)
    ap.add_argument("--lon", type=float)
    ap.add_argument("--name", default="")
    ap.add_argument("--source", default="Agent")
    ap.add_argument("--state", default="")
    ap.add_argument("--summary", default="")
    ap.add_argument("--clear", action="store_true")
    ap.add_argument("--dry-run", action="store_true")
    a = ap.parse_args()
    if a.action == "agent":
        publish_agent(a.source, a.clear, a.state, a.summary or a.arg or "")
        return
    if a.action == "location":
        save_location(a)
        return
    if a.action == "stop":
        stop_running()
        return
    lock = None if a.dry_run else acquire_lock()
    link = Link(a.dry_run, a.dongle, a.us_per_pixel)
    if a.action == "run":
        pages = [p for p in a.pages.split(",") if p]
        unknown = [p for p in pages if p not in PAGES]
        if unknown:
            sys.exit(f"unknown pages: {unknown}")
        run(link, pages, a.seconds, a.stay, notify=not a.no_notify)
    elif a.action == "settime":
        link.send([(sp.settime_packet(datetime.now()), 0)])
    elif a.action == "stock":
        link.send(sp.Frame().end().packets())
    elif a.action == "text":
        f = sp.Frame().begin(BG)
        for i, line in enumerate(wrap(a.arg or "", 15, 6)):
            f.text(0, 24 + i * 32, line, FG, BG, 2)
        link.send(f.packets())
    elif a.action == "image":
        if not a.arg:
            sys.exit("usage: rt100screen.py image picture.png")
        from PIL import Image
        img = Image.open(a.arg)
        img.thumbnail((sp.W, sp.H) if a.full else (64, 64))
        packets = sp.Frame().begin(0).image((sp.W - img.width) // 2, (sp.H - img.height) // 2, img).packets()
        print(f"{img.width}x{img.height}, {len(packets)} packets", flush=True)
        link.send(packets)
    del lock


if __name__ == "__main__":
    main()
