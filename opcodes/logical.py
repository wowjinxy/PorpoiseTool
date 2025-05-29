"""
Logical operations handler for PowerPC assembly
"""

opcodes = ['andi', 'cmpwi', 'cmplwi', 'clrrwi', 'cmplw', 'and']

def handle(instruction, transpiler):
    """Handle logical and comparison operations."""
    opcode = instruction.opcode.lower().rstrip('.')
    ops = instruction.operands

    if opcode == 'andi' and len(ops) >= 3:
        dst_reg = int(ops[0].lstrip('r'))
        src_reg = int(ops[1].lstrip('r'))
        imm = ops[2]
        return f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg}] & {imm};"
    elif opcode == 'cmpwi' and len(ops) >= 2:
        src_reg = int(ops[0].lstrip('r'))
        imm = ops[1]
        return f"gc_env.cr[0] = (gc_env.r[{src_reg}] == {imm}) ? 0 : (gc_env.r[{src_reg}] < {imm} ? -1 : 1); // Compare with immediate"
    elif opcode == 'cmplwi' and len(ops) >= 2:
        src_reg = int(ops[0].lstrip('r'))
        imm = ops[1]
        return f"gc_env.cr[0] = ((uint32_t)gc_env.r[{src_reg}] == {imm}) ? 0 : ((uint32_t)gc_env.r[{src_reg}] < {imm} ? -1 : 1); // Logical compare with immediate"
    elif opcode == 'clrrwi' and len(ops) >= 3:
        dst_reg = int(ops[0].lstrip('r'))
        src_reg = int(ops[1].lstrip('r'))
        n = int(ops[2])
        return f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg}] & ~((1ULL << {n}) - 1); // Clear rightmost {n} bits"
    elif opcode == 'cmplw' and len(ops) >= 2:
        src_reg1 = int(ops[0].lstrip('r'))
        src_reg2 = int(ops[1].lstrip('r'))
        return f"gc_env.cr[0] = ((uint32_t)gc_env.r[{src_reg1}] == (uint32_t)gc_env.r[{src_reg2}]) ? 0 : ((uint32_t)gc_env.r[{src_reg1}] < (uint32_t)gc_env.r[{src_reg2}] ? -1 : 1); // Logical compare word"
    elif opcode == 'and' and len(ops) >= 3:
        dst_reg = int(ops[0].lstrip('r'))
        src_reg1 = int(ops[1].lstrip('r'))
        src_reg2 = int(ops[2].lstrip('r'))
        return f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg1}] & gc_env.r[{src_reg2}];"
    return f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"