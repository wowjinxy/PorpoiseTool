"""
Control operations handler for PowerPC assembly
"""

opcodes = [
    'mflr', 'mtlr', 'mfmsr', 'mtmsr',  # Register move instructions
    'blr', 'blrl', 'b', 'bl', 'bla',    # Unconditional branches/calls
    'bne', 'beq', 'beq+', 'bge',       # Conditional branches
    'mtctr', 'bdnz',                    # Count register branches
    'mr'                                # Register copy
]

def handle(instruction, transpiler):
    """Handle control flow operations."""
    opcode = instruction.opcode.lower().rstrip('.')
    ops = instruction.operands

    # Register move instructions
    if opcode == 'mflr' and len(ops) >= 1:
        reg_num = int(ops[0].lstrip('r'))
        return f"gc_env.r[{reg_num}] = gc_env.lr; // Move from link register"
    elif opcode == 'mtlr' and len(ops) >= 1:
        reg_num = int(ops[0].lstrip('r'))
        return f"gc_env.lr = gc_env.r[{reg_num}]; // Move to link register"
    elif opcode == 'mfmsr' and len(ops) >= 1:
        reg_num = int(ops[0].lstrip('r'))
        return f"gc_env.r[{reg_num}] = gc_env.msr; // Move from machine state register"
    elif opcode == 'mtmsr' and len(ops) >= 1:
        reg_num = int(ops[0].lstrip('r'))
        return f"gc_env.msr = gc_env.r[{reg_num}]; // Move to machine state register"
    elif opcode == 'mr' and len(ops) >= 2:
        dst_reg = int(ops[0].lstrip('r'))
        src_reg = int(ops[1].lstrip('r'))
        return f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg}]; // Move register"

    # Unconditional branches and calls
    elif opcode == 'blr':
        return "return;"
    elif opcode == 'b' and len(ops) >= 1:
        label = ops[0].lstrip('.')  # Remove leading period
        if label == 'exit':
            transpiler.includes.add('<stdlib.h>')
            return 'exit(gc_env.r[3]);'
        return f"goto {label};"
    elif opcode == 'bl' and len(ops) >= 1:
        target = ops[0].split('@')[0]
        return f"{target}();"
    elif opcode == 'bla' and len(ops) >= 1:
        target = ops[0].split('@')[0]
        return f"{target}();"
    elif opcode == 'blrl':
        return f"// Call function at gc_env.lr; // Branch to link register"

    # Conditional branches
    elif opcode in ('bne', 'beq', 'beq+') and len(ops) >= 1:
        label = ops[0].lstrip('.')  # Remove leading period
        condition = '!=' if opcode == 'bne' else '=='
        return f"if (gc_env.cr[0] {condition} 0) goto {label};"
    elif opcode == 'bge' and len(ops) >= 1:
        label = ops[0].lstrip('.')  # Remove leading period
        return f"if (gc_env.cr[0] >= 0) goto {label};"

    # Count register branches
    elif opcode == 'mtctr' and len(ops) >= 1:
        reg_num = int(ops[0].lstrip('r'))
        return f"gc_env.ctr = gc_env.r[{reg_num}]; // Move to count register"
    elif opcode == 'bdnz' and len(ops) >= 1:
        label = ops[0].lstrip('.')  # Remove leading period
        return [
            f"gc_env.ctr -= 1;",
            f"if (gc_env.ctr != 0) goto {label};"
        ]

    return f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"