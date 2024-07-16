#ifndef OPCODES_H
#define OPCODES_H

#define OPCODE_NUMBER 7

typedef enum {
    _ADD = 0x01,
    _AND = 0x21,
    _OR = 0x0B,
    _XOR = 0x31,
    _NOT = 0xF7,
    _SHL = 0xD3,
    _MOV = 0x89,
} Opcodes;


#endif // OPCODES_H