#ifndef WEEK4_DEQUE_H
#define WEEK4_DEQUE_H


#include <stdbool.h>
#include "week4lib/list_of_char.h"

/// Attempts to read/remove the next value from a linked list. Fails if the list is empty.
/// \param list The list to read from
/// \param value char-address at which the removed value will be stored
/// \return false if no value could be read
bool try_read_deque(list_t * list, char * value);

/// Adds a character to a linked list
/// \param list The list to add the character to
/// \param value The character value to add to the list
void write_deque(list_t * list, char value);

#endif //WEEK4_DEQUE_H
