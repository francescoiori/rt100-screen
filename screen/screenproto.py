"""Packet encoder for the RT100 screen's custom display mode (device/custom/custom.c).

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
OP_CLIP = 0x11
OP_UHEAD, OP_UKEY, OP_URUN = 0x12, 0x13, 0x14
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

    def clip(self) -> Frame:
        """Play the picture stored in the screen firmware."""
        self._add(OP_CLIP, b"")
        return self

    def uhead(self, w: int, h: int, x: int, y: int, pal: list[int], clear: bool) -> Frame:
        body = bytes([w & 255, h & 255, x & 255, y & 255, 1 if clear else 0])
        body += struct.pack("<16H", *pal)
        self._add(OP_UHEAD, body, W * H if clear else 0)
        return self

    def ukey(self, blob: bytes) -> Frame:
        for i in range(0, len(blob), MAX_BODY):
            chunk = blob[i:i + MAX_BODY]
            # A compressed byte becomes several pixels. Pace for that.
            self._add(OP_UKEY, chunk, len(chunk) * 6)
        return self

    def urun(self, blob: bytes) -> Frame:
        for i in range(0, len(blob), MAX_BODY):
            chunk = blob[i:i + MAX_BODY]
            self._add(OP_URUN, chunk, max(1, len(chunk) // 2))
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

    def paint(self, x: int, y: int, img, previous=None, bg: tuple[int, int, int] = (0x0B, 0x0F, 0x1A)) -> Frame:
        """Draw an image, skipping pixels that match `previous` or the background.

        Flat runs go out as rectangle fills. Photos go out as one blit of the
        changed area. A GIF frame then sends only what moved.
        """
        from PIL import Image
        img = img.convert("RGB")
        w, h = img.size
        if previous is not None:
            previous = previous.convert("RGB")
            if previous.size != (w, h):
                previous = None
        if previous is None:
            previous = Image.new("RGB", (w, h), bg)
        px, old = img.load(), previous.load()
        row = 0
        while row < h:
            span = _dirty_span(px, old, row, w)
            if span is None:
                row += 1
                continue
            x0, x1 = span
            end = row + 1
            while end < h:
                nxt = _dirty_span(px, old, end, w)
                if nxt is None:
                    break
                union = max(x1, nxt[1]) - min(x0, nxt[0])
                if union > (x1 - x0) + 12:
                    break
                x0, x1 = min(x0, nxt[0]), max(x1, nxt[1])
                end += 1
            self._encode_band(x, y, px, old, x0, row, x1, end)
            row = end
        return self

    def _encode_band(self, ox, oy, px, old, x0, y0, x1, y1) -> None:
        color = px[x0, y0]
        solid = True
        changed = 0
        runs = 0
        for row in range(y0, y1):
            col = x0
            while col < x1:
                if px[col, row] != color:
                    solid = False
                if px[col, row] == old[col, row]:
                    col += 1
                    continue
                length = _run_length(px, old, col, row, x1)
                changed += length
                if length >= 6:
                    runs += length
                col += length
        if changed == 0:
            return
        if solid:
            self.fill(ox + x0, oy + y0, x1 - x0, y1 - y0, rgb(*color))
            return
        if runs >= changed * 0.45:
            self._rle_band(ox, oy, px, old, x0, y0, x1, y1)
            return
        self._blit_box(ox, oy, px, x0, y0, x1, y1)

    def _rle_band(self, ox, oy, px, old, x0, y0, x1, y1) -> None:
        for row in range(y0, y1):
            col = x0
            while col < x1:
                if px[col, row] == old[col, row]:
                    col += 1
                    continue
                start = col
                run = _run_length(px, old, col, row, x1)
                if run >= 6:
                    self.fill(ox + col, oy + row, run, 1, rgb(*px[col, row]))
                    col += run
                    continue
                while col < x1 and px[col, row] != old[col, row] and _run_length(px, old, col, row, x1) < 6:
                    col += 1
                if col > start:
                    self._blit_box(ox, oy, px, start, row, col, row + 1)

    def _blit_box(self, ox, oy, px, x0, y0, x1, y1) -> None:
        from PIL import Image
        crop = Image.new("RGB", (x1 - x0, y1 - y0))
        crop.putdata([px[col, row] for row in range(y0, y1) for col in range(x0, x1)])
        self.image(ox + x0, oy + y0, crop)

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


def _dirty_span(px, old, row: int, width: int) -> tuple[int, int] | None:
    start = None
    end = None
    for col in range(width):
        if px[col, row] != old[col, row]:
            if start is None:
                start = col
            end = col + 1
    if start is None:
        return None
    return start, end


def _run_length(px, old, col: int, row: int, limit: int) -> int:
    color = px[col, row]
    end = col
    while end < limit and px[end, row] == color and px[end, row] != old[end, row]:
        end += 1
    return end - col


def settime_packet(t: datetime) -> bytes:
    body = struct.pack("<H6B", t.year, t.month, t.day, t.hour, t.minute, t.second, t.isoweekday() % 7)
    return (bytes([PKT_NOW, OP_SETTIME, len(body)]) + body).ljust(PACKET, b"\0")
