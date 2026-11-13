/*
 * Custom display mode for the Epomaker RT100 screen (stock firmware v506).
 *
 * Transport: the keyboard's OLED-update passthrough (USB 0x31 <count>) relays
 * each following 64-byte USB report unchanged to the screen as serial frame
 * 0x3C (0x3D announces the count). The stock app ignores both; the patched
 * "unknown command" path calls custom_frame_hook(), which answers like the
 * bootloader and queues the packet for the main loop.
 *
 * Packet: p[0] = PKT_DRAW (queued, run in the main loop) or PKT_NOW (run at
 * once in the timer interrupt), then commands [op, len, body[len]] until op 0.
 * Multi-byte values are little endian. Coordinates: x right, y down, 240x240.
 */
#include <stdint.h>
#include "font8x16.h"
#include "clip.h"

#define PKT_DRAW 0xC5
#define PKT_NOW  0xC6

enum {
    OP_BEGIN = 0x01,    /* u16 bg                           enter custom mode, clear */
    OP_END = 0x02,      /*                                  leave: reboot to stock UI */
    OP_FILL = 0x03,     /* u16 x, y, w, h, color */
    OP_TEXT = 0x04,     /* u16 x, y, fg, bg; u8 scale; chars */
    OP_BLIT = 0x05,     /* u16 x, y, w, h; u8 mode; u16 fg, bg   mode 0 rgb565, 1 mono */
    OP_DATA = 0x06,     /* pixel bytes for the current blit */
    OP_SETTIME = 0x10,  /* u16 year; u8 month, day, hour, minute, second[, weekday 0=Sun]  (PKT_NOW) */
    OP_CLIP = 0x11,     /* play the picture stored in flash (clip.h) */
    OP_UHEAD = 0x12,    /* u8 w,h,x,y,clear; u16 pal[16]   start an uploaded clip */
    OP_UKEY = 0x13,     /* LZSS bytes of the uploaded keyframe */
    OP_URUN = 0x14,     /* delta runs for the uploaded clip: x,y,n, indexes */
};

#define LCD_W 240
#define LCD_H 240
#define MAGIC 0xC0570A11u
#define QN 32

typedef void (*fn_window_t)(unsigned x, unsigned y, unsigned w, unsigned h);
typedef void (*fn_byte_t)(unsigned b);
typedef void (*fn_void_t)(void);
typedef void (*fn_status_t)(unsigned unused, const volatile uint8_t *payload);
typedef void (*fn_rtc_write_t)(unsigned reg, unsigned value);

#define lcd_window   ((fn_window_t)(0x010106be | 1))
#define lcd_data     ((fn_byte_t)(0x01010678 | 1))
#define stock_reset  ((fn_void_t)(0x01013ef2 | 1))
#define stock_status ((fn_status_t)(0x01011f2a | 1))
#define wdt_feed     ((fn_void_t)(0x01013cc4 | 1))
#define rtc_write    ((fn_rtc_write_t)(0x01014596 | 1))

#define RX        ((const volatile uint8_t *)0x0002a2e8)
#define REPLY     ((volatile uint8_t *)0x0002b34c)
#define REPLY_SUM (*(volatile uint8_t *)0x0002b39f)
#define TX_FLAGS  (*(volatile uint8_t *)0x00020030)
#define UNHANDLED (*(volatile uint8_t *)0x0002b3a6)

static struct {
    uint32_t magic;
    volatile uint8_t head, tail;
    uint8_t blit_mode;
    uint8_t dropped;
    uint16_t blit_fg, blit_bg;
    uint32_t blit_left;
    uint8_t clip_on;
    uint8_t clip_frame;
    uint8_t clip_primed;        /* side bars already drawn; a loop must not wipe the picture */
    uint16_t clip_hold;
    uint16_t win_i;             /* LZSS history, 2048 bytes, only while a pose is decoding */
    uint16_t up_pal[16];
    uint32_t up_left;           /* keyframe pixel-pairs still to draw; 0 = idle */
    uint8_t up_bit, up_flags, up_n, up_hn, up_run;
    uint8_t up_buf[4];
    uint8_t up_hdr[3];
    uint8_t up_x, up_y, up_w, up_h, up_rx, up_ry;
    uint8_t win[2048];
    uint8_t q[QN][64];
} st;

static unsigned u16(const uint8_t *p) { return p[0] | p[1] << 8; }

