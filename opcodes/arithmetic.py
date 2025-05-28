"""
Arithmetic operations handler for PowerPC assembly
"""

opcodes = ['addi']

def handle(instruction, transpiler):
    """Handle arithmetic operations."""
    opcode = instruction.opcode.lower().rstrip('.')
    ops = instruction.operands

    if opcode == 'addi' and len(ops) >= 3:
        dst_reg = int(ops[0].lstrip('r'))
        src_reg = int(ops[1].lstrip('r'))
        imm = ops[2]
        return f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg}] + {imm};"
    return f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"