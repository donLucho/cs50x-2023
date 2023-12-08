#include <cs50.h>
#include <stdio.h>

// Unassigned declarations
int set_starting_value(void);
int set_final_value(int s);
int compute_duration(int s, int f);
void print_response(int y);

int main(void)
{
    // TODO: Prompt for start size
    int start = set_starting_value();

    // TODO: Prompt for end size
    int fin = set_final_value(start);

    // TODO: Calculate number of years until we reach threshold
    int years = compute_duration(start, fin);

    // TODO: Print number of years
    print_response(years);
}

// TODO: Prompt for start size
int set_starting_value(void)
{
    int minimumstartsize = 9;
    int startsize;
    do
    {
        printf("Start size should at least be nine (9).\n");
        startsize = get_int("Start size? ");
    }
    while (startsize < minimumstartsize);
    return startsize;
}

// TODO: Prompt for end size
int set_final_value(int s)
{
    int minimumthreshhold = s;
    int endsize;
    do
    {
        printf("End size should, at least, be the same amount as your starting amount.\n");
        endsize = get_int("End size? ");
    }
    while (endsize < minimumthreshhold);
    return endsize;
}

// TODO: Calculate number of years until we reach threshhold
int compute_duration(int s, int f)
{
    int years;
    for (years = 0; s < f; years++)
    {
        s = s + (s / 3) - (s / 4);
    }
    return years;
}

// TODO: Print number of years
void print_response(int y)
{
    printf("Years: %i\n", y);
}