#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//  Function declarations from "VMfunctions.c"
void fetch (char* from, int instr);
void loadFileProgram (char *requested_program);
void viewRegisters (void);
void clearRegisters (void);
//  Function declaration from "makeInstruction.c"
int makeInstruction(char *program_line);
//  Function declaration from "instructionSet.c"
void execute (void);


#define CURR_STACK_TOP registers[STK]
#define CURR_INSTRUCTION registers[INS]
#define CURR_REGISTER registers[REG]

/*  Define the VM instruction set. These are the basic operations that
    the "CPU" can perform. */
typedef enum {
    PSH,
    POP,
    ADD,
    DIV,
    MULT,
    MOD,
    NEG,
    SUB,
    HLT
} InstructionSet;

/*  Define the CPU registers:
        R0-R4: general purpose registers for storing values loaded from
        the stack.
        INS: Keeps track of which program instruction is being executed.
        STK: Keeps track of which memory block is at the top of the stack.
        REG: Keeps track of the next currently available register. */
typedef enum {
   R0, R1, R2, R3, R4, INS, STK, REG, 
   NUM_OF_REGISTERS
} Registers;