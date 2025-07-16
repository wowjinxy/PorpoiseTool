"""
Handler for PowerPC lfd (Load Floating-Point Double) instruction.
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

opcodes = ['lfd']

class LfdHandler:
    """Handles PowerPC lfd instruction transpilation."""
    
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
        """Handle lfd instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands
        
        self.validate_operand_count(ops, 2, opcode)
        
        try:
            dst_fpreg = self.parse_fpregister(ops[0])
            
            # Check for SDA symbol (e.g., sda:cm_804D7E18)
            if ops[1].startswith('sda:'):
                symbol = self.transpiler.sanitize_symbol_name(ops[1][4:].strip())
                return [f"gc_env.f[{dst_fpreg}] = {symbol}; // lfd f{dst_fpreg}, {symbol}@sda21(r0)"]
            
            # Handle direct SDA relocation format (e.g., cm_804D7E18@sda21(r0))
            if '@sda21(' in ops[1]:
                sda_match = ops[1].split('@sda21(')
                if len(sda_match) == 2:
                    symbol = self.transpiler.sanitize_symbol_name(sda_match[0])
                    base_reg_part = sda_match[1].rstrip(')')
                    base_reg = self.parse_register(base_reg_part)
                    
                    # Add the symbol as an external variable
                    self.transpiler.variables.add(f"extern double {symbol}")
                    
                    if base_reg == 0:  # r0 means absolute SDA access
                        return [f"gc_env.f[{dst_fpreg}] = *(double*)&{symbol}; // lfd f{dst_fpreg}, {symbol}@sda21(r0)"]
                    else:
                        return [f"gc_env.f[{dst_fpreg}] = *((double*)(gc_env.r[{base_reg}] + (uint32_t)&{symbol})); // lfd f{dst_fpreg}, {symbol}@sda21(r{base_reg})"]
                
            # Handle numeric offset (e.g., 0x2bc(r3))
            if '(' in ops[1] and ops[1].endswith(')'):
                offset_base = ops[1].split('(')
                if len(offset_base) == 2:
                    offset = self.parse_immediate(offset_base[0])
                    base_reg = self.parse_register(offset_base[1].rstrip(')'))
                    offset_hex = format_hex(offset)
                    
                    temp = transpiler.new_var('temp')
                    return [
                        f"uint64_t {temp} = gc_mem_read64(gc_env.ram, gc_env.r[{base_reg}] + {offset_hex}); // lfd f{dst_fpreg}, {offset_hex}(r{base_reg})",
                        f"gc_env.f[{dst_fpreg}] = *(double*)&{temp};"
                    ]
            
            # If we get here, the format wasn't recognized
            raise ValueError(f"Unrecognized lfd operand format: {ops[1]}")
            
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for lfd instruction handling."""
    return LfdHandler(transpiler).handle(instruction, transpiler)