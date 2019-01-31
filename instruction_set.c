#include "myVM.h"

extern int stack[];
extern int registers[];
extern bool running;

void execute (int *instr)
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
        case MOD:
        {
            int a = stack[sp--];
            int b = stack[sp--];
            int result = b % a;
            sp++;
            stack[sp] = result;
            break;
        }
        case DIV:
        {
            int a = stack[sp--];
            int b = stack[sp--];
            int result = b / a;
            sp++;
            stack[sp] = result;
            break;
        }
        case MULT:
        {
            int a = stack[sp--];
            int b = stack[sp--];
            int result = b * a;
            sp++;
            stack[sp] = result;
            break;
        }
        case NEG:
        {
            int a = stack[sp--];
            int result = -a;
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