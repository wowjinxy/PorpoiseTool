"""
Handler for PowerPC sth (Store Halfword) instruction.
"""

from typing import List, Tuple, Union
from utils import format_hex

try:
    from . import Instruction
except ImportError:
    try:
        from instruction import Instruction
    except ImportError:
        class Instruction:
            def __init__(self):
                self.opcode = ""
                self.operands = []

opcodes = ['sth']

class SthHandler:
    """Handles PowerPC sth instruction transpilation."""
    
    def parse_register(self, reg_str: str) -> int:
        """Parse register string to integer, handling 'r' prefix."""
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register format: {reg_str}")
    
    def parse_memory_operand(self, mem_str: str, transpiler) -> Tuple[Union[str, int], int, bool, int]:
        """Parse memory operand including SDA and symbol formats."""
        mem_str = mem_str.strip()

        if '@sda21(' in mem_str:
            parts = mem_str.split('@sda21(')
            if len(parts) == 2:
                sym_part = parts[0]
                base_part = parts[1].rstrip(')')
                base_reg = self.parse_register(base_part)

                addend = 0
                if '+' in sym_part or '-' in sym_part:
                    import re
                    m = re.match(r'([^+-]+)([+-]0x[0-9A-Fa-f]+)', sym_part)
                    if m:
                        sym_name = m.group(1)
                        addend = int(m.group(2), 0)
                    else:
                        sym_name = sym_part
                else:
                    sym_name = sym_part

                symbol = transpiler.sanitize_symbol_name(sym_name)
                transpiler.variables.add(f"extern uint32_t {symbol}")
                return symbol, base_reg, True, addend

        if '@l(' in mem_str:
            l_match = mem_str.split('@l(')
            if len(l_match) == 2:
                symbol = transpiler.sanitize_symbol_name(l_match[0])
                base_reg_part = l_match[1].rstrip(')')
                base_reg = self.parse_register(base_reg_part)
                transpiler.variables.add(f"extern uint32_t {symbol}")
                return symbol, base_reg, False, 0

        if mem_str.startswith('sda:'):
            symbol = transpiler.sanitize_symbol_name(mem_str[4:])
            transpiler.variables.add(f"extern uint32_t {symbol}")
            return symbol, 0, True, 0

        if not ('(' in mem_str and ')' in mem_str):
            raise ValueError(f"Invalid memory operand format: {mem_str}")
        parts = mem_str.split('(', 1)
        offset_str = parts[0].strip()
        base_part = parts[1].rstrip(')')
        offset = int(offset_str, 0) if offset_str else 0
        base_reg = self.parse_register(base_part)
        return offset, base_reg, False, 0
    
    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")
    
    def generate_memory_access(self, opcode: str, reg: int, off_or_sym: Union[str, int], base_reg: int, is_sda: bool, addend: int = 0) -> List[str]:
        """Generate memory access code for sth."""
        if is_sda:
            symbol = off_or_sym
            addr = f"(uint32_t)&{symbol}"
            if addend:
                addr = f"{addr} + {format_hex(addend)}"
            if base_reg == 0:
                return [f"gc_mem_write16(gc_env.ram, {addr}, gc_env.r[{reg}]); // {opcode} r{reg}, {symbol}@sda21(r0)"]
            else:
                return [f"gc_mem_write16(gc_env.ram, gc_env.r[{base_reg}] + {addr}, gc_env.r[{reg}]); // {opcode} r{reg}, {symbol}@sda21(r{base_reg})"]
        elif isinstance(off_or_sym, str):
            symbol = off_or_sym
            if base_reg == 0:
                return [f"gc_mem_write16(gc_env.ram, (uint32_t)&{symbol}, gc_env.r[{reg}]); // {opcode} r{reg}, {symbol}@l/h(r0)"]
            else:
                return [f"gc_mem_write16(gc_env.ram, gc_env.r[{base_reg}] + (uint32_t)&{symbol}, gc_env.r[{reg}]); // {opcode} r{reg}, {symbol}@l/h(r{base_reg})"]
        else:
            offset = off_or_sym
            if offset == 0:
                return [f"gc_mem_write16(gc_env.ram, gc_env.r[{base_reg}], gc_env.r[{reg}]); // {opcode} r{reg}, (r{base_reg})"]
            else:
                return [f"gc_mem_write16(gc_env.ram, gc_env.r[{base_reg}] + {format_hex(offset)}, gc_env.r[{reg}]); // {opcode} r{reg}, {format_hex(offset)}(r{base_reg})"]


    def handle(self, instruction: Instruction) -> List[str]:
        """Handle sth instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands
        
        print(f"Processing opcode: {opcode}, operands: {ops}")
        
        try:
            self.validate_operand_count(ops, 2, opcode)
            src_reg = self.parse_register(ops[0])
            off_or_sym, base_reg, is_sda, addend = self.parse_memory_operand(ops[1], transpiler)
            return self.generate_memory_access(opcode, src_reg, off_or_sym, base_reg, is_sda, addend)
        
        except (ValueError, IndexError) as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for sth instruction handling."""
    return SthHandler().handle(instruction)
