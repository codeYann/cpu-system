#include "cpu.h"

void init(CPU *cpu, int *memory) {
    cpu->PC = 0;
    cpu->IR = 0;
    cpu->AC = 0;
    cpu->R1 = 0;
    cpu->R2 = 0;
    cpu->R3 = 0;
    cpu->R4 = 0;
    cpu->memory = memory;
    cpu->memroy_size = sizeof(memory);
}