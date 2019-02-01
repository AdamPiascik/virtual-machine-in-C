/*  This program implements a virtual machine to run programs stored as arrays
    in "programs.c". The desired program is selected by loading it into the
    start of the stack; these blocks are essentially read-only for the rest of
    the program, and only blocks from (last instruction + 1) upwards are
    written to. Instructions are loaded sequentially into R0 where they are executed
    and the result pushed to the top of the stack. */

#include "myVM.h"

/*  Define a memory stack of 256 blocks, each of 4 byte size (total
    stack size is 1 kilobyte) */
int stack[256];
//  Define an array of CPU registers, each of 32 bit size
int registers[NUM_OF_REGISTERS];
//  Define a program status variable
bool running;

int main (int argc, char *argv[])
{
    if (argc == 2){
        running = true; // Set the program status to running
        loadFileProgram(argv[1]); // Loads the requested program from file
        /*  While the program is running, instructions are loaded from the stack
            into the registers, executed, and the next instruction loaded. */
        while (running){
            fetch("instructions", stack[CURR_INSTRUCTION]);
            execute();
            ++CURR_INSTRUCTION;
        }
    }
    //  Error message for invalid program request
    else{
        printf("Please enter only one program to run.\n");
    }
    return 0;
}