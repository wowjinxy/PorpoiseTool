#!/usr/bin/env python3
"""
Handler for PowerPC ori (OR Immediate) instruction.
Handles ori instruction including @l modifier for loading low 16 bits.
"""

import re

opcodes = ['ori']

def handle(instruction, transpiler):
    """
    Handle ori instruction.
    
    ori rD, rS, value@l    -> OR rS with low 16 bits of value, store in rD
    ori rD, rS, immediate  -> OR rS with immediate value, store in rD
    
    Common pattern (following lis):
    lis rD, symbol@h       -> Load high 16 bits
    ori rD, rD, symbol@l   -> OR in low 16 bits (complete 32-bit address)
    """
    if len(instruction.operands) < 3:
        return f"// Invalid ori instruction: {instruction.opcode} {' '.join(instruction.operands)}"
    
    dest_reg = instruction.operands[0].rstrip(',')
    src_reg = instruction.operands[1].rstrip(',')
    value = instruction.operands[2]
    
    # Handle @l modifier (low 16 bits)
    if '@l' in value:
        symbol = value.replace('@l', '')
        # Clean up common symbol prefixes
        if symbol.startswith('*') and symbol.endswith('*'):
            symbol = symbol[1:-1]
        
        # Check if this completes a lis + ori pattern
        if dest_reg == src_reg:
            # This is completing a 32-bit address load
            if 'stack' in symbol.lower():
                return f"{dest_reg} |= (uint32_t)&stack_base & 0xFFFF; // ori {dest_reg}, {src_reg}, {value}"
            elif 'sda2' in symbol.lower():
                return f"{dest_reg} |= (uint32_t)&_SDA2_BASE_ & 0xFFFF; // ori {dest_reg}, {src_reg}, {value}"
            elif 'sda' in symbol.lower() and 'sda2' not in symbol.lower():
                return f"{dest_reg} |= (uint32_t)&_SDA_BASE_ & 0xFFFF; // ori {dest_reg}, {src_reg}, {value}"
            else:
                return f"{dest_reg} |= (uint32_t)&{symbol} & 0xFFFF; // ori {dest_reg}, {src_reg}, {value}"
        else:
            # Different registers
            if 'stack' in symbol.lower():
                return f"{dest_reg} = {src_reg} | ((uint32_t)&stack_base & 0xFFFF); // ori {dest_reg}, {src_reg}, {value}"
            elif 'sda2' in symbol.lower():
                return f"{dest_reg} = {src_reg} | ((uint32_t)&_SDA2_BASE_ & 0xFFFF); // ori {dest_reg}, {src_reg}, {value}"
            elif 'sda' in symbol.lower() and 'sda2' not in symbol.lower():
                return f"{dest_reg} = {src_reg} | ((uint32_t)&_SDA_BASE_ & 0xFFFF); // ori {dest_reg}, {src_reg}, {value}"
            else:
                return f"{dest_reg} = {src_reg} | ((uint32_t)&{symbol} & 0xFFFF); // ori {dest_reg}, {src_reg}, {value}"
    
    # Handle immediate values
    if value.startswith('0x'):
        try:
            imm_val = int(value, 16)
            if dest_reg == src_reg:
                return f"{dest_reg} |= {imm_val}; // ori {dest_reg}, {src_reg}, {value}"
            else:
                return f"{dest_reg} = {src_reg} | {imm_val}; // ori {dest_reg}, {src_reg}, {value}"
        except ValueError:
            pass
    
    # Handle decimal immediate
    try:
        imm_val = int(value)
        if dest_reg == src_reg:
            return f"{dest_reg} |= {imm_val}; // ori {dest_reg}, {src_reg}, {value}"
        else:
            return f"{dest_reg} = {src_reg} | {imm_val}; // ori {dest_reg}, {src_reg}, {value}"
    except ValueError:
        pass
    
    # Default case
    if dest_reg == src_reg:
        return f"{dest_reg} |= {value}; // ori {dest_reg}, {src_reg}, {value}"
    else:
        return f"{dest_reg} = {src_reg} | {value}; // ori {dest_reg}, {src_reg}, {value}"