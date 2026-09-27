#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cpu.h"


Instruction parse_line(FILE *file, int *success){

    // this gets the instruction's type from the user (the text file in this case)
    char instruction_name[10];
    int result = fscanf(file , "%s" , instruction_name);

    // this makes sure the instruction name is written correctly in uppercases
    for(int i=0 ; instruction_name[i] != '\0' ; i++){
        instruction_name[i] = toupper(instruction_name[i]);
    }
    
    // checking if we hit the end of the file
    if(result != 1){
        *success = 0;
        Instruction empty = {0};
        return empty;
    }
    *success = 1;

    Instruction instr;

    if(strcmp(instruction_name,"LOAD") == 0){
        instr.type = LOAD;
        fscanf(file , "%d %d", &instr.arg1 , &instr.arg2);
    }
    else if(strcmp(instruction_name,"ADD") == 0){
        instr.type = ADD;
        fscanf(file , "%d %d",  &instr.arg1 , &instr.arg2);
    }
    else if(strcmp(instruction_name,"PRINT") == 0){
        instr.type = PRINT;
        fscanf(file , "%d",  &instr.arg1);
    }
    else if(strcmp(instruction_name,"JUMP") == 0){
        instr.type = JUMP;
        fscanf(file , "%d",  &instr.arg1);
    }
    else if(strcmp(instruction_name,"HALT") == 0){
        instr.type = HALT_INSTR;
    }

    return instr;
}


int read_program(char *filename , Instruction *program){
    FILE *file = fopen(filename , "r");
    if(file == NULL){
        printf("Error: could not reach the file!\n");
        return 0;
    }
    
    int success , count = 0;
    Instruction instr = parse_line(file, &success);
    while(success){
        program[count++] = instr;
        instr = parse_line(file, &success);
    }

    fclose(file);
    return count;
}

int main(){
    // counting how many instructions we have in the program text file
    Instruction program[20];
    int count = read_program("program.txt" , program);

    CPU cpu;
    cpu_init(&cpu);

    while(!cpu.halted_flag && cpu.program_counter < count){
        // step 1 : fetch
        Instruction current = program[cpu.program_counter];

        // step 2 and 3 : decode and execute
        if(current.type == LOAD){
            cpu_load(&cpu , current.arg1 , current.arg2);
        }
        else if(current.type == ADD){
            cpu_add(&cpu , current.arg1 , current.arg2);
        }
        else if(current.type == PRINT){
            cpu_print(&cpu , current.arg1);
        }
        else if(current.type == JUMP){
            cpu_jump(&cpu , current.arg1);
        }
        else if(current.type == HALT_INSTR){
            cpu_halt(&cpu);
        }
        if(current.type != JUMP){
            cpu.program_counter++;
        }
    }

    return 0;
}