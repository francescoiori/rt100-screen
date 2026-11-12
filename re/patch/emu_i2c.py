"""Run the screen firmware's RTC I2C code in Unicorn against a simulated PCF8563.

usage: emu_i2c.py [firmwareOledFile.bin ...]   (default: stock and patched)

The real Thumb code of rtc_read(reg) at 0x010145C4 and rtc_write(reg, val) at
0x01014596 is executed. GPIO38/39 writes drive a bit-level PCF8563 model; the
ROM delay_us at 0x4238 advances virtual time. Two analog effects are modelled:
  t_vd   - slave data valid time after SCL falls (PCF8563: tVD;DAT)
  t_rise - time for a released SDA line to read high through the pull-up
Each grid cell reads 6 registers 4 times and counts correct bytes.
"""
import os, sys
from unicorn import Uc, UC_ARCH_ARM, UC_MODE_THUMB, UC_HOOK_CODE, UC_HOOK_MEM_WRITE, UC_HOOK_MEM_READ
from unicorn.arm_const import UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_SP, UC_ARM_REG_LR, UC_ARM_REG_PC

HERE = os.path.dirname(os.path.abspath(__file__))
STOCK = os.path.join(HERE, "..", "fw", "v507", "firmwareOledFile.bin")
PATCHED = os.path.join(HERE, "out", "firmwareOledFile.bin")
FLASH_BASE, FILE_BASE = 0x01000000, 0x01000200
RTC_READ, RTC_WRITE = 0x010145C4, 0x01014596
DELAY_US, DELAY_MS = 0x4238, 0x425C
GPIO = 0xF8000
SCL_CFG, SDA_CFG, GPIO_IN = 0xF8726, 0xF8727, 0xF8740
RET = 0x1000
CPU_MHZ = 48.0
MAX_INSNS = 2_000_000


class PCF8563:
    ADDR = 0x51

    def __init__(self, t_vd, t_rise):
        self.t_vd, self.t_rise = t_vd, t_rise
        self.regs = bytearray(16)
        self.regs[2:9] = bytes([0x56, 0x34, 0x12, 0x12, 0x04, 0x11, 0x26])
        self.t = 0.0
        self.scl, self.m_sda = 1, None          # master SDA: 0, 1 or None (released)
        self.s_low, self.s_low_next, self.s_change_t = False, False, 0.0
        self.released_t = 0.0
        self.phase, self.bits, self.cur, self.first, self.rw, self.ptr = "idle", 0, 0, False, 0, 0
        self.contention = 0.0

    def advance(self, dt):
        """Advance time, accumulating µs where the master drives SDA high against the slave."""
        end = self.t + dt
        while self.t < end:
            step = end - self.t
            if self.s_change_t > self.t and self.s_low != self.s_low_next:
                step = min(step, self.s_change_t - self.t)
            if self.m_sda == 1 and self._slave_low():
                self.contention += step
            self.t += step
            self._slave_low()

    def _slave_low(self):
        if self.t >= self.s_change_t:
            self.s_low = self.s_low_next
        return self.s_low

    def _drive(self, low, delay):
        self._slave_low()
        if self.s_low and not low:
            self.released_t = max(self.released_t, self.t + delay)
        self.s_low_next, self.s_change_t = low, self.t + delay

    def sda(self):
        if self.m_sda == 0 or self._slave_low():
            return 0
        if self.m_sda == 1:
            return 1
        return 1 if self.t - self.released_t >= self.t_rise else 0

    def set_sda(self, cfg):
        new = {0x3E: 0, 0x3F: 1}.get(cfg)
        before = self.sda()
        if self.m_sda == 0 and new is None:
            self.released_t = self.t
        self.m_sda = new
        after = self.sda() if new is not None else (0 if self._slave_low() else 1)
        if self.scl and before == 1 and after == 0:
            self.phase, self.bits, self.cur, self.first = "rx", 0, 0, True
        elif self.scl and before == 0 and after == 1:
            self.phase = "idle"

    def set_scl(self, cfg):
        level = 1 if cfg == 0x3F else 0
        if level == self.scl:
            return
        self.scl = level
        (self._rise if level else self._fall)()

    def _rise(self):
        if self.phase == "rx":
            self.cur = (self.cur << 1) | self.sda()
            self.bits += 1
        elif self.phase == "tx_ack":
            self.master_ack = self.sda() == 0

    def _fall(self):
        if self.phase == "rx" and self.bits == 8:
            ack = True
            if self.first:
                ack = self.cur >> 1 == self.ADDR
                self.rw = self.cur & 1
            elif self.ptr_set:
                self.regs[self.ptr & 15] = self.cur
                self.ptr += 1
            else:
                self.ptr, self.ptr_set = self.cur, True
            if self.first:
                self.ptr_set = self.ptr_set if self.rw else False
            self.phase = "rx_ack" if ack else "idle"
            self._drive(ack, self.t_vd)
        elif self.phase == "rx_ack":
            self._drive(False, self.t_vd)
            if self.first and self.rw:
                self.phase, self.bits, self.byte = "tx", 0, self.regs[self.ptr & 15]
                self._drive(not (self.byte & 0x80), self.t_vd)
            else:
                self.phase, self.bits, self.cur, self.first = "rx", 0, 0, False
        elif self.phase == "tx":
            self.bits += 1
            if self.bits < 8:
                self._drive(not (self.byte << self.bits & 0x80), self.t_vd)
            else:
                self._drive(False, self.t_vd)
                self.phase = "tx_ack"
        elif self.phase == "tx_ack":
            if getattr(self, "master_ack", False):
                self.ptr += 1
                self.phase, self.bits, self.byte = "tx", 0, self.regs[self.ptr & 15]
                self._drive(not (self.byte & 0x80), self.t_vd)
            else:
                self.phase = "done"