static void push(unsigned c)
{
    lcd_data(c >> 8);
    lcd_data(c & 0xff);
}

static int window(unsigned x, unsigned y, unsigned *w, unsigned *h)
{
    if (x >= LCD_W || y >= LCD_H || *w == 0 || *h == 0)
        return 0;
    if (*w > LCD_W - x) *w = LCD_W - x;
    if (*h > LCD_H - y) *h = LCD_H - y;
    lcd_window(x, y, *w, *h);
    return 1;
}

static void fill(unsigned x, unsigned y, unsigned w, unsigned h, unsigned color)
{
    if (!window(x, y, &w, &h))
        return;
    for (unsigned col = 0; col < w; col++) {
        wdt_feed();
        for (unsigned n = h; n; n--)
            push(color);
    }
}

static void text(unsigned x, unsigned y, unsigned fg, unsigned bg, unsigned s,
                 const uint8_t *str, unsigned n)
{
    if (s == 0) s = 1;
    if (s > 8) s = 8;
    for (unsigned k = 0; k < n && x + 8 * s <= LCD_W && y + 16 * s <= LCD_H; k++, x += 8 * s) {
        unsigned c = str[k];
        const unsigned short *g = font8x16[(c < 32 || c > 126 ? '?' : c) - 32];
        wdt_feed();
        lcd_window(x, y, 8 * s, 16 * s);
        for (unsigned col = 0; col < 8; col++)
            for (unsigned sx = 0; sx < s; sx++)
                for (unsigned row = 0; row < 16; row++) {
                    unsigned color = g[col] >> row & 1 ? fg : bg;
                    for (unsigned sy = 0; sy < s; sy++)
                        push(color);
                }
    }
}

/* Pose 0 is a full picture. Later poses only repaint the pixels that moved,
   which is why a loop has to start again from pose 0. */
static void clip_keyframe(void)
{
    unsigned left = (CLIP_W * CLIP_H) / 2;
    unsigned i = 0, bit = 8, flags = 0;
    st.win_i = 0;
    /* The first pose paints the side bars. Clearing again at the loop would
       flash the whole panel black before the picture is redrawn. */
    if (!st.clip_primed) {
        fill(0, 0, LCD_W, LCD_H, CLIP_BG);
        st.clip_primed = 1;
    }
    lcd_window(CLIP_X, 0, CLIP_W, CLIP_H);
    while (left) {
        unsigned b;
        if (bit == 8) {
            flags = clip_key[i++];
            bit = 0;
            wdt_feed();
        }
        if (flags & (1u << bit)) {
            unsigned b0 = clip_key[i++];
            unsigned b1 = clip_key[i++];
            unsigned len = (b0 >> 3) + 3;
            unsigned dist = ((b0 & 7) << 8 | b1) + 1;
            while (len && left) {
                b = st.win[(st.win_i - dist) & 2047];
                st.win[st.win_i & 2047] = b;
                st.win_i++;
                push(clip_pal[b >> 4]);
                push(clip_pal[b & 15]);
                len--;
                left--;
            }
        } else {
            b = clip_key[i++];
            st.win[st.win_i & 2047] = b;
            st.win_i++;
            push(clip_pal[b >> 4]);
            push(clip_pal[b & 15]);
            left--;
        }
        bit++;
    }
}

static void clip_runs(const uint8_t *p, unsigned n)
{
    unsigned i = 0;
    while (i + 3 <= n) {
        unsigned x = p[i++], y = p[i++], len = p[i++];
        if (len == 0 || i + len > n)
            return;
        wdt_feed();
        lcd_window(CLIP_X + x, y, 1, len);
        while (len--)
            push(clip_pal[p[i++] & 15]);
    }
}

static void clip_draw(unsigned frame)
{
    if (frame == 0)
        clip_keyframe();
    else if (frame == 1)
        clip_runs(clip_d1, sizeof clip_d1);
    else if (frame == 2)
        clip_runs(clip_d2, sizeof clip_d2);
    else
        clip_runs(clip_d3, sizeof clip_d3);
}

static const uint8_t *feed_p;
static unsigned feed_n;

static int feed_have(unsigned n)
{
    return (unsigned)st.up_n + feed_n >= n;
}

