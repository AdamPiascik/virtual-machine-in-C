#include "myVM.h"

extern int stack[];
extern int registers[];
extern bool running;
extern int program[];

void eval(int instr)
{
    switch (instr) {
        case HLT:
        {
            running = false;
            break;
        }
        case PSH:
        {
            sp++;
            stack[sp] = program[++ip];
            break;
        }
        case POP:
        {
            int val_popped = stack[sp--];
            printf("popped %d\n", val_popped);
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
    }
}

int fetch (void)
{
    return program[ip];
}