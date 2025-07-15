"""
Handler for PowerPC mfxer (Move from XER) instruction.
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

opcodes = ['mfxer']

class MfxerHandler:
    """Handles PowerPC mfxer instruction transpilation."""

    def parse_register(self, reg_str: str) -> int:
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register format: {reg_str}")

    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands

        self.validate_operand_count(ops, 1, opcode)

        try:
            dst_reg = self.parse_register(ops[0])
            return [f"gc_env.r[{dst_reg}] = gc_env.xer; // mfxer r{dst_reg}"]
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    return MfxerHandler().handle(instruction)
