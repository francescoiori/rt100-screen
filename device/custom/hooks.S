@ Entry points patched into the stock screen firmware.
    .syntax unified
    .cpu cortex-m0
    .thumb

@ Replaces "bl 0x0101195c" (first UI draw call) in the main loop at 0x010104b0.
@ Stock mode: run that call and return to 0x010104b4 as before.
@ Custom mode: run the non-drawing 0x01014314 that sits between the stock draw
@ calls, then resume at the loop's back-edge 0x010104d4, skipping all UI draws.
    .section .text.hooks, "ax"
    .thumb_func
    .global loop_hook
loop_hook:
    push    {r4, lr}
    bl      custom_tick
    cmp     r0, #0
    bne     1f
    bl      stock_draw0
    pop     {r4, pc}
1:  bl      stock_idle
    pop     {r4}
    pop     {r0}
    ldr     r0, =loop_resume + 1
    bx      r0
    .ltorg
