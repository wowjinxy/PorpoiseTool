"""
Handler for PowerPC cror (Condition Register OR) instruction.
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

opcodes = ['cror']

class CrorHandler:
    """Handles PowerPC cror instruction transpilation."""
    
    def __init__(self, transpiler: 'ModularTranspiler'):
        self.transpiler = transpiler
    
    def parse_cr_bit(self, bit_str: str) -> int:
        """Parse condition register bit name to bit position."""
        bit_map = {'lt': 0, 'gt': 1, 'eq': 2, 'so': 3}
        bit_str = bit_str.lower().rstrip(',')
        if bit_str not in bit_map:
            raise ValueError(f"Invalid CR bit: {bit_str}")
        return bit_map[bit_str]
    
    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        """Handle cror instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands
        
        self.validate_operand_count(ops, 3, opcode)
        
        try:
            dst_bit = self.parse_cr_bit(ops[0])
            src_a_bit = self.parse_cr_bit(ops[1])
            src_b_bit = self.parse_cr_bit(ops[2])
            
            if opcode == 'cror':
                # Assuming cr0 (index 0) for simplicity; adjust if cr field is specified
                return [
                    f"gc_env.cr[0] = (gc_env.cr[0] & ~(1 << {dst_bit})) | ((((gc_env.cr[0] >> {src_a_bit}) & 1) | ((gc_env.cr[0] >> {src_b_bit}) & 1)) << {dst_bit}); // cror {ops[0]}, {ops[1]}, {ops[2]}"
                ]
            
            return [f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"]
        
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for cror instruction handling."""
    return CrorHandler(transpiler).handle(instruction)