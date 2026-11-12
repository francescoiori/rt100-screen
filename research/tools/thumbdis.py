"""Tiny Thumb disassembler: dis.py <bin> <base> <start> [count]"""
import struct, sys
import capstone

path, base, start = sys.argv[1], int(sys.argv[2], 0), int(sys.argv[3], 0)
count = int(sys.argv[4]) if len(sys.argv) > 4 else 80
d = open(path, "rb").read()
md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB)
md.detail = True
for i, ins in enumerate(md.disasm(d[start - base:], start)):
    extra = ""
    if ins.mnemonic.startswith("ldr") and "pc" in ins.op_str and len(ins.operands) > 1:
        a = (ins.address + 4 & ~3) + ins.operands[1].mem.disp
        if 0 <= a - base < len(d) - 3:
            extra = f"   ; =0x{struct.unpack_from('<I', d, a - base)[0]:08x}"
    print(f"{ins.address:08x} {ins.mnemonic:8s} {ins.op_str}{extra}")
    if i + 1 >= count:
        break
