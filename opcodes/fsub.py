"""
Handler for PowerPC fsub (Floating-Point Subtract) instruction.
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

opcodes = ['fsub']

class FsubHandler:
    """Handles PowerPC fsub instruction transpilation."""

    def __init__(self, transpiler: 'ModularTranspiler'):
        self.transpiler = transpiler

    def parse_fpregister(self, reg_str: str) -> int:
        """Parse floating-point register string to integer, handling 'f' prefix."""
        try:
            return int(reg_str.lstrip('fF').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid FP register: {reg_str}")

    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        """Handle fsub instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands

        self.validate_operand_count(ops, 3, opcode)

        try:
            dst_fpreg = self.parse_fpregister(ops[0])
            src_a_fpreg = self.parse_fpregister(ops[1])
            src_b_fpreg = self.parse_fpregister(ops[2])

            if opcode == 'fsub':
                return [
                    f"gc_env.f[{dst_fpreg}] = gc_env.f[{src_a_fpreg}] - gc_env.f[{src_b_fpreg}]; // fsub f{dst_fpreg}, f{src_a_fpreg}, f{src_b_fpreg}"
                ]

            return [f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"]

        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for fsub instruction handling."""
    return FsubHandler(transpiler).handle(instruction)
