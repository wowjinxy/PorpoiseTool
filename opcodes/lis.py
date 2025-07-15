"""
Handler for PowerPC lis (Load Immediate Shifted) instruction.
Handles both standalone lis and proper pattern detection for lis + addi/ori.
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

opcodes = ['lis']

class LisHandler:
    """Handles PowerPC lis instruction transpilation."""
    
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
    
    def extract_symbol(self, operand: str) -> tuple[str, str]:
        """Extract symbol name and suffix from operand like 'symbol@h'."""
        if operand.endswith('@ha'):
            sym = operand[:-3].strip('"')
            return self.transpiler.sanitize_symbol_name(sym), '@ha'
        elif operand.endswith('@h'):
            sym = operand[:-2].strip('"')
            return self.transpiler.sanitize_symbol_name(sym), '@h'
        sym = operand.strip('"')
        return self.transpiler.sanitize_symbol_name(sym), ''
    
    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) < expected:
            raise ValueError(f"{opcode} requires at least {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        """Handle lis instruction."""
        opcode = instruction.opcode.lower()
        ops = instruction.operands
        
        self.validate_operand_count(ops, 2, opcode)
        
        try:
            dst_reg = self.parse_register(ops[0])
            value = ops[1].strip()
            
            # Handle @h or @ha modifier (high 16 bits)
            symbol, suffix = self.extract_symbol(value)
            if suffix in ('@h', '@ha'):
                # Store this as a pending instruction for pattern matching
                if hasattr(self.transpiler, 'set_pending_lis'):
                    # Modern pattern-aware transpiler
                    self.transpiler.set_pending_lis({
                        'dst_reg': dst_reg,
                        'symbol': symbol,
                        'suffix': suffix,
                        'full_operand': value
                    })
                    # Generate placeholder that can be replaced
                    return [f"__LIS_PENDING__{dst_reg}__{symbol}__"]
                else:
                    # Fallback: generate standalone lis instruction
                    # This loads the high 16 bits of the symbol address
                    return [f"gc_env.r[{dst_reg}] = ((uint32_t)&{symbol} >> 16) & 0xFFFF; // lis r{dst_reg}, {value}"]
            
            # Handle immediate values
            imm = self.parse_immediate(value)
            # Sign-extend 16-bit immediate if necessary
            if imm > 0x7FFF:
                imm = imm - 0x10000  # Convert to signed
            return [f"gc_env.r[{dst_reg}] = {imm} << 16; // lis r{dst_reg}, {value}"]
        
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for lis instruction handling."""
    return LisHandler(transpiler).handle(instruction)


# Alternative simpler approach - always generate working C code
class SimpleLisHandler:
    """Simplified LIS handler that always generates working C code."""
    
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
    
    def extract_symbol(self, operand: str) -> tuple[str, str]:
        """Extract symbol name and suffix from operand."""
        if operand.endswith('@ha'):
            sym = operand[:-3].strip('"')
            return self.transpiler.sanitize_symbol_name(sym), '@ha'
        elif operand.endswith('@h'):
            sym = operand[:-2].strip('"')
            return self.transpiler.sanitize_symbol_name(sym), '@h'
        sym = operand.strip('"')
        return self.transpiler.sanitize_symbol_name(sym), ''
    
    def handle(self, instruction: Instruction) -> List[str]:
        """Handle lis instruction - always generate working C code."""
        ops = instruction.operands
        
        if len(ops) < 2:
            return [f"// Error: lis requires 2 operands, got {len(ops)}"]
        
        try:
            dst_reg = self.parse_register(ops[0])
            value = ops[1].strip()
            
            # Handle symbol references
            symbol, suffix = self.extract_symbol(value)
            if suffix in ('@h', '@ha'):
                # Generate working C code that loads high 16 bits
                return [f"gc_env.r[{dst_reg}] = ((uint32_t)&{symbol} >> 16) & 0xFFFF; // lis r{dst_reg}, {value}"]
            
            # Handle immediate values
            imm = self.parse_immediate(value)
            # Handle negative values properly
            if imm > 0x7FFF:
                imm = imm - 0x10000
            return [f"gc_env.r[{dst_reg}] = {imm} << 16; // lis r{dst_reg}, {value}"]
        
        except ValueError as e:
            return [f"// Error processing lis: {str(e)}"]


# Quick fix function to replace the problematic line in your output
def fix_broken_lis_line(c_code: str) -> str:
    """
    Quick fix to replace broken lis+addi patterns in generated C code.
    This is a temporary solution until proper pattern detection is implemented.
    """
    import re
    
    # Pattern to match broken lines like:
    # gc_env.r[6] = gc_env.r[6] + InitMetroTRK@l;
    pattern = r'gc_env\.r\[(\d+)\]\s*=\s*gc_env\.r\[\d+\]\s*\+\s*(\w+)@l;'
    
    def replace_broken_pattern(match):
        reg_num = match.group(1)
        symbol = match.group(2)
        return f'gc_env.r[{reg_num}] = (uint32_t)&{symbol}; // lis + addi {symbol}'
    
    # Replace the broken pattern
    fixed_code = re.sub(pattern, replace_broken_pattern, c_code)
    
    # Also fix comment-only lines that should be replaced
    comment_pattern = r'//\s*lis\s+r(\d+),\s*(\w+)@ha\s*\(waiting for ori @l\)'
    def replace_comment(match):
        reg_num = match.group(1)
        symbol = match.group(2)
        return f'gc_env.r[{reg_num}] = ((uint32_t)&{symbol} >> 16) & 0xFFFF; // lis r{reg_num}, {symbol}@ha'
    
    fixed_code = re.sub(comment_pattern, replace_comment, fixed_code)
    
    return fixed_code
