"""
Handler for PowerPC ori (OR Immediate) instruction.
Handles ori instruction including @l modifier for loading low 16 bits.
Also handles lis + addi pattern detection.
"""

from typing import List, Optional, Tuple

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

opcodes = ['ori']

class OriHandler:
    """Handles PowerPC ori instruction transpilation."""
    
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
            return int(imm_str, 0)  # Handles 0x prefix automatically
        except ValueError:
            raise ValueError(f"Invalid immediate value: {imm_str}")
    
    def extract_symbol(self, operand: str) -> Tuple[str, str]:
        """Extract symbol name and suffix from operand like 'symbol@l'."""
        if operand.endswith('@l'):
            sym = operand[:-2].strip('"')
            return self.transpiler.sanitize_symbol_name(sym), '@l'
        elif operand.endswith('@h'):
            sym = operand[:-2].strip('"')
            return self.transpiler.sanitize_symbol_name(sym), '@h'
        elif operand.endswith('@ha'):
            sym = operand[:-3].strip('"')
            return self.transpiler.sanitize_symbol_name(sym), '@ha'
        sym = operand.strip('"')
        return self.transpiler.sanitize_symbol_name(sym), ''
    
    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) < expected:
            raise ValueError(f"{opcode} requires at least {expected} operands, got {len(ops)}")

    def check_lis_pattern(self, dst_reg: int, symbol: str) -> bool:
        """Check if previous instruction was a matching lis instruction."""
        if not hasattr(self.transpiler, 'previous_instruction') or not self.transpiler.previous_instruction:
            return False
            
        prev = self.transpiler.previous_instruction
        if prev.opcode.lower() != 'lis' or len(prev.operands) < 2:
            return False
            
        try:
            prev_dst = self.parse_register(prev.operands[0])
            prev_symbol, prev_suffix = self.extract_symbol(prev.operands[1])
            
            # Check if it's the same symbol and compatible registers
            # Note: lis + ori can use different destination registers
            return prev_symbol == symbol and prev_suffix in ('@h', '@ha')
        except (ValueError, IndexError):
            return False

    def handle(self, instruction: Instruction) -> List[str]:
        """Handle ori instruction."""
        opcode = instruction.opcode.lower()
        ops = instruction.operands
        
        self.validate_operand_count(ops, 3, opcode)
        
        try:
            dst_reg = self.parse_register(ops[0])
            src_reg = self.parse_register(ops[1])
            value = ops[2].strip()
            
            # Handle @l modifier (low 16 bits)
            symbol, suffix = self.extract_symbol(value)
            if suffix == '@l':
                # Check for lis + ori pattern
                if self.check_lis_pattern(dst_reg, symbol):
                    # Complete the lis + ori pattern
                    # Replace the incomplete lis instruction with complete address load
                    if hasattr(self.transpiler, 'replace_previous_instruction'):
                        self.transpiler.replace_previous_instruction(
                            f"gc_env.r[{dst_reg}] = (uint32_t)&{symbol}; // lis + ori {symbol}"
                        )
                        return []  # No additional instruction needed
                    else:
                        # Fallback: generate the complete instruction here
                        return [f"gc_env.r[{dst_reg}] = (uint32_t)&{symbol}; // lis + ori {symbol}"]
                else:
                    # Standalone ori with @l (OR with low 16 bits of symbol)
                    return [f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg}] | ((uint32_t)&{symbol} & 0xFFFF); // ori r{dst_reg}, r{src_reg}, {value}"]
            
            # Handle immediate values
            imm = self.parse_immediate(value)
            if dst_reg == src_reg:
                return [f"gc_env.r[{dst_reg}] |= {imm}; // ori r{dst_reg}, r{src_reg}, {value}"]
            else:
                return [f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg}] | {imm}; // ori r{dst_reg}, r{src_reg}, {value}"]
        
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for ori instruction handling."""
    return OriHandler(transpiler).handle(instruction)


# Additional helper class for better pattern detection
class PatternDetector:
    """Helper class to detect instruction patterns like lis+ori, lis+addi."""
    
    @staticmethod
    def is_address_load_pattern(prev_instr: Optional[Instruction], curr_instr: Instruction) -> Tuple[bool, str]:
        """
        Detect if current instruction completes an address loading pattern.
        Returns (is_pattern, pattern_type).
        """
        if not prev_instr:
            return False, ""
            
        prev_op = prev_instr.opcode.lower()
        curr_op = curr_instr.opcode.lower()
        
        if prev_op == 'lis':
            if curr_op in ['ori', 'addi']:
                # Check if they're working with the same symbol
                if len(prev_instr.operands) >= 2 and len(curr_instr.operands) >= 3:
                    try:
                        prev_symbol = prev_instr.operands[1].strip()
                        curr_symbol = curr_instr.operands[2].strip()
                        
                        # Extract base symbol names
                        prev_base = prev_symbol.replace('@ha', '').replace('@h', '')
                        curr_base = curr_symbol.replace('@l', '')
                        
                        if prev_base == curr_base:
                            return True, f"lis+{curr_op}"
                    except (IndexError, AttributeError):
                        pass
        
        return False, ""