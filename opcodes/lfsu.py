"""
Handler for PowerPC lfsu (Load Floating-Point Single with Update) instruction.
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

opcodes = ['lfsu']

class LfsuHandler:
    """Handles PowerPC lfsu instruction transpilation."""
    
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
        """Handle lfsu instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands
        
        self.validate_operand_count(ops, 2, opcode)
        
        try:
            dst_fpreg = self.parse_fpregister(ops[0])
            offset_base = ops[1].split('(')
            if len(offset_base) != 2 or not offset_base[1].endswith(')'):
                raise ValueError(f"Invalid lfsu format: {ops[1]}")
            
            offset = self.parse_immediate(offset_base[0])
            base_reg = self.parse_register(offset_base[1].rstrip(')'))
            offset_hex = format_hex(offset)
            
            if opcode == 'lfsu':
                temp = self.transpiler.new_var('temp')
                return [
                    f"uint32_t {temp} = gc_mem_read32(gc_env.ram, gc_env.r[{base_reg}] + {offset_hex}); // lfsu f{dst_fpreg}, {offset_hex}(r{base_reg})",
                    f"gc_env.f[{dst_fpreg}] = *(float*)&{temp};",
                    f"gc_env.r[{base_reg}] = gc_env.r[{base_reg}] + {offset_hex};",
                ]
            
            return [f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"]
        
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for lfsu instruction handling."""
    return LfsuHandler(transpiler).handle(instruction, transpiler)
