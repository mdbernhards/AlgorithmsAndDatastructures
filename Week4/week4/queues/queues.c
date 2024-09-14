
#include <stdio.h>
#include <stdlib.h>
#include <week4lib/utils.h>
#include <week4lib/list_of_char.h>
#include "deque.h"

/// Copies an input file to an output file, character by character and via a double-ended queue
/// \param input The file to read from
/// \param output The file to write to
/// \param deque The double-ended queue (a doubly linked list) to temporarily store the characters
void copy_file(FILE * input, FILE * output, list_t * deque) {
    char value;
    while (!feof(input)) {
        // write some characters from the deque into the output file
        while (random_double() < 0.5 && try_read_deque(deque, &value)) {
            fputc(value, output);
        }

        // read next character from file, write it into the deque
        write_deque(deque, fgetc(input));
    }
    // write remaining characters from the deque into the output file
    while (try_read_deque(deque, &value)) {
        fputc(value, output);
    }
}

int main(void) {
    // TODO (Activity 4):
    //  Implement try_read_deque and write_deque in deque.c
    //  Run this program, and verify whether the text from input.txt was successfully
    //  copied into the file output.txt

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

    list_t * list = list_create();
    copy_file(input, output, list);
    list_destroy(list);
    free(list);

    fclose(input);
    fclose(output);

    return 0;
}
