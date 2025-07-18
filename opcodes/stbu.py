"""
Handler for PowerPC stbu (Store Byte with Update) instruction.
"""

from typing import List, Tuple

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

opcodes = ['stbu']

class StbuHandler:
    """Handles PowerPC stbu instruction transpilation."""

    def parse_register(self, reg_str: str) -> int:
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register format: {reg_str}")

    def parse_memory_operand(self, mem_str: str) -> Tuple[str, int]:
        mem_str = mem_str.strip()
        if not ('(' in mem_str and ')' in mem_str):
            raise ValueError(f"Invalid memory operand format: {mem_str}")
        parts = mem_str.split('(', 1)
        offset_str = parts[0].strip()
        base_part = parts[1].rstrip(')')
        offset = offset_str if offset_str else "0"
        base_reg = self.parse_register(base_part)
        return offset, base_reg

    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def generate_memory_access(self, opcode: str, reg: int, offset: str, base_reg: int) -> List[str]:
        return [
            f"gc_mem_write8(gc_env.ram, gc_env.r[{base_reg}] + {offset}, gc_env.r[{reg}]); // {opcode} r{reg}, {offset}(r{base_reg})",
            f"gc_env.r[{base_reg}] = gc_env.r[{base_reg}] + {offset};",
        ]

    def handle(self, instruction: Instruction) -> List[str]:
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands

        try:
            self.validate_operand_count(ops, 2, opcode)
            src_reg = self.parse_register(ops[0])
            offset, base_reg = self.parse_memory_operand(ops[1])
            return self.generate_memory_access(opcode, src_reg, offset, base_reg)
        except (ValueError, IndexError) as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    return StbuHandler().handle(instruction)
