#ifndef clox_debug_h
#define clox_debug_h

#include "common.h"
#include "chunk.h"

void disassembleChunk(Chunk *chunk, const char *name);
int disassembleInstruction(Chunk *chunk, int offset);
static int constantInstruction(const char *name, Chunk *chunk, int offset);
static int simpleInstruction(const char *name, int offset);

#endif
