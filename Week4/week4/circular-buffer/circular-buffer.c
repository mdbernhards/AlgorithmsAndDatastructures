#include <stdio.h>
#include <stdlib.h>
#include "buffer.h"
#include "test_buffer.h"
#include <week4lib/utils.h>

/// Copies an input file to an output file via a buffer, character by character
/// \param input The file to read from
/// \param output The file to write to
/// \param buffer The buffer to temporarily store the characters
void copy_file(FILE * input, FILE * output, buffer_t * buffer) {
    char value, ch;
    ch = fgetc(input);
    while (!feof(input)) {
        // write some characters from the buffer into the output file
        while (random_double() < 0.5 && buffer_try_read(buffer, &value)) {
            fputc(value, output);
        }

        // read next character
        if (buffer_try_write(buffer, ch)) ch = fgetc(input);
    }
    // write remaining characters from the buffer into the output file
    while (buffer_try_read(buffer, &value)) {
        fputc(value, output);
    }
}

int main(void) {
    // Activity 8: implement buffer_get_rear_idx
    test_buffer_get_write_idx();

    // Activity 9: implement buffer_try_write
    test_buffer_try_write();

    // Activity 10: implement buffer_try_read
    test_buffer_try_read();

    // read file char by char, write output file char by char
    FILE * input = fopen("input.txt", "r");
    FILE * output = fopen("output.txt", "w");

    if (input == NULL) {
        fputs("error opening input file\n", stderr);
        return 1;
    }
    if (output == NULL) {
        fputs("error creating output file\n", stderr);
        return 1;
    }

    buffer_t * buffer = buffer_create(20);
    copy_file(input, output, buffer);
    buffer_destroy(buffer);
    free(buffer);

    fclose(input);
    fclose(output);

    return 0;
}
