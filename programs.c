#include "myVM.h"

/*  These are some test programs, which will eventually be moved
    into separate text files. */

const int program1[] = {
    PSH, 10,
    PSH, 2,
    SUB,
    POP,
    HLT
};
size_t program1_length = sizeof(program1) / sizeof(program1[0]);

const int program2[] = {
    PSH, 10,
    PSH, 2,
    MOD,
    POP,
    HLT
};
size_t program2_length = sizeof(program2) / sizeof(program2[0]);

const int program3[] = {
    PSH, 10,
    PSH, 2,
    NEG,
    POP,
    HLT
};
size_t program3_length = sizeof(program3) / sizeof(program3[0]);