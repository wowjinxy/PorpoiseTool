"""
Handler for PowerPC blt (Branch if Less Than) instruction.
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

opcodes = ['blt']

class BltHandler:
    """Handles PowerPC blt instruction transpilation."""
    
    def __init__(self, transpiler: 'ModularTranspiler'):
        self.transpiler = transpiler
    
    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) < expected:
            raise ValueError(f"{opcode} requires at least {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        """Handle blt instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands
        
        self.validate_operand_count(ops, 1, opcode)

        try:
            cond_reg = 0
            label_idx = 0
            if ops[0].lower().startswith('cr') and len(ops) >= 2:
                cond_reg = int(ops[0][2:])
                label_idx = 1
            label = ops[label_idx].lstrip('.')  # Remove leading period
            if opcode == 'blt':
                return [f"if (gc_env.cr[{cond_reg}] & 0x8) goto {label}; // blt {ops[label_idx]}"]
            
            return [f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"]
        
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for blt instruction handling."""
    return BltHandler(transpiler).handle(instruction)