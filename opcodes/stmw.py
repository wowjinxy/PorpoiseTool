"""
Handler for PowerPC stmw (Store Multiple Word) instruction.
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

opcodes = ['stmw']

class StmwHandler:
    """Handles PowerPC stmw instruction transpilation."""
    
    def __init__(self, transpiler: 'ModularTranspiler'):
        self.transpiler = transpiler
    
    def parse_register(self, reg_str: str) -> int:
        """Parse register string to integer, handling 'r' prefix."""
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register format: {reg_str}")
    
    def parse_immediate(self, imm_str: str) -> int:
        """Parse immediate value, handling hex/decimal formats."""
        imm_str = imm_str.strip()
        try:
            return int(imm_str, 0)
        except ValueError:
            raise ValueError(f"Invalid immediate value: {imm_str}")
    
    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) < expected:
            raise ValueError(f"{opcode} requires at least {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        """Handle stmw instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands
        
        self.validate_operand_count(ops, 2, opcode)
        
        try:
            # Parse operands: stmw rS, offset(rA)
            first_reg = self.parse_register(ops[0])
            offset_base = ops[1].split('(')
            if len(offset_base) != 2 or not offset_base[1].endswith(')'):
                raise ValueError(f"Invalid stmw format: {ops[1]}")
            
            offset = self.parse_immediate(offset_base[0])
            base_reg = self.parse_register(offset_base[1].rstrip(')'))
            offset_hex = format_hex(offset)
            
            if opcode == 'stmw':
                result = []
                # Store registers from rS to r31
                for reg in range(first_reg, 32):
                    addr_offset = offset + (reg - first_reg) * 4
                    result.append(f"gc_mem_write32(gc_env.ram, gc_env.r[{base_reg}] + {format_hex(addr_offset)}, gc_env.r[{reg}]); // stmw r{first_reg}, {offset_hex}(r{base_reg})")
                return result
            
            return [f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"]
        
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for stmw instruction handling."""
    return StmwHandler(transpiler).handle(instruction)