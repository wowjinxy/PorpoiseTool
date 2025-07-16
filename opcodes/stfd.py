"""
Handler for PowerPC stfd (Store Floating-Point Double) instruction.
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

opcodes = ['stfd']

class StfdHandler:
    """Handles PowerPC stfd instruction transpilation."""
    
    def __init__(self, transpiler: 'ModularTranspiler'):
        self.transpiler = transpiler
    
    def parse_fpregister(self, reg_str: str) -> int:
        """Parse floating-point register string to integer, handling 'f' prefix."""
        try:
            return int(reg_str.lstrip('fF').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid FP register: {reg_str}")
    
    def parse_register(self, reg_str: str) -> int:
        """Parse general-purpose register string to integer, handling 'r' prefix."""
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register: {reg_str}")
    
    def parse_immediate(self, imm_str: str) -> int:
        """Parse immediate value, handling hex/decimal formats."""
        try:
            return int(imm_str, 0)
        except ValueError:
            raise ValueError(f"Invalid immediate: {imm_str}")
    
    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
        """Handle stfd instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands
        
        self.validate_operand_count(ops, 2, opcode)
        
        try:
            src_fpreg = self.parse_fpregister(ops[0])
            offset_base = ops[1].split('(')
            if len(offset_base) != 2 or not offset_base[1].endswith(')'):
                raise ValueError(f"Invalid stfd format: {ops[1]}")
            
            offset = self.parse_immediate(offset_base[0])
            base_reg = self.parse_register(offset_base[1].rstrip(')'))
            offset_hex = format_hex(offset)
            
            if opcode == 'stfd':
                temp = transpiler.new_var('temp')
                return [
                    f"uint64_t {temp};",
                    f"memcpy(&{temp}, &gc_env.f[{src_fpreg}], sizeof(double));",
                    f"gc_mem_write64(gc_env.ram, gc_env.r[{base_reg}] + {offset_hex}, {temp}); // stfd f{src_fpreg}, {offset_hex}(r{base_reg})",
                ]
            
            return [f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"]
        
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for stfd instruction handling."""
    return StfdHandler(transpiler).handle(instruction, transpiler)
