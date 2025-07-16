"""
Handler for PowerPC adde instruction.
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

opcodes = ['adde']

class AddeHandler:
    """Handles PowerPC adde instruction transpilation."""

    def parse_register(self, reg_str: str) -> int:
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register format: {reg_str}")

    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands

        self.validate_operand_count(ops, 3, opcode)

        try:
            dst_reg = self.parse_register(ops[0])
            src_reg1 = self.parse_register(ops[1])
            src_reg2 = self.parse_register(ops[2])

            temp = transpiler.new_var('adde_temp')
            result = [
                f"uint64_t {temp} = (uint64_t)gc_env.r[{src_reg1}] + gc_env.r[{src_reg2}] + ((gc_env.xer & 0x20000000) ? 1 : 0);",
                f"gc_env.r[{dst_reg}] = (uint32_t){temp}; // {opcode} r{dst_reg}, r{src_reg1}, r{src_reg2}",
                f"gc_env.xer = (gc_env.xer & ~0x20000000) | ({temp} > 0xFFFFFFFF ? 0x20000000 : 0);",
            ]
            return result
        except (ValueError, IndexError) as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]


def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for adde instruction handling."""
    return AddeHandler().handle(instruction, transpiler)
