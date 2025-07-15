"""
Handler for PowerPC mtsr (Move to Segment Register) instruction.
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

opcodes = ['mtsr']

class MtsrHandler:
    """Handles PowerPC mtsr instruction transpilation."""

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
            return [f"// Error processing mtsr {' '.join(ops)}: insufficient operands"]
        try:
            sr_idx = self.parse_sr_index(ops[0])
            src_reg = self.parse_register(ops[1])
            if 0 <= sr_idx < 16:
                return [f"gc_env.sr[{sr_idx}] = gc_env.r[{src_reg}]; // mtsr {sr_idx}, r{src_reg}"]
            return [f"// Invalid SR index {sr_idx} for mtsr"]
        except ValueError as e:
            return [f"// Error processing mtsr {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    return MtsrHandler(transpiler).handle(instruction)
