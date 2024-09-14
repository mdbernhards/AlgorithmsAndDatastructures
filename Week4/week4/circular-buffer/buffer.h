#ifndef WEEK4_BUFFER_H
#define WEEK4_BUFFER_H

#include <stddef.h>
#include <stdbool.h>

/*
 * A structure to work with circular buffers.
 */
typedef struct buffer {
    size_t head;        // The index of the next char that is to be read
    size_t count;       // The number of characters that can be read
    size_t capacity;    // The number of characters that can be stored
    char *data;        // Address of the memory block holding the data
} buffer_t;

/// Initializes a buffer to a given capacity, with head and count set to 0
/// \param buffer An uninitialized buffer
/// \param capacity The capacity of the buffer
/// \return An initialized buffer, or NULL if an error occurred
buffer_t *buffer_init(buffer_t *buffer, size_t capacity);

/// heap-allocates and initializes a new buffer with the given capacity
/// \param capacity The capacity of the new buffer
/// \return address of a heap-allocated buffer, or NULL if an error occurred
buffer_t *buffer_create(size_t capacity);

/// Deallocates the memory holding the buffer's data
/// \param buffer The buffer to destroy
void buffer_destroy(buffer_t *buffer);

/// Returns the index into buffer's data into which the next written character will be stored
/// TODO: Implement (Activity 8)
/// \param buffer
/// \return
size_t buffer_get_rear_idx(const buffer_t *buffer);

/// Attempts to write the given character into the buffer. Fails if the buffer is full.
/// Updates the buffer's count if the character can be written.
/// TODO: Implement (Activity 9)
/// \param buffer The buffer to write character into
/// \param character The character to be written into the buffer
/// \return true if the character could be written, false if the buffer was full
bool buffer_try_write(buffer_t *buffer, char character);

/// Attemps to read the next character from the buffer. Fails if the buffer is empty
/// Updates the buffer's count and head if a character was read
/// TODO: Implement (Activity 10)
/// \param buffer The buffer to read the character from
/// \param character char-address at which the retrieved character is to be stored
/// \return true if a character was read, false if the buffer was empty
bool buffer_try_read(buffer_t *buffer, char *character);

#endif //WEEK4_BUFFER_H
