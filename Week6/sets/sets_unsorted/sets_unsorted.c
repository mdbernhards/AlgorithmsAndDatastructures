#include <set.h>
#include "test_set.h"

int main(void) {
    // Part 1 - a set using an unsorted array
    test_unsorted_set_contains();
    test_unsorted_set_add();
    test_unsorted_set_remove();

    return 0;
}