static unsigned feed_get(void)
{
    unsigned b;
    if (st.up_n) {
        b = st.up_buf[0];
        for (unsigned i = 1; i < st.up_n; i++)
            st.up_buf[i - 1] = st.up_buf[i];
        st.up_n--;
        return b;
    }
    feed_n--;
    b = *feed_p++;
    return b;
}

static void upload_emit(unsigned b)
{
    st.win[st.win_i & 2047] = (uint8_t)b;
    st.win_i++;
    push(st.up_pal[b >> 4]);
    push(st.up_pal[b & 15]);
    st.up_left--;
}

static void upload_begin(const uint8_t *a, unsigned n)
{
    if (n < 37 || a[0] == 0 || a[1] == 0 || a[0] > LCD_W || a[1] > LCD_H)
        return;
    if (a[2] > LCD_W - a[0] || a[3] > LCD_H - a[1])
        return;
    st.up_w = a[0];
    st.up_h = a[1];
    st.up_x = a[2];
    st.up_y = a[3];
    for (unsigned i = 0; i < 16; i++)
        st.up_pal[i] = a[5 + i * 2] | (a[6 + i * 2] << 8);
    st.up_left = (unsigned)st.up_w * st.up_h / 2;
    st.up_bit = 8;
    st.up_n = 0;
    st.up_hn = 0;
    st.up_run = 0;
    st.win_i = 0;
    st.magic = MAGIC;
    st.clip_on = 0;
    if (a[4])
        fill(0, 0, LCD_W, LCD_H, CLIP_BG);
    lcd_window(st.up_x, st.up_y, st.up_w, st.up_h);
}

static void upload_key(const uint8_t *p, unsigned n)
{
    if (st.up_left == 0)
        return;
    feed_p = p;
    feed_n = n;
    while (st.up_left) {
        if (st.up_bit == 8) {
            if (!feed_have(1))
                break;
            st.up_flags = (uint8_t)feed_get();
            st.up_bit = 0;
            wdt_feed();
        }
        if (st.up_flags & (1u << st.up_bit)) {
            unsigned b0, b1, len, dist;
            if (!feed_have(2))
                break;
            b0 = feed_get();
            b1 = feed_get();
            len = (b0 >> 3) + 3;
            dist = ((b0 & 7) << 8 | b1) + 1;
            while (len && st.up_left) {
                upload_emit(st.win[(st.win_i - dist) & 2047]);
                len--;
            }
        } else {
            if (!feed_have(1))
                break;
            upload_emit(feed_get());
        }
        st.up_bit++;
    }
    if (st.up_left == 0) {
        st.up_n = 0;
        return;
    }
    while (feed_n && st.up_n < 4) {
        st.up_buf[st.up_n++] = *feed_p++;
        feed_n--;
    }
}

static void upload_run(const uint8_t *p, unsigned n)
{
    unsigned i = 0;
    while (i < n || st.up_run) {
        if (st.up_run == 0) {
            while (st.up_hn < 3 && i < n)
                st.up_hdr[st.up_hn++] = p[i++];
            if (st.up_hn < 3)
                return;
            st.up_rx = st.up_hdr[0];
            st.up_ry = st.up_hdr[1];
            st.up_run = st.up_hdr[2];
            st.up_hn = 0;
            if (st.up_run == 0)
                continue;
            wdt_feed();
            lcd_window(st.up_x + st.up_rx, st.up_y + st.up_ry, 1, st.up_run);
        }
        if (i >= n)
            return;
        push(st.up_pal[p[i++] & 15]);
        st.up_run--;
    }
}

static void blit_begin(const uint8_t *a)
{
    unsigned w = u16(a + 4), h = u16(a + 6);
    st.blit_left = 0;
    if (!window(u16(a), u16(a + 2), &w, &h) || w != u16(a + 4) || h != u16(a + 6))
        return;
    st.blit_mode = a[8];
    st.blit_fg = u16(a + 9);
    st.blit_bg = u16(a + 11);
    st.blit_left = w * h;
}

static void blit_data(const uint8_t *a, unsigned n)
{
    wdt_feed();
    if (st.blit_mode == 0) {
        for (unsigned i = 0; i + 1 < n && st.blit_left; i += 2, st.blit_left--) {
            lcd_data(a[i]);
            lcd_data(a[i + 1]);
        }
        return;
    }
    for (unsigned i = 0; i < n; i++)
        for (unsigned bit = 0x80; bit && st.blit_left; bit >>= 1, st.blit_left--)
            push(a[i] & bit ? st.blit_fg : st.blit_bg);
}

