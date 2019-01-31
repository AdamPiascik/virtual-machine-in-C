#include "myVM.h"

int stack[256];
int registers[NUM_OF_REGISTERS];
bool running = true;
int *curr_instruction;

int main (int argc, char *argv[])
{
    printf("\n");
    if (argc == 2){
        while (running) {
            curr_instruction = fetch(argv[1]);
            if (isValid(curr_instruction)){
                eval(curr_instruction);
                ++ip;
            }
            else{
                break;
            }
        }
    }
    else{
        printf("Please enter only one program to run.\n");
    }
    return 0;
}