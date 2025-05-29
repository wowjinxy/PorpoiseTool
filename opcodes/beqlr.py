"""
Handler for PowerPC beqlr (Branch if Equal and Link Return) instruction.
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

opcodes = ['beqlr']

class BeqlrHandler:
    """Handles PowerPC beqlr instruction transpilation."""
    
    def __init__(self, transpiler: 'ModularTranspiler'):
        self.transpiler = transpiler
    
    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        """Handle beqlr instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands
        
        self.validate_operand_count(ops, 0, opcode)
        
        try:
            if opcode == 'beqlr':
                return [f"if (gc_env.cr[0] & 0x2) return; // beqlr"]
            
            return [f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"]
        
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for beqlr instruction handling."""
    return BeqlrHandler(transpiler).handle(instruction)