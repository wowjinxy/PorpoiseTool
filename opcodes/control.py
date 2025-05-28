"""
Control operations handler for PowerPC assembly
"""

opcodes = ['mflr', 'mtlr', 'blr', 'bne', 'beq', 'bl', 'blrl', 'mtctr', 'bdnz', 'b', 'mr']

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
        # Use the target function name directly
        target = ops[0].split('@')[0]  # Strip @ha/@l if present
        return f"{target}();"
    elif opcode == 'blrl':
        return f"// Call function at gc_env.lr; // Branch to link register"
    elif opcode == 'mtctr' and len(ops) >= 1:
        reg_num = int(ops[0].lstrip('r'))
        return f"gc_env.ctr = gc_env.r[{reg_num}]; // Move to count register"
    elif opcode == 'bdnz' and len(ops) >= 1:
        label = ops[0].lstrip('.')  # Remove leading period
        return [
            f"gc_env.ctr -= 1;",
            f"if (gc_env.ctr != 0) goto {label};"
        ]
    elif opcode == 'b' and len(ops) >= 1:
        label = ops[0].lstrip('.')  # Remove leading period
        return f"goto {label};"
    elif opcode == 'mr' and len(ops) >= 2:
        dst_reg = int(ops[0].lstrip('r'))
        src_reg = int(ops[1].lstrip('r'))
        return f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg}]; // Move register"
    return f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"