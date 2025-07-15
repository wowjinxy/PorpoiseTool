"""
Handler for PowerPC lbz (Load Byte and Zero) instruction.
"""

from typing import List, Tuple

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

opcodes = ['lbz']

class LbzHandler:
    """Handles PowerPC lbz instruction transpilation."""
    
    def parse_register(self, reg_str: str) -> int:
        """Parse register string to integer, handling 'r' prefix."""
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register format: {reg_str}")
    
    def process_offset(self, offset_str: str, transpiler=None) -> str:
        """Process offset, handling SDA symbols and immediate values."""
        offset_str = offset_str.strip()
        
        # Handle SDA symbols (both preprocessed and raw formats)
        if offset_str.startswith("sda:"):
            symbol_name = transpiler.sanitize_symbol_name(offset_str[4:])  # Remove "sda:" prefix
            if transpiler:
                transpiler.variables.add(f"extern uint8_t {symbol_name}")
            return f"(uint32_t)&{symbol_name}"
        elif "@sda21" in offset_str:
            # Handle raw @sda21 syntax
            symbol_name = transpiler.sanitize_symbol_name(offset_str.split("@sda21")[0])
            if transpiler:
                transpiler.variables.add(f"extern uint8_t {symbol_name}")
            return f"(uint32_t)&{symbol_name}"
        
        # Handle immediate values (hex, decimal, negative)
        if offset_str.startswith('0x') or offset_str.startswith('-0x'):
            return offset_str
        elif offset_str.lstrip('-').isdigit():
            return offset_str
        elif offset_str == "":
            return "0"
        
        # Handle other symbols (assume they're global variables or constants)
        sanitized = transpiler.sanitize_symbol_name(offset_str)
        if sanitized.isidentifier():
            if transpiler:
                transpiler.variables.add(f"extern uint32_t {sanitized}")
            return f"(uint32_t)&{sanitized}"
        
        # If we can't parse it, return as-is
        return offset_str
    
    def parse_memory_operand(self, mem_str: str, transpiler=None) -> Tuple[str, int]:
        """Parse memory operand like 'offset(rN)' or '(rN)'. Returns (processed_offset, base_register)."""
        mem_str = mem_str.strip()
        if not ('(' in mem_str and ')' in mem_str):
            raise ValueError(f"Invalid memory operand format: {mem_str}")
        parts = mem_str.split('(', 1)
        offset_str = parts[0].strip()
        base_part = parts[1].rstrip(')')
        
        # Process the offset (handle SDA symbols, etc.)
        processed_offset = self.process_offset(offset_str, transpiler)
        base_reg = self.parse_register(base_part)
        
        return processed_offset, base_reg
    
    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")
    
    def generate_memory_access(self, opcode: str, reg: int, offset: str, base_reg: int, original_offset: str = None) -> List[str]:
        """Generate memory access code for lbz."""
        comment_offset = original_offset if original_offset else offset
        
        # Special case: if base register is r0 and we have an SDA symbol, treat it as absolute address
        if base_reg == 0 and ("&" in offset or offset.startswith("(uint32_t)")):
            return [
                f"gc_env.r[{reg}] = gc_mem_read8(gc_env.ram, {offset}); // {opcode} r{reg}, {comment_offset}(r{base_reg})"
            ]
        else:
            return [
                f"gc_env.r[{reg}] = gc_mem_read8(gc_env.ram, gc_env.r[{base_reg}] + {offset}); // {opcode} r{reg}, {comment_offset}(r{base_reg})"
            ]

    def handle(self, instruction: Instruction, transpiler=None) -> List[str]:
        """Handle lbz instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands
        
        print(f"Processing opcode: {opcode}, operands: {ops}")
        
        try:
            self.validate_operand_count(ops, 2, opcode)
            dst_reg = self.parse_register(ops[0])
            
            # Store original operand for comment
            original_mem_operand = ops[1]
            
            # Parse and process the memory operand
            offset, base_reg = self.parse_memory_operand(ops[1], transpiler)
            
            # Extract original offset for comment
            original_offset = original_mem_operand.split('(')[0].strip() if '(' in original_mem_operand else "0"
            
            return self.generate_memory_access(opcode, dst_reg, offset, base_reg, original_offset)
        
        except (ValueError, IndexError) as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for lbz instruction handling."""
    return LbzHandler().handle(instruction, transpiler)