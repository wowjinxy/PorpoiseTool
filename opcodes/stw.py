"""
Handler for PowerPC stw (Store Word) instruction.
"""

from typing import List, Tuple, Union

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

opcodes = ['stw']

class StwHandler:
    """Handles PowerPC stw instruction transpilation."""
    
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
        try:
            return int(imm_str, 0)
        except ValueError:
            raise ValueError(f"Invalid immediate: {imm_str}")
    
    def parse_memory_operand(self, mem_str: str) -> Tuple[Union[str, int], int, bool]:
        """
        Parse memory operand like 'offset(rN)', '(rN)', 'symbol@sda21(rN)', or 'symbol@l(rN)'.
        Returns (offset_or_symbol, base_register, is_sda_symbol).
        """
        mem_str = mem_str.strip()
        
        # Handle SDA relocation format (e.g., cm_804D6458@sda21(r0))
        if '@sda21(' in mem_str:
            sda_match = mem_str.split('@sda21(')
            if len(sda_match) == 2:
                symbol = sda_match[0]
                base_reg_part = sda_match[1].rstrip(')')
                base_reg = self.parse_register(base_reg_part)
                
                # Add the symbol as an external variable
                self.transpiler.variables.add(f"extern uint32_t {symbol}")
                
                return symbol, base_reg, True
        
        # Handle @l (low) relocation format (e.g., cm_80452C68@l(r5))
        if '@l(' in mem_str:
            l_match = mem_str.split('@l(')
            if len(l_match) == 2:
                symbol = l_match[0]
                base_reg_part = l_match[1].rstrip(')')
                base_reg = self.parse_register(base_reg_part)
                
                # Add the symbol as an external variable
                self.transpiler.variables.add(f"extern uint32_t {symbol}")
                
                return symbol, base_reg, False  # Not SDA, but symbol-based
        
        # Handle @h (high) relocation format (e.g., symbol@h(rN))
        if '@h(' in mem_str:
            h_match = mem_str.split('@h(')
            if len(h_match) == 2:
                symbol = h_match[0]
                base_reg_part = h_match[1].rstrip(')')
                base_reg = self.parse_register(base_reg_part)
                
                # Add the symbol as an external variable
                self.transpiler.variables.add(f"extern uint32_t {symbol}")
                
                return symbol, base_reg, False  # Not SDA, but symbol-based
        
        # Handle preprocessed SDA format (e.g., sda:symbol)
        if mem_str.startswith('sda:'):
            # This shouldn't happen with stw typically, but handle it just in case
            symbol = mem_str[4:].strip()
            self.transpiler.variables.add(f"extern uint32_t {symbol}")
            return symbol, 0, True
        
        # Handle regular memory operand format
        if not ('(' in mem_str and ')' in mem_str):
            raise ValueError(f"Invalid memory operand format: {mem_str}")
        
        parts = mem_str.split('(', 1)
        offset_str = parts[0].strip()
        base_part = parts[1].rstrip(')')
        
        if offset_str:
            offset = self.parse_immediate(offset_str)
        else:
            offset = 0
        
        base_reg = self.parse_register(base_part)
        return offset, base_reg, False
    
    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")
    
    def generate_memory_access(self, opcode: str, src_reg: int, offset_or_symbol: Union[str, int], base_reg: int, is_sda: bool) -> List[str]:
        """Generate memory access code for stw."""
        if is_sda:
            symbol = offset_or_symbol
            if base_reg == 0:  # r0 means absolute SDA access
                return [f"{symbol} = gc_env.r[{src_reg}]; // {opcode} r{src_reg}, {symbol}@sda21(r0)"]
            else:
                return [f"gc_mem_write32(gc_env.ram, gc_env.r[{base_reg}] + (uint32_t)&{symbol}, gc_env.r[{src_reg}]); // {opcode} r{src_reg}, {symbol}@sda21(r{base_reg})"]
        elif isinstance(offset_or_symbol, str):
            # Handle symbol-based addressing (@l, @h relocations)
            symbol = offset_or_symbol
            if base_reg == 0:
                return [f"gc_mem_write32(gc_env.ram, (uint32_t)&{symbol}, gc_env.r[{src_reg}]); // {opcode} r{src_reg}, {symbol}@l/h(r0)"]
            else:
                return [f"gc_mem_write32(gc_env.ram, gc_env.r[{base_reg}] + (uint32_t)&{symbol}, gc_env.r[{src_reg}]); // {opcode} r{src_reg}, {symbol}@l/h(r{base_reg})"]
        else:
            offset = offset_or_symbol
            if offset == 0:
                return [f"gc_mem_write32(gc_env.ram, gc_env.r[{base_reg}], gc_env.r[{src_reg}]); // {opcode} r{src_reg}, (r{base_reg})"]
            else:
                return [f"gc_mem_write32(gc_env.ram, gc_env.r[{base_reg}] + 0x{offset:X}, gc_env.r[{src_reg}]); // {opcode} r{src_reg}, 0x{offset:X}(r{base_reg})"]

    def handle(self, instruction: Instruction) -> List[str]:
        """Handle stw instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands
        
        print(f"Processing opcode: {opcode}, operands: {ops}")
        
        try:
            self.validate_operand_count(ops, 2, opcode)
            src_reg = self.parse_register(ops[0])
            offset_or_symbol, base_reg, is_sda = self.parse_memory_operand(ops[1])
            return self.generate_memory_access(opcode, src_reg, offset_or_symbol, base_reg, is_sda)
        
        except (ValueError, IndexError) as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for stw instruction handling."""
    return StwHandler(transpiler).handle(instruction)