//
// Created by rgr24 on 17/02/2023.
//

#include "test_list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void test_list_prepend(void) {
    list_t list;
    list_init(&list);
    list_prepend(&list, 1);
    assert(list.head == list.tail);
    assert(list.head != NULL);
    assert(list.head->value == 1);
    assert(list.head->next == NULL);
    assert(list.head->prev == NULL);

    list_prepend(&list, -1);
    assert(list.head != list.tail);
    assert(list.head != NULL);
    assert(list.tail != NULL);

    assert(list.head->value == -1);
    assert(list.head->next == list.tail);
    assert(list.head->prev == NULL);

    assert(list.tail->value == 1);
    assert(list.tail->prev == list.head);
    assert(list.tail->next == NULL);

    free(list.tail);
    free(list.head);

    fputs("test_list_prepend PASS\n", stderr);
}

void test_list_append(void) {
    list_t list;
    list_init(&list);
    list_append(&list, 1);
    assert(list.head == list.tail);
    assert(list.head != NULL);
    assert(list.head->value == 1);
    assert(list.head->next == NULL);
    assert(list.head->prev == NULL);

    list_append(&list, 2);
    assert(list.head != list.tail);
    assert(list.head != NULL);
    assert(list.tail != NULL);

    assert(list.head->value == 1);
    assert(list.head->next == list.tail);
    assert(list.head->prev == NULL);

    assert(list.tail->value == 2);
    assert(list.tail->prev == list.head);
    assert(list.tail->next == NULL);

    free(list.tail);
    free(list.head);

    fputs("test_list_append PASS\n", stderr);
}

void test_list_remove(void) {
    list_t list;
    list_init(&list);
    list_prepend(&list, 4);
    list_prepend(&list, 3);
    list_prepend(&list, 2);
    list_prepend(&list, 1);

    // remove second element, leaving three elements
    list_remove(&list, list.head->next);
    assert(list.head != NULL);
    assert(list.tail != NULL);
    assert(list.head->next != NULL);
    assert(list.tail->prev != NULL);
    assert(list.head->next == list.tail->prev);
    assert(list.tail->prev == list.head->next);
    assert(list.head->next->next == list.tail);
    assert(list.head == list.tail->prev->prev);
    assert(list.head->value == 1);
    assert(list.head->next->value == 3);
    assert(list.tail->value == 4);

    // remove first element, leaving two elements
    list_remove(&list, list.head);
    assert(list.head != NULL);
    assert(list.tail != NULL);
    assert(list.head->next == list.tail);
    assert(list.head == list.tail->prev);
    assert(list.head->value == 3);
    assert(list.tail->value == 4);

    // remove last element, leaving a single element
    list_remove(&list, list.tail);
    assert(list.head != NULL);
    assert(list.head == list.tail);
    assert(list.head->next == NULL);
    assert(list.head->prev == NULL);
    assert(list.head->value == 3);

    // remove last element from the list
    list_remove(&list, list.head);
    assert(list.head == NULL);
    assert(list.tail == NULL);

    fputs("test_list_remove PASS\n", stderr);
}

void test_list_insert_before(void) {
    list_t list;
    list_init(&list);
    list_prepend(&list, 1);

    // insert value -1 before 1 (prepend), contents are now -1,1
    list_insert_before(&list, list.head, -1);
    assert(list.head != NULL);
    assert(list.head->value == -1);
    assert(list.tail != NULL);
    assert(list.tail->value == 1);
    assert(list.head->prev == NULL);
    assert(list.head->next == list.tail);
    assert(list.tail->prev == list.head);
    assert(list.tail->next == NULL);

    // insert value 0 before 1, contents are now -1,0,1
    list_insert_before(&list, list.tail, 0);
    assert(list.head != NULL);
    assert(list.head->value == -1);
    assert(list.tail != NULL);
    assert(list.tail->value == 1);
    assert(list.head->prev == NULL);
    assert(list.head->next != NULL);
    assert(list.tail->prev != NULL);
    assert(list.head->next == list.tail->prev);
    assert(list.head->next->next == list.tail);
    assert(list.head == list.tail->prev->prev);
    assert(list.tail->next == NULL);

    free(list.head->next->next);
    free(list.head->next);
    free(list.head);

    fputs("test_list_insert_before PASS\n", stderr);
}
