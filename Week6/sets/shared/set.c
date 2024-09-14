#include "set.h"
#include <stdlib.h>

bool ensure_capacity(set_t * set) {
    if (set->count < set->capacity) return true;
    size_t cap = (set->capacity + 1) * 3 / 2;
    double * ptr = realloc(set->data, cap * sizeof(double));
    if (ptr != NULL) {
        set->data = ptr;
        set->capacity = cap;
        return true;
    }
    else return false;
}

void set_destroy(set_t * set) {
    free(set->data);
    set->data = NULL;
    set->capacity = 0;
}

