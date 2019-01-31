#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define sp (registers[SP])
#define ip (registers[IP])

int * fetch (char *program);
void eval (int *instr);
int isValid (int *program);

/*
Define the VM instruction set
*/
typedef enum {
    POP,
    SET,
    HLT,
    PSH,
    ADD,
    SUB
} InstructionSet;

/*
Define the CPU registers
*/
typedef enum {
   A, B, C, D, E, F, IP, SP,
   NUM_OF_REGISTERS
} Registers;