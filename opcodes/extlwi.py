"""
Handler for PowerPC extlwi (Extract and Left Rotate Word Immediate) instruction.
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

opcodes = ['extlwi']

class ExtlwiHandler:
    """Handles PowerPC extlwi instruction transpilation."""

    def __init__(self, transpiler: 'ModularTranspiler'):
        self.transpiler = transpiler

    def parse_register(self, reg_str: str) -> int:
        """Parse register string to integer, handling 'r' prefix."""
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register: {reg_str}")

    def parse_immediate(self, imm_str: str) -> int:
        """Parse immediate value, handling decimal formats."""
        imm_str = imm_str.strip()
        try:
            return int(imm_str)
        except ValueError:
            raise ValueError(f"Invalid immediate value: {imm_str}")

    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) < expected:
            raise ValueError(f"{opcode} requires at least {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        """Handle extlwi instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands

        self.validate_operand_count(ops, 4, opcode)

        try:
            dst_reg = self.parse_register(ops[0])
            src_reg = self.parse_register(ops[1])
            n = self.parse_immediate(ops[2])  # Number of bits
            b = self.parse_immediate(ops[3])  # Shift amount

            if opcode == 'extlwi':
                mask = (1 << n) - 1
                mask_hex = format_hex(mask)
                result = [
                    f"uint32_t rotated = (gc_env.r[{src_reg}] << {b}) | (gc_env.r[{src_reg}] >> {32 - b}); // extlwi r{dst_reg}, r{src_reg}, {n}, {b}",
                    f"gc_env.r[{dst_reg}] = rotated & {mask_hex};"
                ]
                if instruction.opcode.endswith('.'):
                    result.append(
                        f"gc_env.cr[0] = (gc_env.r[{dst_reg}] == 0) ? 0x2 : ((int32_t)gc_env.r[{dst_reg}] < 0 ? 0x8 : 0x4);"
                    )
                return result

            return [f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"]

        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for extlwi instruction handling."""
    return ExtlwiHandler(transpiler).handle(instruction)
