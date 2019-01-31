#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define sp (registers[SP])
#define ip (registers[IP])

//  Function declarations.
int * fetch (char *program);
void execute (int *instr);
int isValid (int *program);

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
        R1-R8: general purpose registers for storing values loaded from
        the stack.
        IP: Keeps track of which porgram instruction is being executed.
        SP: Keeps track of which memory block is at the top of the stack. */
typedef enum {
   R1, R2, R3, R4, R5, R6, R7, R8,
   IP, SP, NUM_OF_REGISTERS
} Registers;