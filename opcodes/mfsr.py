"""
Handler for PowerPC mfsr (Move from Segment Register) instruction.
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

opcodes = ['mfsr']

class MfsrHandler:
    """Handles PowerPC mfsr instruction transpilation."""

    def __init__(self, transpiler: 'ModularTranspiler'):
        self.transpiler = transpiler

    def parse_register(self, reg_str: str) -> int:
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register format: {reg_str}")

    def parse_sr_index(self, sr_str: str) -> int:
        try:
            return int(sr_str.rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid SR index: {sr_str}")

    def handle(self, instruction: Instruction) -> List[str]:
        ops = instruction.operands
        if len(ops) == 1 and ' ' in ops[0]:
            ops = [o for o in ops[0].replace(',', ' ').split() if o]
        if len(ops) < 2:
            return [f"// Error processing mfsr {' '.join(ops)}: insufficient operands"]
        try:
            dst_reg = self.parse_register(ops[0])
            sr_idx = self.parse_sr_index(ops[1])
            if 0 <= sr_idx < 16:
                return [f"gc_env.r[{dst_reg}] = gc_env.sr[{sr_idx}]; // mfsr r{dst_reg}, {sr_idx}"]
            return [f"// Invalid SR index {sr_idx} for mfsr"]
        except ValueError as e:
            return [f"// Error processing mfsr {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    return MfsrHandler(transpiler).handle(instruction)
