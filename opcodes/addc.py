"""
Handler for PowerPC addc instruction.
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

opcodes = ['addc']

class AddcHandler:
    """Handles PowerPC addc instruction transpilation."""

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

    def handle(self, instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
        """Handle addc instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands

        print(f"Processing opcode: {opcode}, operands: {ops}")

        try:
            self.validate_operand_count(ops, 3, opcode)
            dst_reg = self.parse_register(ops[0])
            src_reg1 = self.parse_register(ops[1])
            src_reg2 = self.parse_register(ops[2])

            temp = transpiler.new_var('addc_temp')
            result = [
                f"uint64_t {temp} = (uint64_t)gc_env.r[{src_reg1}] + gc_env.r[{src_reg2}];",
                f"gc_env.r[{dst_reg}] = (uint32_t){temp}; // {opcode} r{dst_reg}, r{src_reg1}, r{src_reg2}",
                f"gc_env.xer = (gc_env.xer & ~0x20000000) | ({temp} > 0xFFFFFFFF ? 0x20000000 : 0);",
            ]
            return result

        except (ValueError, IndexError) as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]


def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for addc instruction handling."""
    return AddcHandler().handle(instruction, transpiler)
