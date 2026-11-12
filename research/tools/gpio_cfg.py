"""gpio_cfg.py <bin> <base>: histogram of constants stored into the GPIO config block 0xF8700..0xF873F."""
import struct, sys, collections, capstone
from capstone import arm
path, base = sys.argv[1], int(sys.argv[2], 0)
d = open(path, "rb").read()
md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB); md.detail = True
regs, consts, hist, off = {}, {}, collections.Counter(), 0
while off < len(d) - 1:
    ins = next(md.disasm(d[off:off + 4], base + off), None)
    if ins is None:
        regs.clear(); consts.clear(); off += 2; continue
    m, ops = ins.mnemonic, ins.operands
    if m.startswith("ldr") and "pc" in ins.op_str and len(ops) == 2:
        la = (ins.address + 4 & ~3) + ops[1].mem.disp
        if 0 <= la - base < len(d) - 3:
            regs[ops[0].reg] = struct.unpack_from("<I", d, la - base)[0]
    elif m == "movs" and len(ops) == 2 and ops[1].type == arm.ARM_OP_IMM:
        consts[ops[0].reg] = ops[1].imm; regs.pop(ops[0].reg, None)
    elif m == "strb" and ops[1].type == arm.ARM_OP_MEM and ops[1].mem.base in regs and ops[1].mem.index == 0:
        a = regs[ops[1].mem.base] + ops[1].mem.disp
        if 0xF8700 <= a < 0xF8740 and ops[0].reg in consts:
            hist[consts[ops[0].reg]] += 1
    elif ops and ops[0].type == arm.ARM_OP_REG and not m.startswith(("str", "cmp", "tst")):
        regs.pop(ops[0].reg, None); consts.pop(ops[0].reg, None)
    if m == "bl":
        regs.clear(); consts.clear()
    off += ins.size
for v, n in sorted(hist.items()):
    print(f"0x{v:02x}: {n}")
