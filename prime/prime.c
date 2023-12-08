// Optional lab: prime

#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

// Hoisted unassigned declarations
int set_min_value(void);
int set_max_value(int min);
void cycle_through_range(int min, int max);
bool prime(int number);

int main(void)
{
    // TODO: Prompt for a minimum value greater than 1
    int min = set_min_value();

    // TODO: Prompt for a maximum value greater than the minimum value
    int max = set_max_value(min);

    // TODO: loop through range of numbers; if variable i returns true, print variable i
    cycle_through_range(min, max);
}

// TODO: Prompt for a minimum value greater than 1
int set_min_value(void)
{
    int min;
    do
    {
        printf("Enter a value greater than zero.\n");
        min = get_int("Minimum: ");
    }
    while (min < 1);
    return min;
}

// TODO: Prompt for a maximum value greater than the minimum value
int set_max_value(int min)
{
    int max;
    do
    {
        printf("Enter a value greater than the minimum value.\n");
        max = get_int("Maximum: ");
    }
    while (min >= max);
    return max;
}

// TODO: loop through range of numbers; if variable i returns true, print variable i
void cycle_through_range(int min, int max)
{
    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

// TODO: determine if a number is prime using modulo and for loops to complete the assignment
bool prime(int number)
{
    // ■ By definition, 1 is not a prime number.
    // ■ There is only one even prime number, 2.

    // to check if a number is prime, is to try dividing it by every number from 2 up to, but not including, the number itself. If any number divides into it with no remainder, that number is not prime.

    // first 25 prime numbers... everything else is composite
    // 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97

    int lowerthreshhold = 2;
    int testingiteration;

    if (number < lowerthreshhold)
    {
        return false;
    }

    for (testingiteration = lowerthreshhold; testingiteration < number; testingiteration++)
    {
        if (number % testingiteration == 0)
        {
            return false;
        }
    }
    return true;
}