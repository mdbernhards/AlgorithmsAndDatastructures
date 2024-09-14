//
// Created by rgr24 on 17/02/2023.
//

#ifndef ADS_WEEK3_LIST_H
#define ADS_WEEK3_LIST_H

#include <stddef.h>

// a node in a doubly linked list
typedef struct node {
    int value;
    struct node *prev;  // address of predecessor node
    struct node *next;  // address of successor node
} node_t;

// a doubly linked list consisting of nodes that are linked together
typedef struct list {
    node_t * head;  // first element of the list
    node_t * tail;  // last element of the list
} list_t;

/// initializes a node structure
/// \param ptr address of the node to initialize
/// \param value the value to be stored in the node
/// \return the address of the initialized node
node_t * node_init(node_t * ptr, int value);

/// creates and initializes a node structure
/// \param value the value to be stored in the node
/// \return the created node (NULL if it could not be created)
node_t * node_create(int value);

/// initializes a list structure
/// \param plist the list to initialize. Must not be NULL.
/// \return the initialized list
list_t * list_init(list_t * plist);

/// Prepends a new value to the list, heap-allocating a node for it
/// \param plist the list to prepend the value to. Must not be NULL.
/// \param value the value to prepend
void list_prepend(list_t * plist, int value);

/// Appends a new heap-allocated node to the list, with the given value
/// TODO: implement in list.c (Activity 9)
/// \param plist the list to append the value to. Must not be NULL.
/// \param value the value to append
void list_append(list_t * plist, int value);

/// Removes the given node from the list
/// TODO: implement in list.c (Activity 10)
/// \param plist the list from which to remove the node. Must contain the node.
/// \param pnode the (address of the) node to remove from the list
void list_remove(list_t * plist, node_t * pnode);

/// Inserts a value into the list *before* the given node.
/// This may update the list's head, but not its tail.
/// TODO: implement in list.c (Activity 11)
/// \param plist the list into which the value must be inserted
/// \param pnode the node before which the value must be inserted
/// \param value the value to insert
void list_insert_before(list_t * plist, node_t * pnode, int value);

#endif //ADS_WEEK3_LIST_H