class Emu:
    def __init__(self, fw_path, t_vd, t_rise):
        fw = open(fw_path, "rb").read()
        self.rtc = PCF8563(t_vd, t_rise)
        self.rtc.ptr_set = False
        uc = self.uc = Uc(UC_ARCH_ARM, UC_MODE_THUMB)
        uc.mem_map(0, 0x10000)
        uc.mem_map(FLASH_BASE, 0x40000)
        uc.mem_map(0x20000, 0x20000)
        uc.mem_map(GPIO, 0x1000)
        uc.mem_write(FILE_BASE, fw)
        for a in (DELAY_US, DELAY_MS, RET):
            uc.mem_write(a, b"\x70\x47")       # bx lr
        self.insns = 0
        uc.hook_add(UC_HOOK_CODE, self._code)
        uc.hook_add(UC_HOOK_MEM_WRITE, self._mmio_w, begin=GPIO, end=GPIO + 0xFFF)
        uc.hook_add(UC_HOOK_MEM_READ, self._mmio_r, begin=GPIO, end=GPIO + 0xFFF)

    def _code(self, uc, addr, size, _):
        self.insns += 1
        self.rtc.advance(1.0 / CPU_MHZ)
        if addr == DELAY_US:
            self.rtc.advance(uc.reg_read(UC_ARM_REG_R0))
        elif addr == DELAY_MS:
            self.rtc.advance(1000.0 * uc.reg_read(UC_ARM_REG_R0))
        if self.insns > MAX_INSNS:
            raise RuntimeError(f"no return after {MAX_INSNS} instructions (pc=0x{addr:08x})")

    def _mmio_w(self, uc, access, addr, size, value, _):
        if addr == SCL_CFG:
            self.rtc.set_scl(value & 0xFF)
        elif addr == SDA_CFG:
            self.rtc.set_sda(value & 0xFF)
        elif not (0xF8700 <= addr < 0xF8740):
            raise RuntimeError(f"unexpected MMIO write 0x{addr:05x}=0x{value:x}")

    def _mmio_r(self, uc, access, addr, size, value, _):
        if addr == GPIO_IN:
            uc.mem_write(GPIO_IN, (self.rtc.sda() << 7).to_bytes(2, "little"))

    def call(self, fn, *args):
        uc = self.uc
        for r, v in zip((UC_ARM_REG_R0, UC_ARM_REG_R1), args):
            uc.reg_write(r, v)
        uc.reg_write(UC_ARM_REG_SP, 0x3FF00)
        uc.reg_write(UC_ARM_REG_LR, RET | 1)
        t0 = self.rtc.t
        uc.emu_start(fn | 1, RET)
        return uc.reg_read(UC_ARM_REG_R0) & 0xFF, self.rtc.t - t0


def run_cell(path, t_vd, t_rise, rounds=4):
    e = Emu(path, t_vd, t_rise)
    ok = total = 0
    dur = 0.0
    for _ in range(rounds):
        for reg in (2, 3, 4, 5, 7, 8):
            got, dt = e.call(RTC_READ, reg)
            ok += got == e.rtc.regs[reg]
            total += 1
            dur = max(dur, dt)
    return ok, total, dur, e.rtc.contention / total


def main():
    paths = sys.argv[1:] or [STOCK, PATCHED]
    t_vds = (0.0, 0.3, 0.6, 0.9, 1.2)
    t_rises = (0.0, 0.5, 1.0, 1.5, 2.0, 3.0)
    for p in paths:
        e = Emu(p, 0.0, 0.0)
        e.call(RTC_WRITE, 9, 0x42)
        wr_ok = e.rtc.regs[9] == 0x42 and e.call(RTC_READ, 9)[0] == 0x42
        print(f"\n{os.path.relpath(p)}  (ideal bus: write+readback {'OK' if wr_ok else 'FAIL'})")
        print("correct reads out of 24; rows t_vd (µs), columns t_rise (µs)")
        print("t_vd\\t_rise " + "".join(f"{r:>7}" for r in t_rises))
        worst_dur, cont = 0.0, 0
        for vd in t_vds:
            cells = []
            for tr in t_rises:
                ok, total, dur, c = run_cell(p, vd, tr)
                worst_dur, cont = max(worst_dur, dur), max(cont, c)
                cells.append(f"{ok:>4}/{total}")
            print(f"{vd:>11} " + "".join(f"{c:>7}" for c in cells))
        print(f"one rtc_read takes {worst_dur:.0f} µs; worst SDA contention {cont:.2f} µs per rtc_read")


if __name__ == "__main__":
    main()
