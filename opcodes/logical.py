"""
Logical operations handler for PowerPC assembly
"""

opcodes = ['andi', 'cmpwi']

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
    return f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"