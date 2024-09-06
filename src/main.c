#include "chunk.h"
#include "common.h"
#include "value.h"
#include "debug.h"

int main(int argc, const char* argv[]) {
    Chunk chunk;
    initChunk(&chunk);

    writeChunk(&chunk, OP_CONSTANT, 1);

    uint8_t constant = chunk.counstants.count;
    writeValueArray(&chunk.counstants, 20.7);
    writeChunk(&chunk, constant, 1);

    writeChunk(&chunk, OP_RETURN, 1);

    disassembleChunk(&chunk, "Test Chunk");
}
