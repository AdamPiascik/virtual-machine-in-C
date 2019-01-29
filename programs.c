#include "myVM.h"

/*
This is a test program consisting of five instructions
*/
const int program[] = {
    PSH, 5,
    PSH, 6,
    ADD,
    POP,
    HLT
};