# Mini CPU / Register Simulator

A small C program that simulates a tiny CPU — reading a simple "assembly" program from a text file and executing it instruction by instruction, using registers, a program counter, and basic control flow like jumps.

## Overview

This project simulates the fetch-decode-execute cycle used by real processors. It reads a program written in a simple custom instruction format, loads it into memory, then runs it step by step — updating registers, printing values, and jumping between instructions as directed.

The project is organized in an OOP-inspired style in C: a `CPU` struct represents the machine's state, and a set of functions (its "methods") operate on that state.

## Features

- Supports 5 instructions: `LOAD`, `ADD`, `PRINT`, `JUMP`, `HALT`
- Reads a program from a text file and parses it into instructions
- Executes instructions using a real fetch-decode-execute loop
- Registers are 1-based (register `1` is the first register) for readability
- Correctly handles control flow via `JUMP`, redirecting the program counter

## File Structure

- `cpu.h` — struct/enum definitions (`CPU`, `Instruction`, `InstructionType`) and function declarations
- `cpu.c` — implementation of all CPU "methods" (`cpu_init`, `cpu_load`, `cpu_add`, `cpu_print`, `cpu_jump`, `cpu_halt`)
- `main.c` — parses `program.txt`, builds the CPU, and runs the execution loop
- `program.txt` — the program to run, written in the custom instruction format

## Instruction Format

Each line in `program.txt` is one instruction:

```
LOAD reg value     # loads a value into a register
ADD reg1 reg2      # adds reg2 into reg1
PRINT reg          # prints a register's value
JUMP index         # jumps to a given instruction index (0-based)
HALT               # stops execution
```

Example:
```
LOAD 1 10
LOAD 2 50
JUMP 4
ADD 1 2
PRINT 1
HALT
```

## How to Build and Run

Compile both source files together:
```bash
gcc main.c cpu.c -o cpu
```

Run it:
```bash
./cpu       # on Linux/Mac
.\cpu.exe     # on Windows
```

Make sure `program.txt` is in the same folder as the compiled program.

## Skills Practiced

- Multi-file C project structure (`.h`/`.c` separation)
- OOP-style design in C using structs and function "methods"
- Enums for representing instruction types
- File parsing with variable-format lines (using `fscanf` and `strcmp`)
- Communicating success/failure from a function using pointer parameters
- Implementing a state machine (fetch-decode-execute loop)
- Real debugging: typos, logic errors, and off-by-one indexing issues

## Possible Future Improvements

- Add more instructions (`SUB`, `MUL`, conditional jumps like `JUMP_IF_ZERO`)
- Add input validation for malformed program files
- Support more registers
- Add a step-by-step debug mode that prints CPU state after every instruction

## Author

Mouayed
