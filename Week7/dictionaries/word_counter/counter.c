#include <string.h>
#include <stdlib.h>
#include "counter.h"
#include "binsearch.h"

/// Ensures that the counter can store at least one more element
/// \param counter The counter
/// \return true if the counter can store at least one more element, false otherwise
static bool _ensure_capacity(counter_t *counter) 
{
    if (counter->count < counter->capacity) return true;
    size_t cap = (counter->capacity + 1) * 3 / 2;
    void *ptr = realloc(counter->data, cap * sizeof(pair_t));
    if (ptr != NULL) {
        counter->data = ptr;
        counter->capacity = cap;
        return true;
    } else return false;
}

counter_t *counter_create(size_t init_cap) 
{
    return counter_init((counter_t *) malloc(sizeof(counter_t)), init_cap);
}

counter_t *counter_init(counter_t *counter, size_t init_cap) 
{
    if (counter != NULL) {
        counter->data = malloc(init_cap * sizeof(pair_t));
        counter->count = 0;
        counter->capacity = counter->data != NULL ? init_cap : 0;
    }

    return counter;
}

bool counter_contains_key(const counter_t *counter, const char *key)
{
    if (counter == NULL && key == NULL)
    {
        return false;
    }

    pair_t tempPair = make_pair(key);
    bsearch_compare_fun compare = (bsearch_compare_fun)compare_pairs;

    bsearch_result_t result = binary_search(&tempPair, counter->data, counter->count, sizeof(pair_t), *compare);
    return result.found;
}

size_t counter_get_count(const counter_t *counter, const char *key)
{
    if (counter == NULL && key == NULL)
    {
        return false;
    }

    pair_t tempPair = make_pair(key);
    bsearch_compare_fun compare = (bsearch_compare_fun)compare_pairs;

    bsearch_result_t result = binary_search(&tempPair, counter->data, counter->count, sizeof(pair_t), *compare);

    if (result.found)
    {
        return counter->data[result.index].value;
    }
    else
    {
        return 0;
    }
}

void counter_remove_key(counter_t *counter, const char *key) 
{
    if (counter == NULL && key == NULL)
    {
        return;
    }

    pair_t tempPair = make_pair(key);
    bsearch_compare_fun compare = (bsearch_compare_fun)compare_pairs;
    
    bsearch_result_t result = binary_search(&tempPair, counter->data, counter->count, sizeof(pair_t), *compare);

    if (!result.found)
    {
        return;
    }

    memcpy(&counter->data[result.index], &counter->data[result.index + 1], (counter->count - result.index - 1) * sizeof(pair_t));
    counter->count--;
}

void counter_increment(counter_t *counter, const char *key) 
{
    if (counter == NULL && key == NULL)
    {
        return;
    }

    pair_t tempPair = make_pair(key);
    bsearch_compare_fun compare = (bsearch_compare_fun)compare_pairs;

    bsearch_result_t result = binary_search(&tempPair, counter->data, counter->count, sizeof(pair_t), *compare);

    if (result.found)
    {
        counter->data[result.index].value++;

    }
    else if (_ensure_capacity(counter))
    {
        memcpy(&counter->data[result.index + 1], &counter->data[result.index], (counter->count - result.index) * sizeof(pair_t));
        counter->data[result.index] = tempPair;
        counter->count++;
    }
}

void counter_destroy(counter_t *counter) 
{
    if (counter == NULL && counter->data == NULL)
    {
        return;
    }

    for (size_t i = 0; i < counter->count; i++)
    {
       destroy_pair(&counter->data[i]);
    }

    free(counter->data);
    counter = NULL;
}