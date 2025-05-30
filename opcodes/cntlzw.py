"""
Handler for PowerPC cntlzw (Count Leading Zeros Word) instruction.
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

opcodes = ['cntlzw']

class CntlzwHandler:
    """Handles PowerPC cntlzw instruction transpilation."""
    
    def __init__(self, transpiler: 'ModularTranspiler'):
        self.transpiler = transpiler
    
    def parse_register(self, reg_str: str) -> int:
        """Parse register string to integer, handling 'r' prefix."""
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register: {reg_str}")
    
    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        """Handle cntlzw instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands
        
        self.validate_operand_count(ops, 2, opcode)
        
        try:
            dst_reg = self.parse_register(ops[0])
            src_reg = self.parse_register(ops[1])
            
            if opcode == 'cntlzw':
                return [
                    f"uint32_t val = gc_env.r[{src_reg}]; int count = 0; while (val && !(val & 0x80000000)) {{ val <<= 1; count++; }} gc_env.r[{dst_reg}] = count; // cntlzw r{dst_reg}, r{src_reg}"
                ]
            
            return [f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"]
        
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for cntlzw instruction handling."""
    return CntlzwHandler(transpiler).handle(instruction)