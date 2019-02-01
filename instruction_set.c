#include "myVM.h"

// load externally declared variables
// from "VM_funcs.c"
extern int registers[], registers[REG];
// from "myVM.c"
extern bool running;
extern int stack[];

/*  This function executes whichever instruction has been loaded into
    register R0, via a switch statement. */
void execute (void)
{
    switch (registers[R0]){
        case HLT:
        {
            running = false;
            break;
        }
        case PSH:
        {
            stack[registers[STK]] = registers[R1];
            ++registers[STK];
            break;
        }
        case POP:
        {
            int val_popped = stack[--registers[STK]];
            printf("Popped %d!\n", val_popped);
            break;
        }
        case ADD:
        {
            fetch("stack", stack[--registers[STK]]);
            fetch("stack", stack[--registers[STK]]);
            registers[registers[REG] -= 2] = registers[registers[REG] + 1] + registers[registers[REG]];
            stack[registers[STK]] = registers[registers[REG]];
            ++registers[STK];
            break;
        }
        case SUB:
        {
            fetch("stack", stack[--registers[STK]]);
            fetch("stack", stack[--registers[STK]]);
            registers[registers[REG] -= 2] = registers[registers[REG] + 1] - registers[registers[REG]];
            stack[registers[STK]] = registers[registers[REG]];
            ++registers[STK];
            break;
        }
        case MOD:
        {
            fetch("stack", stack[--registers[STK]]);
            fetch("stack", stack[--registers[STK]]);
            registers[registers[REG] -= 2] = registers[registers[REG] + 1] % registers[registers[REG]];
            stack[registers[STK]] = registers[registers[REG]];
            ++registers[STK];
            break;
        }
        case DIV:
        {
            fetch("stack", stack[--registers[STK]]);
            fetch("stack", stack[--registers[STK]]);
            registers[registers[REG] -= 2] = registers[registers[REG] + 1] / registers[registers[REG]];
            stack[registers[STK]] = registers[registers[REG]];
            ++registers[STK];
            break;
        }
        case MULT:
        {
            fetch("stack", stack[--registers[STK]]);
            fetch("stack", stack[--registers[STK]]);
            registers[registers[REG] -= 2] = registers[registers[REG] + 1] * registers[registers[REG]];
            stack[registers[STK]] = registers[registers[REG]];
            ++registers[STK];
            break;
        }
        case NEG:
        {
            fetch("stack", stack[--registers[STK]]);
            registers[registers[REG] -= 1] = -registers[registers[REG]];
            stack[registers[STK]] = registers[registers[REG]];
            ++registers[STK];
            break;
        }
        default:
        {
            printf("An invalid instruction was requested.\n");
            break;
        }
    }
}