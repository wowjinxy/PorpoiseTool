"""
Handler for PowerPC mfspr (Move from Special Purpose Register) instruction.
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

opcodes = ['mfspr']

class MfsprHandler:
    """Handles PowerPC mfspr instruction transpilation."""
    
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
        """Handle mfspr instruction."""
        opcode = instruction.opcode.lower().rstrip('.')
        ops = instruction.operands
        
        self.validate_operand_count(ops, 2, opcode)
        
        try:
            dst_reg = self.parse_register(ops[0])
            spr = ops[1].strip().upper()
            
            if opcode == 'mfspr':
                if spr == 'HID0':
                    return [f"gc_env.r[{dst_reg}] = gc_env.hid0; // mfspr r{dst_reg}, {spr}"]
                elif spr == 'HID2':
                    return [f"gc_env.r[{dst_reg}] = gc_env.hid2; // mfspr r{dst_reg}, {spr}"]
                elif spr == 'L2CR':
                    return [f"gc_env.r[{dst_reg}] = gc_env.l2cr; // mfspr r{dst_reg}, {spr}"]
                elif spr == 'IABR':
                    return [f"gc_env.r[{dst_reg}] = gc_env.iabr; // mfspr r{dst_reg}, {spr}"]
                elif spr.startswith('GQR') and spr[3:].isdigit():
                    idx = int(spr[3:])
                    if 0 <= idx < 8:
                        return [f"gc_env.r[{dst_reg}] = gc_env.gqr[{idx}]; // mfspr r{dst_reg}, {spr}"]
                return [f"// Unsupported SPR: {spr} for mfspr r{dst_reg}, {spr}"]
            
            return [f"// Unknown opcode: {instruction.opcode} {' '.join(ops)}"]
        
        except ValueError as e:
            return [f"// Error processing {opcode} {' '.join(ops)}: {str(e)}"]

def handle(instruction: Instruction, transpiler: 'ModularTranspiler') -> List[str]:
    """Entry point for mfspr instruction handling."""
    return MfsprHandler(transpiler).handle(instruction)