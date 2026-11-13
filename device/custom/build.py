"""Build the custom-display screen firmware on top of the RTC I2C fix.

Steps: compile custom.c + hooks.S at 0x01017EB8 (after the stock app), append
the code, redirect two stock calls to it, and extend the stock zero-init
region over the new .bss so every boot starts in stock mode.
Writes out/firmwareOledFile.bin and out/patch.txt.
"""
import glob, hashlib, os, struct, subprocess, sys

HERE = os.path.dirname(os.path.abspath(__file__))
OUT = os.path.join(HERE, "out")
BASE_IMAGE = os.path.join(HERE, "..", "patch", "out", "firmwareOledFile.bin")  # device/patch
BASE_SHA256 = "6f3c923946f4f4ff1065faa004c8fe2fcdbfb9b6ff537f07b022e4e553e57c1b"
APP_FILE_OFS, APP_BASE = 0x10000, 0x01010200
APP_END = 0x01017EB8
APP_LIMIT = 0x01020000

FRAME_SITE = 0x01011FEE       # ldr r0,[pc,#0x390]; strb r6,[r0,#6]; b 0x01011e48
FRAME_SITE_ORIG = bytes.fromhex("e448" "8671" "29e7")
DISPATCH_EXIT = 0x01011E48
LOOP_SITE = 0x010104B0        # bl 0x0101195c
ZI_SIZE_LITERAL = 0x01017E64  # stock zero-init length for RAM 0x2004C
ZI_BASE, ZI_SIZE_ORIG = 0x0002004C, 0x0000BB60

CFLAGS = ["-mcpu=cortex-m0", "-mthumb", "-Os", "-ffreestanding", "-fno-builtin", "-nostdlib",
          "-fno-common", "-fno-tree-loop-distribute-patterns", "-ffunction-sections",
          "-Wall", "-Wextra", "-Werror"]


def tool(name):
    hits = glob.glob(os.path.expanduser(f"~/tools/xpack-arm-none-eabi-gcc-*/bin/arm-none-eabi-{name}"))
    if not hits:
        sys.exit("arm-none-eabi toolchain not found in ~/tools")
    return hits[0]


def bl(pc, target):
    off = target - (pc + 4)
    assert off % 2 == 0 and -(1 << 24) <= off < (1 << 24)
    off &= (1 << 25) - 1
    s, i1, i2 = off >> 24 & 1, off >> 23 & 1, off >> 22 & 1
    j1, j2 = (~(i1 ^ s)) & 1, (~(i2 ^ s)) & 1
    return struct.pack("<HH", 0xF000 | s << 10 | (off >> 12 & 0x3FF),
                       0xD000 | j1 << 13 | j2 << 11 | (off >> 1 & 0x7FF))


def b(pc, target):
    off = target - (pc + 4)
    assert off % 2 == 0 and -2048 <= off < 2048
    return struct.pack("<H", 0xE000 | (off >> 1 & 0x7FF))


def build_code():
    os.makedirs(OUT, exist_ok=True)
    subprocess.check_call([sys.executable, os.path.join(HERE, "gen_font.py")])
    subprocess.check_call([sys.executable, os.path.join(HERE, "gen_clip.py")])
    elf = os.path.join(OUT, "custom.elf")
    subprocess.check_call([tool("gcc"), *CFLAGS, "-T", os.path.join(HERE, "link.ld"),
                           "-Wl,--gc-sections", "-Wl,-Map=" + os.path.join(OUT, "custom.map"),
                           "-Wl,--no-warn-rwx-segments",
                           os.path.join(HERE, "hooks.S"), os.path.join(HERE, "custom.c"), "-lgcc", "-o", elf])
    code_bin = os.path.join(OUT, "custom.bin")
    subprocess.check_call([tool("objcopy"), "-O", "binary", "-j", ".text", elf, code_bin])
    syms = {}
    for line in subprocess.check_output([tool("nm"), elf], text=True).splitlines():
        parts = line.split()
        if len(parts) == 3:
            syms[parts[2]] = int(parts[0], 16)
    return open(code_bin, "rb").read(), syms


def main():
    fw = bytearray(open(BASE_IMAGE, "rb").read())
    assert hashlib.sha256(fw).hexdigest() == BASE_SHA256, "base image is not the flashed I2C-fix build"
    assert len(fw) == APP_FILE_OFS + APP_END - APP_BASE
    code, syms = build_code()
    assert syms["loop_hook"] == APP_END, "loop_hook must be first in .text"
    end = APP_END + len(code)
    assert end <= APP_LIMIT, f"code too big, ends at 0x{end:08x}"
    bss_end = syms["__bss_end"]
    zi_size = (bss_end - ZI_BASE + 3) & ~3
    assert zi_size % 4 == 0 and zi_size >= ZI_SIZE_ORIG and bss_end <= 0x0002D000

    def at(addr, n):
        o = APP_FILE_OFS + addr - APP_BASE
        return slice(o, o + n)

    assert fw[at(FRAME_SITE, 6)] == FRAME_SITE_ORIG
    assert fw[at(LOOP_SITE, 4)] == bl(LOOP_SITE, 0x0101195C)
    assert struct.unpack("<I", fw[at(ZI_SIZE_LITERAL, 4)])[0] == ZI_SIZE_ORIG

    patches = [
        (FRAME_SITE, bl(FRAME_SITE, syms["custom_frame_hook"]) + b(FRAME_SITE + 4, DISPATCH_EXIT),
         "unknown-command path -> custom_frame_hook"),
        (LOOP_SITE, bl(LOOP_SITE, syms["loop_hook"]), "main loop first UI call -> loop_hook"),
        (ZI_SIZE_LITERAL, struct.pack("<I", zi_size), f"zero-init 0x{ZI_BASE:05x}+0x{zi_size:x} (was 0x{ZI_SIZE_ORIG:x})"),
    ]
    with open(os.path.join(OUT, "patch.txt"), "w") as log:
        for addr, data, what in patches:
            old = bytes(fw[at(addr, len(data))])
            fw[at(addr, len(data))] = data
            log.write(f"0x{addr:08x}: {old.hex(' ')} -> {data.hex(' ')}   {what}\n")
        fw += code
        log.write(f"0x{APP_END:08x}..0x{end:08x}: appended {len(code)} bytes of code\n")
        log.write(f".bss 0x{syms['__bss_start']:05x}..0x{bss_end:05x}\n")
        for k in ("loop_hook", "custom_frame_hook", "custom_tick"):
            log.write(f"{k} = 0x{syms[k]:08x}\n")
    out = os.path.join(OUT, "firmwareOledFile.bin")
    open(out, "wb").write(fw)
    app = fw[APP_FILE_OFS:]
    print(open(os.path.join(OUT, "patch.txt")).read(), end="")
    print(f"wrote {out}: app {len(app)} bytes, sum 0x{sum(app):08x}")


if __name__ == "__main__":
    main()
