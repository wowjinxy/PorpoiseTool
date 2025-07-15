"""
Handler for PowerPC clrlslwi (Clear Left then Shift Left Word Immediate) instruction.
"""

from typing import List
from utils import format_hex

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

opcodes = ['clrlslwi']

class ClrlslwiHandler:
    """Handles PowerPC clrlslwi instruction transpilation."""

    def __init__(self, transpiler: 'ModularTranspiler'):
        self.transpiler = transpiler

    def parse_register(self, reg_str: str) -> int:
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register format: {reg_str}")

    def parse_immediate(self, imm_str: str) -> int:
        imm_str = imm_str.strip()
        try:
            return int(imm_str)
        except ValueError:
            raise ValueError(f"Invalid immediate value: {imm_str}")

    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        if len(ops) < expected:
            raise ValueError(f"{opcode} requires at least {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands

        self.validate_operand_count(ops, 4, opcode)

        try:
            dst_reg = self.parse_register(ops[0])
            src_reg = self.parse_register(ops[1])
            b = self.parse_immediate(ops[2])
            n = self.parse_immediate(ops[3])

            mask = (1 << (32 - b)) - 1
            mask_hex = format_hex(mask)
            return [f"gc_env.r[{dst_reg}] = (gc_env.r[{src_reg}] << {n}) & {mask_hex}; // clrlslwi r{dst_reg}, r{src_reg}, {b}, {n}"]
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]


def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for clrlslwi instruction handling."""
    return ClrlslwiHandler(transpiler).handle(instruction)
