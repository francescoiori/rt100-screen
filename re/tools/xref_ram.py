"""xref_ram.py <bin> <base> <lo> <hi>: find loads/stores hitting RAM [lo,hi) via literal-loaded base regs."""
import struct, sys, capstone
from capstone import arm
path, base, lo, hi = sys.argv[1], int(sys.argv[2], 0), int(sys.argv[3], 0), int(sys.argv[4], 0)
d = open(path, "rb").read()
md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB); md.detail = True
regs = {}
off = 0
while off < len(d) - 1:
    ins = next(md.disasm(d[off:off + 4], base + off), None)
    if ins is None:
        regs.clear(); off += 2; continue
    m = ins.mnemonic
    if m.startswith("ldr") and "pc" in ins.op_str and len(ins.operands) == 2:
        la = (ins.address + 4 & ~3) + ins.operands[1].mem.disp
        if 0 <= la - base < len(d) - 3:
            regs[ins.operands[0].reg] = struct.unpack_from("<I", d, la - base)[0]
    elif m.startswith(("ldr", "str")) and len(ins.operands) == 2 and ins.operands[1].type == arm.ARM_OP_MEM:
        mem = ins.operands[1].mem
        if mem.base in regs and mem.index == 0:
            a = regs[mem.base] + mem.disp
            if lo <= a < hi:
                print(f"{ins.address:08x} {m:6s} {ins.op_str:24s} -> 0x{a:05x}")
        if m.startswith("ldr"):
            regs.pop(ins.operands[0].reg, None)
    elif m == "adds" and len(ins.operands) == 2 and ins.operands[0].reg in regs and ins.operands[1].type == arm.ARM_OP_IMM:
        regs[ins.operands[0].reg] += ins.operands[1].imm
    elif m == "mov" and len(ins.operands) == 2 and ins.operands[1].type == arm.ARM_OP_REG and ins.operands[1].reg in regs:
        regs[ins.operands[0].reg] = regs[ins.operands[1].reg]
    else:
        if ins.operands and ins.operands[0].type == arm.ARM_OP_REG:
            regs.pop(ins.operands[0].reg, None)
    if m in ("b", "bx", "pop", "bl") or m.startswith("b") and len(m) == 3:
        if m == "bl":
            for r in (arm.ARM_REG_R0, arm.ARM_REG_R1, arm.ARM_REG_R2, arm.ARM_REG_R3):
                regs.pop(r, None)
    off += ins.size
