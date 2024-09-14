#include "set.h"
#include <malloc.h>

void set_add(set_t * set, double value) 
{
    if (!ensure_capacity(set) || set_contains(set, value)) 
    {
        return;
    }

    set->data[set->count++] = value;
}

void set_remove(set_t * set, double value) 
{
    bool valueFound = false;

    for (size_t i = 0; i < set->count; i++)
    {
        if (set->eq_fun(set->data[i], value) && !valueFound)
        {
            valueFound = true;
            set->data[i] = set->data[i + 1];
            set->count--;
        }
        else if (valueFound)
        {
            set->data[i] = set->data[i + 1];
        }
    }
}

bool set_contains(const set_t * set, double value) 
{
    for (size_t i = 0; i < set->count; i++)
    {
        if (set->eq_fun(set->data[i], value))
        {
            return true;
        }
    }
    
    return false;
}

set_t * set_create(size_t init_cap, eq_fun_t fun) {
    return set_init((set_t*) malloc(sizeof(set_t)), init_cap, fun);
}

set_t * set_init(set_t * set, size_t init_cap, eq_fun_t fun) {
    if (set != NULL) {
        set->eq_fun = fun;
        set->data = (double*) malloc(sizeof(double) * init_cap);
        set->count = 0;
        set->capacity = set->data != NULL ? init_cap : 0;
    }
    return set;
}

