#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "test_buffer.h"
#include "buffer.h"

void test_buffer_get_write_idx(void) {
    buffer_t * buffer = buffer_create(5);

    assert(0 == buffer_get_rear_idx(buffer));

    buffer->head = 0;
    buffer->count = 1;
    assert(1 == buffer_get_rear_idx(buffer));

    buffer->head = 2;
    buffer->count = 4;
    assert(1 == buffer_get_rear_idx(buffer));

    buffer->head = 3;
    buffer->count = 5;
    assert(3 == buffer_get_rear_idx(buffer));

    buffer->head = 2;
    buffer->count = 12;
    assert(4 == buffer_get_rear_idx(buffer));

    buffer->head = 2;
    buffer->count = 12;
    buffer->capacity = 4;
    assert(2 == buffer_get_rear_idx(buffer));

    buffer->head = 1;
    buffer->count = 8;
    assert(1 == buffer_get_rear_idx(buffer));

    buffer->head = 1;
    buffer->count = 9;
    assert(2 == buffer_get_rear_idx(buffer));

    buffer_destroy(buffer);
    free(buffer);

    fputs("test_buffer_get_write_idx PASS\n", stderr);
}

void test_buffer_try_write(void) {
    buffer_t * buffer = buffer_create(3);
    bool result;
    result = buffer_try_write(buffer, 'a');
    assert(true == result);
    assert(0 == buffer->head);
    assert(1 == buffer->count);
    assert('a' == buffer->data[0]);

    result = buffer_try_write(buffer, 'b');
    assert(true == result);
    assert(0 == buffer->head);
    assert(2 == buffer->count);
    assert('b' == buffer->data[1]);

    result = buffer_try_write(buffer, 'c');
    assert(true == result);
    assert(0 == buffer->head);
    assert(3 == buffer->count);
    assert('c' == buffer->data[2]);

    result = buffer_try_write(buffer, 'd');
    assert(false == result);
    assert(0 == buffer->head);
    assert(3 == buffer->count);

    buffer->head = 1;
    buffer->count = 2;
    result = buffer_try_write(buffer, 'd');
    assert(true == result);
    assert(1 == buffer->head);
    assert(3 == buffer->count);
    assert('d' == buffer->data[0]);

    buffer_destroy(buffer);
    free(buffer);

    fputs("test_buffer_try_write PASS\n", stderr);
}

void test_buffer_try_read(void) {
    buffer_t * buffer = buffer_create(3);
    char value;
    bool result;

    buffer->data[0] = 'a';
    buffer->data[1] = 'b';
    buffer->data[2] = 'c';
    buffer->count = 3;
    result = buffer_try_read(buffer, &value);
    assert(true == result);
    assert('a' == value);
    assert(2 == buffer->count);
    assert(1 == buffer->head);
    result = buffer_try_read(buffer, &value);
    assert(true == result);
    assert('b' == value);
    assert(1 == buffer->count);
    assert(2 == buffer->head);
    result = buffer_try_read(buffer, &value);
    assert(true == result);
    assert('c' == value);
    assert(0 == buffer->count);
    assert(0 == buffer->head);
    result = buffer_try_read(buffer, &value);
    assert(false == result);
    assert(0 == buffer->count);
    assert(0 == buffer->head);
    buffer->head = 2;
    buffer->count = 3;
    result = buffer_try_read(buffer, &value);
    assert(true == result);
    assert('c' == value);
    assert(2 == buffer->count);
    assert(0 == buffer->head);
    result = buffer_try_read(buffer, &value);
    assert(true == result);
    assert('a' == value);
    assert(1 == buffer->count);
    assert(1 == buffer->head);

    buffer_destroy(buffer);
    free(buffer);

    fputs("test_buffer_try_read PASS\n", stderr);
}
