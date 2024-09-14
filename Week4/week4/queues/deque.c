#include "deque.h"

bool try_read_deque(list_t *list, char *value) {
    return list_try_remove(list, REAR, value);
}

void  write_deque(list_t *list, char value) {
    list_add(list, FRONT, value);
}
