"""
Handler for PowerPC mffs (Move from FPSCR) instruction.
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

opcodes = ['mffs']

class MffsHandler:
    """Handles PowerPC mffs instruction transpilation."""

    def parse_fpregister(self, reg_str: str) -> int:
        try:
            return int(reg_str.lstrip('fF').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid FP register: {reg_str}")

    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands

        self.validate_operand_count(ops, 1, opcode)

        try:
            dst_fp = self.parse_fpregister(ops[0])
            return [f"gc_env.f[{dst_fp}] = (double)gc_env.fpscr; // mffs f{dst_fp}"]
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    return MffsHandler().handle(instruction)
