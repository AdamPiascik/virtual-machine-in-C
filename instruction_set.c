#include "myVM.h"

extern int stack[];
extern int registers[];
extern bool running;
extern int program1[], program2[], program3[], *curr_instruction;

void eval(int *instr)
{
    switch (*instr) {
        case HLT:
        {
            running = false;
            break;
        }
        case PSH:
        {
            sp++;
            stack[sp] = *(++instr);
            ++ip;
            break;
        }
        case POP:
        {
            printf("Popping the result of the program...\n");
            int val_popped = stack[sp--];
            printf("Popped %d!\n", val_popped);
            break;
        }
        case ADD:
        {
            int a = stack[sp--];
            int b = stack[sp--];
            int result = b + a;
            sp++;
            stack[sp] = result;
            break;
        }
        case SUB:
        {
            int a = stack[sp--];
            int b = stack[sp--];
            int result = b - a;
            sp++;
            stack[sp] = result;
            break;
        }
        default:
        {
            printf("An invalid instruction was requested.\n");
            break;
        }
    }
}

int * fetch (char *requested_program)
{
    if (strcmp(requested_program, "program1") == 0){
        return program1 + ip;
    } 
    else if (strcmp(requested_program, "program2") == 0){
        return program2 + ip;
    }
    else if (strcmp(requested_program, "program3") == 0){
        return program3 + ip;
    }
    else{
        printf("The requested program isn't valid..\n");
        return (int *) 0;
    }
}