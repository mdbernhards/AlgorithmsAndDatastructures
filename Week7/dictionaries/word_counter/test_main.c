#include "test_counter.h"

int main(void) {
    // TODO (Activity 7): implement the following functions in counter.c
    //  counter_init
    //  counter_contains_key
    //  counter_get_count
    //  counter_remove_key
    //  counter_increment
    //  counter_destroy
    //  All tests must pass, and the address sanitizer must find no issues
    test_counter_init();
    test_counter_contains_key();
    test_counter_get_count();
    test_counter_remove_key();
    test_counter_increment();

    return 0;
}
