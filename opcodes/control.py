"""
Control operations handler for PowerPC assembly
"""

opcodes = ['mflr', 'mtlr', 'blr', 'bne', 'bl']

def handle(instruction, transpiler):
    """Handle control flow operations."""
    opcode = instruction.opcode.lower().rstrip('.')
    ops = instruction.operands

    if opcode == 'mflr' and len(ops) >= 1:
        reg_num = int(ops[0].lstrip('r'))
        return f"gc_env.r[{reg_num}] = gc_env.lr; // Move from link register"
    elif opcode == 'mtlr' and len(ops) >= 1:
        reg_num = int(ops[0].lstrip('r'))
        return f"gc_env.lr = gc_env.r[{reg_num}]; // Move to link register"
    elif opcode == 'blr':
        return "return;"
    elif opcode == 'bne' and len(ops) >= 1:
        label = ops[0].lstrip('.')  # Remove leading period
        return f"if (gc_env.cr[0] != 0) goto {label};"
    elif opcode == 'bl' and len(ops) >= 1:
        transpiler.includes.add('"os.h"')  # Assume OSReset is in os.h
        return f"OSReset();"
    return f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"