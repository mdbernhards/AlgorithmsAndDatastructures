#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "test_list.h"

int main(void) {
    test_list_prepend();
    test_list_append();
    test_list_remove();
    test_list_insert_before();
    return 0;
}
