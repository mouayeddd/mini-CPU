#include <stdio.h>
#include "cpu.h"

// this sets up a fresh CPU
void cpu_init(CPU *cpu){
    for(int i=0 ; i<4 ; i++){
        cpu->registers[i] = 0;
    }
    cpu->program_counter = 0;
    cpu->halted_flag = 0;
}

// this puts a value into a register
void cpu_load(CPU *cpu, int reg, int value){
    cpu->registers[reg - 1] = value;

}

// this adds one register into another
void cpu_add(CPU *cpu, int reg1, int reg2){
    cpu->registers[reg1 - 1] += cpu->registers[reg2 - 1];
}

// this prints the value stored in the target register
void cpu_print(CPU *cpu, int reg){
    printf("The value stored in register %d is: %d\n", reg , cpu->registers[reg - 1]);
}

// this moves the program counter to a specific line
void cpu_jump(CPU *cpu, int targetLine){
    cpu->program_counter = targetLine;
}

// this marks the cpu as halted
void cpu_halt(CPU *cpu){
    cpu->halted_flag = 1;
}