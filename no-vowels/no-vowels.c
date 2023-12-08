// Optional Lab(s) 2 by Luis Artavia - no-vowels
// draft processed on June 28, 2023
// Composed on: July 5, 2023
// Practice document not intended for evaluation

// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

// Hoisted function name declarations
string replace(string str);
int string_length(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Enter one command-line argument only (e.g. - a word... any word... your choice). Gracefully exiting now.\n");
        return 1;
    }

    string myCliArg = replace((string) argv[1]);
    printf("myCliArg: %s\n", myCliArg);

    // return 0;
}

// TODO - a becomes 6 , e becomes 3 , i becomes 1 , o becomes 0
string replace(string str)
{
    // printf("%s\n", str);

    // Count the number of characters until '\0' (i.e.-- NUL)
    int length = string_length(str);
    // printf("%i\n", length);

    // CYCLE THROUGH string str with a loop
    for (int i = 0; i < length; i++)
    {

        // printf("String's ASCII codes: %i ", str[i]);
        // printf("%i ", str[i]);

        // printf("String expressed as chars: %c ", str[i]);
        // printf("%c ", str[i]);

        // Assign unique instances with applicable value
        switch (str[i])
        {
            // a
            case 'a':
                str[i] = '6';
                break;

            // e
            case 'e':
                str[i] = '3';
                break;

            // i
            case 'i':
                str[i] = '1';
                break;

            // o
            case 'o':
                str[i] = '0';
                break;
        }

    }
    // printf("\n");
    // printf("%s ", newword);
    // return "1 2 buckle my shoe!";

    return str;
}

// TODO - Count the number of characters until '\0' (i.e.-- NUL)
int string_length(string s)
{
    int n = 0;
    while (s[n] != '\0')
    {
        // n++;
        n = n + 1;
    }
    return n;
}