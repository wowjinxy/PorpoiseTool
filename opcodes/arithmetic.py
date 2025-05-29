"""
Arithmetic operations handler for PowerPC assembly - Fixed version
"""

from typing import List, Optional, Union

# Handle import for both package and standalone execution
try:
    from . import Instruction
except ImportError:
    # Fallback for standalone execution
    try:
        from instruction import Instruction
    except ImportError:
        # If neither works, define a minimal class for type hints
        class Instruction:
            def __init__(self):
                self.opcode = ""
                self.operands = []

opcodes = [
    'add', 'addi', 'addis', 'sub', 'subi', 'subis',
    'mulli', 'mullw', 'divw', 'divwu', 'lis', 'li'
]


class ArithmeticHandler:
    """Handles PowerPC arithmetic instruction transpilation."""
    
    def __init__(self, transpiler: 'ModularTranspiler'):
        self.transpiler = transpiler
    
    def parse_register(self, reg_str: str) -> int:
        """Parse register string to integer, handling 'r' prefix."""
        try:
            return int(reg_str.lstrip('rR'))
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
            return operand[:-3], '@ha'
        elif operand.endswith('@h'):
            return operand[:-2], '@h'
        elif operand.endswith('@l'):
            return operand[:-2], '@l'
        return operand, ''
    
    def handle_symbol_reference(self, dst_reg: int, current_operand: str) -> Optional[str]:
        """
        Handle lis/addi symbol reference pattern.
        Returns C code if pattern matches, None otherwise.
        """
        if not current_operand.endswith('@l'):
            return None
        
        # Check if transpiler has previous_instruction attribute
        if not hasattr(self.transpiler, 'previous_instruction') or not self.transpiler.previous_instruction:
            return None
        
        prev = self.transpiler.previous_instruction
        if prev.opcode.lower() != 'lis' or len(prev.operands) < 2:
            return None
        
        # Check if previous lis targets the same register as current addi source
        try:
            prev_dst = self.parse_register(prev.operands[0])
            if prev_dst != dst_reg:  # For addi r3, r3, symbol@l pattern
                return None
        except ValueError:
            return None
        
        # Extract symbols and check if they match
        current_symbol, _ = self.extract_symbol(current_operand)
        prev_symbol, prev_suffix = self.extract_symbol(prev.operands[1])
        
        if (current_symbol == prev_symbol and 
            prev_suffix in ('@h', '@ha')):
            return f"gc_env.r[{dst_reg}] = (uint32_t)&{current_symbol};"
        
        return None
    
    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) < expected:
            raise ValueError(f"{opcode} requires at least {expected} operands, got {len(ops)}")


def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Handle arithmetic operations with improved structure."""
    handler = ArithmeticHandler(transpiler)
    opcode = instruction.opcode.lower().rstrip('.')
    ops = instruction.operands
    
    print(f"Processing opcode: {opcode}, operands: {ops}")
    
    try:
        if opcode == 'li':
            handler.validate_operand_count(ops, 2, opcode)
            dst_reg = handler.parse_register(ops[0])
            value = ops[1].strip()
            return [f"gc_env.r[{dst_reg}] = {value};"]
        
        elif opcode == 'lis':
            handler.validate_operand_count(ops, 2, opcode)
            dst_reg = handler.parse_register(ops[0])
            value = ops[1].strip()
            
            symbol, suffix = handler.extract_symbol(value)
            if suffix in ('@h', '@ha'):
                return [f"// lis r{dst_reg}, {value} (waiting for @l)"]
            else:
                imm = handler.parse_immediate(value)
                return [f"gc_env.r[{dst_reg}] = {imm} << 16;"]
        
        elif opcode == 'addi':
            handler.validate_operand_count(ops, 3, opcode)
            dst_reg = handler.parse_register(ops[0])
            src_reg = handler.parse_register(ops[1])
            imm_str = ops[2].strip()
            
            # Check for symbol reference pattern
            symbol_code = handler.handle_symbol_reference(dst_reg, imm_str)
            if symbol_code:
                return [symbol_code]
            
            # Regular immediate addition
            return [f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg}] + {imm_str};"]
        
        elif opcode == 'addis':
            handler.validate_operand_count(ops, 3, opcode)
            dst_reg = handler.parse_register(ops[0])
            src_reg = handler.parse_register(ops[1])
            imm = handler.parse_immediate(ops[2])
            return [f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg}] + ({imm} << 16);"]
        
        elif opcode == 'add':
            handler.validate_operand_count(ops, 3, opcode)
            dst_reg = handler.parse_register(ops[0])
            src_reg1 = handler.parse_register(ops[1])
            src_reg2 = handler.parse_register(ops[2])
            return [f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg1}] + gc_env.r[{src_reg2}];"]
        
        elif opcode == 'sub':
            handler.validate_operand_count(ops, 3, opcode)
            dst_reg = handler.parse_register(ops[0])
            src_reg1 = handler.parse_register(ops[1])
            src_reg2 = handler.parse_register(ops[2])
            return [f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg1}] - gc_env.r[{src_reg2}];"]
        
        elif opcode == 'subi':
            handler.validate_operand_count(ops, 3, opcode)
            dst_reg = handler.parse_register(ops[0])
            src_reg = handler.parse_register(ops[1])
            imm = handler.parse_immediate(ops[2])
            return [f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg}] - {imm};"]
        
        elif opcode == 'subis':
            handler.validate_operand_count(ops, 3, opcode)
            dst_reg = handler.parse_register(ops[0])
            src_reg = handler.parse_register(ops[1])
            imm = handler.parse_immediate(ops[2])
            return [f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg}] - ({imm} << 16);"]
        
        elif opcode == 'mulli':
            handler.validate_operand_count(ops, 3, opcode)
            dst_reg = handler.parse_register(ops[0])
            src_reg = handler.parse_register(ops[1])
            imm = handler.parse_immediate(ops[2])
            return [f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg}] * {imm};"]
        
        elif opcode == 'mullw':
            handler.validate_operand_count(ops, 3, opcode)
            dst_reg = handler.parse_register(ops[0])
            src_reg1 = handler.parse_register(ops[1])
            src_reg2 = handler.parse_register(ops[2])
            return [f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg1}] * gc_env.r[{src_reg2}];"]
        
        elif opcode == 'divw':
            handler.validate_operand_count(ops, 3, opcode)
            dst_reg = handler.parse_register(ops[0])
            src_reg1 = handler.parse_register(ops[1])
            src_reg2 = handler.parse_register(ops[2])
            return [f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg1}] / gc_env.r[{src_reg2}];"]
        
        elif opcode == 'divwu':
            handler.validate_operand_count(ops, 3, opcode)
            dst_reg = handler.parse_register(ops[0])
            src_reg1 = handler.parse_register(ops[1])
            src_reg2 = handler.parse_register(ops[2])
            return [f"gc_env.r[{dst_reg}] = (uint32_t)gc_env.r[{src_reg1}] / (uint32_t)gc_env.r[{src_reg2}];"]
        
        else:
            return [f"// Unknown arithmetic opcode: {instruction.opcode} {' '.join(ops)}"]
    
    except (ValueError, IndexError) as e:
        return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]