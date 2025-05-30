"""
Handler for PowerPC bctr (Branch to Count Register) instruction.
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

opcodes = ['bctr']

class BctrHandler:
    """Handles PowerPC bctr instruction transpilation."""
    
    def __init__(self, transpiler: 'ModularTranspiler'):
        self.transpiler = transpiler
    
    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        """Handle bctr instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands
        
        self.validate_operand_count(ops, 0, opcode)
        
        if opcode == 'bctr':
            return [
                f"return gc_env.ctr; // bctr"
            ]
        
        return [f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for bctr instruction handling."""
    return BctrHandler(transpiler).handle(instruction)