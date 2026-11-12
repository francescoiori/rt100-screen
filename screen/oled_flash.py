"""Flash the RT100 screen (OLED module) firmware, replicating the official driver.

Sequence (from EPOMAKER Driver 2.1.92, `oledUpgrade`):
  1. 0x30 55 AA 55 AA            enter the screen bootloader
  2. 0xB0 (poll, read back)      wait until the reply starts with 0xB0
  3. 0x31 <count u16 LE>         start, count = number of 64-byte chunks
  4. raw 64-byte chunks          no checksum byte, last chunk zero-padded
  5. 0xB1 <sum u32 LE>           byte sum of the image; reply[1] == 0x55 is success
The image is firmwareOledFile.bin with its first 64 KiB (the bootloader) skipped.
"""

import argparse
import sys
import time
import zipfile

import rt100

EXPECTED_DEV_ID = 946
BOOTLOADER_SIZE = 0x10000
CHUNK = 64

CMD_SET_OLEDBOOTLOADER = 0x30
CMD_SET_OLEDBOOTSTART = 0x31
CMD_GET_OLEDBOOTLOADER = 0xB0
CMD_GET_OLEDBOOTCHECKSUM = 0xB1
CMD_GET_REV = 0x80
CMD_GET_INFOR = 0x8F
CMD_GETOLED_VERSION = 0xAD


def command(cmd: int, *args: int) -> bytes:
    packet = bytearray(rt100.REPORT_LEN)
    packet[0] = cmd
    packet[1 : 1 + len(args)] = bytes(args)
    packet[7] = (0xFF - sum(packet[:7])) & 0xFF
    return bytes(packet)


def load_image(path: str) -> bytes:
    if zipfile.is_zipfile(path):
        with zipfile.ZipFile(path) as z:
            name = next(n for n in z.namelist() if "firmwareOledFile.bin" in n)
            data = z.read(name)
    else:
        data = open(path, "rb").read()
    if len(data) <= BOOTLOADER_SIZE:
        raise SystemExit(f"image too small ({len(data)} bytes)")
    app = data[BOOTLOADER_SIZE:]
    # The application starts with the same Thumb "ldr r0,[pc]; bx r0" jump table.
    if app[2:4] != b"\x00\x47":
        raise SystemExit("unexpected application header, refusing to flash")
    return app


def u16(r: bytes) -> int:
    return r[1] | (r[2] << 8)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("firmware", help="firmware zip or firmwareOledFile.bin")
    parser.add_argument("--dry-run", action="store_true")
    parser.add_argument("--chunk-delay", type=float, default=0.01)
    args = parser.parse_args()

    app = load_image(args.firmware)
    chunks = [app[i : i + CHUNK] for i in range(0, len(app), CHUNK)]
    total = sum(app)
    print(f"image: {len(app)} bytes, {len(chunks)} chunks, sum 0x{total:08x}")

    if args.dry_run:
        print("enter  ", command(CMD_SET_OLEDBOOTLOADER, 0x55, 0xAA, 0x55, 0xAA)[:8].hex(" "))
        print("poll   ", command(CMD_GET_OLEDBOOTLOADER)[:8].hex(" "))
        print("start  ", command(CMD_SET_OLEDBOOTSTART, len(chunks) & 0xFF, len(chunks) >> 8)[:8].hex(" "))
        print("chunk0 ", chunks[0][:16].hex(" "), "...")
        print("verify ", command(CMD_GET_OLEDBOOTCHECKSUM, *total.to_bytes(4, "little"))[:8].hex(" "))
        return

    path = rt100.find_vendor_hidraw((0x4010,))
    rev = u16(rt100.query(path, command(CMD_GET_REV), 0.1))
    dev_id = u16(rt100.query(path, command(CMD_GET_INFOR), 0.1))
    oled = u16(rt100.query(path, command(CMD_GETOLED_VERSION), 0.1))
    print(f"keyboard v{rev:x}, dev_id {dev_id}, screen v{oled:x}")
    if dev_id != EXPECTED_DEV_ID:
        raise SystemExit(f"dev_id {dev_id} != {EXPECTED_DEV_ID}, refusing to flash")

    rt100.send(path, command(CMD_SET_OLEDBOOTLOADER, 0x55, 0xAA, 0x55, 0xAA))
    for attempt in range(5):
        time.sleep(3)
        reply = rt100.query(path, command(CMD_GET_OLEDBOOTLOADER), 0.1)
        print(f"bootloader poll {attempt + 1}: {reply[:8].hex(' ')}")
        if reply[0] == CMD_GET_OLEDBOOTLOADER:
            break
    else:
        raise SystemExit("screen did not enter its bootloader; nothing was written")

    rt100.send(path, command(CMD_SET_OLEDBOOTSTART, len(chunks) & 0xFF, len(chunks) >> 8))
    for i, chunk in enumerate(chunks):
        rt100.send(path, chunk.ljust(CHUNK, b"\x00"))
        time.sleep(args.chunk_delay)
        if i % 25 == 0 or i == len(chunks) - 1:
            print(f"\r  {i + 1}/{len(chunks)}", end="", flush=True)
    print()

    rt100.send(path, command(CMD_GET_OLEDBOOTCHECKSUM, *total.to_bytes(4, "little")))
    time.sleep(1)
    reply = rt100.read(path)
    print("verify reply:", reply[:8].hex(" "))
    if reply[1] != 0x55:
        sys.exit("checksum NOT confirmed (reply[1] != 0x55)")
    print("screen firmware flashed and verified")


if __name__ == "__main__":
    main()
