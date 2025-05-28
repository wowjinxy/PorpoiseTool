"""
Control operations handler for PowerPC assembly
"""

opcodes = ['mflr', 'mtlr', 'blr', 'bne', 'beq', 'bl', 'blrl']

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
    elif opcode in ('bne', 'beq') and len(ops) >= 1:
        label = ops[0].lstrip('.')  # Remove leading period
        condition = '!=' if opcode == 'bne' else '=='
        return f"if (gc_env.cr[0] {condition} 0) goto {label};"
    elif opcode == 'bl' and len(ops) >= 1:
        transpiler.includes.add('"os.h"')
        return f"OSReset();"
    elif opcode == 'blrl':
        return f"// Call function at gc_env.lr; // Branch to link register"
        # Note: Actual function call requires runtime support or function pointer
    return f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"