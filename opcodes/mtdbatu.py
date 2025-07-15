"""
Handler for PowerPC mtdbatu (Move to Data BAT Upper) instruction.
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

opcodes = ['mtdbatu']

class MtdbatuHandler:
    """Handles PowerPC mtdbatu instruction transpilation."""

    def parse_register(self, reg_str: str) -> int:
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register format: {reg_str}")

    def parse_index(self, idx_str: str) -> int:
        try:
            return int(idx_str.rstrip(',').strip(), 0)
        except ValueError:
            raise ValueError(f"Invalid DBAT index: {idx_str}")

    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands

        self.validate_operand_count(ops, 2, opcode)

        try:
            index = self.parse_index(ops[0])
            src_reg = self.parse_register(ops[1])
            if 0 <= index < 4:
                return [f"gc_env.dbatu[{index}] = gc_env.r[{src_reg}]; // mtdbatu {index}, r{src_reg}"]
            return [f"// Unsupported DBAT index {index} for mtdbatu"]
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    return MtdbatuHandler().handle(instruction)
