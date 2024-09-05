#include "value.h"
#include "memory.h"
#include <stdlib.h>

void initValueArray(ValueArray *array) {
    array->count = 0;
    array->capacity = 0;
    array->values = NULL;
}

void freeValueArray(ValueArray *array) {
    free(array->values);
    initValueArray(array);
}

void writeValueArray(ValueArray *array, Value value) {
    if (array->capacity < array->count + 1) {
        int oldSize = array->capacity;
        array->capacity = GROW_CAPACITY(oldSize);
        array->values = GROW_ARRAY(Value, array->values, oldSize, array->capacity);
    }

    array->values[array->count] = value;
    array->count++;
}
