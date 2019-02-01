#include "myVM.h"

// load externally declared variables
// from "programs.c"
extern int program1[], program2[], program3[]; 
extern size_t program1_length, program2_length, program3_length;
 // from "myVM.c"
extern int stack[];

//  Define an array of CPU registers[INS], each of 32 bit size
extern int registers[];
// Declare a simple loop variable;
int i;

/*  This function loads programs into the start of the stack by checking
    which program array to take from "programs.c" and copying instructions
    using a for loop. The instruction pointer (registers[INS]) is then set to
    the first instruction at the start of the stack, and the stack counter
    (registers[STK]) is set to the block just beyond the last instruction. */
void loadProgram (char *requested_program)
{
    if (strcmp(requested_program, "program1") == 0){
        for (i = 0; i < program1_length; ++i){
            stack[i] = program1[i];
            registers[INS] = 0;
            registers[STK] = program1_length;
        }
    }
    else if (strcmp(requested_program, "program2") == 0){
        for (i = 0; i < program2_length; ++i){
            stack[i] = program2[i];
            registers[INS] = 0;
            registers[STK] = program2_length;
        }
    }
    else if (strcmp(requested_program, "program3") == 0){
        for (i = 0; i < program3_length; ++i){
            stack[i] = program3[i];
            registers[INS] = 0;
            registers[STK] = program3_length;
        }
    }
    else{
        printf("The requested program isn't valid..\n");
    }
}

/*  This function moves data from the stack to the registers. If called with
    "instructions" as the "from" argument, it fetches data from the instruction
    block and loads it starting from R0. If called with "stack" as the "from"
    argument, it fetches data from the top of the stack and loads it
    sequentially from R1. */
void fetch (char* from, int instr)
{
    if (strcmp(from, "instructions") == 0){
        if (instr != PSH){
            registers[REG] = R0;
            registers[registers[REG]] = instr;
            ++registers[REG];
        }
        else if (instr == PSH){
            registers[REG] = R0;
            registers[registers[REG]] = stack[registers[INS]++];
            ++registers[REG];
            registers[registers[REG]] = stack[registers[INS]];
            ++registers[REG];
        }    
    }
    else if (strcmp(from, "stack") == 0){
        registers[registers[REG]] = instr;
        ++registers[REG];
    }
}