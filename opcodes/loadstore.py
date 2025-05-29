"""
Load/Store operations handler for PowerPC assembly - Refactored
"""

from typing import List, Tuple

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

opcodes = ['stw', 'stwu', 'lhz', 'lwz', 'lbz', 'stb', 'sth', 'lhzu', 'lwzu', 'sthu', 'stbu']


class LoadStoreHandler:
    """Handles PowerPC load/store instruction transpilation."""
    
    def parse_register(self, reg_str: str) -> int:
        """Parse register string to integer, handling 'r' prefix."""
        try:
            return int(reg_str.lstrip('rR'))
        except ValueError:
            raise ValueError(f"Invalid register format: {reg_str}")
    
    def parse_memory_operand(self, mem_str: str) -> Tuple[str, int]:
        """
        Parse memory operand like 'offset(rN)' or '(rN)'.
        Returns (offset, base_register).
        """
        mem_str = mem_str.strip()
        
        if not ('(' in mem_str and ')' in mem_str):
            raise ValueError(f"Invalid memory operand format: {mem_str}")
        
        # Split on '(' to get offset and base register part
        parts = mem_str.split('(', 1)
        offset_str = parts[0].strip()
        base_part = parts[1].rstrip(')')
        
        # Parse offset (can be empty for 0 offset)
        offset = offset_str if offset_str else "0"
        
        # Parse base register
        base_reg = self.parse_register(base_part)
        
        return offset, base_reg
    
    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) < expected:
            raise ValueError(f"{opcode} requires at least {expected} operands, got {len(ops)}")
    
    def generate_memory_access(self, opcode: str, reg: int, offset: str, base_reg: int, 
                             is_store: bool, size: int, update_base: bool = False) -> List[str]:
        """
        Generate memory access code.
        
        Args:
            opcode: The instruction opcode
            reg: Source register (store) or destination register (load)
            offset: Memory offset
            base_reg: Base register for address calculation
            is_store: True for store operations, False for load
            size: Memory access size in bits (8, 16, 32)
            update_base: True for update variants (adds offset to base register)
        """
        result = []
        
        # Generate the memory access
        if is_store:
            if size == 32:
                result.append(f"gc_mem_write32(gc_env.ram, gc_env.r[{base_reg}] + {offset}, gc_env.r[{reg}]);")
            elif size == 16:
                result.append(f"gc_mem_write16(gc_env.ram, gc_env.r[{base_reg}] + {offset}, gc_env.r[{reg}]);")
            elif size == 8:
                result.append(f"gc_mem_write8(gc_env.ram, gc_env.r[{base_reg}] + {offset}, gc_env.r[{reg}]);")
        else:
            if size == 32:
                result.append(f"gc_env.r[{reg}] = gc_mem_read32(gc_env.ram, gc_env.r[{base_reg}] + {offset});")
            elif size == 16:
                result.append(f"gc_env.r[{reg}] = gc_mem_read16(gc_env.ram, gc_env.r[{base_reg}] + {offset});")
            elif size == 8:
                result.append(f"gc_env.r[{reg}] = gc_mem_read8(gc_env.ram, gc_env.r[{base_reg}] + {offset});")
        
        # Update base register if this is an update variant
        if update_base:
            result.append(f"gc_env.r[{base_reg}] = gc_env.r[{base_reg}] + {offset};")
        
        return result


