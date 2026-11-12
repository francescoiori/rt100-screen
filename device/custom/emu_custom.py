"""Run the custom-mode firmware in Unicorn and render what the panel would show.

The patched image's real code runs: serial frames go through the stock frame
parser (0x010122FC) into the patched dispatcher and custom_frame_hook; the
main-loop hook draws through the stock LCD routines. The 1-byte SPI send at
0x01013DF4 feeds an ST7789 model (DC = GPIO9 config byte at 0xF8709), RTC
writes are recorded, and the stock UI functions are stubs that count calls.
Writes out/emu_<page>.png.
"""
import os, struct, sys
from datetime import datetime
from PIL import Image
from unicorn import Uc, UcError, UC_ARCH_ARM, UC_MODE_THUMB, UC_HOOK_CODE, UC_HOOK_MEM_WRITE
from unicorn.arm_const import UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_SP, UC_ARM_REG_LR, UC_ARM_REG_PC

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, "..", "..", "screen"))
import rt100screen as ui  # noqa: E402
import screenproto as sp  # noqa: E402

IMAGE = os.path.join(HERE, "out", "firmwareOledFile.bin")
FILE_BASE = 0x01000200
RAM, RAM_SIZE = 0x20000, 0x10000
RX, RX_LEN, PARSER = 0x0002A2E8, 0x00020034, 0x010122FC
FRAME_STATE, TX_FLAGS, REPLY, REPLY_SUM = 0x0002B3A0, 0x00020030, 0x0002B34C, 0x0002B39F
LOOP_HOOK, LOOP_NEXT, LOOP_RESUME = 0x01017EB8, 0x010104B4, 0x010104D4
STUBS = {0x0101195C: "stock_draw0", 0x01014314: "stock_idle", 0x01013EF2: "reset",
         0x01013DF4: "spi", 0x01014596: "rtc_write", 0x01013CC4: "wdt_feed"}
RET = 0x1000


