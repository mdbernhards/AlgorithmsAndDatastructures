#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "week4lib/utils.h"
#include "week4lib/array_of_int.h"
#include "week4lib/list_of_char.h"

typedef struct node {
    char value;
    struct node *next, *prev;
} node_t;

typedef struct list {
    node_t *head, *tail;
} list_t;

typedef struct array {
    size_t capacity;
    size_t count;
    int *data;
} array_t;

static bool array_resize(array_t *array, size_t min_capacity);

array_t *array_init(array_t *array, size_t capacity) {
    if (array != NULL) {
        array->count = 0;
        array->data = malloc(sizeof(int[capacity]));
        array->capacity = array->data ? capacity : 0;
    }
    return array;
}

void array_push_back(array_t *array, int value) {
    array_resize(array, array->capacity + 1);
    array->data[array->count++] = value;
}

bool try_array_pop_back(array_t *array, int *value) {
    if (!array->count)
        return false;

    *value = array->data[--array->count];
    return true;
}

array_t *array_create(size_t capacity) {
    return array_init((array_t*) malloc(sizeof(array_t)), capacity);
}

void array_destroy(array_t *array) {
    if (array != NULL) {
        free(array->data);
        array->data = NULL;
        array->capacity = array->count = 0;
    }
}

bool array_resize(array_t *array, size_t min_capacity) {
    if (!array) return false;
    size_t cap = array->capacity;
    while (cap < min_capacity) cap = (cap + 1) * 3 / 2;
    if (cap != array->capacity) {
        int *ptr = (int *) realloc(array->data, sizeof(int[cap]));
        if (!ptr) return false;
        array->data = ptr;
        array->capacity = cap;
    }
    return true;
}

list_t *list_init(list_t *list) {
    if (list != NULL) list->head = list->tail = NULL;
    return list;
}

bool list_try_remove_first(list_t *list, char *value) {
    node_t *current_head = list->head;     // save ptr to current head
    if (list->head == NULL) return false;   // list has no elements
    else if (list->head == list->tail) {
        // list has exactly one element
        list->head = list->tail = NULL;
    } else {
        // list has at least two elements
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    *value = current_head->value;
    free(current_head);
    return true;
}

bool list_try_remove_last(list_t *list, char *value) {
    node_t *current_tail = list->tail;     // save ptr to current tail
    if (list->tail == NULL) return false;   // list has no elements
    else if (list->tail == list->head) {
        // list has exactly one element
        list->head = list->tail = NULL;
    } else {
        // list has at least two elements
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    *value = current_tail->value;
    free(current_tail);
    return true;
}

void list_prepend(list_t *list, char value) {
    node_t *node = (node_t *) malloc(sizeof(node_t));
    node->next = list->head;
    node->prev = NULL;
    node->value = value;
    if (list->head == NULL) list->tail = node;  // empty list, so update tail as well
    else list->head->prev = node;               // non-empty list, update prev of current head
    list->head = node;                          // update head
}

void list_append(list_t *list, char value) {
    node_t *node = (node_t *) malloc(sizeof(node_t));
    node->prev = list->tail;
    node->next = NULL;
    node->value = value;
    if (list->tail == NULL) list->head = node;  // empty list, so update head as well
    else list->tail->next = node;               // non-empty list, update next of current tail
    list->tail = node;                          // update tail
}

list_t *list_create(void) {
    return list_init((list_t*) malloc(sizeof(list_t)));
}

void list_destroy(list_t *list) {
    node_t * ptr = list->head;
    while (ptr) {
        node_t * tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }
    list->head = list->tail = NULL;
}

double random_double(void) {
    static bool initialized = false;
    if (!initialized) {
        srand(time(NULL));
        initialized = true;
    }
    return ((double) rand()) / RAND_MAX;
}

bool list_try_remove(list_t *list, list_end which_end, char * value) {
    switch (which_end) {
        case FRONT:
            if (!list_try_remove_first(list, value)) return false;
            else break;
        case REAR:
            if (!list_try_remove_last(list, value)) return false;
            else break;
        default:
            fprintf(stderr, "list_try_remove: unknown list_end");
            return false;
    }
    return true;
}

void list_add(list_t *list, list_end which_end, char value) {
    switch (which_end) {
        case FRONT:
            list_prepend(list, value);
            break;
        case REAR:
            list_append(list, value);
            break;
        default:
            fprintf(stderr, "list_add: unknown list_end");
            return;
    }
}
