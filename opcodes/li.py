"""
Handler for PowerPC li instruction.
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

opcodes = ['li']

class LiHandler:
    """Handles PowerPC li instruction transpilation."""
    
    def parse_register(self, reg_str: str) -> int:
        """Parse register string to integer, handling 'r' prefix."""
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register format: {reg_str}")
    
    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) != expected:
            raise ValueError(f"{opcode} expects {expected} operands, got {len(ops)}")

    def process_sda_symbol(self, value: str, transpiler=None) -> str:
        """Process SDA symbols and return appropriate C code."""
        if value.startswith("sda:"):
            symbol_name = value[4:]  # Remove "sda:" prefix
            # For SDA symbols, we need to get the address relative to the SDA base
            # This is typically done by taking the address of the symbol
            if transpiler:
                transpiler.variables.add(f"extern uint32_t {symbol_name}")
            return f"(uint32_t)&{symbol_name}"
        elif "@sda21" in value:
            # Handle raw @sda21 syntax
            symbol_name = value.split("@sda21")[0]
            if transpiler:
                transpiler.variables.add(f"extern uint32_t {symbol_name}")
            return f"(uint32_t)&{symbol_name}"
        return value

    def handle(self, instruction: Instruction, transpiler=None) -> List[str]:
        """Handle li instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands
        
        print(f"Processing opcode: {opcode}, operands: {ops}")
        
        try:
            self.validate_operand_count(ops, 2, opcode)
            dst_reg = self.parse_register(ops[0])
            value = ops[1].strip()
            
            # Process SDA symbols
            processed_value = self.process_sda_symbol(value, transpiler)
            
            return [f"gc_env.r[{dst_reg}] = {processed_value}; // {opcode} r{dst_reg}, {value}"]
        
        except (ValueError, IndexError) as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for li instruction handling."""
    return LiHandler().handle(instruction)