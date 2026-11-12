"""Recursive-descent Thumb disassembler that understands __ARM_common_switch8 tables.

usage: rdis.py <bin> <base> <func_addr> [switch8_helper_addr]

Follows conditional/unconditional branches inside one function (BL calls are
not followed), decodes inline switch8 jump tables and prints a sorted listing
with labels, resolved PC-relative literals and BL targets.
"""
import struct, sys
import capstone

path, base, entry = sys.argv[1], int(sys.argv[2], 0), int(sys.argv[3], 0)
helper = int(sys.argv[4], 0) if len(sys.argv) > 4 else None
d = open(path, "rb").read()
md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB)
md.detail = True


def find_switch8_helper():
    # push {r4,r5}; mov r4,lr; subs r4,#1; ldrb r5,[r4]; adds r4,#1; cmp r3,r5
    sig = bytes.fromhex("30b4 7446 641e 2578 641c ab42".replace(" ", ""))
    o = d.find(sig)
    return base + o if o >= 0 else None


helper = helper or find_switch8_helper()
insns, labels, tables, todo = {}, {entry: "entry"}, {}, [entry]
while todo:
    pc = todo.pop()
    while pc not in insns and 0 <= pc - base < len(d) - 1:
        ins = next(md.disasm(d[pc - base:pc - base + 4], pc), None)
        if ins is None:
            break
        insns[pc] = ins
        m, nxt = ins.mnemonic, pc + ins.size
        if m == "bl" and ins.operands[0].imm == helper:
            t = nxt
            n = d[t - base]
            offs = d[t - base + 1:t - base + 2 + n]
            targets = [t + 2 * o for o in offs]
            tables[t] = (n, targets)
            for i, tg in enumerate(targets):
                labels.setdefault(tg, f"case_{i}" if i < n else "default")
                todo.append(tg)
            break
        if m in ("b", "b.w") or (m.startswith("b") and m[1:3] in
                                  ("eq", "ne", "hs", "lo", "mi", "pl", "vs", "vc", "hi", "ls", "ge", "lt", "gt", "le", "cs", "cc")):
            tg = ins.operands[0].imm
            labels.setdefault(tg, f"L_{tg:08x}")
            todo.append(tg)
            if m in ("b", "b.w"):
                break
        if m in ("bx", "pop") and ("pc" in ins.op_str or m == "bx"):
            break
        pc = nxt

for a in sorted(set(insns) | set(tables)):
    if a in labels:
        print(f"\n{labels[a]}:")
    if a in tables:
        n, tg = tables[a]
        print(f"  {a:08x} .switch8 n={n} -> " + ", ".join(f"{i}:{t:08x}" for i, t in enumerate(tg)))
        continue
    ins = insns[a]
    extra = ""
    if ins.mnemonic.startswith("ldr") and "pc" in ins.op_str and len(ins.operands) > 1:
        la = (a + 4 & ~3) + ins.operands[1].mem.disp
        if 0 <= la - base < len(d) - 3:
            extra = f"   ; =0x{struct.unpack_from('<I', d, la - base)[0]:08x}"
    if ins.mnemonic == "bl":
        extra = "   ; switch8" if ins.operands[0].imm == helper else ""
    print(f"  {a:08x} {ins.mnemonic:8s} {ins.op_str}{extra}")
