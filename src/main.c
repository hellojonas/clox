#include "chunk.h"
#include "common.h"
#include "vm.h"

int main(int argc, const char *argv[]) {
    initVM();

    Chunk chunk;
    initChunk(&chunk);

    int constant = addConstant(&chunk, 20.7);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);


    constant = addConstant(&chunk, 10);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    writeChunk(&chunk, OP_SUBTRACT, 1);

    writeChunk(&chunk, OP_RETURN, 2);

    interpret(&chunk);

    freeVM();
    freeChunk(&chunk);
}
