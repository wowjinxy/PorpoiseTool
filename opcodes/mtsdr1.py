"""
Handler for PowerPC mtsdr1 (Move to SDR1) instruction.
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

opcodes = ['mtsdr1']

class Mtsdr1Handler:
    """Handles PowerPC mtsdr1 instruction transpilation."""

    def parse_register(self, reg_str: str) -> int:
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register format: {reg_str}")

    def handle(self, instruction: Instruction) -> List[str]:
        ops = instruction.operands
        if len(ops) == 1 and ' ' in ops[0]:
            ops = [o for o in ops[0].replace(',', ' ').split() if o]
        if len(ops) < 1:
            return [f"// Error processing mtsdr1 {' '.join(ops)}: insufficient operands"]
        try:
            src_reg = self.parse_register(ops[0])
            return [f"gc_env.sdr1 = gc_env.r[{src_reg}]; // mtsdr1 r{src_reg}"]
        except ValueError as e:
            return [f"// Error processing mtsdr1 {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    return Mtsdr1Handler().handle(instruction)
