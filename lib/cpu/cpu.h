#include <stddef.h>

#ifndef CPU_H
#define CPU_H

typedef struct {
    int PC, IR, AC;     // Define the fetch-decode-execute main registers
    int R1, R2, R3, R4; // define geral purpose registers
    int *memory;        // define memory pointer
    size_t memroy_size;
} CPU;

void init(CPU *cpu, int *memory);

#endif // CPU_H