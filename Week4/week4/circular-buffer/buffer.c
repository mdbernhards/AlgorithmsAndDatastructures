#include <stdlib.h>
#include "buffer.h"

buffer_t *buffer_init(buffer_t *buffer, size_t capacity) {
    if (buffer != NULL) {
        buffer->head = buffer->count = buffer->capacity = 0;
        buffer->data = (char *) malloc(sizeof(char[capacity]));
        if (buffer->data != NULL) buffer->capacity = capacity;
    }
    return buffer;
}

buffer_t *buffer_create(size_t capacity) {
    return buffer_init((buffer_t *) malloc(sizeof(buffer_t)), capacity);
}

void buffer_destroy(buffer_t *buffer) {
    if (buffer != NULL) {
        free(buffer->data);
        buffer->count = buffer->capacity = 0;
    }
}

size_t buffer_get_rear_idx(const buffer_t *buffer) {
    return (buffer->head + buffer->count) % buffer->capacity;
}

bool buffer_try_write(buffer_t *buffer, char character) {
    if (buffer->count < buffer->capacity)
    {
        size_t write_idx = buffer_get_rear_idx(buffer);
        buffer->data[write_idx] = character;
        buffer->count++;

        return true;
    }

    return false;
}

bool buffer_try_read(buffer_t *buffer, char *character) {
    if (buffer->count > 0)
    {
        *character = buffer->data[buffer->head];
        if(*character != '\0')
        {
            buffer->count--;
            buffer->head = (buffer->head + 1) % buffer->capacity;
            
            return true;
        }
    }

    return false;
}
