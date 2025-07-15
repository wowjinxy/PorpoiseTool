"""
Handler for PowerPC mftb (Move from Time Base) instruction.
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

opcodes = ['mftb']

class MftbHandler:
    """Handles PowerPC mftb instruction transpilation."""

    def parse_register(self, reg_str: str) -> int:
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register format: {reg_str}")

    def parse_tbr(self, tbr_str: str) -> int:
        try:
            return int(tbr_str.rstrip(',').strip(), 0)
        except ValueError:
            raise ValueError(f"Invalid TBR value: {tbr_str}")

    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands

        self.validate_operand_count(ops, 2, opcode)

        try:
            dst_reg = self.parse_register(ops[0])
            tbr = self.parse_tbr(ops[1])
            if tbr == 268:  # TBL
                return [f"gc_env.r[{dst_reg}] = (uint32_t)(gc_env.tb & 0xFFFFFFFF); // mftb r{dst_reg}, {tbr}"]
            elif tbr == 269:  # TBU
                return [f"gc_env.r[{dst_reg}] = (uint32_t)(gc_env.tb >> 32); // mftb r{dst_reg}, {tbr}"]
            return [f"// Unsupported TBR value {tbr} for mftb"]
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    return MftbHandler().handle(instruction)
