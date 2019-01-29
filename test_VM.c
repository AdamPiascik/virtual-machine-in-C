#include "myVM.h"

int stack[256];
int registers[NUM_OF_REGISTERS];
bool running = true;

int main (void) {
    while (running) {
        eval(fetch());
        ip++;
    }
}