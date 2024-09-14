#include <stdio.h>
#include "selection_sort.h"

size_t g_compares = 0;

int *find_min(int *values, size_t count) {
    int* min = values;

    if (count <= 0)
    {
        return NULL;
    }


    for (size_t i = 1; i < count; i++)
    {
        if (*min > values[i])
        {
            min = &values[i];
        }

        g_compares++;
    }
    
    return min;
}

void array_sort(array_t *array) {
    if (array->count <= 0)
    {
        return;
    }

    for (size_t i = 0; i < array->count; i++)
    {
        swap(&array->data[i], find_min(&array->data[i], array->count - i));
    }
}
