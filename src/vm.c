#include "vm.h"
#include "chunk.h"
#include "common.h"
#include "debug.h"
#include "value.h"
#include <stdio.h>

VM vm;

void initVM() {
    resetStack();
}

void freeVM() {
}

static void resetStack() {
    vm.stackTop = vm.stack;
}

void push(Value value) {
    *vm.stackTop = value;
    vm.stackTop++;
}

Value pop() {
    vm.stackTop--;
    return *vm.stackTop;
}

InterpretResult interpret(Chunk *chunk) {
    vm.chunk = chunk;
    vm.ip = chunk->code;
    return run();
}

InterpretResult run() {
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk->counstants.values[READ_BYTE()])
#define BINARY_OP(op)                                                          \
    do {                                                                       \
        double b = pop();                                                      \
        double a = pop();                                                      \
        push(a op b);                                                          \
    } while (false)

    for (;;) {
#ifdef DEBUG_TRANCE_EXECUTION
        printf("          ");
        for (Value *slot = vm.stack; slot < vm.stackTop; slot++) {
            printf("[ ");
            printValue(*slot);
            printf(" ]");
        }
        printf("\n");
        disassembleInstruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
#endif

        uint8_t instruction = READ_BYTE();
        switch (instruction) {
        case OP_CONSTANT: {
            Value constant = READ_CONSTANT();
            push(constant);
            printf("\n");
            break;
        }
        case OP_ADD: {
            BINARY_OP(+);
            break;
        }
        case OP_SUBTRACT: {
            BINARY_OP(-);
            break;
        }
        case OP_MULTIPLY: {
            BINARY_OP(*);
            break;
        }
        case OP_DEVIDE: {
            BINARY_OP(/);
            break;
        }
        case OP_NEGATE: {
            push(-pop());
            break;
        }
        case OP_RETURN: {
            printValue(pop());
            printf("\n");
            return INTERPRET_OK;
        }
        }
    }

#undef READ_BYTE
#undef READ_CONSTANT
#undef BINARY_OP
}
