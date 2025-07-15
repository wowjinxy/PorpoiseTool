"""
Handler for PowerPC mtcrf (Move to Condition Register Fields) instruction.
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

opcodes = ['mtcrf']

class MtcrfHandler:
    """Handles PowerPC mtcrf instruction transpilation."""

    def parse_register(self, reg_str: str) -> int:
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register format: {reg_str}")

    def parse_mask(self, mask_str: str) -> int:
        try:
            return int(mask_str.rstrip(',').strip(), 0)
        except ValueError:
            raise ValueError(f"Invalid mask: {mask_str}")

    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands

        self.validate_operand_count(ops, 2, opcode)

        try:
            mask = self.parse_mask(ops[0])
            src_reg = self.parse_register(ops[1])
            if mask == 0xFF:
                lines = [
                    f"gc_env.cr[{i}] = (gc_env.r[{src_reg}] >> {28 - i*4}) & 0xF;" for i in range(8)
                ]
                lines.append(f"// mtcrf {mask}, r{src_reg}")
                return lines
            return [f"// Unsupported mask {mask} for mtcrf"]
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    return MtcrfHandler().handle(instruction)
