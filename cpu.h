#ifndef CPU_H
#define CPU_H

// the type of instruction that the cpu will execute
typedef enum {
    LOAD,
    ADD,
    PRINT,
    JUMP,
    HALT_INSTR
}InstructionType;

// the instructions structure
typedef struct {
    InstructionType type;
    int arg1;
    int arg2;
}Instruction;

// the cpu structure
typedef struct {
    int registers[4];
    int program_counter;
    int halted_flag;    // flag: 1 if halt was hit
}CPU;

void cpu_init(CPU *cpu);
void cpu_load(CPU *cpu, int reg, int value);
void cpu_add(CPU *cpu, int reg1, int reg2);
void cpu_print(CPU *cpu, int reg);
void cpu_jump(CPU *cpu, int targetLine);
void cpu_halt(CPU *cpu);

#endif