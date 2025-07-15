"""
Handler for PowerPC mtsprg (Move to Special Purpose Register General) instruction.
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

opcodes = ['mtsprg']

class MtsprgHandler:
    """Handles PowerPC mtsprg instruction transpilation."""

    def parse_register(self, reg_str: str) -> int:
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register format: {reg_str}")

    def parse_sprg(self, sprg_str: str) -> int:
        try:
            return int(sprg_str.rstrip(',').strip())
        except ValueError:
            raise ValueError(f"Invalid SPRG number: {sprg_str}")

    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands

        self.validate_operand_count(ops, 2, opcode)

        try:
            sprg_num = self.parse_sprg(ops[0])
            src_reg = self.parse_register(ops[1])
            if 0 <= sprg_num < 4:
                return [f"gc_env.sprg[{sprg_num}] = gc_env.r[{src_reg}]; // mtsprg {sprg_num}, r{src_reg}"]
            return [f"// Unsupported SPRG index {sprg_num} for mtsprg"]
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    return MtsprgHandler().handle(instruction)
