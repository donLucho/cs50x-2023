// Optional Lab(s) 3 by Luis Artavia - atoi (abstract to integer)
// draft processed on: July 12, 2023
// Composed on: July 14, 2023
// Practice document not intended for evaluation

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Hoisted function name declarations
bool valid(string stringkey, int stringlen);
int convert(string input);

int main(void)
{
    // First, receive the string
    string input = get_string("Enter a positive integer: ");

    // Second, convert the string to int
    int tbd = convert(input);
}

// TODO - Ensure single command-line argument contains only digit characters
bool valid(string stringkey, int stringlen)
{
    // printf("stringlen: %i\n", stringlen);
    // printf("stringkey: %s\n", stringkey);

    int final_sum = 0;
    bool legitimate_entry;

    // CYCLE THROUGH string stringkey with a loop
    for (int i = 0; i < stringlen; i++)
    {
        // isdigit
        // According to [https://manual.cs50.io/3/isdigit]
        // returns a non-zero int if determined to be a decimal digit
        // returns a zero if determined to NOT be a decimal digit

        bool burningquestion = isdigit(stringkey[i]);
        final_sum = final_sum + burningquestion;
        // printf("final_sum: %i\n", final_sum);
    }

    if (final_sum == stringlen)
    {
        legitimate_entry = true;
    }
    if (final_sum < stringlen)
    {
        legitimate_entry = false;
    }
    return legitimate_entry;
}

// TODO - Convert string input to integer format
int convert(string input)
{
    int length = strlen(input);

    bool yepnope = valid((string) input, (int) length);
    // printf("yepnope: %i\n", (int) yepnope);

    if (yepnope <= 0)
    {
        printf("Invalid Input!\n");
        return 1;
    }

    int converted_value = atoi(input);

    // printf("DEV CONSOLE: converted_value: %i\n", converted_value);
    printf("%i\n", converted_value);

    return converted_value;
}