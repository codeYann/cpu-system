#include "opcodes.h"

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

typedef void (*Handler)(int, int);

typedef struct {
    Opcodes opcode;
    Handler handler;
} Instruction;

Instruction table[OPCODE_NUMBER];

void init_instruction_table();

#endif // INSTRUCTIONS_H