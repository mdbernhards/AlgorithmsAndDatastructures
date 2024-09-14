#include <stdio.h>
#include <week4lib/array_of_int.h>
#include <week4lib/utils.h>

void push_pop(array_t * stack, size_t count) {
    int value;
    for (size_t i = 0; i < count; ++i) {
        while (random_double() < 0.5 && try_array_pop_back(stack, &value)) {
            printf(" %d", value);
        }
        array_push_back(stack, i);
    }
    while (try_array_pop_back(stack, &value)) printf(" %d", value);
    puts("");
}

int main(void) {
    array_t * array = array_create(10);
    push_pop(array, 10);
    array_destroy(array);

    return 0;
}
