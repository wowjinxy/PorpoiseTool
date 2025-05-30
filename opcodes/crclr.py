"""
Handler for PowerPC crclr (Condition Register Clear) instruction.
"""

from typing import List

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

opcodes = ['crclr']

class CrclrHandler:
    """Handles PowerPC crclr instruction transpilation."""
    
    def __init__(self, transpiler: 'ModularTranspiler'):
        self.transpiler = transpiler
    
    def parse_cr_bit(self, bit_str: str) -> tuple:
        """Parse CR bit (e.g., 'cr1eq') into CR field index and bit mask."""
        bit_str = bit_str.lower().strip()
        if not bit_str.startswith('cr'):
            raise ValueError(f"Invalid CR bit format: {bit_str}")
        
        # Extract field number and bit name (e.g., 'cr1eq' -> '1', 'eq')
        parts = bit_str[2:].rstrip(',')
        field_num = ''
        bit_name = ''
        for char in parts:
            if char.isdigit():
                field_num += char
            else:
                bit_name += char
        
        try:
            field = int(field_num)
            if not (0 <= field <= 7):
                raise ValueError(f"CR field must be 0-7, got {field}")
        except ValueError:
            raise ValueError(f"Invalid CR field number: {field_num}")
        
        bit_map = {'lt': 0x8, 'gt': 0x4, 'eq': 0x2, 'so': 0x1}
        if bit_name not in bit_map:
            raise ValueError(f"Invalid CR bit name: {bit_name}, expected lt, gt, eq, or so")
        
        return field, bit_map[bit_name]
    
    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        """Handle crclr instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands
        
        self.validate_operand_count(ops, 1, opcode)
        
        try:
            cr_field, bit_mask = self.parse_cr_bit(ops[0])
            
            if opcode == 'crclr':
                return [f"gc_env.cr[{cr_field}] &= ~0x{bit_mask:X}; // crclr {ops[0]}"]
            
            return [f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"]
        
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for crclr instruction handling."""
    return CrclrHandler(transpiler).handle(instruction)