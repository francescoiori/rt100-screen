"""Drive the RT100 screen in custom display mode (needs the device/custom firmware).

usage:
  rt100screen.py run [--pages clock,system,media,weather] [--seconds 10] [--no-notify]
  rt100screen.py settime | stock | stop | text "hello" | image picture.png
  rt100screen.py location CITY | location --lat LAT --lon LON --name CITY
  rt100screen.py agent --source Cursor          # used by the Cursor and Claude hooks
While it runs, a control page is at http://127.0.0.1:8765
If the wired keyboard disappears, the last frame stays and the program waits.
It does not reboot the screen back to the stock UI.
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
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
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
import teamscal

PASSTHROUGH = 0x31
NOOP = bytes([sp.PKT_DRAW]).ljust(sp.PACKET, b"\0")

# Uploaded clips are played by the screen from the compact format.
FAST_UPLOAD = True
BG = sp.hexcolor("0b0f1a")
FG = sp.hexcolor("f5f7fa")
ACCENT = sp.hexcolor("4fd1ff")
MUTED = sp.hexcolor("8b95a7")
TRACK = sp.hexcolor("1f2937")
GOOD, WARN, BAD = sp.hexcolor("7ee787"), sp.hexcolor("ffb454"), sp.hexcolor("ff6b6b")


# ---- link -------------------------------------------------------------------

class LinkDown(Exception):
    """The keyboard went away mid-send. A custom screen keeps the frame it already has."""


class Link:
    def __init__(self, dry_run: bool = False, dongle: bool = False,
                 us_per_pixel: float = 6.0, packet_delay: float = 0.0005,
                 require: bool = True) -> None:
        self.dry_run, self.us_per_pixel, self.packet_delay = dry_run, us_per_pixel, packet_delay
        self.dongle = dongle
        self.path = None
        self.alive = bool(dry_run)
        self.rt100 = None
        if not dry_run:
            import rt100
            self.rt100 = rt100
            self.reopen(require)

    def reopen(self, require: bool = False) -> bool:
        """Look for the wired keyboard again. The 2.4 GHz dongle stays opt-in."""
        if self.dry_run:
            self.alive = True
            return True
        try:
            self.path = self.rt100.find_vendor_hidraw((0x4011,) if self.dongle else (0x4010,))
        except FileNotFoundError:
            self.alive = False
            self.path = None
            if require:
                raise
            return False
        self.alive = True
        return True

    def send(self, packets: list[tuple[bytes, int]]) -> None:
        for start in range(0, len(packets), 0xFFFF):
            self._session(packets[start:start + 0xFFFF])

    def _write(self, packet: bytes) -> None:
        try:
            self.rt100.send(self.path, packet)
        except OSError:
            self.alive = False
            raise LinkDown

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
        self._write(bytes(start))
        time.sleep(0.01)
        sent = 0
        try:
            for p, px in packets:
                self._write(p)
                sent += 1
                time.sleep(self.packet_delay + px * self.us_per_pixel / 1e6)
        finally:
            for _ in range(n - sent):
                if not self.alive:
                    break
                self._write(NOOP)
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
    battery = None
    bat = psutil.sensors_battery()
    if bat is not None:
        battery = {"percent": round(bat.percent), "plugged": bool(bat.power_plugged)}
    return {"cpu": psutil.cpu_percent(interval=None), "ram": psutil.virtual_memory().percent,
            "temp": temp, "battery": battery}


def system_page(_now: datetime, s: dict) -> dict:
    w = {"title": title("system")}
    rows = [("cpu", "CPU", s["cpu"] / 100, f"{s['cpu']:.0f}%"),
            ("ram", "RAM", s["ram"] / 100, f"{s['ram']:.0f}%")]
    if s.get("temp") is not None:
        rows.append(("temp", "TEMP", (s["temp"] - 30) / 70, f"{s['temp']:.0f}C"))
    # Scale-2 text is 32px tall. The meter goes under the words, and the
    # battery line stays above the page dots at y=224.
    for i, (key, label, frac, value) in enumerate(rows):
        y = 48 + i * 46
        w[key + "_l"] = Text(16, y, 4, label, MUTED)
        w[key + "_v"] = Text(144, y, 5, value, FG, 2, "right")
        w[key + "_b"] = Bar(16, y + 34, 208, 6, frac, level(frac))
    bat = s.get("battery")
    if bat:
        state = "PLUGGED" if bat["plugged"] else "BATTERY"
        w["bat"] = Text(16, 48 + len(rows) * 46, 13, f"{bat['percent']}%  {state}",
                        ACCENT if bat["plugged"] else WARN, 2, "center")
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


def _wpctl(target: str) -> dict | None:
    try:
        out = subprocess.run(["wpctl", "get-volume", target], capture_output=True, text=True, timeout=1)
    except (OSError, subprocess.TimeoutExpired):
        return None
    line = (out.stdout or "").strip()
    parts = line.split()
    if len(parts) < 2 or parts[0] != "Volume:":
        return None
    try:
        level = float(parts[1])
    except ValueError:
        return None
    return {"level": max(0.0, level), "muted": "MUTED" in line}


def volume_info() -> dict | None:
    sink = _wpctl("@DEFAULT_AUDIO_SINK@")
    if sink is None:
        return None
    mic = _wpctl("@DEFAULT_AUDIO_SOURCE@")
    return {"level": sink["level"], "muted": sink["muted"], "mic_muted": bool(mic and mic["muted"])}


def volume_page(_now: datetime, v: dict) -> dict:
    muted = v["muted"]
    label = "MUTED" if muted else f"{round(min(v['level'], 1) * 100)}%"
    return {
        "title": title("volume"),
        "level": Text(centered(5, 4), 72, 5, label, MUTED if muted else FG, 4, "center"),
        "bar": Bar(20, 156, 200, 12, 0 if muted else min(1.0, v["level"])),
        "mic": Text(16, 188, 13, "MIC MUTED" if v["mic_muted"] else "MIC ON",
                    BAD if v["mic_muted"] else MUTED, 2, "center"),
    }


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


def save_config(updates: dict) -> None:
    cfg = load_config()
    cfg.update(updates)
    os.makedirs(os.path.dirname(CONFIG_PATH), exist_ok=True)
    tmp = CONFIG_PATH + ".tmp"
    with open(tmp, "w") as f:
        json.dump(cfg, f, indent=2)
        f.write("\n")
    os.replace(tmp, CONFIG_PATH)


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

def _display_env() -> dict[str, str]:
    env = os.environ.copy()
    env.setdefault("DISPLAY", ":1")
    return env


def _words(text: str) -> list[str]:
    word, out = [], []
    for ch in text.lower():
        if ch.isalnum():
            word.append(ch)
        elif word:
            out.append("".join(word))
            word = []
    if word:
        out.append("".join(word))
    return out


def focused_window() -> tuple[str, str]:
    """WM_CLASS and title of the window in front. Empty if it cannot be read."""
    env = _display_env()
    try:
        root = subprocess.check_output(
            ["xprop", "-root", "_NET_ACTIVE_WINDOW"],
            env=env, text=True, timeout=0.4, stderr=subprocess.DEVNULL)
    except (OSError, subprocess.TimeoutExpired):
        return "", ""
    wid = next((part for part in root.split() if part.startswith("0x")), "")
    if not wid or wid in ("0x0", "0x0,"):
        return "", ""
    try:
        info = subprocess.check_output(
            ["xprop", "-id", wid.rstrip(","), "WM_CLASS", "_NET_WM_NAME"],
            env=env, text=True, timeout=0.4, stderr=subprocess.DEVNULL)
    except (OSError, subprocess.TimeoutExpired):
        return "", ""
    classes, title = [], ""
    for line in info.splitlines():
        if line.startswith("WM_CLASS"):
            classes.extend(_quoted_fields(line))
        elif line.startswith("_NET_WM_NAME"):
            names = _quoted_fields(line)
            title = names[-1] if names else ""
    return " ".join(classes), title


def _quoted_fields(line: str) -> list[str]:
    out, i = [], 0
    while True:
        start = line.find('"', i)
        if start < 0:
            return out
        end = line.find('"', start + 1)
        if end < 0:
            return out
        out.append(line[start + 1:end])
        i = end + 1


def window_is_app(app: str, classes: str, title: str) -> bool:
    """True when the focused window is the application that sent the notice."""
    app_c = "".join(_words(app))
    if len(app_c) < 3:
        return False
    for token in _words(classes):
        if len(token) >= 3 and (token in app_c or app_c in token):
            return True
    tail = "".join(_words(title.split(" - ")[-1] if title else ""))
    return len(tail) >= 3 and (app_c in tail or tail in app_c)


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
            latest = self._latest
            if latest is None or time.monotonic() - latest[0] >= hold:
                return None
            app, summary = latest[1], latest[2]
        classes, title = focused_window()
        if window_is_app(app, classes, title):
            with self._lock:
                if self._latest is latest:
                    self._latest = None
            return None
        return {"app": app, "summary": summary}

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


def _window_label(source: str, folder: str) -> str:
    """The title-bar name of the Cursor or Claude window for this project."""
    folder = folder.strip()
    if not folder:
        return ""
    try:
        env = _display_env()
        tree = subprocess.check_output(
            ["xwininfo", "-root", "-tree"], env=env, text=True, timeout=2, stderr=subprocess.DEVNULL)
    except (OSError, subprocess.TimeoutExpired):
        return folder
    app = "cursor" if source.lower() == "cursor" else "claude"
    folder_l = folder.lower()
    for line in tree.splitlines():
        start = line.find('"')
        end = line.find('"', start + 1)
        if start < 0 or end < 0:
            continue
        title = line[start + 1:end]
        parts = [part.strip() for part in title.split(" - ") if part.strip()]
        if not parts or app not in parts[-1].lower():
            continue
        if not any(folder_l in part.lower() for part in parts):
            continue
        for part in parts[:-1]:
            if folder_l in part.lower():
                return part[:48]
    return folder


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
            summary = _short(payload.get("message") or payload.get("title") or "")
        folder = _project_name(payload)
        where = _window_label(source, folder)
        os.makedirs(os.path.dirname(AGENT_PATH), exist_ok=True)
        tmp = AGENT_PATH + ".tmp"
        with open(tmp, "w") as f:
            json.dump({"source": source, "state": state, "summary": summary,
                       "where": where, "at": time.time()}, f)
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


def agent_page(now: datetime, a: dict) -> dict:
    state = a["state"] if a.get("state") in AGENT_LABEL else "waiting"
    label = AGENT_LABEL[state]
    color = BAD if state in ("needs-you", "error") else WARN if state == "waiting" else MUTED
    flash = state in ("waiting", "needs-you", "error") and int(now.timestamp() * 2) % 2 == 0
    ink, paper = (BG, color) if flash else (color, BG)
    owner = ascii_only(str(a.get("source") or "AGENT")).upper()[:8] or "AGENT"
    where = str(a.get("where") or "").replace("-", " ").replace("_", " ")
    summary = str(a.get("summary") or "")
    if summary.lower() == str(a.get("where") or "").lower():
        summary = ""
    w = {
        "who": Text(centered(len(owner), 3), 8, len(owner), owner, ACCENT, 3, "center"),
        "band": Rect(0, 62, sp.W, 76, paper),
        "state": Text(centered(9, 3), 76, 9, label, ink, 3, "center", paper),
        "win": Text(centered(6, 1), 148, 6, "WINDOW", MUTED, 1, "center"),
    }
    shown = ascii_only(where).strip().upper()
    if shown and len(shown) <= 8 and " " not in shown:
        w["w0"] = Text(centered(len(shown), 3), 168, len(shown), shown, FG, 3, "center")
    else:
        for i, line in enumerate(wrap(shown or owner, 13, 2)):
            w[f"w{i}"] = Text(16, 166 + i * 32, 13, line, FG, 2, "center")
    if summary and "w1" not in w:
        w["why"] = Text(8, 216, 26, summary, MUTED, 1, "center")
    return w


def notify_page(_now: datetime, n: dict) -> dict:
    w = {"title": title("notice"), "app": Text(16, 52, 13, n["app"], ACCENT)}
    for i, line in enumerate(wrap(n["summary"], 13, 3)):
        w[f"s{i}"] = Text(16, 96 + i * 36, 13, line, FG)
    return w


def _agenda_loop() -> None:
    while not _stop.is_set():
        try:
            teamscal.poll()
        except Exception:
            pass
        _stop.wait(5)


def agenda_info() -> dict | None:
    event = teamscal.next_event()
    if event:
        return event
    info = teamscal.signin()
    if info["signed_in"]:
        return None
    return {"when": "TEAMS", "title": "Sign in on the laptop"}


def agenda_page(_now: datetime, a: dict) -> dict:
    w = {"title": title("next"), "when": Text(16, 56, 13, a["when"], ACCENT, 2, "center")}
    for i, line in enumerate(wrap(a["title"], 13, 3)):
        w[f"t{i}"] = Text(16, 108 + i * 36, 13, line, FG)
    return w


def agenda_empty() -> dict:
    return {"title": title("next"), "none": Text(16, 104, 13, "NOTHING NEXT", MUTED, 2, "center")}


def timer_page(_now: datetime, t: dict) -> dict:
    if t["done"]:
        return {"title": title("timer"), "done": Text(centered(4, 4), 88, 4, "DONE", GOOD, 4, "center")}
    text = f"{t['left'] // 60:02d}:{t['left'] % 60:02d}"
    return {"title": title("timer"), "left": Text(centered(5, 4), 80, 5, text, FG, 4, "center")}


PAGES = {"clock": (clock_page, lambda: None),
         "system": (system_page, system_stats),
         "media": (media_page, media_info),
         "weather": (weather_page, weather_info),
         "agenda": (agenda_page, agenda_info),
         "volume": (volume_page, volume_info)}
PAGE_LABEL = {"clock": "Clock", "system": "System", "media": "Now playing", "weather": "Weather",
              "agenda": "Next up", "volume": "Volume", "timer": "Timer",
              "notify": "Notification", "agent": "Agent", "text": "Your text", "image": "Image"}
DEFAULT_PAGES = ["clock", "system", "media", "weather", "agenda", "volume"]


def rotation_prefs() -> tuple[list[str], float, bool]:
    cfg = load_config()
    pages = [p for p in (cfg.get("pages") or []) if p in PAGES]
    if not pages:
        pages = list(DEFAULT_PAGES)
    try:
        seconds = float(cfg.get("seconds", 10))
    except (TypeError, ValueError):
        seconds = 10.0
    return pages, min(60.0, max(3.0, seconds)), bool(cfg.get("quiet"))


def caption(shown: str, data=None, text: str = "") -> str:
    if shown == "clock":
        return datetime.now().strftime("%H:%M")
    if shown == "system" and isinstance(data, dict):
        extra = f" {data['temp']:.0f}C" if data.get("temp") is not None else ""
        bat = data.get("battery")
        charge = f" {bat['percent']}%" if bat else ""
        return f"CPU {data['cpu']:.0f}%{extra}{charge}"
    if shown == "media" and isinstance(data, dict):
        return (data.get("title") or "Nothing playing")[:42]
    if shown == "weather" and isinstance(data, dict):
        return f"{data['temp']}C {data['label']}"
    if shown == "agenda" and isinstance(data, dict):
        return (data.get("title") or "Nothing next")[:42]
    if shown == "volume" and isinstance(data, dict):
        mic = " mic off" if data.get("mic_muted") else ""
        return ("Muted" if data.get("muted") else f"{round(min(data['level'], 1) * 100)}%") + mic
    if shown == "timer" and isinstance(data, dict):
        return "Done" if data.get("done") else f"{data['left'] // 60:02d}:{data['left'] % 60:02d}"
    if shown == "notify" and isinstance(data, dict):
        return (data.get("summary") or data.get("app") or "Notification")[:42]
    if shown == "agent" and isinstance(data, dict):
        parts = [data.get("source") or "Agent", data.get("where") or "", AGENT_LABEL.get(data.get("state"), "")]
        return " · ".join(part for part in parts if part)[:42]
    if shown == "text":
        return text[:42]
    if shown == "image":
        return "Image"
    if shown == "unplugged":
        return "Keyboard unplugged"
    if shown == "stock":
        return "Stock clock"
    return ""


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


PANEL_HTML = """<!doctype html>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>RT100</title>
<style>
  :root { color-scheme: dark; }
  body { margin: 0; background: #0b0f1a; color: #f5f7fa;
         font: 15px/1.4 ui-sans-serif, system-ui, sans-serif; }
  main { max-width: 440px; margin: 0 auto; padding: 22px 18px 32px; }
  header { display: flex; align-items: center; justify-content: space-between; gap: 12px; }
  h1 { margin: 0; font-size: 13px; letter-spacing: .18em; color: #4fd1ff; font-weight: 650; }
  a.repo { color: #8b95a7; text-decoration: none; font-size: 13px;
           border: 1px solid #263044; border-radius: 999px; padding: 6px 12px; }
  a.repo:hover { color: #f5f7fa; border-color: #4fd1ff; }
  .status { margin: 16px 0 14px; padding: 14px 16px; background: #121826;
            border: 1px solid #263044; border-radius: 16px; border-left: 3px solid #4fd1ff; }
  .status.alert { border-left-color: #ffb020; }
  .status.down { border-left-color: #8b95a7; }
  .status .mode { margin: 0; font-size: 11px; letter-spacing: .16em; text-transform: uppercase; color: #8b95a7; }
  .status .screen { margin: 2px 0 0; font-size: 22px; font-weight: 650; }
  .status .detail { margin: 4px 0 0; color: #c5cedb; min-height: 1.2em; }
  #teams { margin: 0 0 8px; }
  #teams[hidden] { display: none; }
  #teams .note { margin: 8px 2px 0; color: #8b95a7; font-size: 13px; }
  h2 { margin: 0 0 10px; font-size: 12px; letter-spacing: .14em; color: #8b95a7;
       font-weight: 650; text-transform: uppercase; }
  .card { margin-top: 14px; padding: 14px; background: #121826;
          border: 1px solid #1c2433; border-radius: 16px; }
  .hint { margin: -4px 0 10px; color: #8b95a7; font-size: 13px; }
  .chips { display: grid; grid-template-columns: 1fr 1fr; gap: 8px; }
  button, input { font: inherit; color: inherit; background: #151b2b;
                  border: 1px solid #263044; border-radius: 12px; }
  button { padding: 12px; cursor: pointer; }
  button.on { border-color: #4fd1ff; color: #4fd1ff; }
  button.chip { display: flex; align-items: center; justify-content: space-between; gap: 8px; text-align: left; }
  button.chip i { width: 14px; height: 14px; border-radius: 50%; border: 1px solid #3a465c;
                  background: transparent; flex: 0 0 auto; }
  button.chip.in i { background: #4fd1ff; border-color: #4fd1ff; }
  .pills, .pair { display: flex; gap: 8px; }
  .pills { margin-top: 10px; }
  .pills button { flex: 1; border-radius: 999px; padding: 8px 10px; }
  .pair { margin-top: 8px; }
  .pair button { flex: 1; }
  button.wide { width: 100%; margin-top: 8px; }
  form { display: flex; gap: 8px; margin-top: 8px; }
  input[type=text], input[type=number] { min-width: 0; padding: 12px; background: #0b0f1a; }
  input[type=text] { flex: 1; }
  input[type=number] { width: 64px; }
  .drop { margin-top: 8px; padding: 22px 14px; text-align: center; color: #c5cedb;
          border: 1px dashed #314056; border-radius: 14px; background: #0b0f1a; cursor: pointer; }
  input[type=file] { display: none; }
  .drop strong { display: block; font-weight: 650; color: #f5f7fa; }
  .drop span { display: block; margin-top: 4px; color: #8b95a7; font-size: 13px; }
  .drop.minor { padding: 12px; color: #8b95a7; }
  .drop.on { border-color: #4fd1ff; color: #4fd1ff; }
  footer { margin-top: 18px; font-size: 13px; }
  footer a { color: #4fd1ff; text-decoration: none; }
  [data-tip] { position: relative; }
  [data-tip]:hover::after, [data-tip]:focus-visible::after {
    content: attr(data-tip);
    position: absolute; left: 0; bottom: calc(100% + 8px); z-index: 5;
    width: max-content; max-width: 220px;
    padding: 6px 8px; border-radius: 8px;
    background: #f5f7fa; color: #0b0f1a;
    font-size: 12px; font-weight: 600; line-height: 1.3; letter-spacing: 0;
    text-transform: none; text-align: left; white-space: normal;
    box-shadow: 0 8px 20px rgba(0, 0, 0, .35);
    pointer-events: none;
  }
  .chip:has(i:hover)::after { content: none; }
</style>
<main>
  <header>
    <h1>RT100</h1>
    <a class="repo" href="https://github.com/francescoiori/epomaker" target="_blank" rel="noopener" data-tip="Open this project on GitHub">GitHub</a>
  </header>
  <section class="status" id="status">
    <p class="mode" id="mode">Connecting</p>
    <p class="screen" id="screen"></p>
    <p class="detail" id="detail"></p>
  </section>
  <div id="teams" hidden></div>
  <section class="card">
    <h2>Pages</h2>
    <p class="hint">Tap a page to show it. The dot keeps it in the rotation.</p>
    <div class="chips" id="pages"></div>
    <div class="pills" id="dwell">
      <button type="button" data-seconds="5" data-tip="Show each page for 5 seconds">5s</button>
      <button type="button" data-seconds="10" data-tip="Show each page for 10 seconds">10s</button>
      <button type="button" data-seconds="20" data-tip="Show each page for 20 seconds">20s</button>
    </div>
    <div class="pair">
      <button id="pause" type="button" data-tip="Hold whatever is on the screen">Pause</button>
      <button id="resume" type="button" data-tip="Cycle the pages marked with a dot">Rotate</button>
    </div>
    <button id="quiet" type="button" class="wide" data-tip="Stop desktop notifications from taking over the screen">Quiet notifications</button>
  </section>
  <section class="card">
    <div class="pair">
      <button id="stock" type="button" data-tip="Give the screen back to the keyboard's own clock">Stock clock</button>
      <button id="custom" type="button" data-tip="Clear the screen and start drawing again">Custom screen</button>
    </div>
    <form id="line">
      <input id="text" type="text" maxlength="90" placeholder="A line for the screen" autocomplete="off">
      <button type="submit" data-tip="Send this line to the screen">Show</button>
    </form>
    <form id="timer">
      <input id="minutes" type="number" min="1" max="180" value="5" aria-label="Minutes" data-tip="How many minutes to count">
      <button type="submit" data-tip="Start a countdown on the screen">Start timer</button>
    </form>
  </section>
  <section class="card">
    <h2>Picture</h2>
    <button id="stored" type="button" class="wide" data-tip="Play the four poses stored in the screen">Show stored picture</button>
    <div class="drop" id="drop-main" data-size="200" data-tip="Click or drop a picture or GIF. It plays at 200px from the laptop.">
      <strong>Upload a picture or GIF</strong>
      <span>Click or drop. Plays at 200px from the laptop.</span>
    </div>
    <div class="drop minor" id="drop-full" data-size="240" data-tip="Click or drop a picture that fills the 240px panel. The first frame takes longer.">Edge to edge. The first frame is slower.</div>
  </section>
  <footer>
    <a href="https://github.com/francescoiori/epomaker" target="_blank" rel="noopener">github.com/francescoiori/epomaker</a>
  </footer>
</main>
<script>
const pages = [
  ["clock","Clock","Show the clock"],
  ["system","System","Show CPU, memory, temperature and battery"],
  ["media","Now playing","Show the track that is playing"],
  ["weather","Weather","Show the London weather"],
  ["agenda","Next up","Show the next Teams meeting"],
  ["volume","Volume","Show the speaker and microphone"],
];
const box = document.querySelector("#pages");
for (const [id, label, tip] of pages) {
  const b = document.createElement("button");
  b.type = "button"; b.className = "chip in"; b.dataset.page = id; b.dataset.tip = tip;
  b.onclick = () => send("page", id);
  const mark = document.createElement("i");
  mark.dataset.tip = "Keep this page in the rotation";
  mark.onclick = (e) => { e.stopPropagation(); toggleRotate(id); };
  b.append(document.createTextNode(label), mark);
  box.append(b);
}
document.querySelector("#pause").onclick = () => send("pause");
document.querySelector("#resume").onclick = () => send("resume");
document.querySelector("#stock").onclick = () => send("stock");
document.querySelector("#stored").onclick = () => send("stored");
document.querySelector("#custom").onclick = () => send("custom");
document.querySelectorAll("#dwell button").forEach(b => {
  b.onclick = () => send("rotation", rotationNames().join(","), {seconds: Number(b.dataset.seconds)});
});
document.querySelector("#quiet").onclick = (e) => send("quiet", e.target.classList.contains("on") ? "off" : "on");
document.querySelector("#line").onsubmit = (e) => {
  e.preventDefault();
  const input = document.querySelector("#text");
  if (input.value.trim()) send("text", input.value.trim());
  input.value = "";
};
document.querySelector("#timer").onsubmit = (e) => {
  e.preventDefault();
  send("timer", document.querySelector("#minutes").value);
};
async function upload(drop, file) {
  if (!file) return;
  await fetch("/image?size=" + drop.dataset.size, {method: "POST", body: file});
  refresh();
}
for (const drop of document.querySelectorAll(".drop")) {
  const picker = document.createElement("input");
  picker.type = "file";
  picker.accept = "image/*,.gif";
  drop.append(picker);
  drop.onclick = () => picker.click();
  picker.onchange = () => { upload(drop, picker.files[0]); picker.value = ""; };
  drop.ondragover = (e) => { e.preventDefault(); drop.classList.add("on"); };
  drop.ondragleave = () => drop.classList.remove("on");
  drop.ondrop = (e) => {
    e.preventDefault();
    drop.classList.remove("on");
    upload(drop, e.dataTransfer.files[0]);
  };
}
function rotationNames() {
  const names = [...document.querySelectorAll(".chip.in")].map(b => b.dataset.page);
  return names.length ? names : pages.map(p => p[0]);
}
function toggleRotate(id) {
  const chip = document.querySelector('.chip[data-page="' + id + '"]');
  chip.classList.toggle("in");
  if (!document.querySelector(".chip.in")) chip.classList.add("in");
  const dwell = document.querySelector("#dwell button.on");
  send("rotation", rotationNames().join(","), {seconds: dwell ? Number(dwell.dataset.seconds) : 10});
}
function pageName(shown) {
  return {clock:"Clock", system:"System", media:"Now playing", weather:"Weather",
          agenda:"Next up", volume:"Volume", timer:"Timer",
          notify:"Notification", agent:"Agent", text:"Your text", image:"Image",
          stored:"Stored picture", fast:"Picture",
          unplugged:"Unplugged", stock:"Stock clock"}[shown] || shown || "RT100";
}
function fillStatus(s) {
  const card = document.querySelector("#status");
  const unplugged = s.link === "down" || s.shown === "unplugged";
  card.classList.toggle("down", unplugged);
  card.classList.toggle("alert", !unplugged && (s.shown === "agent" || s.shown === "notify"));
  let mode = "Holding", screen = pageName(s.shown), detail = s.detail || "";
  if (unplugged) {
    mode = "Unplugged"; screen = "Keyboard unplugged"; detail = "The last picture stays on the screen.";
  } else if (s.mode === "stock") {
    mode = "Stock"; screen = "Stock clock"; detail = "";
  } else if ((s.shown || "").endsWith("unavailable")) {
    mode = s.mode === "rotate" ? "Rotating" : "Holding";
    screen = s.shown[0].toUpperCase() + s.shown.slice(1);
    detail = "";
  } else if (s.mode === "rotate") {
    mode = "Rotating";
  }
  if (detail === screen) detail = "";
  document.querySelector("#mode").textContent = mode;
  document.querySelector("#screen").textContent = screen;
  document.querySelector("#detail").textContent = detail;
}
async function send(cmd, arg="", extra={}) {
  await fetch("/command", {method:"POST", headers:{"Content-Type":"application/json"},
                           body: JSON.stringify(Object.assign({cmd, arg}, extra))});
  refresh();
}
async function refresh() {
  const s = await fetch("/status").then(r => r.json());
  fillStatus(s);
  document.querySelectorAll(".chip").forEach(b => {
    b.classList.toggle("on", s.mode === "hold" && s.page === b.dataset.page);
    b.classList.toggle("in", (s.pages || []).includes(b.dataset.page));
  });
  document.querySelector("#pause").classList.toggle("on", s.mode === "hold" && !s.page);
  document.querySelector("#resume").classList.toggle("on", s.mode === "rotate");
  document.querySelector("#stock").classList.toggle("on", s.mode === "stock");
  document.querySelector("#stored").classList.toggle("on", s.page === "stored");
  const choices = [5, 10, 20];
  const nearest = choices.reduce((best, n) => Math.abs(n - s.seconds) < Math.abs(best - s.seconds) ? n : best, choices[0]);
  document.querySelectorAll("#dwell button").forEach(b => b.classList.toggle("on", Number(b.dataset.seconds) === nearest));
  document.querySelector("#quiet").classList.toggle("on", !!s.quiet);
  const teams = document.querySelector("#teams");
  const sign = s.teams || {};
  teams.replaceChildren();
  if (sign.signed_in) {
    teams.hidden = !sign.error;
    if (sign.error) teams.textContent = sign.error;
  } else {
    teams.hidden = false;
    const b = document.createElement("button");
    b.type = "button";
    b.className = "wide";
    b.dataset.tip = "Open a browser window and allow calendar access";
    b.textContent = sign.waiting ? "Waiting for Teams…" : "Sign in to Teams";
    b.onclick = () => send("teams");
    teams.append(b);
    if (sign.error) {
      const note = document.createElement("p");
      note.className = "note";
      note.textContent = sign.error;
      teams.append(note);
    }
  }
}
refresh();
setInterval(refresh, 1000);
</script>
"""


class Control:
    """What the local page wants. The screen loop is the only thing that draws."""

    def __init__(self, pages: list[str], seconds: float) -> None:
        self._lock = threading.Lock()
        pref_pages, pref_seconds, quiet = rotation_prefs()
        cfg = load_config()
        self.pages = pref_pages if "pages" in cfg else ([p for p in pages if p in PAGES] or pref_pages)
        self.seconds = pref_seconds if "seconds" in cfg else min(60.0, max(3.0, seconds))
        self.quiet = quiet
        self.mode = "rotate"
        self.page: str | None = None
        self.text: str | None = None
        self.image: tuple[bytes, int] | None = None
        self.clip: dict | None = None
        self.fast: dict | None = None
        self.timer_until: float | None = None
        self.enter = False
        self.shown = "starting"
        self.detail = ""
        self.link = "up"

    def snapshot(self):
        with self._lock:
            text, self.text = self.text, None
            image, self.image = self.image, None
            enter, self.enter = self.enter, False
            return (self.mode, self.page, text, image, enter,
                    self.quiet, list(self.pages), self.seconds)

    def command(self, cmd: str, arg: str = "", data: dict | None = None) -> bool:
        if cmd == "teams":
            teamscal.begin()
            return True
        with self._lock:
            if cmd == "resume":
                self.mode, self.page = "rotate", None
                self._clear_picture()
                self.timer_until = None
            elif cmd == "pause":
                self.mode = "hold"
            elif cmd == "page" and arg in PAGES:
                self.mode, self.page = "hold", arg
                self._clear_picture()
                self.timer_until = None
            elif cmd == "text" and arg.strip():
                self.mode, self.page, self.text = "hold", None, arg.strip()[:90]
                self._clear_picture()
                self.timer_until = None
            elif cmd == "timer":
                try:
                    minutes = int(float(arg))
                except ValueError:
                    return False
                if not 1 <= minutes <= 180:
                    return False
                self.timer_until = time.time() + minutes * 60
                self.mode, self.page = "hold", "timer"
                self._clear_picture()
            elif cmd == "stock":
                self.mode = "stock"
                self._clear_picture()
                self.timer_until = None
            elif cmd == "custom":
                self.mode, self.page, self.enter = "rotate", None, True
                self._clear_picture()
                self.timer_until = None
            elif cmd == "stored":
                self._clear_picture()
                self.timer_until = None
                self.mode, self.page = "hold", "stored"
            elif cmd == "quiet":
                self.quiet = arg.strip().lower() in ("1", "true", "on", "yes")
                save_config({"quiet": self.quiet})
            elif cmd == "rotation":
                names = [p for p in (arg or "").split(",") if p in PAGES]
                if not names:
                    return False
                try:
                    seconds = float((data or {}).get("seconds", self.seconds))
                except (TypeError, ValueError):
                    return False
                self.pages = names
                self.seconds = min(60.0, max(3.0, seconds))
                save_config({"pages": names, "seconds": self.seconds})
            else:
                return False
            return True

    def _clear_picture(self) -> None:
        self.image = None
        self.clip = None
        self.fast = None

    def show_image(self, blob: bytes, size: int) -> None:
        fast = _prepare_fast(blob) if FAST_UPLOAD else None
        with self._lock:
            self.timer_until = None
            self.clip = None
            if fast is not None:
                self.mode, self.page = "hold", "fast"
                self.fast = fast
                self.image = None
                return
            self.fast = None
            self.mode, self.page = "hold", "image"
            self.image = (blob, 240 if size >= 220 else 200)

    def set_clip(self, frames: list) -> None:
        with self._lock:
            self.clip = {"frames": frames, "i": 0, "due": 0.0}

    def next_clip_frame(self):
        with self._lock:
            clip = self.clip
            if clip is None or self.page != "image":
                return None
            now = time.monotonic()
            if now < clip["due"]:
                return None
            frame, delay = clip["frames"][clip["i"]]
            clip["i"] = (clip["i"] + 1) % len(clip["frames"])
            clip["due"] = now + delay
            return frame

    def rewind_fast(self) -> None:
        with self._lock:
            if self.fast is None:
                return
            self.fast["i"] = 0
            self.fast["loops"] = 0
            self.fast["due"] = 0.0

    def next_fast_pose(self):
        with self._lock:
            fast = self.fast
            if fast is None or self.page != "fast":
                return None
            now = time.monotonic()
            if now < fast["due"]:
                return None
            i = fast["i"]
            packets = fast["loop0"] if i == 0 and fast["loops"] else fast["poses"][i]
            fast["i"] = (i + 1) % len(fast["poses"])
            if fast["i"] == 0:
                fast["loops"] += 1
            fast["due"] = now + fast["delay"]
            return packets

    def fast_wait(self) -> float | None:
        with self._lock:
            if self.fast is None or self.page != "fast":
                return None
            return self.fast["due"] - time.monotonic()

    def clip_wait(self) -> float | None:
        with self._lock:
            if self.clip is None or self.page != "image":
                return None
            return self.clip["due"] - time.monotonic()

    def clip_label(self) -> str:
        with self._lock:
            frames = self.clip["frames"] if self.clip else []
            return "GIF" if len(frames) > 1 else "Image"

    def timer_view(self) -> dict | None:
        with self._lock:
            if self.timer_until is None:
                return None
            left = int(self.timer_until - time.time())
            if left > 0:
                return {"left": left, "done": False}
            return {"left": 0, "done": True}

    def claim_finished_timer(self) -> bool:
        """Hold the screen on DONE once a countdown reaches zero."""
        with self._lock:
            if self.timer_until is None or time.time() < self.timer_until or self.mode == "stock":
                return False
            if self.mode == "hold" and self.page == "timer":
                return True
            self.mode, self.page = "hold", "timer"
            self.image = None
            self.clip = None
            return True

    def release(self, detail: str) -> None:
        with self._lock:
            self.mode, self.page = "hold", None
            self.shown, self.detail = "paused", detail

    def mark(self, shown: str, detail: str | None = None) -> None:
        with self._lock:
            self.shown = shown
            if detail is not None:
                self.detail = detail
            self.link = "down" if shown == "unplugged" else "up"

    def status(self) -> dict:
        with self._lock:
            return {"mode": self.mode, "page": self.page, "shown": self.shown,
                    "detail": self.detail, "quiet": self.quiet, "pages": list(self.pages),
                    "seconds": self.seconds, "link": self.link, "teams": teamscal.signin()}


def serve_panel(control: Control, port: int = 8765) -> None:
    page = PANEL_HTML.encode()

    class Handler(BaseHTTPRequestHandler):
        def do_GET(self):
            if self.path.split("?", 1)[0] == "/status":
                body = json.dumps(control.status()).encode()
                kind = "application/json"
            elif self.path.split("?", 1)[0] == "/":
                body, kind = page, "text/html; charset=utf-8"
            else:
                self.send_error(404)
                return
            self.send_response(200)
            self.send_header("Content-Type", kind)
            self.send_header("Content-Length", str(len(body)))
            self.send_header("Cache-Control", "no-store")
            self.end_headers()
            self.wfile.write(body)

        def do_POST(self):
            path = self.path.split("?", 1)[0]
            if path == "/image":
                try:
                    size = int(self.headers.get("Content-Length", "0"))
                except ValueError:
                    size = 0
                if not 0 < size <= 3_000_000:
                    self.send_error(413)
                    return
                query = urllib.parse.parse_qs(urllib.parse.urlparse(self.path).query)
                try:
                    px = int((query.get("size") or ["64"])[0])
                except ValueError:
                    px = 64
                control.show_image(self.rfile.read(size), px)
                body = b'{"ok": true}'
                self.send_response(200)
                self.send_header("Content-Type", "application/json")
                self.send_header("Content-Length", str(len(body)))
                self.end_headers()
                self.wfile.write(body)
                return
            if path != "/command":
                self.send_error(404)
                return
            try:
                size = int(self.headers.get("Content-Length", "0"))
                data = json.loads(self.rfile.read(size) or b"{}")
                ok = control.command(str(data.get("cmd", "")), str(data.get("arg", "")), data)
            except (ValueError, TypeError):
                ok = False
            body = json.dumps({"ok": ok}).encode()
            self.send_response(200 if ok else 400)
            self.send_header("Content-Type", "application/json")
            self.send_header("Content-Length", str(len(body)))
            self.end_headers()
            self.wfile.write(body)

        def log_message(self, fmt, *args):
            return

    try:
        httpd = ThreadingHTTPServer(("127.0.0.1", port), Handler)
    except OSError as exc:
        print(f"control page not started: {exc}", flush=True)
        return
    threading.Thread(target=httpd.serve_forever, daemon=True).start()
    print(f"control page http://127.0.0.1:{port}", flush=True)


def _request_stop(signum: int, _frame) -> None:
    if _stop.is_set():
        raise KeyboardInterrupt
    _stop.set()


def _prepare_fast(blob: bytes):
    """Encode an upload as the compact clip, or None if it cannot be encoded."""
    root = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "device", "custom")
    if root not in sys.path:
        sys.path.insert(0, root)
    import gen_clip
    try:
        clip = gen_clip.encode_gif(blob)
    except (OSError, ValueError):
        return None
    pal = clip["pal"]

    def pose(data: bytes, key: bool, clear: bool):
        frame = sp.Frame()
        if key or clear:
            frame.uhead(clip["w"], clip["h"], clip["x"], clip["y"], pal, clear)
        if key:
            frame.ukey(data)
        elif data:
            frame.urun(data)
        return frame.packets()

    # The first pose is sent once. Every later pass through the loop sends only
    # the pixels that lead back to it, so the screen is not repainted from scratch.
    poses = [pose(clip["key"], True, True)]
    for delta in clip["deltas"]:
        poses.append(pose(delta, False, False))
    return {
        "poses": poses,
        "loop0": pose(clip["wrap"], False, False),
        "i": 0,
        "loops": 0,
        "due": 0.0,
        "delay": clip["delay"] if len(poses) > 1 else 1e9,
    }


def _fit_frame(img, size: int):
    from PIL import Image
    img = img.convert("RGB")
    img.thumbnail((size, size))
    canvas = Image.new("RGB", (size, size), (0x0B, 0x0F, 0x1A))
    canvas.paste(img, ((size - img.width) // 2, (size - img.height) // 2))
    return canvas


def _decode_clip(blob: bytes, size: int) -> list:
    """Frames of a still image or a GIF, each padded to a square of `size`."""
    import io
    from PIL import Image
    im = Image.open(io.BytesIO(blob))
    try:
        count = min(int(getattr(im, "n_frames", 1) or 1), 24)
    except (OSError, ValueError, AttributeError):
        count = 1
    canvas = Image.new("RGBA", im.size, (0x0B, 0x0F, 0x1A, 255))
    frames = []
    for index in range(count):
        im.seek(index)
        frame = im.convert("RGBA")
        disposal = int(getattr(im, "disposal_method", None) or im.info.get("disposal_method") or 1)
        previous = canvas.copy()
        canvas.alpha_composite(frame)
        delay = max(int(im.info.get("duration") or 100), 40) / 1000
        frames.append((_fit_frame(canvas, size), delay if count > 1 else 1e9))
        if disposal in (2, 3):
            canvas = previous
    if not frames:
        raise ValueError("empty image")
    # Some GIFs end on a blank frame so the loop flashes black. Drop those.
    while len(frames) > 1 and _mostly_blank(frames[-1][0]):
        frames.pop()
    return frames


def _mostly_blank(img, bg: tuple[int, int, int] = (0x0B, 0x0F, 0x1A)) -> bool:
    px = img.get_flattened_data() if hasattr(img, "get_flattened_data") else img.getdata()
    blank = total = 0
    for pixel in px:
        r, g, b = pixel[:3]
        total += 1
        if (r < 16 and g < 16 and b < 16) or (
                abs(r - bg[0]) < 20 and abs(g - bg[1]) < 20 and abs(b - bg[2]) < 20):
            blank += 1
    return total > 0 and blank / total > 0.92


def _send_image(link: Link, screen: Screen, img, clear: bool) -> None:
    frame = sp.Frame()
    last = getattr(screen, "last_image", None)
    if clear or last is None or last.size != img.size:
        frame.begin(BG)
        screen.shown = {}
        previous = None
    else:
        previous = last
    frame.paint((sp.W - img.width) // 2, (sp.H - img.height) // 2, img, previous)
    if frame.cmds:
        link.send(frame.packets())
    screen.last_image = img
    screen.page = "image"


def run(link: Link, pages: list[str], seconds: float, stay: bool, notify: bool = True) -> None:
    import psutil
    psutil.cpu_percent(interval=None)
    signal.signal(signal.SIGINT, _request_stop)
    signal.signal(signal.SIGTERM, _request_stop)
    notes = Notifications() if notify else None
    control = Control(pages, seconds)
    threading.Thread(target=_agenda_loop, daemon=True).start()
    serve_panel(control)
    if "weather" in control.pages and "latitude" not in load_config():
        print("weather needs a location: screen/rt100screen.py location CITY", flush=True)
    screen, index, switched = Screen(link), 0, time.monotonic()
    ready = False
    # Plugging the cable back in makes the keyboard restart the old interface on
    # top of whatever we drew. Clear again once that restart has finished.
    reenter: list[float] = []
    try:
        while not _stop.is_set():
            if not link.alive and not link.reopen():
                control.mark("unplugged", "Keyboard unplugged")
                ready = False
                reenter = []
                time.sleep(1)
                continue
            mode, held, text, image, enter, quiet, rotate_pages, dwell = control.snapshot()
            blink = False
            note_showing = False
            if not ready:
                enter = mode != "stock"
                ready = True
                now = time.monotonic()
                reenter = [] if mode == "stock" else [now + 2.0, now + 5.0]
            elif reenter and mode != "stock" and time.monotonic() >= reenter[0]:
                enter = True
                reenter.pop(0)
            if control.claim_finished_timer():
                mode, held, image = "hold", "timer", None
            try:
                if mode == "stock":
                    if screen.page != "stock":
                        link.send(sp.Frame().end().packets())
                        screen.page, screen.shown = "stock", {}
                    control.mark("stock", "Stock clock")
                elif mode == "hold" and held == "stored":
                    if enter or screen.page != "stored":
                        link.send(sp.Frame().clip().packets())
                        screen.page, screen.shown = "stored", {}
                    control.mark("stored", "Four poses, from the screen")
                elif mode == "hold" and held == "fast":
                    if enter:
                        control.rewind_fast()
                    packets = control.next_fast_pose()
                    if packets:
                        link.send(packets)
                        screen.page, screen.shown = "fast", {}
                    control.mark("fast", "Playing on the screen")
                else:
                    if enter or screen.page in ("stock", "stored", "fast"):
                        link.send(sp.Frame().begin(BG).packets())
                        link.send([(sp.settime_packet(datetime.now()), 0)])
                        screen.page, screen.shown = None, {}
                    if image is not None:
                        try:
                            control.set_clip(_decode_clip(image[0], image[1]))
                        except (OSError, ValueError):
                            control.release("Could not show that image")
                    frame = control.next_clip_frame()
                    if frame is not None:
                        _send_image(link, screen, frame, screen.page != "image")
                        control.mark("image", control.clip_label())
                    elif text is not None:
                        frame = sp.Frame().begin(BG)
                        for i, line in enumerate(wrap(text, 15, 6)):
                            frame.text(0, 24 + i * 32, line, FG, BG, 2)
                        link.send(frame.packets())
                        screen.page, screen.shown = "text", {}
                        control.mark("text", caption("text", text=text))
                    elif mode == "hold" and held == "image":
                        control.mark("image", control.clip_label())
                    elif mode == "hold" and held == "timer":
                        ticking = control.timer_view() or {"left": 0, "done": True}
                        screen.show("timer", timer_page(datetime.now(), ticking))
                        control.mark("timer", caption("timer", ticking))
                    elif mode == "hold" and held:
                        render, source = PAGES[held]
                        data = source()
                        if data is None and held == "agenda":
                            screen.show("agenda", agenda_empty())
                            control.mark("agenda", "Nothing next")
                        elif data is None and held in ("media", "weather", "volume"):
                            control.mark(f"{held} unavailable")
                        else:
                            screen.show(held, render(datetime.now(), data))
                            control.mark(held, caption(held, data))
                    elif mode == "hold":
                        control.mark(screen.page or "paused")
                    else:
                        note = notes.current() if notes and not quiet else None
                        agent = agent_status()
                        if note:
                            note_showing = True
                            screen.show("notify", notify_page(datetime.now(), note))
                            control.mark("notify", caption("notify", note))
                        elif agent:
                            screen.show("agent", agent_page(datetime.now(), agent))
                            control.mark("agent", caption("agent", agent))
                            blink = agent.get("state") in ("waiting", "needs-you", "error")
                        else:
                            available = []
                            for name in rotate_pages:
                                render, source = PAGES[name]
                                data = source()
                                if name in ("media", "weather", "volume") and data is None:
                                    continue
                                if name == "agenda" and data is None:
                                    continue
                                available.append((name, render, data))
                            if available:
                                if time.monotonic() - switched >= dwell:
                                    index, switched = (index + 1) % len(available), time.monotonic()
                                name, render, data = available[index % len(available)]
                                widgets = render(datetime.now(), data)
                                widgets.update(dots(index % len(available), len(available)))
                                screen.show(name, widgets)
                                control.mark(name, caption(name, data))
            except LinkDown:
                ready = False
                reenter = []
                control.mark("unplugged", "Keyboard unplugged")
            pause = max(0.05, 1 - (time.time() % 1))
            if blink:
                pause = min(pause, 0.45)
            if note_showing:
                pause = min(pause, 0.25)
            wait = control.clip_wait()
            if wait is not None:
                pause = min(pause, max(0.05, wait))
            fast_wait = control.fast_wait()
            if fast_wait is not None:
                pause = min(pause, max(0.02, fast_wait))
            time.sleep(pause)
    finally:
        if link.alive and not stay and screen.page != "stock":
            try:
                link.send(sp.Frame().end().packets())
            except LinkDown:
                pass


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
    save_config(cfg)
    print(f"saved {cfg['name']} ({cfg['latitude']:.3f}, {cfg['longitude']:.3f})")


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("action", choices=["run", "settime", "stock", "stop", "text", "image", "location", "agent"])
    ap.add_argument("arg", nargs="?")
    ap.add_argument("--pages", default=",".join(DEFAULT_PAGES))
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
    link = Link(a.dry_run, a.dongle, a.us_per_pixel, require=a.action != "run")
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
        img.thumbnail((sp.W, sp.H) if a.full else (200, 200))
        packets = sp.Frame().begin(0).paint((sp.W - img.width) // 2, (sp.H - img.height) // 2, img).packets()
        print(f"{img.width}x{img.height}, {len(packets)} packets", flush=True)
        link.send(packets)
    del lock


if __name__ == "__main__":
    main()
