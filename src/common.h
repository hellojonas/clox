#ifndef clox_common_h
#define clox_common_h

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define DEBUG_TRANCE_EXECUTION

typedef enum {
    OP_CONSTANT,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DEVIDE,
    OP_NEGATE,
    OP_RETURN
} OpCode;

#endif
