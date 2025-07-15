"""
Handler for PowerPC rfi instruction.
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

opcodes = ['rfi']

class RfiHandler:
    """Handles PowerPC rfi instruction transpilation."""

    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands

        self.validate_operand_count(ops, 0, opcode)

        return ["// rfi: return from interrupt (not implemented)"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    return RfiHandler().handle(instruction)
