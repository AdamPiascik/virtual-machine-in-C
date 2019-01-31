/*  This program implements a virtual machine to run programs stored as arrays
    in "programs.c". The desired program is selected by choosing passing it to
    the program in the command line; programs execute line by line.*/

#include "myVM.h"

/*  Define a memory stack of 256 blocks, each of 4 byte size (total
    stack size is 1 kilobyte) */
int stack[256];
//  Define an array of CPU registers, each of 32 bit size
int registers[NUM_OF_REGISTERS];
//  Define a program status variable
bool running;
//  Declare a pointer to the current instruction of the requested program
int *curr_instr;

int main (int argc, char *argv[])
{
    printf("\n"); // Some formatting
    //  Check whether only one program was requested
    if (argc == 2){
        running = true; // Set the program status to running
        //  Execute the program
        while (running) {
            /*  Fetch the instruction at array position [ip] in the
                requested program. ip is initially set to 0. */
            curr_instr = fetch(argv[1]);
            //  Check whether the instruction is valid
            if (isValid(curr_instr)){
                //  Execute the instruction
                execute(curr_instr);
                //  Move on to the next instruction
                ++ip;
            }
            else{
                break;
            }
        }
    }
    //  Error message for invalid program request
    else{
        printf("Please enter only one program to run.\n");
    }
    return 0;
}