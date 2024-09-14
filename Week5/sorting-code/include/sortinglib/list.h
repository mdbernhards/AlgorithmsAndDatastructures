#ifndef SORTING_LIST_H
#define SORTING_LIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node * next;
} node_t;

typedef struct list {
    node_t * head;
} list_t;

void node_sequence_destroy(node_t * pnode);

void list_init(list_t * plist);

void list_destroy(list_t * plist);

void list_append(list_t * plist, int value);

void list_append_multi(list_t * plist, int * values, size_t count);

node_t * node_make_sequence(int values[], size_t count);

void node_sequence_print(const node_t * first);

size_t node_sequence_length(const node_t * head);

bool list_is_sorted(node_t * first);



#endif //SORTING_LIST_H
