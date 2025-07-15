"""
Handler for PowerPC mtfsf (Move to FPSCR Fields) instruction.
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

opcodes = ['mtfsf']

class MtfsfHandler:
    """Handles PowerPC mtfsf instruction transpilation."""

    def parse_fpreg(self, fpreg_str: str) -> int:
        try:
            return int(fpreg_str.lstrip('fF').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid floating-point register: {fpreg_str}")

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
            src_fp = self.parse_fpreg(ops[1])
            if mask == 0xFF:
                return [f"gc_env.fpscr = (uint32_t)gc_env.f[{src_fp}]; // mtfsf {mask}, f{src_fp}"]
            return [f"// Unsupported mask {mask} for mtfsf"]
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    return MtfsfHandler().handle(instruction)
