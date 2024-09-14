//
// Created by rgr24 on 17/02/2023.
//

#include "test_list.h"
#include "list.h"
#include <assert.h>
#include <stdio.h>

void test_list_prepend(void) {
    list_t list;
    list_init(&list);
    list_prepend(&list, 1);
    assert(list.head != NULL);
    assert(list.head->value == 1);
    assert(list.head->next == NULL);
    node_t * ptr = list.head;

    list_prepend(&list, -1);
    assert(list.head != NULL);
    assert(list.head->value == -1);
    assert(list.head->next == ptr);
    assert(list.head->next->value == 1);

    list_destroy(&list);

    fputs("test_list_prepend PASS\n", stderr);
}

void test_list_append(void) {
    list_t list;
    list_init(&list);
    list_append(&list, 1);
    assert(list.head != NULL);
    assert(list.head->value == 1);
    assert(list.head->next == NULL);
    node_t * head = list.head;

    list_append(&list, 2);
    assert(list.head == head);
    assert(list.head->value == 1);
    assert(list.head->next != NULL);
    assert(list.head->next->value  == 2);
    assert(list.head->next->next == NULL);

    list_destroy(&list);

    fputs("test_list_append PASS\n", stderr);
}

void test_list_at(void) {
    list_t list;
    list_init(&list);
    list_prepend(&list, 3);
    list_prepend(&list, 2);
    list_prepend(&list, 1);
    const node_t * first = list_at(&list, 0);
    const node_t * second = list_at(&list, 1);
    const node_t * third = list_at(&list, 2);
    const node_t * fourth = list_at(&list, 3);
    assert(first == list.head);
    assert(second == list.head->next);
    assert(third == list.head->next->next);
    assert(fourth == NULL);

    list_destroy(&list);

    fputs("test_list_at PASS\n", stderr);
}

void test_list_remove_first(void) {
    list_t list;
    list_init(&list);
    list_prepend(&list, 2);
    list_prepend(&list, 1);
    const node_t * last = list.head->next;
    bool removed = list_remove_first(&list);
    assert(removed);
    assert(list.head == last);
    assert(list.head->next == NULL);

    removed = list_remove_first(&list);
    assert(removed);
    assert(list.head == NULL);

    removed = list_remove_first(&list);
    assert(!removed);
    assert(list.head == NULL);

    list_destroy(&list);

    fputs("test_list_remove_first PASS\n", stderr);
}

void test_list_remove_last(void) {
    list_t list;
    list_init(&list);
    list_prepend(&list, 3);
    list_prepend(&list, 2);
    list_prepend(&list, 1);

    const node_t * first = list.head;
    const node_t * second = first->next;

    bool removed = list_remove_last(&list);
    assert(removed);
    assert(list.head == first);
    assert(first->next == second);
    assert(second->next == NULL);

    removed = list_remove_last(&list);
    assert(removed);
    assert(list.head == first);
    assert(first->next == NULL);

    removed = list_remove_last(&list);
    assert(removed);
    assert(list.head == NULL);

    removed = list_remove_last(&list);
    assert(!removed);
    assert(list.head == NULL);

    list_destroy(&list);

    fputs("test_list_remove_last PASS\n", stderr);
}

