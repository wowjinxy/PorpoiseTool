"""
Handler for PowerPC rlwimi (Rotate Left Word Immediate then Mask Insert) instruction.
"""

from typing import List
from utils import format_hex

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

opcodes = ['rlwimi']

class RlwimiHandler:
    """Handles PowerPC rlwimi instruction transpilation."""
    
    def __init__(self, transpiler: 'ModularTranspiler'):
        self.transpiler = transpiler
    
    def parse_register(self, reg_str: str) -> int:
        """Parse register string to integer, handling 'r' prefix."""
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register: {reg_str}")
    
    def parse_immediate(self, imm_str: str) -> int:
        """Parse immediate value, handling decimal formats."""
        try:
            return int(imm_str.strip())
        except ValueError:
            raise ValueError(f"Invalid immediate: {imm_str}")
    
    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        """Handle rlwimi instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands
        
        self.validate_operand_count(ops, 5, opcode)
        
        try:
            dst_reg = self.parse_register(ops[0])
            src_reg = self.parse_register(ops[1])
            sh = self.parse_immediate(ops[2])  # Shift amount
            mb = self.parse_immediate(ops[3])  # Mask begin
            me = self.parse_immediate(ops[4])  # Mask end
            
            if opcode == 'rlwimi':
                # Compute mask: 1s from mb to me (inclusive), 0s elsewhere
                mask = ((1 << (32 - mb)) - 1) ^ ((1 << (32 - me - 1)) - 1) if me >= mb else ((1 << (32 - mb)) - 1) | ~((1 << (32 - me - 1)) - 1)
                mask_hex = format_hex(mask)
                result = [
                    f"uint32_t rotated = gc_env.r[{src_reg}] << {sh}; // rlwimi r{dst_reg}, r{src_reg}, {sh}, {mb}, {me}",
                    f"gc_env.r[{dst_reg}] = (gc_env.r[{dst_reg}] & ~{mask_hex}) | (rotated & {mask_hex});"
                ]
                # Handle dot (.) for cr0 update
                if instruction.opcode.endswith('.'):
                    result.append(f"gc_env.cr[0] = (gc_env.r[{dst_reg}] == 0) ? 0x2 : ((int32_t)gc_env.r[{dst_reg}] < 0 ? 0x8 : 0x4);")
                return result
            
            return [f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"]
        
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for rlwimi instruction handling."""
    return RlwimiHandler(transpiler).handle(instruction)