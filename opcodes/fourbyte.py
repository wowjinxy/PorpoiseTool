"""
Handler for PowerPC .4byte directive.
Simply emits a comment in generated C code.
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

opcodes = ['.4byte']

class FourByteHandler:
    """Handles .4byte directive transpilation."""

    def handle(self, instruction: Instruction) -> List[str]:
        opcode = instruction.opcode
        ops = instruction.operands
        value = ops[0] if ops else ''
        return [f"// .4byte {value}"]


def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for .4byte directive handling."""
    return FourByteHandler().handle(instruction)
