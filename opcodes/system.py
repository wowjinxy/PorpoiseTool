"""
System and cache operations handler for PowerPC assembly
"""

opcodes = ['dcbst', 'sync', 'icbi', 'isync', 'dcbf', 'dcbi']

def handle(instruction, transpiler):
    """Handle cache and synchronization operations."""
    opcode = instruction.opcode.lower().rstrip('.')
    ops = instruction.operands

    if opcode == 'dcbst' and len(ops) >= 2:
        return f"// dcbst: Data cache block store (no-op in this context)"
    elif opcode == 'dcbf' and len(ops) >= 2:
        return f"// dcbf: Data cache block flush (no-op in this context)"
    elif opcode == 'sync':
        return f"// sync: Memory barrier (no-op in this context)"
    elif opcode == 'icbi' and len(ops) >= 2:
        return f"// icbi: Instruction cache block invalidate (no-op in this context)"
    elif opcode == 'dcbi' and len(ops) >= 2:
        return f"// dcbi: Data cache block invalidate (no-op in this context)"
    elif opcode == 'isync':
        return f"// isync: Instruction synchronize (no-op in this context)"

    return f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"