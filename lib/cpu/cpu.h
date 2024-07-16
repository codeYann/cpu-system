#include <stddef.h>

#ifndef CPU_H
#define CPU_H

typedef struct {
    int PC, IR, AC;       // Fetch-decode-execute main registers
    int R1, R2, R3, R4;   // A geral purpose registers
    unsigned int *memory; // Memory pointer
    size_t memroy_size;   // Memory size
    long clock_cycles;    // Counts cycles
    void (*instructions[256])(
        struct CPU *cpu); // Array of function pointers for instruction
} CPU;

void init(CPU *cpu, unsigned int *memory);
void fetch(CPU *cpu);
void decode(CPU *cpu);
void execute(CPU *cpu);

#endif // CPU_H