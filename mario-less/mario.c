// Problem set 1 - Mario-less
// Let’s recreate that pyramid in C... using hashes...

#include <cs50.h>
#include <stdio.h>

// Hoisted deck(s)
int set_height(void);
void print_hashes(int height);

int main(void)
{
    // TODO: prompt user for height for numbers between 1 and 8 of type integer
    int height = set_height();
    // printf("height console: %row\n", height);

    // TODO: print hashes to screen
    print_hashes(height);
}

// TODO: prompt user for height for numbers between 1 and 8 of type integer
int set_height(void)
{
    int lower_limit = 1;
    int upper_limit = 8;
    int height;
    do
    {
        printf("Choose a value from one (1) to eight(8)!\n\n");
        height = get_int("Height: ");
    }
    while (!((height >= lower_limit) && (height <= upper_limit)));
    return height;
}

// TODO: print hashes to screen
// mario1 - Prints a row of N hashes
void print_hashes(int height)
{
    int row;
    int space;
    int column;

    int minvalue = 1;
    int maxvalue = height;

    // Rows
    for (row = minvalue; row <= maxvalue; row++)
    {
        // Spaces
        for (space = row; space < maxvalue; space++)
        {
            printf(" ");
        }

        // Shifted Columns
        for (column = minvalue; column <= row; column++)
        {
            printf("#");
        }

        // Add line break to each row
        printf("\n");
    }
}