"""
Handler for PowerPC addi instruction.
"""

from typing import List, Optional

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

opcodes = ['addi']

class AddiHandler:
    """Handles PowerPC addi instruction transpilation."""
    
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
    
    def extract_symbol(self, operand: str) -> tuple[str, str, int]:
        """Extract symbol name, suffix and addend from operands like 'sym+0x4@l'."""
        operand = operand.strip()
        suffix = ''
        if operand.endswith('@l'):
            suffix = '@l'
            operand = operand[:-2]
        elif operand.endswith('@ha'):
            suffix = '@ha'
            operand = operand[:-3]
        elif operand.endswith('@h'):
            suffix = '@h'
            operand = operand[:-2]
        operand = operand.strip('"')
        addend = 0
        if '+' in operand or '-' in operand[1:]:
            import re
            m = re.match(r'([^+-]+)([+-]0x[0-9A-Fa-f]+)', operand)
            if m:
                operand = m.group(1)
                addend = int(m.group(2), 0)
        return operand, suffix, addend
    
    def clean_symbol_name(self, symbol: str) -> str:
        """Clean up symbol names by replacing invalid C characters."""
        symbol = symbol.replace('*bss*', '_bss_')
        symbol = symbol.replace('*', '_')
        return self.transpiler.sanitize_symbol_name(symbol)
    
    def check_lis_pattern(self, src_reg: int, symbol: str, addend: int) -> bool:
        """Check if previous instruction was a matching lis instruction."""
        if not hasattr(self.transpiler, 'previous_instruction') or not self.transpiler.previous_instruction:
            return False
        prev = self.transpiler.previous_instruction
        if prev.opcode.lower() != 'lis' or len(prev.operands) < 2:
            return False
        try:
            prev_dst = self.parse_register(prev.operands[0])
            prev_symbol, prev_suffix, prev_add = self.extract_symbol(prev.operands[1])
            prev_symbol_clean = self.clean_symbol_name(prev_symbol)
            symbol_clean = self.clean_symbol_name(symbol)
            return (prev_symbol_clean == symbol_clean and prev_add == addend and
                    prev_suffix in ('@h', '@ha') and src_reg == prev_dst)
        except (ValueError, IndexError):
            return False
    
    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        """Handle addi instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands
        
        print(f"Processing opcode: {opcode}, operands: {ops}")
        
        try:
            self.validate_operand_count(ops, 3, opcode)
            dst_reg = self.parse_register(ops[0])
            src_reg = self.parse_register(ops[1])
            value = ops[2].strip()
            
            symbol, suffix, addend = self.extract_symbol(value)
            if suffix == '@l':
                symbol_clean = self.clean_symbol_name(symbol)
                if self.check_lis_pattern(src_reg, symbol, addend):
                    expr = f"(uint32_t)&{symbol_clean}"
                    if addend:
                        expr = f"{expr} + {addend}"
                    if hasattr(self.transpiler, 'replace_previous_and_current'):
                        self.transpiler.replace_previous_and_current(
                            f"gc_env.r[{dst_reg}] = {expr}; // lis + addi {symbol}"
                        )
                        return []
                    elif hasattr(self.transpiler, 'replace_previous_instruction'):
                        self.transpiler.replace_previous_instruction(
                            f"gc_env.r[{dst_reg}] = {expr}; // lis + addi {symbol}"
                        )
                        return []
                    else:
                        return [f"gc_env.r[{dst_reg}] = {expr}; // lis + addi {symbol} (completing pattern)"]
                else:
                    expr = f"((uint32_t)&{symbol_clean} + {addend})" if addend else f"((uint32_t)&{symbol_clean} & 0xFFFF)"
                    return [f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg}] + {expr}; // addi r{dst_reg}, r{src_reg}, {value}"]
            
            try:
                imm = self.parse_immediate(value)
                if src_reg == 0:
                    return [f"gc_env.r[{dst_reg}] = {imm}; // li r{dst_reg}, {value} (addi r{dst_reg}, r0, {value})"]
                if dst_reg == src_reg and imm != 0:
                    if imm > 0:
                        return [f"gc_env.r[{dst_reg}] += {imm}; // addi r{dst_reg}, r{src_reg}, {value}"]
                    else:
                        return [f"gc_env.r[{dst_reg}] -= {-imm}; // addi r{dst_reg}, r{src_reg}, {value}"]
                else:
                    return [f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg}] + {imm}; // addi r{dst_reg}, r{src_reg}, {value}"]
            except ValueError:
                return [f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg}] + {value}; // addi r{dst_reg}, r{src_reg}, {value}"]
        
        except (ValueError, IndexError) as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for addi instruction handling."""
    return AddiHandler(transpiler).handle(instruction)