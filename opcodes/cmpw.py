"""
Handler for PowerPC cmpw (Compare Word) instruction.
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

opcodes = ['cmpw']

class CmpwHandler:
    """Handles PowerPC cmpw instruction transpilation."""
    
    def __init__(self, transpiler: 'ModularTranspiler'):
        self.transpiler = transpiler
    
    def parse_register(self, reg_str: str) -> int:
        """Parse register string to integer, handling 'r' prefix."""
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register: {reg_str}")
    
    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        """Handle cmpw instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands
        
        self.validate_operand_count(ops, 2, opcode)
        
        try:
            reg_a = self.parse_register(ops[0])
            reg_b = self.parse_register(ops[1])
            
            if opcode == 'cmpw':
                return [
                    f"gc_env.cr[0] = (int32_t)gc_env.r[{reg_a}] < (int32_t)gc_env.r[{reg_b}] ? 0x8 : ((int32_t)gc_env.r[{reg_a}] > (int32_t)gc_env.r[{reg_b}] ? 0x4 : 0x2); // cmpw r{reg_a}, r{reg_b}"
                ]
            
            return [f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"]
        
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for cmpw instruction handling."""
    return CmpwHandler(transpiler).handle(instruction)