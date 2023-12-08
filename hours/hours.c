// Optional Lab(s) 2 by Luis Artavia - hours
// draft processed on June 28, 2023
// Composed on: July 5, 2023
// Practice document not intended for evaluation

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

// Hoisted function name declarations
float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    float returnvalue;
    if (output == 'T')
    {
        int sum = 0;
        for (int i = 0; i < weeks; i = i + 1)
        {
            sum += hours[i];
        }
        returnvalue = sum;
    }
    if (output == 'A')
    {
        int sum = 0;
        for (int i = 0; i < weeks; i = i + 1)
        {
            sum += hours[i];
        }
        returnvalue = sum / (float) weeks;
    }
    return returnvalue;
}