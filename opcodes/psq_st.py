"""
Handler for PowerPC psq_st instruction (simplified).
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

opcodes = ['psq_st']

class PsqStHandler:
    """Handles PowerPC psq_st instruction transpilation."""

    def parse_fpregister(self, reg_str: str) -> int:
        try:
            return int(reg_str.lstrip('fF').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid FP register format: {reg_str}")

    def parse_register(self, reg_str: str) -> int:
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register format: {reg_str}")

    def parse_immediate(self, imm_str: str) -> int:
        try:
            return int(imm_str, 0)
        except ValueError:
            raise ValueError(f"Invalid immediate value: {imm_str}")

    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        if len(ops) < expected:
            raise ValueError(f"{opcode} requires at least {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands

        # psq_st fS, offset(rA), 0, qr0
        self.validate_operand_count(ops, 2, opcode)

        try:
            src_fp = self.parse_fpregister(ops[0])
            offset_base = ops[1].split('(')
            if len(offset_base) != 2 or not offset_base[1].endswith(')'):
                raise ValueError(f"Invalid psq_st format: {ops[1]}")
            offset = self.parse_immediate(offset_base[0])
            base_reg = self.parse_register(offset_base[1].rstrip(')'))
            return [
                f"float temp = (float)gc_env.f[{src_fp}]; // psq_st f{src_fp}, 0x{offset:X}(r{base_reg})",
                f"gc_mem_write32(gc_env.ram, gc_env.r[{base_reg}] + 0x{offset:X}, *(uint32_t*)&temp);"
            ]
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    return PsqStHandler().handle(instruction)
