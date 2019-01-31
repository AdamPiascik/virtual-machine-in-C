#include "myVM.h"

const int program1[] = {
    PSH, 9,
    PSH, 5,
    ADD,
    POP,
    HLT
};

const int program2[] = {
    PSH, 10,
    PSH, 5,
    DIV,
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