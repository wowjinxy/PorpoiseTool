"""
Handler for PowerPC xor (Exclusive OR) instruction.
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

opcodes = ['xor']

class XorHandler:
    """Handles PowerPC xor instruction transpilation."""
    
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
        """Handle xor instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands
        
        self.validate_operand_count(ops, 3, opcode)
        
        try:
            dst_reg = self.parse_register(ops[0])
            src_a_reg = self.parse_register(ops[1])
            src_b_reg = self.parse_register(ops[2])
            
            if opcode == 'xor':
                return [
                    f"gc_env.r[{dst_reg}] = gc_env.r[{src_a_reg}] ^ gc_env.r[{src_b_reg}]; // xor r{dst_reg}, r{src_a_reg}, r{src_b_reg}"
                ]
            
            return [f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"]
        
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for xor instruction handling."""
    return XorHandler(transpiler).handle(instruction)