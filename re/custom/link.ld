/* Appended after the stock app (ends 0x01017EB8); the app image may grow up to
   0x01020000. RAM starts right after the stock zero-initialised region
   (0x2004C..0x2BBAC); build.py extends the stock zero-init length over .bss. */
MEMORY
{
    FLASH (rx) : ORIGIN = 0x01017EB8, LENGTH = 0x01020000 - 0x01017EB8
    RAM (rw)   : ORIGIN = 0x0002BBB0, LENGTH = 0x0002D000 - 0x0002BBB0
}

stock_draw0 = 0x0101195C;
stock_idle  = 0x01014314;
loop_resume = 0x010104D4;

SECTIONS
{
    .text : { KEEP(*(.text.hooks)) KEEP(*(.text.custom_frame_hook)) *(.text*) *(.rodata*) } > FLASH
    .data : { *(.data*) } > RAM AT > FLASH
    .bss (NOLOAD) : { __bss_start = .; *(.bss*) *(COMMON) . = ALIGN(4); __bss_end = .; } > RAM
    /DISCARD/ : { *(.ARM.exidx*) *(.ARM.attributes) *(.comment) }
}

ASSERT(SIZEOF(.data) == 0, "initialised data is not supported: nothing copies it to RAM")
