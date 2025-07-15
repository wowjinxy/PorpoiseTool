"""
Handler for PowerPC subfic (Subtract From Immediate Carrying) instruction.
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

opcodes = ['subfic']

class SubficHandler:
    """Handles PowerPC subfic instruction transpilation."""

    def parse_register(self, reg_str: str) -> int:
        """Parse register string to integer, handling 'r' prefix."""
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register format: {reg_str}")

    def parse_immediate(self, imm_str: str) -> int:
        """Parse immediate value."""
        imm_str = imm_str.strip()
        try:
            return int(imm_str, 0)
        except ValueError:
            raise ValueError(f"Invalid immediate value: {imm_str}")

    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        """Handle subfic instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands

        self.validate_operand_count(ops, 3, opcode)

        try:
            dst_reg = self.parse_register(ops[0])
            src_reg = self.parse_register(ops[1])
            imm = self.parse_immediate(ops[2])

            result = [
                f"gc_env.r[{dst_reg}] = {imm} - gc_env.r[{src_reg}]; // subfic r{dst_reg}, r{src_reg}, {imm}",
                f"gc_env.xer = (gc_env.xer & ~0x20000000) | ({imm} >= gc_env.r[{src_reg}] ? 0x20000000 : 0);",
            ]
            return result
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]


def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for subfic instruction handling."""
    return SubficHandler().handle(instruction)
