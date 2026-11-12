"""Build a screen firmware image with the RTC I2C driver fix.

Reads the stock firmwareOledFile.bin (v506), assembles i2c_fix.S at the stock
addresses, patches only the I2C driver (0x01014488..0x01014596) and writes
out/firmwareOledFile.bin plus a byte-level diff listing.
"""
import glob, os, subprocess, sys

HERE = os.path.dirname(os.path.abspath(__file__))
STOCK = os.path.join(HERE, "..", "..", "research", "fw", "v507", "firmwareOledFile.bin")
OUT = os.path.join(HERE, "out")
APP_FILE_OFS = 0x10000
APP_BASE = 0x01010200
DELAY_US = 0x01012F20

SLOTS = {".ack": (0x010144CE, 0x01014506), ".rdb": (0x01014540, 0x01014596)}
DELAY_IMMEDIATES = [
    0x01014492, 0x0101449C, 0x010144A4,   # i2c_start
    0x010144B4, 0x010144BE, 0x010144C6,   # i2c_stop
    0x01014522, 0x0101452A,               # i2c_write_byte data/clock-high phases
]
# 0x01014538 (write_byte's delay after the 8th SCL fall) stays at 1 µs: SDA is
# still driven high there while the RTC starts pulling it low for ACK.
I2C_DRIVER = (0x01014488, 0x01014596)
STOCK_APP_SIZE = 31928
STOCK_APP_SUM = 0x00265EDA


def gcc_bin(tool):
    hits = glob.glob(os.path.expanduser(f"~/tools/xpack-arm-none-eabi-gcc-*/bin/arm-none-eabi-{tool}"))
    if not hits:
        sys.exit("arm-none-eabi toolchain not found in ~/tools")
    return hits[0]


def build_sections():
    os.makedirs(OUT, exist_ok=True)
    obj, elf, ld = (os.path.join(OUT, n) for n in ("i2c_fix.o", "i2c_fix.elf", "i2c_fix.ld"))
    with open(ld, "w") as f:
        f.write("SECTIONS {\n" + "".join(
            f"  {s} 0x{lo:08x} : {{ *({s}) }}\n" for s, (lo, _) in SLOTS.items()) + "}\n")
    subprocess.check_call([gcc_bin("gcc"), "-c", "-mcpu=cortex-m0", "-mthumb",
                           os.path.join(HERE, "i2c_fix.S"), "-o", obj])
    subprocess.check_call([gcc_bin("ld"), "--no-warnings", "-T", ld,
                           f"--defsym=delay_us=0x{DELAY_US:08x}", obj, "-o", elf])
    syms = dict(l.split()[::2][::-1] for l in subprocess.check_output([gcc_bin("nm"), elf], text=True).splitlines())
    for name, s in (("i2c_wait_ack", ".ack"), ("i2c_read_byte", ".rdb")):
        assert int(syms[name], 16) == SLOTS[s][0], f"{name} linked at {syms[name]}, expected 0x{SLOTS[s][0]:08x}"
    code = {}
    for s in SLOTS:
        b = os.path.join(OUT, s.strip(".") + ".bin")
        subprocess.check_call([gcc_bin("objcopy"), "-O", "binary", "-j", s, elf, b])
        code[s] = open(b, "rb").read()
    return code


def main():
    fw = bytearray(open(STOCK, "rb").read())
    app = fw[APP_FILE_OFS:]
    assert len(app) == STOCK_APP_SIZE and sum(app) == STOCK_APP_SUM, "unexpected stock image"
    orig = bytes(fw)

    def put(addr, data):
        o = APP_FILE_OFS + addr - APP_BASE
        fw[o:o + len(data)] = data

    for s, data in build_sections().items():
        lo, hi = SLOTS[s]
        assert len(data) <= hi - lo, f"{s} is {len(data)} bytes, slot is {hi - lo}"
        pad = hi - lo - len(data)
        assert pad % 2 == 0
        put(lo, data + b"\x00\xbf" * (pad // 2))
        print(f"{s}: {len(data)}/{hi - lo} bytes at 0x{lo:08x}")

    for a in DELAY_IMMEDIATES:
        o = APP_FILE_OFS + a - APP_BASE
        assert orig[o:o + 2] == b"\x01\x20", f"0x{a:08x} is not 'movs r0, #1'"
        put(a, b"\x05\x20")

    changed = [i for i in range(len(fw)) if fw[i] != orig[i]]
    lo = APP_FILE_OFS + I2C_DRIVER[0] - APP_BASE
    hi = APP_FILE_OFS + I2C_DRIVER[1] - APP_BASE
    assert all(lo <= i < hi for i in changed), "patch escaped the I2C driver"
    assert len(fw) == len(orig)

    out = os.path.join(OUT, "firmwareOledFile.bin")
    open(out, "wb").write(fw)
    with open(os.path.join(OUT, "diff.txt"), "w") as f:
        for i in changed:
            f.write(f"0x{APP_BASE + i - APP_FILE_OFS:08x}: {orig[i]:02x} -> {fw[i]:02x}\n")
    app = fw[APP_FILE_OFS:]
    print(f"{len(changed)} bytes changed, all inside 0x{I2C_DRIVER[0]:08x}..0x{I2C_DRIVER[1]:08x}")
    print(f"wrote {out}: app {len(app)} bytes, sum 0x{sum(app):08x}")


if __name__ == "__main__":
    main()
