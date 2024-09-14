//
// Created by rgr24 on 04/04/2023.
//

#include "list.h"
#include <stdlib.h>

node_t *node_create(void *data) {
    node_t *node = malloc(sizeof(node_t));
    if (node == NULL) return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

void list_init(list_t *list) {
    if (list != NULL) list->head = NULL;
}

void list_destroy(list_t *list) {
    if (list == NULL) return;
    node_t *current = list->head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
}

void list_append(list_t *list, node_t *node) {
    if (list == NULL) return;
    if (node == NULL) return;
    if (list->head == NULL) {
        list->head = node;
        return;
    }
    node_t *current = list->head;
    while (current->next != NULL) current = current->next;
    current->next = node;
}

void list_prepend(list_t *list, node_t *node) {
    if (list == NULL) return;
    if (node == NULL) return;
    node->next = list->head;
    list->head = node;
}

void list_remove(list_t *list, node_t *node) {
    if (list == NULL || node == NULL) return;
    node_t *current = list->head;
    node_t *previous = NULL;
    while (current != NULL) {
        if (current == node) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

size_t list_length(const list_t *list) {
    if (list == NULL) return 0;
    size_t length = 0;
    for (const node_t *current = list->head; current != NULL; current = current->next) length++;
    return length;
}
