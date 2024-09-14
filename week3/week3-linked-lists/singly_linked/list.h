//
// Created by rgr24 on 17/02/2023.
//

#ifndef ADS_WEEK3_LIST_H
#define ADS_WEEK3_LIST_H

#include <stddef.h>
#include <stdbool.h>

// represents a node in a linked list
typedef struct node {
    int value;
    struct node *next;  // address of successor node
} node_t;

typedef struct list {
    node_t * head;
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

/// Frees the memory allocated by the nodes of the list, and resets head to NULL
/// TODO: implement in list.c (Activity 3)
/// \param plist the list to destroy
void list_destroy(list_t * plist);

/// Prepends a new value to the list, heap-allocating a node for it
/// \param plist the list to prepend the value to. Must not be NULL.
/// \param value the value to prepend
void list_prepend(list_t * plist, int value);

/// Appends a new heap-allocated node to the list, with the given value
/// TODO: implement in list.c (Activity 4)
/// \param plist the list to append the value to. Must not be NULL.
/// \param value the value to append
void list_append(list_t * plist, int value);

/// Returns the address of the node at the given index, or NULL if the node does not exist
/// TODO: implement in list.c (Activity 6)
/// \param plist the list to retrieve the node from. Must not be NULL.
/// \param index the index of the node to retrieve (0 = first, 1 = second, ...)
/// \return the address of the node at the given index, or NULL if it does not exist
const node_t * list_at(const list_t *plist, size_t index);

/// Removes the first node from the list
/// \param plist the list from which to remove the first node. Must not be NULL.
/// \return true if the list was changed, false otherwise
bool list_remove_first(list_t * plist);

/// Removes the first node from the list
/// TODO: implement in list.c (Activity 8)
/// \param plist the list from which to remove the first node. Must not be NULL.
/// \return true if the list was changed, false otherwise
bool list_remove_last(list_t * plist);

#endif //ADS_WEEK3_LIST_H
