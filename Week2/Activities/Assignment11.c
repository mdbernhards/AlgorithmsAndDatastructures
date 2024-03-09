#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct array {
    size_t capacity;
    size_t count;
    float *data;
} array_t;
void array_append(array_t *arr, float value){
    arr->capacity++;
    arr->data = realloc(arr->data, sizeof(float[arr->capacity]));
    arr->data[arr->count++] = value;
}

array_t *array_init(array_t *pArray, size_t capacity) {
    if (pArray != NULL) {
        pArray->data = malloc(sizeof(float[capacity]));
        pArray->count = 0;
        pArray->capacity = pArray->data != NULL ? capacity : 0;
    }

    return pArray;
}

void array_destroy(array_t *pArray) {
    if (pArray != NULL) {
        free(pArray->data);
        pArray->data = NULL;
        pArray->count = pArray->capacity = 0;
    }
}

// keep asking the user to enter a grade, stop when user enters 0
void input_grades(array_t * grades) {
    while(1) {
        printf("Please enter a grade:");
        float num;

        scanf("%f", &num);  

        if (num == 0)
        {
            break;
        }
        
        array_append(grades, num);
    }
}

// computes and returns the average grade
float compute_average(const array_t * grades) {
    float summ = 0;
    for (int i = 0; i < grades->count ; ++i) {
        summ += grades->data[i];
    }

    return summ/grades->count;
}

// counts and returns the number of grades that are at least the ←
//threshold
int num_passed(const array_t * grades, float threshold) {
    int passed = 0;
    for (int i = 0; i < grades->count; ++i) {
        if (grades->data[i] >= threshold){
            passed++;
        }
    }

    return passed;
}

int main() {
    array_t grades;
    array_init(&grades, 0);
    input_grades(&grades);
    float average = compute_average(&grades);
    int passed = num_passed(&grades, 5.5f);
    printf("Average grade: %.2f\n", average);
    printf("%d out of %zu students passed\n", passed, grades.count);
    array_destroy(&grades);
    return 0;
}