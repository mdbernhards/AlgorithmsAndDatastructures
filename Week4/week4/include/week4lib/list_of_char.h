//
// Created by rgr24 on 11/03/2023.
//

#ifndef WEEK4_LIST_OF_CHAR_H
#define WEEK4_LIST_OF_CHAR_H

#include <stdbool.h>

typedef struct list list_t;

typedef enum {
    FRONT, REAR
} list_end;
list_t * list_create(void);

void list_destroy(list_t * list);

bool list_try_remove_first(list_t *list, char *value);

bool list_try_remove_last(list_t *list, char *value);

void list_prepend(list_t *list, char value);

void list_append(list_t *list, char value);

bool list_try_remove(list_t *list, list_end which_end, char * value);

void list_add(list_t *list, list_end which_end, char value);

#endif //WEEK4_LIST_OF_CHAR_H
