"""
Handler for PowerPC lhzx (Load Halfword and Zero Indexed) instruction.
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

opcodes = ['lhzx']

class LhzxHandler:
    """Handles PowerPC lhzx instruction transpilation."""

    def __init__(self, transpiler: 'ModularTranspiler'):
        self.transpiler = transpiler

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
        """Handle lhzx instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands

        self.validate_operand_count(ops, 3, opcode)

        try:
            dst_reg = self.parse_register(ops[0])
            base_reg = self.parse_register(ops[1])
            index_reg = self.parse_register(ops[2])

            if opcode == 'lhzx':
                return [
                    f"gc_env.r[{dst_reg}] = gc_mem_read16(gc_env.ram, gc_env.r[{base_reg}] + gc_env.r[{index_reg}]); // lhzx r{dst_reg}, r{base_reg}, r{index_reg}"
                ]

            return [f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"]

        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for lhzx instruction handling."""
    return LhzxHandler(transpiler).handle(instruction)
