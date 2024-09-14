//
// Created by rgr24 on 12/04/2023.
//

#include "statistics.h"

load_statistics_t hashmap_get_load_statistics(const hashmap_t *map) 
{
    load_statistics_t result = 
    {
        .load_factor = (float) map->count / map->capacity,
        .free_slots_fraction = 0.0f,
        .slots_with_more_than_x_items = {0},
        .length_of_longest_chain = 0
    };

    size_t slotsFree = 0;

    for (size_t i = 0; i < map->capacity; i++) 
    {
        size_t listLength = list_length(&map->slots[i]);

        if (listLength != 0)
        {
            if (listLength > result.length_of_longest_chain)
            {
                result.length_of_longest_chain = listLength;
            }

            for (size_t j = 0; j < 5; j++)
            {
                if (listLength > j)
                {
                    result.slots_with_more_than_x_items[j]++;
                }
            }
        } 
        else
        {
            slotsFree++;
        }
    }

    result.free_slots_fraction = (float) slotsFree / map->capacity;

    return result;

    // TODO (Activity 10): go over the slots and determine the fraction of empty slots, the number of slots with more than X items,
    //  and the length of the longest chain. Store these results in the result struct.
}

void hashmap_print_load_statistics(FILE *f, const hashmap_t *map) {
    load_statistics_t stats = hashmap_get_load_statistics(map);
    fprintf(f, "Map contains %zu items distributed over %zu slots:\n", map->count, map->capacity);
    fprintf(f, " Load factor:         %6.2f\n", stats.load_factor);
    fprintf(f, " Free slots fraction: %6.2f\n", stats.free_slots_fraction);
    for (int i = 0; i < 5; i++) {
        fprintf(f, " Slots with >%d items: %6zu\n", i, stats.slots_with_more_than_x_items[i]);
    }
    fprintf(f, " Longest chain:       %6zu\n", stats.length_of_longest_chain);
}
