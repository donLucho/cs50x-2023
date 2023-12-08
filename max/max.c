// Optional Lab(s) 3 by Luis Artavia - Max
// draft processed on: July 12, 2023
// Composed on: July 14, 2023
// Practice document not intended for evaluation

// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Hoists
// TODO: return the max value
int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    int best_candidate;
    best_candidate = array[0];
    int i;
    for (i = 0; i < n; i++)
    {
        // printf("best_candidate: %i \\ array[%i]: %i \n", best_candidate, i, array[i]);
        if (best_candidate < array[i])
        {
            best_candidate = array[i];
        }
    }
    //printf("The highest amount is %i.\n", best_candidate);

    return best_candidate;
}