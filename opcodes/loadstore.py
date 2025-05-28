"""
Load/Store operations handler for PowerPC assembly
"""

opcodes = ['lis', 'stw', 'stwu', 'lhz', 'lwz', 'li']

def handle(instruction, transpiler):
    """Handle load/store operations."""
    opcode = instruction.opcode.lower().rstrip('.')
    ops = instruction.operands

    if opcode == 'lis' and len(ops) >= 2:
        reg_num = int(ops[0].lstrip('r'))
        return f"gc_env.r[{reg_num}] = ({ops[1]}) << 16;"
    elif opcode == 'stw' and len(ops) >= 2:
        src_reg = int(ops[0].lstrip('r'))
        if '(' in ops[1] and ')' in ops[1]:
            offset, base = ops[1].split('(')
            base_reg = int(base.rstrip(')').lstrip('r'))
            return f"gc_mem_write32(gc_env.ram, gc_env.r[{base_reg}] + {offset}, gc_env.r[{src_reg}]);"
        return f"// Unsupported stw: {ops[0]} {ops[1]}"
    elif opcode == 'stwu' and len(ops) >= 2:
        src_reg = int(ops[0].lstrip('r'))
        if '(' in ops[1] and ')' in ops[1]:
            offset, base = ops[1].split('(')
            base_reg = int(base.rstrip(')').lstrip('r'))
            return [
                f"gc_mem_write32(gc_env.ram, gc_env.r[{base_reg}] + {offset}, gc_env.r[{src_reg}]);",
                f"gc_env.r[{base_reg}] = gc_env.r[{base_reg}] + {offset};"
            ]
        return f"// Unsupported stwu: {ops[0]} {ops[1]}"
    elif opcode == 'lhz' and len(ops) >= 2:
        dst_reg = int(ops[0].lstrip('r'))
        if '(' in ops[1] and ')' in ops[1]:
            offset, base = ops[1].split('(')
            base_reg = int(base.rstrip(')').lstrip('r'))
            return f"gc_env.r[{dst_reg}] = gc_mem_read16(gc_env.ram, gc_env.r[{base_reg}] + {offset});"
        return f"// Unsupported lhz: {ops[0]} {ops[1]}"
    elif opcode == 'lwz' and len(ops) >= 2:
        dst_reg = int(ops[0].lstrip('r'))
        if '(' in ops[1] and ')' in ops[1]:
            offset, base = ops[1].split('(')
            base_reg = int(base.rstrip(')').lstrip('r'))
            return f"gc_env.r[{dst_reg}] = gc_mem_read32(gc_env.ram, gc_env.r[{base_reg}] + {offset});"
        return f"// Unsupported lwz: {ops[0]} {ops[1]}"
    elif opcode == 'li' and len(ops) >= 2:
        reg_num = int(ops[0].lstrip('r'))
        return f"gc_env.r[{reg_num}] = {ops[1]};"
    return f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"