class ST7789:
    def __init__(self):
        self.fb = [[0] * 240 for _ in range(240)]
        self.dc, self.cmd, self.args = 0, None, []
        self.x0 = self.x1 = self.y0 = self.y1 = 0
        self.cx = self.cy = 0
        self.half = None
        self.pixels = 0

    def byte(self, b):
        if self.dc == 0:
            self.cmd, self.args, self.half = b, [], None
            if b == 0x2C:
                self.cx, self.cy = self.x0, self.y0
            return
        if self.cmd in (0x2A, 0x2B):
            self.args.append(b)
            if len(self.args) == 4:
                lo, hi = self.args[0] << 8 | self.args[1], self.args[2] << 8 | self.args[3]
                if self.cmd == 0x2B:      # set_window sends x as RASET
                    self.x0, self.x1 = lo, hi
                else:
                    self.y0, self.y1 = lo, hi
        elif self.cmd == 0x2C:
            if self.half is None:
                self.half = b
                return
            c, self.half = self.half << 8 | b, None
            if self.cx <= self.x1 and self.cx < 240 and self.cy < 240:
                self.fb[self.cy][self.cx] = c
            self.pixels += 1
            self.cy += 1                  # stream runs down each column
            if self.cy > self.y1:
                self.cy, self.cx = self.y0, self.cx + 1

    def png(self, path, scale=2):
        img = Image.new("RGB", (240, 240))
        img.putdata([((c >> 11) * 255 // 31, (c >> 5 & 63) * 255 // 63, (c & 31) * 255 // 31)
                     for row in self.fb for c in row])
        img.resize((240 * scale, 240 * scale), Image.NEAREST).save(path)


class Emu:
    def __init__(self):
        fw = open(IMAGE, "rb").read()
        self.uc = uc = Uc(UC_ARCH_ARM, UC_MODE_THUMB)
        uc.mem_map(0, 0x10000)
        uc.mem_map(0x01000000, 0x20000)
        uc.mem_map(RAM, RAM_SIZE)
        uc.mem_map(0xF0000, 0x10000)
        uc.mem_write(FILE_BASE, fw)
        uc.mem_write(RET, b"\x70\x47")
        self.lcd, self.calls, self.rtc = ST7789(), {}, []
        for addr in STUBS:
            uc.mem_write(addr, b"\x70\x47")               # bx lr
            uc.hook_add(UC_HOOK_CODE, self._stub, begin=addr, end=addr)
        uc.hook_add(UC_HOOK_CODE, self._loop_exit, begin=LOOP_RESUME, end=LOOP_RESUME)
        uc.hook_add(UC_HOOK_MEM_WRITE, self._gpio, begin=0xF8709, end=0xF8709)
        self.exit_pc = None

    def _stub(self, uc, addr, size, _):
        name = STUBS[addr]
        self.calls[name] = self.calls.get(name, 0) + 1
        if name == "spi":
            assert uc.reg_read(UC_ARM_REG_R0) == 1, "LCD is on SPI port 1"
            self.lcd.byte(uc.reg_read(UC_ARM_REG_R1) & 0xFF)
        elif name == "rtc_write":
            self.rtc.append((uc.reg_read(UC_ARM_REG_R0), uc.reg_read(UC_ARM_REG_R1) & 0xFF))
        elif name == "reset":
            uc.emu_stop()

    def _gpio(self, uc, access, addr, size, value, _):
        self.lcd.dc = 1 if value == 0x3F else 0 if value == 0x3E else self.lcd.dc

    def _loop_exit(self, uc, addr, size, _):
        self.exit_pc = addr
        uc.emu_stop()

    def call(self, func, lr=RET | 1, until=RET):
        self.uc.reg_write(UC_ARM_REG_SP, 0x2F000)
        self.uc.reg_write(UC_ARM_REG_LR, lr)
        self.exit_pc = None
        self.uc.emu_start(func | 1, until, count=50_000_000)
        return self.exit_pc if self.exit_pc is not None else self.uc.reg_read(UC_ARM_REG_PC)

    def rd(self, addr, n=1):
        return bytes(self.uc.mem_read(addr, n))

    def frame(self, cmd, payload=b""):
        body = bytes([cmd]) + payload
        f = bytearray([0x55]) + struct.pack("<H", len(body) + 1) + body
        f.append(sum(f[1:]) & 0xFF)
        self.uc.mem_write(RX, bytes(f))
        self.uc.mem_write(RX_LEN, struct.pack("<I", len(f)))
        self.uc.mem_write(FRAME_STATE, bytes([1, 3]))     # data received, 3 idle ticks so far
        self.uc.mem_write(TX_FLAGS, b"\0")
        self.uc.mem_write(REPLY, bytes(4))
        self.call(PARSER)
        return self.rd(REPLY, 4), self.rd(REPLY_SUM)[0], self.rd(TX_FLAGS)[0], self.rd(FRAME_STATE + 6)[0]

    def loop(self):
        """One main-loop pass from the patched call site; returns where it continues."""
        return self.call(LOOP_HOOK, lr=LOOP_NEXT | 1, until=LOOP_NEXT)

    def send(self, packets, check):
        for i, (p, _) in enumerate(packets):
            check(self.frame(0x3C, p) == (bytes([0x44, 3, 0xBC, 0]), 0xBF, 1, 0), f"0x3C reply, packet {i}")
            if i % 4 == 3:
                self.loop()
        for _ in range(len(packets) // 4 + 2):
            self.loop()


def main():
    failures = []

    def check(ok, what):
        if not ok:
            failures.append(what)
            print("FAIL", what)

    emu = Emu()
    check(emu.loop() == LOOP_NEXT and emu.calls.get("stock_draw0") == 1, "stock mode at boot")
    check(emu.frame(0x3D, struct.pack("<H", 5)) == (bytes([0x44, 3, 0xBD, 0]), 0xC0, 1, 0), "0x3D reply")
    emu.frame(0x77)
    check(emu.rd(FRAME_STATE + 6)[0] == 1, "unknown command still flagged like stock")
    emu.uc.mem_write(FRAME_STATE + 6, b"\0")

    emu.send(sp.Frame().begin(ui.BG).packets(), check)
    check(emu.loop() == LOOP_RESUME, "custom mode skips stock drawing")
    check(emu.calls.get("stock_idle", 0) >= 1, "stock non-draw work still runs")
    check(emu.calls.get("wdt_feed", 0) >= 240, "watchdog fed while drawing")
    check(emu.lcd.pixels == 240 * 240, f"BEGIN cleared the panel ({emu.lcd.pixels} px)")

    now = datetime(2026, 11, 12, 21, 47, 30)
    emu.rtc.clear()
    emu.frame(0x3C, sp.settime_packet(now))
    want = [(0, 0), (1, 0x11), (2, 0x30), (3, 0x47), (4, 0x21), (5, 0x12), (7, 0x11), (8, 0x26), (6, 4)]
    check(emu.rtc == want, f"SETTIME RTC writes {emu.rtc}")

    stats = {"cpu": 23.0, "ram": 61.0, "temp": 54.0}
    media = {"status": "Playing", "title": "Everything In Its Right Place",
             "artist": "Radiohead", "length": 251_000_000, "position": 96_000_000}
    weather = {"temp": 11, "hi": 14, "lo": 7, "kind": "rain", "label": "RAIN", "place": "TEST"}
    notice = {"app": "Mail", "summary": "Build finished OK"}
    pages = [("clock", ui.clock_page(now)), ("system", ui.system_page(now, stats)),
             ("media", ui.media_page(now, media)), ("weather", ui.weather_page(now, weather)),
             ("notify", ui.notify_page(now, notice))]
    screen = ui.Screen(None)
    for i, (name, widgets) in enumerate(pages):
        widgets.update(ui.dots(i, len(pages)))
        sent = []
        screen.link = type("L", (), {"send": lambda self, p: sent.extend(p)})()
        screen.show(name, widgets)
        before = emu.lcd.pixels
        emu.send(sent, check)
        drawn = emu.lcd.pixels - before
        check(drawn == sum(px for _, px in sent), f"{name}: drawn pixels match encoder")
        path = os.path.join(HERE, "out", f"emu_{name}.png")
        emu.lcd.png(path)
        print(f"{name}: {len(sent)} packets, {drawn} px -> {path}")

    later = ui.clock_page(datetime(2026, 11, 12, 21, 47, 31))
    later.update(ui.dots(0, 3))
    sent = []
    screen.link = type("L", (), {"send": lambda self, p: sent.extend(p)})()
    screen.show("clock", ui.clock_page(now) | ui.dots(0, 3))
    sent.clear()
    screen.show("clock", later)
    print(f"clock, one second later: {len(sent)} packet(s)")

    emu.send(sp.Frame().end().packets(), check)
    check(emu.calls.get("reset", 0) >= 1, "END reboots to the stock UI")
    print("ALL CHECKS PASSED" if not failures else f"{len(failures)} FAILURES")
    sys.exit(1 if failures else 0)


if __name__ == "__main__":
    try:
        main()
    except UcError as e:
        sys.exit(f"emulation fault: {e}")