def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Handle load/store operations with improved structure."""
    handler = LoadStoreHandler()
    opcode = instruction.opcode.lower().rstrip('.')
    ops = instruction.operands
    
    print(f"Processing opcode: {opcode}, operands: {ops}")
    
    try:
        # Store Word (32-bit)
        if opcode == 'stw':
            handler.validate_operand_count(ops, 2, opcode)
            src_reg = handler.parse_register(ops[0])
            offset, base_reg = handler.parse_memory_operand(ops[1])
            return handler.generate_memory_access(opcode, src_reg, offset, base_reg, 
                                                is_store=True, size=32)
        
        # Store Word with Update
        elif opcode == 'stwu':
            handler.validate_operand_count(ops, 2, opcode)
            src_reg = handler.parse_register(ops[0])
            offset, base_reg = handler.parse_memory_operand(ops[1])
            return handler.generate_memory_access(opcode, src_reg, offset, base_reg, 
                                                is_store=True, size=32, update_base=True)
        
        # Store Halfword (16-bit)
        elif opcode == 'sth':
            handler.validate_operand_count(ops, 2, opcode)
            src_reg = handler.parse_register(ops[0])
            offset, base_reg = handler.parse_memory_operand(ops[1])
            return handler.generate_memory_access(opcode, src_reg, offset, base_reg, 
                                                is_store=True, size=16)
        
        # Store Halfword with Update
        elif opcode == 'sthu':
            handler.validate_operand_count(ops, 2, opcode)
            src_reg = handler.parse_register(ops[0])
            offset, base_reg = handler.parse_memory_operand(ops[1])
            return handler.generate_memory_access(opcode, src_reg, offset, base_reg, 
                                                is_store=True, size=16, update_base=True)
        
        # Store Byte (8-bit)
        elif opcode == 'stb':
            handler.validate_operand_count(ops, 2, opcode)
            src_reg = handler.parse_register(ops[0])
            offset, base_reg = handler.parse_memory_operand(ops[1])
            return handler.generate_memory_access(opcode, src_reg, offset, base_reg, 
                                                is_store=True, size=8)
        
        # Store Byte with Update
        elif opcode == 'stbu':
            handler.validate_operand_count(ops, 2, opcode)
            src_reg = handler.parse_register(ops[0])
            offset, base_reg = handler.parse_memory_operand(ops[1])
            return handler.generate_memory_access(opcode, src_reg, offset, base_reg, 
                                                is_store=True, size=8, update_base=True)
        
        # Load Word and Zero (32-bit)
        elif opcode == 'lwz':
            handler.validate_operand_count(ops, 2, opcode)
            dst_reg = handler.parse_register(ops[0])
            offset, base_reg = handler.parse_memory_operand(ops[1])
            return handler.generate_memory_access(opcode, dst_reg, offset, base_reg, 
                                                is_store=False, size=32)
        
        # Load Word and Zero with Update
        elif opcode == 'lwzu':
            handler.validate_operand_count(ops, 2, opcode)
            dst_reg = handler.parse_register(ops[0])
            offset, base_reg = handler.parse_memory_operand(ops[1])
            return handler.generate_memory_access(opcode, dst_reg, offset, base_reg, 
                                                is_store=False, size=32, update_base=True)
        
        # Load Halfword and Zero (16-bit)
        elif opcode == 'lhz':
            handler.validate_operand_count(ops, 2, opcode)
            dst_reg = handler.parse_register(ops[0])
            offset, base_reg = handler.parse_memory_operand(ops[1])
            return handler.generate_memory_access(opcode, dst_reg, offset, base_reg, 
                                                is_store=False, size=16)
        
        # Load Halfword and Zero with Update
        elif opcode == 'lhzu':
            handler.validate_operand_count(ops, 2, opcode)
            dst_reg = handler.parse_register(ops[0])
            offset, base_reg = handler.parse_memory_operand(ops[1])
            return handler.generate_memory_access(opcode, dst_reg, offset, base_reg, 
                                                is_store=False, size=16, update_base=True)
        
        # Load Byte and Zero (8-bit)
        elif opcode == 'lbz':
            handler.validate_operand_count(ops, 2, opcode)
            dst_reg = handler.parse_register(ops[0])
            offset, base_reg = handler.parse_memory_operand(ops[1])
            return handler.generate_memory_access(opcode, dst_reg, offset, base_reg, 
                                                is_store=False, size=8)
        
        else:
            return [f"// Unknown load/store opcode: {instruction.opcode} {' '.join(ops)}"]
    
    except (ValueError, IndexError) as e:
        return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]