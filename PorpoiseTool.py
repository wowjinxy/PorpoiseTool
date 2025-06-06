#!/usr/bin/env python3
"""
Modular GameCube Assembly to C Transpiler
Converts PowerPC assembly files into C source and header files.
Utilizes modular opcode handlers from external files for extensibility.
"""

import importlib.util
import re
import sys
from pathlib import Path
from typing import Dict, List, Optional, Set, Tuple
from dataclasses import dataclass


@dataclass
class Instruction:
    """Represents a single assembly instruction."""
    opcode: str
    operands: List[str]
    address: Optional[str] = None
    raw_bytes: Optional[str] = None


@dataclass
class Function:
    """Represents a parsed function from assembly code."""
    name: str
    start_addr: Optional[str]
    size: Optional[str]
    instructions: List[Instruction]
    is_local: bool = False


@dataclass
class DataSection:
    """Represents a parsed data section (e.g., gap_ arrays)."""
    name: str
    start_addr: Optional[str]
    size: Optional[str]
    data: List[Tuple[str, str]]  # List of (value, comment) pairs


class ModularTranspiler:
    """Transpiles GameCube assembly code to C source and header files."""
    
    def __init__(self, opcodes_dir: str = "opcodes"):
        """Initialize the transpiler with an opcodes directory."""
        self.opcodes_dir = Path(opcodes_dir)
        self.opcode_handlers: Dict[str, callable] = {}
        self.functions: List[Function] = []
        self.data_sections: List[DataSection] = []
        self.variables: Set[str] = set()
        self.includes: Set[str] = set(['"gc_env.h"'])
        self.previous_instruction = None
        self._load_opcode_handlers()

    def _load_opcode_handlers(self):
        """Load opcode handler modules from the opcodes directory."""
        if not self.opcodes_dir.exists():
            print(f"Error: Opcodes directory '{self.opcodes_dir}' not found")
            sys.exit(1)

        for py_file in self.opcodes_dir.glob("*.py"):
            if py_file.name.startswith("__"):
                continue

            try:
                spec = importlib.util.spec_from_file_location(py_file.stem, py_file)
                if not spec or not spec.loader:
                    print(f"Warning: Failed to create spec for {py_file}")
                    continue
                
                module = importlib.util.module_from_spec(spec)
                spec.loader.exec_module(module)

                if hasattr(module, 'handle') and hasattr(module, 'opcodes'):
                    for opcode in module.opcodes:
                        self.opcode_handlers[opcode.lower()] = module.handle
                else:
                    print(f"Warning: {py_file} lacks 'handle' or 'opcodes' attributes")
            except Exception as e:
                print(f"Warning: Failed to load opcode handler {py_file}: {str(e)}")

    def strip_comments(self, assembly_code: str) -> str:
        """Remove inline comments from assembly code, preserving /* */ comments."""
        lines = []
        for line in assembly_code.split('\n'):
            line = line.rstrip()
            if '#' in line:
                line = line.split('#')[0].rstrip()
            lines.append(line)
        return '\n'.join(lines)

    def extract_gap_sections(self, assembly_code: str) -> Tuple[str, List[Tuple[str, str, str, List[str]]]]:
        """Extract gap_ sections and return cleaned code with gap_ section data."""
        lines = assembly_code.split('\n')
        cleaned_lines = []
        gap_sections = []
        in_gap = False
        current_gap = None
        current_addr = None
        current_size = None
        gap_lines = []

        for line in lines:
            line = line.strip()
            if not line:
                cleaned_lines.append(line)
                continue

            # Match section and address metadata
            addr_match = re.match(r'#\s*\.(\w+):(0x[0-9A-Fa-f]+)\s*\|\s*(0x[0-9A-Fa-f]+)\s*\|\s*size:\s*(0x[0-9A-Fa-f]+)', line)
            if addr_match:
                current_addr = addr_match.group(3)
                current_size = addr_match.group(4)
                cleaned_lines.append(line)
                continue

            # Match function declarations
            fn_match = re.match(r'\.fn\s+(\w+)(?:,\s*(\w+))?', line)
            if fn_match:
                func_name, func_type = fn_match.groups()
                if func_name.startswith('gap_'):
                    in_gap = True
                    current_gap = (func_name, func_type, current_addr, current_size)
                    gap_lines = []
                    print(f"Found gap section: {func_name} at {current_addr}")
                    continue
                else:
                    cleaned_lines.append(line)
                    continue

            # Match function/data end
            if line.startswith('.endfn'):
                if in_gap and current_gap:
                    gap_sections.append((current_gap[0], current_gap[2], current_gap[3], gap_lines))
                    print(f"Extracted gap section: {current_gap[0]}, {len(gap_lines)} lines")
                    in_gap = False
                    current_gap = None
                    gap_lines = []
                    continue
                cleaned_lines.append(line)
                continue

            # Collect lines in gap section
            if in_gap:
                gap_lines.append(line)
            else:
                cleaned_lines.append(line)

        return '\n'.join(cleaned_lines), gap_sections

    def parse_gap_section(self, name: str, addr: Optional[str], size: Optional[str], lines: List[str]) -> DataSection:
        """Parse a gap_ section into a DataSection with .4byte values."""
        data = []
        for line in lines:
            line = line.strip()
            if not line:
                continue

            # Match .hidden directive
            if line.startswith('.hidden'):
                continue

            # Match instructions with address and raw bytes
            instr_match = re.match(r'/\*\s*([0-9A-Fa-f]+)\s+([0-9A-Fa-f]+)\s+([0-9A-Fa-f\s]+)\s*\*/\s*(.+)', line)
            if instr_match:
                address, _, raw_bytes, instruction = instr_match.groups()
                bytes_str = ''.join(raw_bytes.split())
                value = f"0x{bytes_str[:8]}"  # Take first 4 bytes
                comment = instruction.strip()
                if comment.startswith('.4byte'):
                    value = comment.split('.4byte ')[1].split(' ')[0]
                data.append((value, comment))
                print(f"Parsed gap data at {address}: {value} ({comment})")
                continue

            # Match .4byte directives
            fourbyte_match = re.match(r'\.4byte\s+(0x[0-9A-Fa-f]+)', line)
            if fourbyte_match:
                value = fourbyte_match.group(1)
                data.append((value, f".4byte {value}"))
                print(f"Parsed gap data: {value}")
                continue

            # Handle labels
            if line.endswith(':'):
                label = line.lstrip('.')
                data.append(('//', f"Label: {label}"))
                print(f"Parsed gap label: {label}")
                continue

            # Warn about unrecognized lines
            print(f"Warning: Unrecognized gap line: {line}")
            data.append(('//', f"Unrecognized: {line}"))

        return DataSection(name=name, start_addr=addr, size=size, data=data)

    def parse_assembly(self, assembly_code: str) -> None:
        """Parse assembly code into functions and data sections."""
        # Extract gap_ sections first
        cleaned_code, gap_sections = self.extract_gap_sections(assembly_code)
        # Parse gap_ sections
        for name, addr, size, lines in gap_sections:
            self.data_sections.append(self.parse_gap_section(name, addr, size, lines))

        # Parse remaining code for functions
        lines = cleaned_code.split('\n')
        current_function = None
        current_addr = None
        current_size = None

        for line in lines:
            line = line.strip()
            if not line:
                continue

            # Match section and address metadata
            addr_match = re.match(r'#\s*\.(\w+):(0x[0-9A-Fa-f]+)\s*\|\s*(0x[0-9A-Fa-f]+)\s*\|\s*size:\s*(0x[0-9A-Fa-f]+)', line)
            if addr_match:
                current_addr = addr_match.group(3)
                current_size = addr_match.group(4)
                continue

            # Match function declarations
            fn_match = re.match(r'\.fn\s+(\w+)(?:,\s*(\w+))?', line)
            if fn_match:
                func_name, func_type = fn_match.groups()
                current_function = Function(
                    name=func_name,
                    start_addr=current_addr,
                    size=current_size,
                    instructions=[],
                    is_local=(func_type == 'local')
                )
                self.functions.append(current_function)
                print(f"Parsed function: {func_name} at {current_addr}")
                current_addr = None
                current_size = None
                continue

            # Match function end
            if line.startswith('.endfn'):
                if current_function:
                    print(f"End of function: {current_function.name}, {len(current_function.instructions)} instructions")
                    current_function = None
                continue

            # Match .hidden directive
            if line.startswith('.hidden'):
                continue

            # Match instructions with address and raw bytes
            instr_match = re.match(r'/\*\s*([0-9A-Fa-f]+)\s+([0-9A-Fa-f]+)\s+([0-9A-Fa-f\s]+)\s*\*/\s*(.+)', line)
            if instr_match and current_function:
                address, _, raw_bytes, instruction = instr_match.groups()
                instr_parts = re.split(r'[,\s]+', instruction.strip())
                if instr_parts:
                    opcode = instr_parts[0]
                    operands = [op.strip() for op in instr_parts[1:] if op.strip()]
                    current_function.instructions.append(Instruction(
                        opcode=opcode,
                        operands=operands,
                        address=f"0x{address}",
                        raw_bytes=raw_bytes.strip()
                    ))
                    print(f"Parsed instruction at {address}: {opcode} {' '.join(operands)}")
                else:
                    print(f"Warning: Failed to parse instruction parts in line: {line}")
                continue

            # Match simple instructions
            simple_instr_match = re.match(r'(\w+\.?)(?:\s*\+)?\s*(.*)', line)
            if simple_instr_match and current_function:
                opcode, operands_str = simple_instr_match.groups()
                opcode = opcode.rstrip('.')
                processed_operands = []
                
                # Preprocess operands for SDA relocations
                for op in re.split(r'[,\s]+', operands_str.strip()):
                    op = op.strip()
                    if not op:
                        continue
                    if '@sda21' in op:
                        # Example: cm_804D7E14@sda21(r0)
                        symbol_match = re.match(r'(\w+)@sda21\((r\d+)\)', op)
                        if symbol_match:
                            symbol, base_reg = symbol_match.groups()
                            processed_operands.append(f"sda:{symbol}")  # Mark as SDA symbol
                            self.variables.add(f"extern float {symbol}")  # Declare as float
                            print(f"Detected SDA symbol: {symbol}")
                        else:
                            processed_operands.append(op)
                            print(f"Warning: Invalid SDA format: {op}")
                    else:
                        processed_operands.append(op)
                
                current_function.instructions.append(Instruction(
                    opcode=opcode,
                    operands=processed_operands,
                    address=None,
                    raw_bytes=None
                ))
                print(f"Parsed simple instruction: {opcode} {' '.join(processed_operands)}")
                continue

            # Handle labels
            if line.endswith(':') and current_function:
                label = line.lstrip('.')
                current_function.instructions.append(Instruction(
                    opcode=label,
                    operands=[],
                    address=None,
                    raw_bytes=None
                ))
                print(f"Parsed label: {label}")
                continue

            if current_function:
                print(f"Warning: Unrecognized line: {line}")

    def translate_instruction(self, instruction: Instruction) -> List[str]:
        """Translate a single instruction to C code."""
        if instruction.opcode.endswith(':'):
            return [instruction.opcode]

        opcode = instruction.opcode.lower().rstrip('.')
        handler = self.opcode_handlers.get(opcode)
        
        if handler:
            try:
                result = handler(instruction, self)
                print(f"Translated {instruction.opcode} {' '.join(instruction.operands)} to: {result}")
                return [result] if isinstance(result, str) else result
            except Exception as e:
                print(f"Error in handler for {instruction.opcode}: {str(e)}")
                return [f"// Error in handler for {instruction.opcode}: {str(e)}"]
        print(f"Unknown opcode: {instruction.opcode} {' '.join(instruction.operands)}")
        return [f"// Unknown opcode: {instruction.opcode} {' '.join(instruction.operands)}"]

    def generate_c_file(self, output_name: str) -> str:
        """Generate content for the C source file."""
        c_lines = [
            f'#include "{output_name}.h"',
            '#include <stdint.h>',
            '#include <stdio.h>',
            ''
        ]
        
        # Add math.h if fcmpo is used
        if any(instr.opcode.lower().rstrip('.') == 'fcmpo' for func in self.functions for instr in func.instructions):
            c_lines.append('#include <math.h>')
            c_lines.append('')

        if self.includes:
            c_lines.extend(f'#include {inc}' for inc in sorted(self.includes))
            c_lines.append('')

        if self.variables:
            c_lines.append('// Global variables')
            c_lines.extend(f'{var};' for var in sorted(self.variables))
            c_lines.append('')

        # Generate functions
        for func in self.functions:
            c_lines.append(f'// Function: {func.name}')
            if func.start_addr:
                c_lines.append(f'// Address: {func.start_addr}')

            c_lines.append(f'void {func.name}(void) {{')
            
            for instr in func.instructions:
                c_lines.extend(f'    {line}' for line in self.translate_instruction(instr) if line.strip())

            c_lines.extend(['}', ''])

        # Generate data sections
        for data in self.data_sections:
            c_lines.append(f'// Data section: {data.name}')
            if data.start_addr:
                c_lines.append(f'// Address: {data.start_addr}')
            c_lines.append(f'uint32_t {data.name}[] = {{')
            for value, comment in data.data:
                if value.startswith('//'):
                    c_lines.append(f'    {value} {comment}')
                else:
                    c_lines.append(f'    {value}, // {comment}')
            c_lines.append('};')
            c_lines.append('')

        return '\n'.join(c_lines)

    def generate_header_file(self, output_name: str) -> str:
        """Generate content for the C header file."""
        guard_name = f"__{output_name.upper()}_H__"
        h_lines = [
            f'#ifndef {guard_name}',
            f'#define {guard_name}',
            '',
            '#include <stdint.h>',
            ''
        ]
    
        # Add system symbols if they were used
        if any('stack_base' in var or '_SDA' in var for var in self.variables):
            h_lines.append('// System symbols')
            h_lines.append('extern uint32_t stack_base;')
            h_lines.append('extern uint32_t _SDA_BASE_;')
            h_lines.append('extern uint32_t _SDA2_BASE_;')
            h_lines.append('')
    
        h_lines.append('// Function declarations')
        for func in self.functions:
            h_lines.append(f'void {func.name}(void);')
    
        h_lines.append('')
        h_lines.append('// Data section declarations')
        for data in self.data_sections:
            h_lines.append(f'extern uint32_t {data.name}[];')
    
        h_lines.extend(['', f'#endif // {guard_name}'])
        return '\n'.join(h_lines)
    
    def transpile_file(self, input_file: str) -> None:
        """Transpile an assembly file to C source and header files."""
        input_path = Path(input_file)
        if not input_path.exists():
            print(f"Error: Input file '{input_file}' not found")
            sys.exit(1)

        try:
            with input_path.open('r') as f:
                assembly_code = f.read()
        except Exception as e:
            print(f"Error reading file '{input_file}': {str(e)}")
            sys.exit(1)

        self.functions = []
        self.data_sections = []
        self.parse_assembly(assembly_code)
        if not self.functions and not self.data_sections:
            print("Error: No functions or data sections found in assembly file")
            sys.exit(1)

        base_name = input_path.stem
        c_file = input_path.parent / f"{base_name}.c"
        h_file = input_path.parent / f"{base_name}.h"

        try:
            with c_file.open('w') as f:
                f.write(self.generate_c_file(base_name))
            print(f"Generated: {c_file}")

            with h_file.open('w') as f:
                f.write(self.generate_header_file(base_name))
            print(f"Generated: {h_file}")
        except Exception as e:
            print(f"Error writing output files: {str(e)}")
            sys.exit(1)

    def add_gamecube_symbols(self):
        """Add common GameCube/Wii system symbols to the includes/variables."""
        # Add common system symbols that might be referenced
        self.variables.update([
            "extern uint32_t stack_base",
            "extern uint32_t _SDA_BASE_",
            "extern uint32_t _SDA2_BASE_"
        ])

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python PyDol.py <assembly_file> [opcodes_dir]")
        sys.exit(1)

    opcodes_dir = sys.argv[2] if len(sys.argv) > 2 else "opcodes"
    transpiler = ModularTranspiler(opcodes_dir)
    transpiler.transpile_file(sys.argv[1])