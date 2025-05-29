"""
Arithmetic operations handler for PowerPC assembly
"""

from typing import List, Optional, Union

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

opcodes = [
    'add', 'addi', 'addis', 'sub', 'subi', 'subis',
    'mulli', 'mullw', 'divw', 'divwu', 'lis', 'li',
    'subf', 'addic', 'subic', 'subic.'
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
        
        if not hasattr(self.transpiler, 'previous_instruction') or not self.transpiler.previous_instruction:
            return None
        
        prev = self.transpiler.previous_instruction
        if prev.opcode.lower() != 'lis' or len(prev.operands) < 2:
            return None
        
        try:
            prev_dst = self.parse_register(prev.operands[0])
            if prev_dst != dst_reg:
                return None
        except ValueError:
            return None
        
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
    """Handle arithmetic operations."""
    handler = ArithmeticHandler(transpiler)
    original_opcode = instruction.opcode.lower()
    opcode = original_opcode.rstrip('.')
    has_dot = original_opcode.endswith('.')
    ops = instruction.operands
    
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
            
            symbol_code = handler.handle_symbol_reference(dst_reg, imm_str)
            if symbol_code:
                return [symbol_code]
            
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
        
        elif opcode == 'subf':
            handler.validate_operand_count(ops, 3, opcode)
            dst_reg = handler.parse_register(ops[0])
            src_reg1 = handler.parse_register(ops[1])
            src_reg2 = handler.parse_register(ops[2])
            return [f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg2}] - gc_env.r[{src_reg1}];"]  # Note: subf is rB - rA
        
        elif opcode == 'addic':
            handler.validate_operand_count(ops, 3, opcode)
            dst_reg = handler.parse_register(ops[0])
            src_reg = handler.parse_register(ops[1])
            imm = handler.parse_immediate(ops[2])
            result = [f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg}] + {imm};"]
            
            # Set carry bit in XER register
            result.append(f"gc_env.xer = (gc_env.xer & ~0x20000000) | (((uint64_t)gc_env.r[{src_reg}] + {imm}) > 0xFFFFFFFF ? 0x20000000 : 0);")
            
            if has_dot:
                # Update condition register CR0
                result.append(f"gc_env.cr[0] = (gc_env.r[{dst_reg}] == 0) ? 0x2 : ((int32_t)gc_env.r[{dst_reg}] < 0 ? 0x8 : 0x4);")
            
            return result
        
        elif opcode == 'subic':
            handler.validate_operand_count(ops, 3, opcode)
            dst_reg = handler.parse_register(ops[0])
            src_reg = handler.parse_register(ops[1])
            imm = handler.parse_immediate(ops[2])
            
            result = [f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg}] - {imm};"]
            
            # Set carry bit in XER register (carry set if no borrow occurred)
            result.append(f"gc_env.xer = (gc_env.xer & ~0x20000000) | (gc_env.r[{src_reg}] >= {imm} ? 0x20000000 : 0);")
            
            if has_dot:
                # Update condition register CR0
                result.append(f"gc_env.cr[0] = (gc_env.r[{dst_reg}] == 0) ? 0x2 : ((int32_t)gc_env.r[{dst_reg}] < 0 ? 0x8 : 0x4);")
            
            return result
        
        else:
            return [f"// Unknown arithmetic opcode: {instruction.opcode} {' '.join(ops)}"]
    
    except (ValueError, IndexError) as e:
        return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]