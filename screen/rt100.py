"""Minimal RT100 vendor-interface client, matching the official Epomaker driver.

The official driver talks to the HID interface with usage page 0xFFFF / usage 2
(interface 2) using 64-byte feature reports with report ID 0, checksum at byte 7.
"""

import fcntl
import glob
import os
import time
from datetime import datetime

VENDOR_ID = 0x3151
PRODUCT_IDS = (0x4010, 0x4011)
REPORT_LEN = 64

CMD_SET_OLEDCLOCK = 0x28


def _hidiocsfeature(length: int) -> int:
    return (3 << 30) | (length << 16) | (ord("H") << 8) | 0x06


def _hidiocgfeature(length: int) -> int:
    return (3 << 30) | (length << 16) | (ord("H") << 8) | 0x07


def find_vendor_hidraw(product_ids: tuple[int, ...] = PRODUCT_IDS) -> str:
    for dev in sorted(glob.glob("/sys/class/hidraw/hidraw*")):
        uevent = open(os.path.join(dev, "device", "uevent")).read()
        hid_id = next(l for l in uevent.splitlines() if l.startswith("HID_ID="))
        _, vid, pid = hid_id.split("=")[1].split(":")
        if int(vid, 16) != VENDOR_ID or int(pid, 16) not in product_ids:
            continue
        descriptor = open(os.path.join(dev, "device", "report_descriptor"), "rb").read()
        if descriptor.startswith(b"\x06\xff\xff\x09\x02"):
            return "/dev/" + os.path.basename(dev)
    raise FileNotFoundError("RT100 vendor interface not found")


def build_packet(cmd: int, payload: bytes = b"") -> bytes:
    packet = bytearray(REPORT_LEN)
    packet[0] = cmd
    packet[7] = (0xFF - sum(packet[:7])) & 0xFF
    packet[8 : 8 + len(payload)] = payload
    return bytes(packet)


def send(path: str, packet: bytes) -> None:
    buf = bytearray(b"\x00" + packet)
    with open(path, "rb+", buffering=0) as f:
        fcntl.ioctl(f, _hidiocsfeature(len(buf)), buf)


def read(path: str) -> bytes:
    buf = bytearray(REPORT_LEN + 1)
    with open(path, "rb+", buffering=0) as f:
        fcntl.ioctl(f, _hidiocgfeature(len(buf)), buf)
    return bytes(buf[1:])


def query(path: str, packet: bytes, delay: float = 0.05) -> bytes:
    send(path, packet)
    time.sleep(delay)
    return read(path)


def upload_rect(path: str, x0: int, y0: int, x1: int, y1: int, pixels: bytes,
                chunk_delay: float = 0.002) -> None:
    """Upload big-endian RGB565 `pixels` into the screen rectangle (x0, y0)-(x1, y1).

    Same packets as the full-image upload: an 0xA5 init carrying the byte count
    and rectangle, then 0x25 data packets of up to 56 bytes each.
    """
    size = len(pixels)
    init = bytearray(build_packet(0xA5))
    init[1:7] = bytes([0x00, 0x01, 0x00, size & 0xFF, (size >> 8) & 0xFF, size >> 16])
    init[7] = (0xFF - sum(init[:7])) & 0xFF
    init[8:12] = bytes([x0, y0, x1, y1])
    send(path, bytes(init))
    time.sleep(0.25)
    for index, offset in enumerate(range(0, size, 56)):
        data = pixels[offset : offset + 56]
        packet = bytearray(REPORT_LEN)
        packet[0:7] = bytes([0x25, 0x00, 0x01, 0x00, index & 0xFF, index >> 8, len(data)])
        packet[7] = (0xFF - sum(packet[:7])) & 0xFF
        packet[8 : 8 + len(data)] = data
        send(path, bytes(packet))
        time.sleep(chunk_delay)


def rgb565(r: int, g: int, b: int) -> bytes:
    value = ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3)
    return value.to_bytes(2, "big")


def clock_packet(t: datetime) -> bytes:
    return build_packet(
        CMD_SET_OLEDCLOCK,
        bytes([t.year >> 8, t.year & 0xFF, t.month, t.day, t.hour, t.minute, t.second]),
    )


if __name__ == "__main__":
    path = find_vendor_hidraw((0x4010,))
    packet = clock_packet(datetime.now())
    print(path, packet[:16].hex(" "))
    send(path, packet)
