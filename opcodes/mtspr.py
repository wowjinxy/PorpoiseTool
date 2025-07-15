"""
Handler for PowerPC mtspr (Move to Special Purpose Register) instruction.
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

opcodes = ['mtspr']

class MtsprHandler:
    """Handles PowerPC mtspr instruction transpilation."""
    
    def __init__(self, transpiler: 'ModularTranspiler'):
        self.transpiler = transpiler
    
    def parse_register(self, reg_str: str) -> int:
        """Parse register string to integer, handling 'r' prefix."""
        try:
            return int(reg_str.lstrip('rR').rstrip(','))
        except ValueError:
            raise ValueError(f"Invalid register format: {reg_str}")
    
    def validate_operand_count(self, ops: List[str], expected: int, opcode: str) -> None:
        """Validate operand count for instruction."""
        if len(ops) < expected:
            raise ValueError(f"{opcode} requires at least {expected} operands, got {len(ops)}")

    def handle(self, instruction: Instruction) -> List[str]:
        """Handle mtspr instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands
        
        # Handle potential missing comma (e.g., 'HID2 r3' instead of 'HID2, r3')
        if len(ops) == 1 and ' ' in ops[0]:
            ops = [op.strip() for op in ops[0].replace(',', ' ').split()]
        
        self.validate_operand_count(ops, 2, opcode)
        
        try:
            spr = ops[0].strip().upper()
            src_reg = self.parse_register(ops[1])
            
            if opcode == 'mtspr':
                if spr == 'L2CR':
                    return [f"gc_env.l2cr = gc_env.r[{src_reg}]; // mtspr {spr}, r{src_reg}"]
                elif spr == 'HID2':
                    return [f"gc_env.hid2 = gc_env.r[{src_reg}]; // mtspr {spr}, r{src_reg}"]
                elif spr == 'HID0':
                    return [f"gc_env.hid0 = gc_env.r[{src_reg}]; // mtspr {spr}, r{src_reg}"]
                elif spr.startswith('GQR') and spr[3:].isdigit():
                    idx = int(spr[3:])
                    if 0 <= idx < 8:
                        return [f"gc_env.gqr[{idx}] = gc_env.r[{src_reg}]; // mtspr {spr}, r{src_reg}"]
                return [f"// Unsupported SPR: {spr} for mtspr {spr}, r{src_reg}"]
            
            return [f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"]
        
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for mtspr instruction handling."""
    return MtsprHandler(transpiler).handle(instruction)