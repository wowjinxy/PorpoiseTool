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
        operand = operand.strip()
        if operand.endswith('@l'):
            return operand[:-2], '@l'
        elif operand.endswith('@ha'):
            return operand[:-3], '@ha'
        elif operand.endswith('@h'):
            return operand[:-2], '@h'
        return operand, ''
    
    def clean_symbol_name(self, symbol: str) -> str:
        """Clean up symbol names by replacing invalid C characters."""
        # Replace *bss* with _bss_ and other common patterns
        symbol = symbol.replace('*bss*', '_bss_')
        symbol = symbol.replace('*', '_')
        return symbol
    
    def check_lis_pattern(self, src_reg: int, symbol: str) -> bool:
        """Check if previous instruction was a matching lis instruction."""
        if not hasattr(self.transpiler, 'previous_instruction') or not self.transpiler.previous_instruction:
            return False
            
        prev = self.transpiler.previous_instruction
        if prev.opcode.lower() != 'lis' or len(prev.operands) < 2:
            return False
            
        try:
            prev_dst = self.parse_register(prev.operands[0])
            prev_symbol, prev_suffix = self.extract_symbol(prev.operands[1])
            
            # Clean both symbols for comparison
            prev_symbol_clean = self.clean_symbol_name(prev_symbol)
            symbol_clean = self.clean_symbol_name(symbol)
            
            # Check if it's the same symbol and the source register matches the lis destination
            return (prev_symbol_clean == symbol_clean and 
                    prev_suffix in ('@h', '@ha') and 
                    src_reg == prev_dst)
        except (ValueError, IndexError):
            return False
    
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
        
        # Clean symbol names for comparison
        current_symbol_clean = self.clean_symbol_name(current_symbol)
        prev_symbol_clean = self.clean_symbol_name(prev_symbol)
        
        if (current_symbol_clean == prev_symbol_clean and 
            prev_suffix in ('@h', '@ha')):
            return f"gc_env.r[{dst_reg}] = (uint32_t)&{current_symbol_clean}; // lis + addi {current_symbol}"
        
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
            value = ops[2].strip()
            
            # Handle @l modifier (low 16 bits of symbol)
            symbol, suffix = handler.extract_symbol(value)
            if suffix == '@l':
                symbol_clean = handler.clean_symbol_name(symbol)
                
                # Check for lis + addi pattern
                if handler.check_lis_pattern(src_reg, symbol):
                    # This completes a lis + addi pattern
                    # Replace both instructions with a single address load
                    if hasattr(transpiler, 'replace_previous_and_current'):
                        # Advanced transpiler that can replace multiple lines
                        transpiler.replace_previous_and_current(
                            f"gc_env.r[{dst_reg}] = (uint32_t)&{symbol_clean}; // lis + addi {symbol}"
                        )
                        return []  # No additional line needed
                    elif hasattr(transpiler, 'replace_previous_instruction'):
                        # Transpiler that can replace the previous line
                        transpiler.replace_previous_instruction(
                            f"gc_env.r[{dst_reg}] = (uint32_t)&{symbol_clean}; // lis + addi {symbol}"
                        )
                        return []  # No additional line needed
                    else:
                        # Fallback: generate the complete address load here
                        # This will result in two lines, but at least it's correct
                        return [f"gc_env.r[{dst_reg}] = (uint32_t)&{symbol_clean}; // lis + addi {symbol} (completing pattern)"]
                else:
                    # Standalone addi with symbol reference
                    return [f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg}] + ((uint32_t)&{symbol_clean} & 0xFFFF); // addi r{dst_reg}, r{src_reg}, {value}"]
            
            # Handle immediate values
            try:
                imm = handler.parse_immediate(value)
                
                # Special case: addi with r0 as source (li pseudo-instruction)
                if src_reg == 0:
                    return [f"gc_env.r[{dst_reg}] = {imm}; // li r{dst_reg}, {value} (addi r{dst_reg}, r0, {value})"]
                
                # Regular addi
                if dst_reg == src_reg and imm != 0:
                    if imm > 0:
                        return [f"gc_env.r[{dst_reg}] += {imm}; // addi r{dst_reg}, r{src_reg}, {value}"]
                    else:
                        return [f"gc_env.r[{dst_reg}] -= {-imm}; // addi r{dst_reg}, r{src_reg}, {value}"]
                else:
                    return [f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg}] + {imm}; // addi r{dst_reg}, r{src_reg}, {value}"]
            except ValueError:
                # If we can't parse as immediate, treat as symbol without suffix
                return [f"gc_env.r[{dst_reg}] = gc_env.r[{src_reg}] + {value}; // addi r{dst_reg}, r{src_reg}, {value}"]
        
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