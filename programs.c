#include "myVM.h"

/*
This is a test program consisting of five instructions
*/
const int program1[] = {
    PSH, 9,
    PSH, 5,
    ADD,
    POP,
    HLT
};

const int program2[] = {
    PSH, 9,
    PSH, 5,
    SUB,
    POP,
    HLT
};

const int program3[] = {
    PSH, 9,
    PSH, 9,
    ADD,
    POP,
    HLT
};

int isValid (int *program)
{
    if (program != (int *) 0){
        return 1;
    }
    else{
        return 0;
    }
}