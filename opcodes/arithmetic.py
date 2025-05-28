"""
Arithmetic operations handler for PowerPC assembly
"""

opcodes = ['addi', 'add']

def handle(instruction, transpiler):
    """Handle arithmetic operations."""
    opcode = instruction.opcode.lower().rstrip('.')
    ops = instruction.operands

    if opcode == 'addi' and len(ops) >= 3:
        dst_reg = int(ops[0].lstrip('r'))
        src_reg = int(ops[1].lstrip('r'))
        imm = ops[2]
        return f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg}] + {imm};"
    elif opcode == 'add' and len(ops) >= 3:
        dst_reg = int(ops[0].lstrip('r'))
        src_reg1 = int(ops[1].lstrip('r'))
        src_reg2 = int(ops[2].lstrip('r'))
        return f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg1}] + gc_env.r[{src_reg2}];"
    return f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"