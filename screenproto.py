"""Packet encoder for the RT100 screen's custom display mode (re/custom/custom.c).

A Frame collects drawing commands and packs them into 64-byte packets:
p[0] = PKT_DRAW, then commands [op, len, body] until a zero op. Values are
little endian; x runs right and y down on the 240x240 panel. Pixel data is
streamed column by column (x outer, y inner), big-endian RGB565.
"""
from __future__ import annotations

import struct
from datetime import datetime

W = H = 240
PACKET = 64
PKT_DRAW, PKT_NOW = 0xC5, 0xC6
OP_BEGIN, OP_END, OP_FILL, OP_TEXT, OP_BLIT, OP_DATA, OP_SETTIME = 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x10
MAX_BODY = PACKET - 1 - 2
TEXT_CHARS = MAX_BODY - 9
CHAR_W, CHAR_H = 8, 16


def rgb(r: int, g: int, b: int) -> int:
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3)


def hexcolor(s: str) -> int:
    s = s.lstrip("#")
    return rgb(int(s[0:2], 16), int(s[2:4], 16), int(s[4:6], 16))


class Frame:
    def __init__(self) -> None:
        self.cmds: list[tuple[bytes, int]] = []  # (encoded command, pixels it draws)

    def _add(self, op: int, body: bytes, pixels: int = 0) -> None:
        assert len(body) <= MAX_BODY
        self.cmds.append((bytes([op, len(body)]) + body, pixels))

    def begin(self, bg: int = 0) -> Frame:
        self._add(OP_BEGIN, struct.pack("<H", bg), W * H)
        return self

    def end(self) -> Frame:
        self._add(OP_END, b"")
        return self

    def fill(self, x: int, y: int, w: int, h: int, color: int) -> Frame:
        if w > 0 and h > 0:
            self._add(OP_FILL, struct.pack("<5H", x, y, w, h, color), w * h)
        return self

    def text(self, x: int, y: int, s: str, fg: int, bg: int = 0, scale: int = 1) -> Frame:
        data = s.encode("ascii", "replace")
        step = CHAR_W * scale
        for i in range(0, len(data), TEXT_CHARS):
            part = data[i:i + TEXT_CHARS]
            self._add(OP_TEXT, struct.pack("<4HB", x + i * step, y, fg, bg, scale) + part,
                      len(part) * step * CHAR_H * scale)
        return self

    def image(self, x: int, y: int, img) -> Frame:
        """Draw a PIL image (converted to RGB) at (x, y); must fit on the panel."""
        img = img.convert("RGB")
        w, h = img.size
        assert 0 <= x and 0 <= y and x + w <= W and y + h <= H
        px = img.load()
        data = bytearray()
        for cx in range(w):
            for cy in range(h):
                data += struct.pack(">H", rgb(*px[cx, cy]))
        self._add(OP_BLIT, struct.pack("<4HB2H", x, y, w, h, 0, 0, 0))
        for i in range(0, len(data), 60):
            self._add(OP_DATA, bytes(data[i:i + 60]), 30)
        return self

    def mono(self, x: int, y: int, w: int, h: int, bits: bytes, fg: int, bg: int) -> Frame:
        """1-bit bitmap, column-major, MSB first; w*h bits."""
        assert 0 <= x and 0 <= y and x + w <= W and y + h <= H and len(bits) * 8 >= w * h
        self._add(OP_BLIT, struct.pack("<4HB2H", x, y, w, h, 1, fg, bg))
        for i in range(0, (w * h + 7) // 8, MAX_BODY):
            chunk = bits[i:i + MAX_BODY]
            self._add(OP_DATA, chunk, len(chunk) * 8)
        return self

    def packets(self) -> list[tuple[bytes, int]]:
        """Pack commands into packets; returns (packet, pixels drawn) pairs."""
        out: list[tuple[bytes, int]] = []
        cur, pixels = bytearray([PKT_DRAW]), 0
        for cmd, n in self.cmds:
            if len(cur) + len(cmd) > PACKET:
                out.append((bytes(cur.ljust(PACKET, b"\0")), pixels))
                cur, pixels = bytearray([PKT_DRAW]), 0
            cur += cmd
            pixels += n
        if len(cur) > 1:
            out.append((bytes(cur.ljust(PACKET, b"\0")), pixels))
        return out


def settime_packet(t: datetime) -> bytes:
    body = struct.pack("<H6B", t.year, t.month, t.day, t.hour, t.minute, t.second, t.isoweekday() % 7)
    return (bytes([PKT_NOW, OP_SETTIME, len(body)]) + body).ljust(PACKET, b"\0")
