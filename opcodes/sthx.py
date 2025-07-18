"""
Handler for PowerPC sthx (Store Halfword Indexed) instruction.
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

opcodes = ['sthx']

class SthxHandler:
    """Handles PowerPC sthx instruction transpilation."""

    def parse_register(self, reg_str: str) -> int:
        """Parse register string to integer, handling 'r' prefix."""
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register: {reg_str}")

    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        """Handle sthx instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands

        self.validate_operand_count(ops, 3, opcode)

        try:
            src_reg = self.parse_register(ops[0])
            base_reg = self.parse_register(ops[1])
            index_reg = self.parse_register(ops[2])

            if opcode == 'sthx':
                return [
                    f"gc_mem_write16(gc_env.ram, gc_env.r[{base_reg}] + gc_env.r[{index_reg}], gc_env.r[{src_reg}]); // sthx r{src_reg}, r{base_reg}, r{index_reg}"
                ]

            return [f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"]

        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]


def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for sthx instruction handling."""
    return SthxHandler().handle(instruction)
