#include "debug.h"
#include "common.h"
#include <stdint.h>
#include <stdio.h>

void disassembleChunk(Chunk *chunk, const char *name) {
    printf("== %s ==\n", name);

    int offset = 0;

    while (offset < chunk->count) {
        offset = disassembleInstruction(chunk, offset);
    }
}

int disassembleInstruction(Chunk *chunk, int offset) {
    uint8_t instruction = chunk->code[offset];
        printf("%04d ", instruction);

    if (offset > 0 && chunk->lines[offset] == chunk->lines[offset-1]) {
        printf("   | ");
    } else {
        printf("%4d ", chunk->lines[offset]);
    }

    switch (instruction) {
        case OP_CONSTANT: {
            return constantInstruction("OP_CONSTANT", chunk, offset);
        }
        case OP_RETURN: {
            return simpleInstruction("OP_RETURN", offset);
        }
        default: {
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
        }
    }
}

static int constantInstruction(const char *name, Chunk *chunk, int offset) {
    uint8_t constant = chunk->code[offset + 1];
    Value value = chunk->counstants.values[constant];

    printf("%-16s %4d '", name, constant);
    printValue(chunk->counstants.values[constant]);
    printf("'\n");

    return offset + 2;
}

static int simpleInstruction(const char *name, int offset) {
    printf("%s\n", name);
    return offset + 1;
}
