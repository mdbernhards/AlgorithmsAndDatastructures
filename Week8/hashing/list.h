//
// Created by rgr24 on 04/04/2023.
//

#ifndef HASHING_LIST_H
#define HASHING_LIST_H

#include <stddef.h>

typedef struct node {
    void *data;
    struct node *next;
} node_t;

typedef struct list {
    node_t *head;
} list_t;

node_t * node_create(void *data);
void list_init(list_t *list);

/// Destroys the list and frees all nodes.
/// @param list the list to destroy
void list_destroy(list_t *list);

/// Appends a node to the list.
/// @param list the list to append the node to
/// @param node the node to append
void list_append(list_t *list, node_t *node);

/// Prepends a node to the list.
/// @param list the list to prepend the node to
/// @param node the node to prepend
void list_prepend(list_t *list, node_t *node);

/// Removes a node from the list. Does not free the node.
/// @param list the list to remove the node from
/// @param node the node to remove
void list_remove(list_t *list, node_t *node);

/// Returns the number of nodes in the list.
/// @param list the list to count
/// @return the number of nodes in the list
size_t list_length(const list_t *list);

#endif //HASHING_LIST_H
