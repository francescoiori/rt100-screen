"""callgraph.py <bin> <base> <func>...: transitive BL callees of each function (switch8-aware)."""
import struct, sys, capstone
path, base = sys.argv[1], int(sys.argv[2], 0)
d = open(path, "rb").read()
md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB); md.detail = True
sig = bytes.fromhex("30b47446641e2578641cab42")
helper = base + d.find(sig)
COND = ("eq", "ne", "hs", "lo", "mi", "pl", "vs", "vc", "hi", "ls", "ge", "lt", "gt", "le", "cs", "cc")


def direct_calls(entry):
    seen, todo, calls = set(), [entry], set()
    while todo:
        pc = todo.pop()
        while pc not in seen and 0 <= pc - base < len(d) - 1:
            seen.add(pc)
            ins = next(md.disasm(d[pc - base:pc - base + 4], pc), None)
            if ins is None:
                break
            m, nxt = ins.mnemonic, pc + ins.size
            if m == "bl":
                t = ins.operands[0].imm
                if t == helper:
                    n = d[nxt - base]
                    todo += [nxt + 2 * o for o in d[nxt - base + 1:nxt - base + 2 + n]]
                    break
                calls.add(t)
            elif m == "b" or (m[0] == "b" and m[1:3] in COND and len(m) <= 4):
                todo.append(ins.operands[0].imm)
                if m == "b":
                    break
            elif m == "bx" or (m == "pop" and "pc" in ins.op_str):
                break
            pc = nxt
    return calls


cache = {}
def closure(f, depth=0):
    if f in cache: return cache[f]
    cache[f] = set()
    out = set(direct_calls(f))
    for c in list(out):
        if base <= c < base + len(d):
            out |= closure(c, depth + 1)
    cache[f] = out
    return out


names = {}
for a in sys.argv[3:]:
    if "=" in a:
        k, v = a.split("="); names[int(k, 0)] = v
funcs = [int(a, 0) for a in sys.argv[3:] if "=" not in a]
for f in funcs:
    c = closure(f)
    tags = sorted(names[x] for x in c if x in names)
    print(f"{f:08x}: {len(c):3d} callees  {' '.join(tags)}")
