#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>

#define sp (registers[SP])
#define ip (registers[IP])

int fetch (void);
void eval(int instr);

/*
Define the VM instruction set
*/
typedef enum {
    PSH,
    ADD,
    POP,
    SET,
    HLT
} InstructionSet;

/*
Define the CPU registers:   8 general purpose (R_x)
                            a program counter (R_PC)
                            a conditonal flag register (R_COND)
The final enum value represents the number of registers (10)
*/
typedef enum {
   A, B, C, D, E, F, IP, SP,
   NUM_OF_REGISTERS
} Registers;