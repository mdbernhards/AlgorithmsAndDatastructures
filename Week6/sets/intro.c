#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool is_even(int x) {
    return x % 2 == 0;
}

bool is_odd(int x) {
    return !is_even(x);
}

int print_subtraction(int a, int b) 
{
    return a - b;
}

int print_division_remainder(int a, int b) 
{
    return a % b;
}

void fun_with_ints(int (*funptr)(int, int)) 
{
    for (int r = 1; r <= 15; ++r) 
    {
        for (int c = 1; c <= 15; ++c) 
        {
            int result = funptr(r, c);
            printf(" %5d", result);
        }
        printf("\n");
    }
    printf("\n\n");
}

bool equals_dbl(double a, double b)    // Activity 1
{
    return fabs(a-b) < __FLT_EPSILON__;
}


int main(void) {
    // Activity 1: test if two doubles are equal, write function equals_dbl
    
    const double a = 41.0 + 0.5 + 0.2 + 0.2 + 0.1;
    const double b = 43.0 - 0.5 - 0.2 - 0.2 - 0.1;
    const double pi_1 = 3.14159265;
    const double pi_2 = 355.0 / 113.0;

    printf("%lf and %lf are %s\n", // must print "equal"
    a, b, equals_dbl(a, b) ? "equal" : "not equal");
    printf("%lf and %lf are %s\n", // must print "equal"
    b, a, equals_dbl(b, a) ? "equal" : "not equal");
    printf("%lf and %lf are %s\n", // must print "not equal"
    pi_1, pi_2, equals_dbl(pi_1, pi_2) ? "equal" : "not equal");
    printf("%lf and %lf are %s\n", // must print "not equal"
    pi_2, pi_1, equals_dbl(pi_2, pi_1) ? "equal" : "not equal");
    

    // Activity 2: function pointers
    int (*fun_ptr)(int, int) = print_subtraction;
    fun_with_ints(fun_ptr);

    fun_ptr = print_division_remainder;
    fun_with_ints(fun_ptr);

    //  ptr is a function pointer to a function that takes an int parameter,
    //  and returns a bool
    bool (*ptr)(int) = is_even;

    // Function pointers can be "called" like functions
    printf("Result of ptr(42): %d\n", ptr(42));

    // Just like data pointers, function pointers can be reassigned:
    ptr = is_odd;
    printf("Result of ptr(42): %d\n", ptr(42));

    // TODO: Create two functions that match the expected function pointer parameter in fun_with_ints.
    //   Call the function fun_with_ints twice, passing in the two different functions you've created

    return 0;
}
