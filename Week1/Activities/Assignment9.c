#include <stdio.h>
#include <stdlib.h>

int main( void ) {
    float *grades = NULL;
    int newMemoryAdressCount = 0;
    size_t capacity = 1024;
    for (int count = 0; count < 10000; capacity += 1024, ++count) 
    {
        float *new_grades = (float*)realloc(grades, sizeof(float[capacity]));
        
        if (new_grades != NULL)
        {
            if (grades == new_grades)
            {
                newMemoryAdressCount++;
            }

            grades = new_grades;
        }

    }
    printf("New adress count: %d\n", newMemoryAdressCount);
}
