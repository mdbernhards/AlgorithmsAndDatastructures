#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void node_init(node_t **ppnode, int value) {
    node_t * ptr = malloc(sizeof(node_t));
    if (ptr != NULL) {
        ptr->value = value;
        ptr->next = NULL;
    }
    *ppnode = ptr;
}

void node_sequence_destroy(node_t *pnode) {
    while (pnode != NULL) {
        node_t * next = pnode->next;
        free(pnode);
        pnode = next;
    }
}

void list_init(list_t *plist) {
    plist->head = NULL;
}

void list_destroy(list_t *plist) {
    node_sequence_destroy(plist->head);
    plist->head = NULL;
}

void list_append(list_t *plist, int value) {
    node_t ** ptr = &plist->head;
    while (*ptr != NULL) {
        ptr = &(*ptr)->next;
    }
    node_init(ptr, value);
}

void list_append_multi(list_t *plist, int *values, size_t count) {
    if (count == 0) return;

    node_t ** ptr = &plist->head;
    while (*ptr != NULL) {
        ptr = &(*ptr)->next;
    }
    node_init(ptr, values[0]);
    for (size_t i = 1; i < count; i++) {
        ptr = &(*ptr)->next;
        node_init(ptr, values[i]);
    }
}

void node_sequence_print(const node_t *first) {
    printf("[");
    if (first != NULL) {
        printf("%d", first->value);
        first = first->next;
        while (first != NULL) {
            printf(", %d", first->value);
            first = first->next;
        }
    }
    printf("]");
}

bool list_is_sorted(node_t *first) {
    if (!first) return true;    // an empty list is sorted
    while (first->next != NULL) {
        if (first->next->value < first->value) return false;
        first = first->next;
    }
    return true;
}

size_t node_sequence_length(const node_t *head) {
    size_t length = 0;
    while (head) {
        head = head->next;
        length++;
    }
    return length;
}

node_t *node_create(int value) {
    node_t * node = (node_t*) malloc(sizeof(node_t));
    if (node != NULL) {
        node->next = NULL;
        node->value = value;
    }
    return node;
}

node_t *node_make_sequence(int *values, size_t count) {
    node_t sentinel = {.next = NULL };
    node_t * ptr = &sentinel;
    for (size_t i = 0; i < count; ++i) ptr = ptr->next = node_create(values[i]);
    return sentinel.next;
}

