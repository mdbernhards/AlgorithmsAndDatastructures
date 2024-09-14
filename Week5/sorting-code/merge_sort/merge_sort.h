#ifndef SORTING_MERGE_SORT_H
#define SORTING_MERGE_SORT_H

#include <sortinglib/list.h>

/// splits a linked list in two halves. The list must not be empty
/// TODO: Complete implementation (Activity ...)
/// \param phead the first node of the list, passed by pointer.
/// \return the first node of the second half of the list, returned by pointer
node_t *split(node_t *phead);

/// Merges two lists
/// TODO: Complete implementation (Activity ...)
/// \param a the first node of the first list, passed by pointer
/// \param b the first node of the second list, passed by pointer
/// \return the first node of the merged list, returned by pointer
node_t *merge(node_t *a, node_t *b);

/// sorts an entire linked list using merge sort
/// TODO: Implement (Activity ...)
/// \param first the first node in the unsorted linked list
/// \return the first node in the sorted linked list
node_t *merge_sort(node_t *first);

/// sorts a linked list, using merge sort
void list_sort(list_t *plist);

#endif //SORTING_MERGE_SORT_H
