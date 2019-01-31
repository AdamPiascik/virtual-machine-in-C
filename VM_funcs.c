#include "myVM.h"

extern int registers[];
extern int program1[], program2[], program3[], *curr_instr;

int * fetch (char *requested_program)
{
    if (strcmp(requested_program, "program1") == 0){
        return program1 + ip;
    } 
    else if (strcmp(requested_program, "program2") == 0){
        return program2 + ip;
    }
    else if (strcmp(requested_program, "program3") == 0){
        return program3 + ip;
    }
    else{
        printf("The requested program isn't valid..\n");
        return (int *) 0;
    }
}

int isValid (int *program)
{
    if (program != (int *) 0){
        return 1;
    }
    else{
        return 0;
    }
}