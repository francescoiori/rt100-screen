@ In-place replacements for two routines of the stock screen firmware v506
@ bit-banged I2C driver (RTC BM8563/PCF8563 at 0xA2 on GPIO38=SCL, GPIO39=SDA).
@
@ GPIO config byte at 0xF8720 + pin: 0x3E drive low, 0x3F drive high,
@ 0x00 input, 0x40 input with pull-up. Input level: 0xF8740 bit 7 (GPIO39).
@
@ Each routine must fit its stock slot; build_i2c_fix.py enforces the sizes.

    .syntax unified
    .cpu cortex-m0
    .thumb

    .equ GPIO_CFG,  0x000F8720
    .equ SCL,       6
    .equ SDA,       7
    .equ IN_OFS,    0x20
    .equ LOW,       0x3E
    .equ HIGH,      0x3F
    .equ IN_PU,     0x40
    .equ HALF,      5               @ µs per half clock, ~100 kHz

@ void i2c_wait_ack(void)   stock slot 0x010144CE..0x01014506
    .section .ack, "ax"
    .thumb_func
    .global i2c_wait_ack
i2c_wait_ack:
    push    {r4, r5, r6, lr}
    movs    r5, #0xF8               @ r5 = GPIO_CFG without a literal pool,
    lsls    r5, r5, #4              @ which would force 4-byte alignment on
    adds    r5, r5, #0x07           @ this 2-byte-aligned slot
    lsls    r5, r5, #8
    adds    r5, r5, #0x20
    movs    r0, #IN_PU
    strb    r0, [r5, #SDA]
    movs    r0, #HIGH
    strb    r0, [r5, #SCL]
    movs    r4, #0
1:  movs    r0, #HALF
    bl      delay_us
    ldrh    r0, [r5, #IN_OFS]
    lsls    r0, r0, #24
    bpl     2f
    adds    r4, r4, #1
    cmp     r4, #10
    blo     1b
2:  movs    r0, #LOW
    strb    r0, [r5, #SCL]
    movs    r0, #HALF
    bl      delay_us
    pop     {r4, r5, r6, pc}

@ uint8_t i2c_read_byte(void)   (always NACKs)   stock slot 0x01014540..0x01014596
    .section .rdb, "ax"
    .thumb_func
    .global i2c_read_byte
i2c_read_byte:
    push    {r4, r5, r6, r7, lr}
    ldr     r6, =GPIO_CFG
    movs    r0, #IN_PU
    strb    r0, [r6, #SDA]
    movs    r7, #LOW
    movs    r4, #0
    movs    r5, #8
1:  movs    r0, #HIGH
    strb    r0, [r6, #SCL]
    movs    r0, #HALF
    bl      delay_us
    lsls    r4, r4, #1
    ldrh    r0, [r6, #IN_OFS]
    lsls    r0, r0, #24
    bpl     2f
    adds    r4, r4, #1
2:  strb    r7, [r6, #SCL]
    movs    r0, #HALF
    bl      delay_us
    subs    r5, r5, #1
    bne     1b
    movs    r5, #HIGH
    strb    r5, [r6, #SDA]
    movs    r0, #HALF
    bl      delay_us
    strb    r5, [r6, #SCL]
    movs    r0, #HALF
    bl      delay_us
    strb    r7, [r6, #SCL]
    movs    r0, #HALF
    bl      delay_us
    uxtb    r0, r4
    pop     {r4, r5, r6, r7, pc}
    .ltorg