static void run_draw(const uint8_t *p)
{
    for (unsigned i = 1; i + 2 <= 64;) {
        unsigned op = p[i], len = p[i + 1];
        const uint8_t *a = p + i + 2;
        if (op == 0 || i + 2 + len > 64)
            return;
        switch (op) {
        case OP_BEGIN:
            st.magic = MAGIC;
            st.blit_left = 0;
            fill(0, 0, LCD_W, LCD_H, len >= 2 ? u16(a) : 0);
            break;
        case OP_END:
            st.magic = 0;
            stock_reset();
            break;
        case OP_FILL:
            if (len >= 10)
                fill(u16(a), u16(a + 2), u16(a + 4), u16(a + 6), u16(a + 8));
            break;
        case OP_TEXT:
            if (len >= 9)
                text(u16(a), u16(a + 2), u16(a + 4), u16(a + 6), a[8], a + 9, len - 9);
            break;
        case OP_BLIT:
            if (len >= 13)
                blit_begin(a);
            break;
        case OP_DATA:
            blit_data(a, len);
            break;
        case OP_CLIP:
            st.magic = MAGIC;
            st.clip_on = 1;
            st.clip_frame = 0;
            st.clip_hold = 0;
            st.clip_primed = 0;
            break;
        case OP_UHEAD:
            if (len >= 37)
                upload_begin(a, len);
            break;
        case OP_UKEY:
            upload_key(a, len);
            break;
        case OP_URUN:
            upload_run(a, len);
            break;
        }
        if (op != OP_DATA && op != OP_BLIT)
            st.blit_left = 0;
        if (op != OP_CLIP)
            st.clip_on = 0;
        i += 2 + len;
    }
}

static void run_now(const volatile uint8_t *p)
{
    for (unsigned i = 1; i + 2 <= 64;) {
        unsigned op = p[i], len = p[i + 1];
        const volatile uint8_t *a = p + i + 2;
        if (op == 0 || i + 2 + len > 64)
            return;
        if (op == OP_SETTIME && len >= 7) {
            /* Same payload the keyboard's clock status frame carries (page 1, item 2):
               the stock handler writes the RTC and refreshes its own time fields. */
            uint8_t s[9] = {1, 2, a[0], a[1], a[2], a[3], a[4], a[5], a[6]};
            stock_status(0, s);
            if (len >= 8 && a[7] < 7)
                rtc_write(6, a[7]);
        }
        i += 2 + len;
    }
}

/* Timer interrupt, from the dispatcher's unknown-command path (stock: UNHANDLED = 1). */
void custom_frame_hook(void)
{
    unsigned cmd = RX[3];
    if (cmd != 0x3C && cmd != 0x3D) {
        UNHANDLED = 1;
        return;
    }
    if (cmd == 0x3C) {
        const volatile uint8_t *p = RX + 4;
        if (p[0] == PKT_NOW) {
            run_now(p);
        } else if (p[0] == PKT_DRAW) {
            unsigned h = st.head, next = (h + 1) & (QN - 1);
            if (next == st.tail) {
                st.dropped++;
            } else {
                for (unsigned i = 0; i < 64; i++)
                    st.q[h][i] = p[i];
                st.head = next;
            }
        }
    }
    REPLY[0] = 0x44;
    REPLY[1] = 3;
    REPLY[2] = cmd | 0x80;
    REPLY[3] = 0;
    REPLY_SUM = 3 + (cmd | 0x80);
    TX_FLAGS |= 1;
}

/* Main loop, once per tick. Returns nonzero when the stock UI must not draw. */
int custom_tick(void)
{
    for (unsigned budget = 4; budget && st.tail != st.head; budget--) {
        unsigned t = st.tail;
        run_draw(st.q[t]);
        st.tail = (t + 1) & (QN - 1);
    }
    /* CLIP_HOLD wakes between poses. The stock loop wakes on its timer
       (about 1–2 ms), so a pose stays up for about half a second to a second. */
    if (st.clip_on) {
        if (st.clip_hold)
            st.clip_hold--;
        else {
            clip_draw(st.clip_frame);
            st.clip_frame++;
            if (st.clip_frame >= CLIP_FRAMES)
                st.clip_frame = 0;
            st.clip_hold = CLIP_HOLD;
        }
    }
    return st.magic == MAGIC;
}
