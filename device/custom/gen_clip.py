"""Bake clip.gif into clip.h: four 16-colour poses that fit the spare flash.

The panel is 240x240 and the spare application flash is about 30 KB, with
about 3 KB of scratch RAM. This GIF is 200x266 and 23 frames. It is scaled
to fit the panel, cut to four poses, and shared down to 16 colours. The first
pose is LZSS with a 2048-byte window (the RAM we can spare). Later poses are
only the pixels that changed, drawn on top of what the panel already shows.
"""
import os
from collections import defaultdict

from PIL import Image, ImageSequence

HERE = os.path.dirname(os.path.abspath(__file__))
GIF = os.path.join(HERE, "clip.gif")
OUT_H = os.path.join(HERE, "clip.h")
OUT_DIR = os.path.join(HERE, "out")

PANEL = 240
COLORS = 16
POSES = (0, 6, 12, 18)   # 23 frames, 100 ms apart -> four poses about 0.6 s apart
WIN = 2048
MIN_MATCH = 3
MAX_MATCH = 34           # 3 + a 5-bit length
HOLD = 600               # stock-loop wakes between poses; SysTick is about 1–2 ms
BG_RGB = (0x0B, 0x0F, 0x1A)


def rgb565(r, g, b):
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3)


def expand(c):
    return ((c >> 11) * 255 // 31, ((c >> 5) & 63) * 255 // 63, (c & 31) * 255 // 31)


def composite(im):
    canvas = Image.new("RGBA", im.size, (0, 0, 0, 255))
    frames = []
    for fr in ImageSequence.Iterator(im):
        canvas = canvas.copy()
        canvas.alpha_composite(fr.convert("RGBA"))
        frames.append(canvas.convert("RGB"))
    return frames


def fit(im):
    w, h = im.size
    s = PANEL / max(w, h)
    nw, nh = max(1, round(w * s)), max(1, round(h * s))
    return im.resize((nw, nh), Image.Resampling.BOX)


def quantize(frames):
    w, h = frames[0].size
    sample = Image.new("RGB", (w, h * len(frames)))
    for i, fr in enumerate(frames):
        sample.paste(fr, (0, i * h))
    pal_img = sample.quantize(colors=COLORS, method=Image.Quantize.MEDIANCUT)
    raw = pal_img.getpalette()
    pal = [rgb565(*raw[i:i + 3]) for i in range(0, COLORS * 3, 3)]
    grids = []
    for fr in frames:
        q = fr.quantize(palette=pal_img, dither=Image.Dither.NONE)
        grids.append(list(q.get_flattened_data()))
    return pal, grids


def pack_columns(grid, w, h):
    """Two pixels per byte, high nibble first, column by column (the LCD's order)."""
    out = bytearray()
    for x in range(w):
        for y in range(0, h, 2):
            out.append((grid[y * w + x] << 4) | grid[(y + 1) * w + x])
    return bytes(out)


def compress(data):
    n = len(data)
    pos = defaultdict(list)
    out = bytearray()
    i = 0

    def index(j):
        if j + 3 <= n:
            pos[data[j:j + 3]].append(j)

    while i < n:
        at = len(out)
        out.append(0)
        flags = 0
        for bit in range(8):
            if i >= n:
                break
            best_len = best_dist = 0
            maxlen = min(MAX_MATCH, n - i)
            if maxlen >= MIN_MATCH:
                limit = i - WIN
                for j in reversed(pos.get(data[i:i + 3], ())):
                    if j < limit:
                        break
                    m = 0
                    while m < maxlen and data[j + m] == data[i + m]:
                        m += 1
                    if m > best_len:
                        best_len, best_dist = m, i - j
                        if m == maxlen:
                            break
            if best_len >= MIN_MATCH:
                length = best_len - MIN_MATCH
                off = best_dist - 1
                out.append((length << 3) | (off >> 8))
                out.append(off & 0xFF)
                flags |= 1 << bit
                for k in range(best_len):
                    index(i + k)
                i += best_len
            else:
                out.append(data[i])
                index(i)
                i += 1
        out[at] = flags
    return bytes(out)


def decompress(data, n):
    """Same bit order as the firmware decoder: flag bit 0 first, bit 8 means 'read flags'."""
    out = bytearray()
    i = 0
    bit = 8
    flags = 0
    while len(out) < n:
        if bit == 8:
            flags = data[i]
            i += 1
            bit = 0
        if flags & (1 << bit):
            b0, b1 = data[i], data[i + 1]
            i += 2
            length = (b0 >> 3) + MIN_MATCH
            dist = ((b0 & 7) << 8 | b1) + 1
            for _ in range(length):
                out.append(out[-dist])
        else:
            out.append(data[i])
            i += 1
        bit += 1
    return bytes(out)


def delta(prev, cur, w, h):
    blob = bytearray()
    for x in range(w):
        y = 0
        while y < h:
            if prev[y * w + x] == cur[y * w + x]:
                y += 1
                continue
            y0 = y
            vals = []
            while y < h and len(vals) < 255 and prev[y * w + x] != cur[y * w + x]:
                vals.append(cur[y * w + x])
                y += 1
            blob.append(x)
            blob.append(y0)
            blob.append(len(vals))
            blob.extend(vals)
    return bytes(blob)


def apply_delta(grid, blob, w):
    i = 0
    while i + 3 <= len(blob):
        x, y, n = blob[i], blob[i + 1], blob[i + 2]
        i += 3
        for k in range(n):
            grid[ (y + k) * w + x] = blob[i]
            i += 1
    return grid


def c_bytes(name, data):
    lines = [f"static const uint8_t {name}[] = {{"]
    if data:
        for i in range(0, len(data), 16):
            lines.append("    " + ", ".join(f"0x{b:02x}" for b in data[i:i + 16]) + ",")
    lines.append("};")
    return "\n".join(lines)


def render(grid, w, h, pal, bg):
    img = Image.new("RGB", (PANEL, PANEL), expand(bg))
    x0 = (PANEL - w) // 2
    for y in range(h):
        for x in range(w):
            img.putpixel((x0 + x, y), expand(pal[grid[y * w + x]]))
    return img


def encode_gif(blob: bytes, indexes=None, max_frames: int = 24) -> dict:
    """Turn a still or a GIF into the clip the screen plays locally.

    Every frame, up to `max_frames`, fitted to the panel and shared down to
    16 colours. Pose 0 is LZSS. Later poses, and the wrap back to pose 0, are
    the pixels that changed.
    """
    import io
    im = Image.open(io.BytesIO(blob))
    delay = max(int(im.info.get("duration") or 100), 40) / 1000
    frames = composite(im)
    if not frames:
        raise ValueError("empty image")
    if indexes is None:
        n = len(frames)
        if n <= max_frames:
            indexes = list(range(n))
        else:
            indexes = []
            for i in range(max_frames):
                j = round(i * (n - 1) / (max_frames - 1))
                if j not in indexes:
                    indexes.append(j)
    chosen = []
    for i in indexes:
        imf = fit(frames[i])
        w, h = imf.size
        if h % 2:
            imf = imf.crop((0, 0, w, h - 1))
            h -= 1
        if h < 2 or w < 1:
            raise ValueError("image too small")
        chosen.append(imf)
    w, h = chosen[0].size
    pal, grids = quantize(chosen)
    raw = pack_columns(grids[0], w, h)
    key = compress(raw)
    if decompress(key, len(raw)) != raw:
        raise ValueError("keyframe did not round-trip")
    deltas = []
    seen = list(grids[0])
    for nxt in grids[1:]:
        blob_d = delta(seen, nxt, w, h)
        apply_delta(seen, blob_d, w)
        if seen != list(nxt):
            raise ValueError("delta did not rebuild the pose")
        deltas.append(bytes(blob_d))
    wrap = b""
    if len(grids) > 1:
        wrap = bytes(delta(seen, grids[0], w, h))
        back = apply_delta(seen, wrap, w)
        if back != list(grids[0]):
            raise ValueError("loop did not return to the first pose")
    return {"w": w, "h": h, "x": (PANEL - w) // 2, "y": (PANEL - h) // 2,
            "pal": pal, "key": key, "deltas": deltas, "wrap": wrap, "delay": delay}


def main():
    frames = composite(Image.open(GIF))
    chosen = [fit(frames[i]) for i in POSES]
    w, h = chosen[0].size
    assert h % 2 == 0 and w <= PANEL and h <= PANEL, (w, h)
    pal, grids = quantize(chosen)
    bg = rgb565(*BG_RGB)
    key = pack_columns(grids[0], w, h)
    key_c = compress(key)
    assert decompress(key_c, len(key)) == key, "keyframe did not round-trip"

    deltas = []
    seen = list(grids[0])
    for nxt in grids[1:]:
        blob = delta(seen, nxt, w, h)
        got = apply_delta(seen, blob, w)
        assert got == list(nxt), "delta did not rebuild the pose"
        deltas.append(blob)
        seen = list(nxt)

    os.makedirs(OUT_DIR, exist_ok=True)
    # Expect pictures are what the emulator must reproduce, including the side bars.
    shown = list(grids[0])
    render(shown, w, h, pal, bg).save(os.path.join(OUT_DIR, "clip_expect_0.png"))
    for n, blob in enumerate(deltas, start=1):
        apply_delta(shown, blob, w)
        render(shown, w, h, pal, bg).save(os.path.join(OUT_DIR, f"clip_expect_{n}.png"))

    with open(OUT_H, "w") as f:
        f.write("/* Generated by gen_clip.py from clip.gif. Do not edit.\n")
        f.write("   Four poses, 16 colours, centred on the 240x240 panel.\n")
        f.write("   Pose 0 is LZSS (2048-byte window, flag bit 0 = match).\n")
        f.write("   Poses 1..3 are runs: u8 x, y, n, then n palette indexes. */\n")
        f.write(f"#define CLIP_W {w}\n#define CLIP_H {h}\n")
        f.write(f"#define CLIP_X {(PANEL - w) // 2}\n")
        f.write(f"#define CLIP_BG 0x{bg:04x}\n")
        f.write(f"#define CLIP_HOLD {HOLD}\n#define CLIP_FRAMES {len(grids)}\n")
        f.write("static const uint16_t clip_pal[16] __attribute__((aligned(4))) = {\n    ")
        f.write(", ".join(f"0x{c:04x}" for c in pal))
        f.write("\n};\n")
        f.write(c_bytes("clip_key", key_c) + "\n")
        for n, blob in enumerate(deltas, start=1):
            f.write(c_bytes(f"clip_d{n}", blob) + "\n")

    total = len(key_c) + sum(len(b) for b in deltas) + COLORS * 2
    print(f"clip {w}x{h} at x={(PANEL - w) // 2}, {len(grids)} poses, "
          f"key {len(key_c)} bytes, deltas {[len(b) for b in deltas]}, "
          f"{total} bytes plus the player")


if __name__ == "__main__":
    main()
