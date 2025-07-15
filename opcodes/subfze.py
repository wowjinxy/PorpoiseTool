"""
Handler for PowerPC subfze (Subtract From Zero Extended) instruction.
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

opcodes = ['subfze']

class SubfzeHandler:
    """Handles PowerPC subfze instruction transpilation."""

    def parse_register(self, reg_str: str) -> int:
        """Parse register string to integer, handling 'r' prefix."""
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register format: {reg_str}")

    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        """Handle subfze instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands

        self.validate_operand_count(ops, 2, opcode)

        try:
            dst_reg = self.parse_register(ops[0])
            src_reg = self.parse_register(ops[1])

            result = [
                "uint32_t subfze_borrow = 1 - ((gc_env.xer & 0x20000000) >> 29);",
                f"uint64_t subfze_temp = (uint64_t)0 - gc_env.r[{src_reg}] - subfze_borrow;",
                f"gc_env.r[{dst_reg}] = (uint32_t)subfze_temp; // subfze r{dst_reg}, r{src_reg}",
                f"gc_env.xer = (gc_env.xer & ~0x20000000) | (0 >= (gc_env.r[{src_reg}] + subfze_borrow) ? 0x20000000 : 0);",
            ]
            return result
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]


def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for subfze instruction handling."""
    return SubfzeHandler().handle(instruction)
