#!/usr/bin/env python3
"""
Handler for PowerPC lis (Load Immediate Shifted) instruction.
Handles both standalone lis and lis + ori patterns for loading 32-bit addresses.
"""

import re

opcodes = ['lis']

def handle(instruction, transpiler):
    """
    Handle lis instruction.
    
    lis rD, value@h    -> Load high 16 bits of value into rD (shifted left 16 bits)
    lis rD, immediate  -> Load immediate value into high 16 bits of rD
    
    Common pattern:
    lis rD, symbol@h
    ori rD, rD, symbol@l
    -> Load full 32-bit address of symbol into rD
    """
    if len(instruction.operands) < 2:
        return f"// Invalid lis instruction: {instruction.opcode} {' '.join(instruction.operands)}"
    
    dest_reg = instruction.operands[0].rstrip(',')
    value = instruction.operands[1]
    
    # Handle @h modifier (high 16 bits)
    if '@h' in value:
        symbol = value.replace('@h', '')
        # Clean up common symbol prefixes
        if symbol.startswith('*') and symbol.endswith('*'):
            symbol = symbol[1:-1]
        
        # Check if this is a known symbol pattern
        if 'stack' in symbol.lower():
            return f"{dest_reg} = (uint32_t)&stack_base >> 16; // lis {dest_reg}, {value}"
        elif 'sda2' in symbol.lower():
            return f"{dest_reg} = (uint32_t)&_SDA2_BASE_ >> 16; // lis {dest_reg}, {value}"
        elif 'sda' in symbol.lower() and 'sda2' not in symbol.lower():
            return f"{dest_reg} = (uint32_t)&_SDA_BASE_ >> 16; // lis {dest_reg}, {value}"
        else:
            return f"{dest_reg} = (uint32_t)&{symbol} >> 16; // lis {dest_reg}, {value}"
    
    # Handle immediate values
    if value.startswith('0x') or value.startswith('-0x'):
        try:
            imm_val = int(value, 16) if value.startswith('0x') else int(value, 16)
            return f"{dest_reg} = {imm_val} << 16; // lis {dest_reg}, {value}"
        except ValueError:
            pass
    
    # Handle decimal immediate
    try:
        imm_val = int(value)
        return f"{dest_reg} = {imm_val} << 16; // lis {dest_reg}, {value}"
    except ValueError:
        pass
    
    # Default case
    return f"{dest_reg} = (uint32_t){value} << 16; // lis {dest_reg}, {value}"