#include "myVM.h"

// load externally declared variables
// from "VM_funcs.c"
extern int registers[], CURR_REGISTER;
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
            stack[CURR_STACK_TOP] = registers[R1];
            ++CURR_STACK_TOP;
            break;
        }
        case POP:
        {
            int val_popped = stack[--CURR_STACK_TOP];
            printf("Popped %d!\n", val_popped);
            break;
        }
        case ADD:
        {
            fetch("stack", stack[--CURR_STACK_TOP]);
            fetch("stack", stack[--CURR_STACK_TOP]);
            registers[CURR_REGISTER -= 2] = registers[CURR_REGISTER + 1] + registers[CURR_REGISTER];
            stack[CURR_STACK_TOP] = registers[CURR_REGISTER];
            ++CURR_STACK_TOP;
            break;
        }
        case SUB:
        {
            fetch("stack", stack[--CURR_STACK_TOP]);
            fetch("stack", stack[--CURR_STACK_TOP]);
            registers[CURR_REGISTER -= 2] = registers[CURR_REGISTER + 1] - registers[CURR_REGISTER];
            stack[CURR_STACK_TOP] = registers[CURR_REGISTER];
            ++CURR_STACK_TOP;
            break;
        }
        case MOD:
        {
            fetch("stack", stack[--CURR_STACK_TOP]);
            fetch("stack", stack[--CURR_STACK_TOP]);
            registers[CURR_REGISTER -= 2] = registers[CURR_REGISTER + 1] % registers[CURR_REGISTER];
            stack[CURR_STACK_TOP] = registers[CURR_REGISTER];
            ++CURR_STACK_TOP;
            break;
        }
        case DIV:
        {
            fetch("stack", stack[--CURR_STACK_TOP]);
            fetch("stack", stack[--CURR_STACK_TOP]);
            registers[CURR_REGISTER -= 2] = registers[CURR_REGISTER + 1] / registers[CURR_REGISTER];
            stack[CURR_STACK_TOP] = registers[CURR_REGISTER];
            ++CURR_STACK_TOP;
            break;
        }
        case MULT:
        {
            fetch("stack", stack[--CURR_STACK_TOP]);
            fetch("stack", stack[--CURR_STACK_TOP]);
            registers[CURR_REGISTER -= 2] = registers[CURR_REGISTER + 1] * registers[CURR_REGISTER];
            stack[CURR_STACK_TOP] = registers[CURR_REGISTER];
            ++CURR_STACK_TOP;
            break;
        }
        case NEG:
        {
            fetch("stack", stack[--CURR_STACK_TOP]);
            registers[CURR_REGISTER -= 1] = -registers[CURR_REGISTER];
            stack[CURR_STACK_TOP] = registers[CURR_REGISTER];
            ++CURR_STACK_TOP;
            break;
        }
        default:
        {
            printf("An invalid instruction was requested.\n");
            break;
        }
    }
}