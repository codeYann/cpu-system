#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define REGISTERS_NUMBER 8
#define MEM_SIZE 1024
// define registers;
typedef enum {
    EAX = 0,
    EBX,
    ECX,
    EDX,
    ESI,
    EDI,
    ESP,
    EBP,
    PC,
    IC,
    AC,
    R1,
    R2,
    R3,
    R4
} Registers;

typedef struct {
    size_t *registers;  // Registers pointer
    size_t *memory;     // Memory pointer
    size_t memory_size; // Memory size
    long clock_cycles;  // Counts cycles
} CPU;

CPU *init(size_t *memory) {
    CPU *cpu = (CPU *)malloc(sizeof(CPU));
    cpu->registers = (size_t *)malloc(REGISTERS_NUMBER * sizeof(size_t));
    cpu->memory = memory;
    cpu->memory_size = sizeof(memory);
    cpu->clock_cycles = 0;
}

int main(int argc, char **argv) {
    // size_t memory[MEM_SIZE];
    //
    // CPU *cpu = init(&memory);
    //
    // printf("%lu", cpu->clock_cycles);
    printf("hello, world!");
}
