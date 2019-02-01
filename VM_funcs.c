#include "myVM.h"

// load externally declared variables
// from "programs.c"
// extern int program1[], program2[], program3[]; 
// extern size_t program1_length, program2_length, program3_length;
 // from "myVM.c"
extern int stack[];

//  Define an array of CPU registers, each of 32 bit size
extern int registers[];

/*  This function moves data from the stack to the registers. If called with
    "instructions" as the "from" argument, it fetches data from the instruction
    block and loads it starting from R0. If called with "stack" as the "from"
    argument, it fetches data from the top of the stack and loads it
    sequentially from R1. */
void fetch (char* from, int instr)
{
    if (strcmp(from, "instructions") == 0){
        if (instr != PSH){
            CURR_REGISTER = R0;
            registers[CURR_REGISTER] = instr;
            ++CURR_REGISTER;
        }
        else if (instr == PSH){
            CURR_REGISTER = R0;
            registers[CURR_REGISTER] = stack[CURR_INSTRUCTION++];
            ++CURR_REGISTER;
            registers[CURR_REGISTER] = stack[CURR_INSTRUCTION];
            ++CURR_REGISTER;
        }    
    }
    else if (strcmp(from, "stack") == 0){
        registers[CURR_REGISTER] = instr;
        ++CURR_REGISTER;
    }
}

void loadFileProgram (char *requested_program)
{
    char full_path[3] = ".\\", suffix[5] = ".txt";
    strncat(requested_program, suffix, 4);
    strncat(full_path, requested_program, strlen(requested_program));
    FILE *program_file = fopen(full_path, "r");
    char line[16];
    int i = 0;

    while (fgets(line, sizeof(line), program_file)){
        if (isalpha(line[0])){
            stack[i] = makeInstruction(line); 
        }
        else{
            stack[i] = atoi(line);
        }        
        ++i;
    }

    fclose(program_file);
    CURR_INSTRUCTION = 0;
    CURR_STACK_TOP = i;   
}

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
    else if (!strcmp(program_line, "HLT")){
        return HLT;
    }
    else{
        return -1;
    }
}
