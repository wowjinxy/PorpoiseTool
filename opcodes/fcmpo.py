"""
Handler for PowerPC fcmpo (Floating-Point Compare Ordered) instruction.
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

opcodes = ['fcmpo']

class FcmpoHandler:
    """Handles PowerPC fcmpo instruction transpilation."""
    
    def __init__(self, transpiler: 'ModularTranspiler'):
        self.transpiler = transpiler
    
    def parse_fpregister(self, reg_str: str) -> int:
        """Parse floating-point register string to integer, handling 'f' prefix."""
        try:
            return int(reg_str.lstrip('fF').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid FP register: {reg_str}")
    
    def parse_crfield(self, cr_str: str) -> int:
        """Parse condition register field string to integer, handling 'cr' prefix."""
        try:
            return int(cr_str.lstrip('cr').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid CR field: {cr_str}")
    
    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        """Handle fcmpo instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands
        
        self.validate_operand_count(ops, 3, opcode)
        
        try:
            cr_field = self.parse_crfield(ops[0])
            src_a_fpreg = self.parse_fpregister(ops[1])
            src_b_fpreg = self.parse_fpregister(ops[2])
            
            if opcode == 'fcmpo':
                return [
                    f"gc_env.cr[{cr_field}] = isnan(gc_env.f[{src_a_fpreg}]) || isnan(gc_env.f[{src_b_fpreg}]) ? 0x1 : (gc_env.f[{src_a_fpreg}] < gc_env.f[{src_b_fpreg}] ? 0x8 : (gc_env.f[{src_a_fpreg}] > gc_env.f[{src_b_fpreg}] ? 0x4 : 0x2)); // fcmpo cr{cr_field}, f{src_a_fpreg}, f{src_b_fpreg}"
                ]
            
            return [f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"]
        
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for fcmpo instruction handling."""
    return FcmpoHandler(transpiler).handle(instruction)