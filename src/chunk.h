#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

typedef struct {
    int count;
    int capacity;
    int line;
    uint8_t* code;
    ValueArray counstants;
    int* lines;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
void addConstant(Chunk *chunk, Value value);

#endif
