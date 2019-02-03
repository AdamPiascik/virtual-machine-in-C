#include "myVM.h"

int makeInstruction(char *program_line)
{
    if (strcmp(program_line, "PSH,\n") == 0){
        return PSH;
    }
    else if (!strcmp(program_line, "POP,\n")){
        return POP;
    }
    else if (!strcmp(program_line, "ADD,\n")){
        return ADD;
    }
    else if (!strcmp(program_line, "SUB,\n")){
        return SUB;
    }
    else if (!strcmp(program_line, "MOD,\n")){
        return MOD;
    }
    else if (!strcmp(program_line, "DIV,\n")){
        return DIV;
    }
    else if (!strcmp(program_line, "MULT,\n")){
        return MULT;
    }
    else if (!strcmp(program_line, "NEG,\n")){
        return NEG;
    }
    else if (!strcmp(program_line, "SQRT,\n")){
        return SQRT;
    }
    else if (!strcmp(program_line, "HLT")){
        return HLT;
    }
    else{
        return -1;
    }
}