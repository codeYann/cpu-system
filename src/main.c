#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int REGISTERS_NUMBER = 8;
const size_t MEM_SIZE = 1024;
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
} Register;

typedef enum {
    MOV_REG_TO_REG = 0x00,
    MOV_MEM_TO_REG = 0x01,
    MOV_REG_TO_MEM = 0x02,
    AND_GATE = 0x03,
    OR_GATE = 0x04,
    XOR_GATE = 0x05,
    NOT_GATE = 0x06,
    ADD = 0x07,
} Opcode;

typedef struct {
    int *registers;     // Registers pointer
    int *memory;        // Memory pointer
    size_t memory_size; // Memory size
    long clock_cycles;  // Counts cycles
} CPU;

CPU *init(size_t memory_size) {
    CPU *cpu = (CPU *)malloc(sizeof(CPU));

    if (!cpu) {
        perror("Failed to allocate CPU!");
        exit(EXIT_FAILURE);
    }

    cpu->registers = (int *)malloc(REGISTERS_NUMBER * sizeof(int));

    if (!cpu->registers) {
        perror("Failed to allocate registers buffer!");
        exit(EXIT_FAILURE);
    }

    cpu->memory = (int *)malloc(memory_size * sizeof(int));

    if (!cpu->memory) {
        perror("Failed to allocate memory!");
        exit(EXIT_FAILURE);
    }

    cpu->memory_size = memory_size;
    cpu->clock_cycles = 0;

    return cpu;
}

void mov_reg_to_reg(CPU *cpu, Register dest, Register src) {
    cpu->registers[dest] = cpu->registers[src];
}

void mov_mem_to_reg(CPU *cpu, Register dest, size_t address) {
    if (address < 0x00 || address > MEM_SIZE) {
        fprintf(stderr, "Memory access out of bounds!");
        return;
    }
    memcpy(&cpu->registers[dest], &cpu->memory[address], sizeof(int));
}

void mov_reg_to_mem(CPU *cpu, size_t address, Register src) {
    if (address < 0x00 || address > MEM_SIZE) {
        fprintf(stderr, "Memory access out of bounds!");
        return;
    }
    memcpy(&cpu->memory[address], &cpu->registers[src], sizeof(int));
}

void and_gate(CPU *cpu, Register dest, Register src) {
    cpu->registers[dest] &= cpu->registers[src];
}

void or_gate(CPU *cpu, Register dest, Register src) {
    cpu->registers[dest] |= cpu->registers[src];
}
void xor_gate(CPU *cpu, Register dest, Register src) {
    cpu->registers[dest] ^= cpu->registers[src];
}

void not_gate(CPU *cpu, Register dest, Register src) {
    cpu->registers[dest] = ~cpu->registers[src];
}

void add(CPU *cpu, Register dest, Register a, Register b) {
    int temp = 0;

    while (cpu->registers[b]) {
        temp = cpu->registers[a];
        cpu->registers[a] ^= cpu->registers[b];
        cpu->registers[b] = (temp & cpu->registers[a]) << 1;
    }

    cpu->registers[dest] = cpu->registers[a];
}

int main(int argc, char **argv) {

    CPU *cpu = init(MEM_SIZE);

    cpu->memory[1023] = 30;
    cpu->registers[EAX] = 10;
    cpu->registers[EBX] = 40;

    printf("EAX = %d, EBX = %d\n", cpu->registers[EAX], cpu->registers[EBX]);

    mov_reg_to_reg(cpu, EAX, EBX);
    printf("EAX = %d, EBX = %d\n", cpu->registers[EAX], cpu->registers[EBX]);

    mov_mem_to_reg(cpu, EAX, 1023);
    printf("EAX = %d, EBX = %d\n", cpu->registers[EAX], cpu->registers[EBX]);

    or_gate(cpu, EAX, EBX);

    printf("EAX = %d, EBX = %d\n", cpu->registers[EAX], cpu->registers[EBX]);

    free(cpu->memory);
    free(cpu->registers);
    free(cpu);
}
