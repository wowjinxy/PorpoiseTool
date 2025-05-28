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
from typing import Dict, List, Optional, Set
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


class ModularTranspiler:
    """Transpiles GameCube assembly code to C source and header files."""
    
    def __init__(self, opcodes_dir: str = "opcodes"):
        """Initialize the transpiler with an opcodes directory."""
        self.opcodes_dir = Path(opcodes_dir)
        self.opcode_handlers: Dict[str, callable] = {}
        self.functions: List[Function] = []
        self.variables: Set[str] = set()
        self.includes: Set[str] = set(['"gc_env.h"'])
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
        """Remove comments from assembly code."""
        lines = []
        for line in assembly_code.split('\n'):
            line = line.rstrip()
            if '#' in line:
                line = line.split('#')[0]
            while '/*' in line and '*/' in line:
                start = line.find('/*')
                end = line.find('*/') + 2
                line = line[:start] + line[end:]
            lines.append(line.rstrip())
        return '\n'.join(lines)

    def parse_assembly(self, assembly_code: str) -> List[Function]:
        """Parse assembly code into a list of Function objects."""
        assembly_code = self.strip_comments(assembly_code)
        lines = assembly_code.split('\n')
        functions = []
        current_function = None

        for line in lines:
            line = line.strip()
            if not line:
                continue

            # Match section and address metadata
            addr_match = re.match(r'#\s*\.(\w+):(0x[0-9A-Fa-f]+)\s*\|\s*(0x[0-9A-Fa-f]+)\s*\|\s*size:\s*(0x[0-9A-Fa-f]+)', line)
            if addr_match:
                continue

            # Match function declarations
            fn_match = re.match(r'\.fn\s+(\w+)(?:,\s*(\w+))?', line)
            if fn_match:
                func_name, func_type = fn_match.groups()
                current_function = Function(
                    name=func_name,
                    start_addr=None,
                    size=None,
                    instructions=[],
                    is_local=(func_type == 'local')
                )
                functions.append(current_function)
                print(f"Parsed function: {func_name}")
                continue

            # Match function end
            if line.startswith('.endfn'):
                if current_function:
                    print(f"End of function: {current_function.name}, {len(current_function.instructions)} instructions")
                current_function = None
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

            # Match simple instructions (no address/raw bytes)
            simple_instr_match = re.match(r'(\w+\.?)(?:\s*\+)?\s*(.*)', line)
            if simple_instr_match and current_function:
                opcode, operands_str = simple_instr_match.groups()
                # Normalize opcode by removing trailing . and handling + (e.g., beq +)
                opcode = opcode.rstrip('.')
                operands = [op.strip() for op in re.split(r'[,\s]+', operands_str.strip()) if op.strip()]
                current_function.instructions.append(Instruction(
                    opcode=opcode,
                    operands=operands,
                    address=None,
                    raw_bytes=None
                ))
                print(f"Parsed simple instruction: {opcode} {' '.join(operands)}")
                continue

            # Handle labels (e.g., .L_80003130:)
            if line.endswith(':') and current_function:
                label = line.lstrip('.')
                print(f"Parsed label: {label}")
                current_function.instructions.append(Instruction(
                    opcode=label,
                    operands=[],
                    address=None,
                    raw_bytes=None
                ))
                continue

            if current_function:
                print(f"Warning: Unrecognized instruction line: {line}")

        return functions

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

    def generate_c_file(self, functions: List[Function], output_name: str) -> str:
        """Generate content for the C source file."""
        c_lines = [
            f'#include "{output_name}.h"',
            '#include <stdint.h>',
            '#include <stdio.h>',
            ''
        ]

        if self.includes:
            c_lines.extend(f'#include {inc}' for inc in sorted(self.includes))
            c_lines.append('')

        if self.variables:
            c_lines.append('// Global variables')
            c_lines.extend(f'{var};' for var in sorted(self.variables))
            c_lines.append('')

        for func in functions:
            c_lines.append(f'// Function: {func.name}')
            if func.start_addr:
                c_lines.append(f'// Address: {func.start_addr}')

            c_lines.append(f'void {func.name}(void) {{')
            
            for instr in func.instructions:
                c_lines.extend(f'    {line}' for line in self.translate_instruction(instr) if line.strip())

            c_lines.extend(['}', ''])

        return '\n'.join(c_lines)

    def generate_header_file(self, functions: List[Function], output_name: str) -> str:
        """Generate content for the C header file."""
        guard_name = f"__{output_name.upper()}_H__"
        h_lines = [
            f'#ifndef {guard_name}',
            f'#define {guard_name}',
            '',
            '#include <stdint.h>',
            ''
        ]

        h_lines.append('// Function declarations')
        for func in functions:
            h_lines.append(f'void {func.name}(void);')

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

        self.functions = self.parse_assembly(assembly_code)
        if not self.functions:
            print("Error: No functions found in assembly file")
            sys.exit(1)

        base_name = input_path.stem
        c_file = input_path.parent / f"{base_name}.c"
        h_file = input_path.parent / f"{base_name}.h"

        try:
            with c_file.open('w') as f:
                f.write(self.generate_c_file(self.functions, base_name))
            print(f"Generated: {c_file}")

            with h_file.open('w') as f:
                f.write(self.generate_header_file(self.functions, base_name))
            print(f"Generated: {h_file}")
        except Exception as e:
            print(f"Error writing output files: {str(e)}")
            sys.exit(1)


def main():
    """Main entry point for the transpiler."""
    if len(sys.argv) < 2:
        print("Usage: python PyDol.py <assembly_file> [opcodes_dir]")
        sys.exit(1)

    opcodes_dir = sys.argv[2] if len(sys.argv) > 2 else "opcodes"
    transpiler = ModularTranspiler(opcodes_dir)
    transpiler.transpile_file(sys.argv[1])


if __name__ == "__main__":
    main()