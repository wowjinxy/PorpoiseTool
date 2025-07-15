"""
Handler for PowerPC bgelr (Branch if Greater or Equal to Link Register) instruction.
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

opcodes = ['bgelr']

class BgelrHandler:
    """Handles PowerPC bgelr instruction transpilation."""

    def __init__(self, transpiler: 'ModularTranspiler'):
        self.transpiler = transpiler

    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands

        self.validate_operand_count(ops, 0, opcode)

        try:
            if opcode == 'bgelr':
                return [f"if (gc_env.cr[0] & (0x4 | 0x2)) return; // bgelr"]
            return [f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"]
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]


def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for bgelr instruction handling."""
    return BgelrHandler(transpiler).handle(instruction)
