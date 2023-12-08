// Required Problem set 2 by Luis Artavia - Caesar
// draft processed on June 29, 2023
// submitted for grade on: July 5, 2023

// The obligatory BOILERPLATE:

#include <stdlib.h>
#include <ctype.h>

#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Hoisted function name declarations
// int key;

// routine 0 TODO - Capture the key or the number of places to shift in the ASCII code
void printout_getkey_bork(void);
bool valid(string stringkey, int stringlen);


// routine 2 TODO - Receive the plaintext of type string to convert it to ciphertext also of type string

string convert_to_ciphertext(string plntxt, int key);

// routine(s) 3, 4 TODO - ASCII codes for A (65) to Z (90) or ASCII codes for a (97) to z (122)
char lowercase_result_to_console(int ascii_idx, int spaces);
char uppercase_result_to_console(int ascii_idx, int spaces);

// int main(void)
int main(int argc, string argv[])
{
    // routine 0 TODO - Capture the key or the number of places to shift in the ASCII code

    // Instantiate local variables
    string rawkey;
    int key;

    // TODO - Get key
    // Make sure program was run with just one command-line argument
    if (argc == 2)
    {
        rawkey = argv[1];
        // printf("rawkey: %s\n", rawkey);
    }
    else
    {
        printout_getkey_bork();
        return 1;
    }

    int length = strlen(rawkey);
    bool yepnope = valid((string) rawkey, (int) length);
    // printf("yepnope: %i\n", (int) yepnope);

    if (yepnope == 0)
    {
        // printf("Your string is NOT valid!\n");
        printout_getkey_bork();
        return 1;
    }
    // printf("Your string is valid!\n");

    // Convert argument to an integer

    // TODO - Handoff the key of type int to the next function...
    key = atoi(rawkey);
    // printf("key: %i\n", key);

    // routine 1 TODO - CS50 convenience method get_string() - Capture and pass the plain text.
    string plaintext_str;
    do
    {
        plaintext_str = get_string("Enter plaintext: ");
    }
    while (strlen(plaintext_str) < 1);

    // convert_to_ciphertext((string) plaintext_str);
    string joeblow = convert_to_ciphertext((string) plaintext_str, (int) key);

    printf("ciphertext: %s\n", joeblow);
}

// routine 0 TODO - Capture the key or the number of places to shift in the ASCII code
// TODO - When encountering situations contrary to the instructions print out a "usage message"
void printout_getkey_bork(void)
{
    printf("Usage: ./caesar key\n");
}

// routine 0 TODO - Capture the key or the number of places to shift in the ASCII code
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
        // printf("burningquestion: %i\n", burningquestion);

        // if (burningquestion)
        // {
        //     printf("Your input of %c is a digit.\n", stringkey[i]);
        // }
        // else
        // {
        //     printf("Your input of %c is NOT a digit.\n", stringkey[i]);
        // }
        // printf("stringkey[i]: %c\n", stringkey[i]);
        // printf("burningquestion: %i\n", burningquestion);

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

// routine 2 TODO - Receive the plaintext of type string to convert it to ciphertext also of type string

string convert_to_ciphertext(string plntxt, int key)
{
    // printf("DEV printf - plntxt: %s\n", plntxt);

    // printf("...and, now the NEXT TODO . Capture and pass the plaintext (of type string) in order to convert it to ciphertext (also of type string). Grazie\n");

    // printf("In fact, the string parameter in this function may still be accessible\n");

    int stringlen = strlen(plntxt);
    for (int i = 0; i < stringlen; i++)
    {

        // printf("plntxt[i] is: %i\n", plntxt[i]);
        // printf("Character of %c vis-a-vis isalpha(plntxt[i]) is: %i\n", plntxt[i], isalpha(plntxt[i]));
        // printf("Character of %c vis-a-vis isupper(plntxt[i]) is: %i\n", plntxt[i], isupper(plntxt[i]));
        // printf("Character of %c vis-a-vis islower(plntxt[i]) is: %i\n", plntxt[i], islower(plntxt[i]));

        if (isalpha(plntxt[i]))
        {
            // plntxt[i] = plntxt[i];

            // TODO - find my head because I am losing my mind going down the rabbit hole
            if (isupper(plntxt[i]))
            {
                // int plntxt[i] = plntxt[i];
                // int plntxt[i] = 90; // z-ish
                // int key = 1;           // a-ish
                // int key = 2;           // b-ish

                // int plntxt[i] = 93; // d-ish
                // int key = 1;           // e-ish
                // int key = 2;           // f-ish

                // int ciphtxt_sub_i =

                // special_result_to_console((int) plntxt[i], (int) key);
                plntxt[i] = uppercase_result_to_console((int) plntxt[i], (int) key);
                // Hey! Phil Hartman called. He says that you're SASSY!
            }
            if (islower(plntxt[i]))
            {
                // int plntxt[i] = plntxt[i];
                // int plntxt[i] = 90; // z-ish
                // int key = 1;           // a-ish
                // int key = 2;           // b-ish

                // int plntxt[i] = 93; // d-ish
                // int key = 1;           // e-ish
                // int key = 2;           // f-ish

                // int ciphtxt_sub_i =

                // special_result_to_console((int) plntxt[i], (int) key);
                plntxt[i] = lowercase_result_to_console((int) plntxt[i], (int) key);
                // Hey! Phil Hartman called. He says that you're SASSY!
            }
        }
        // END if

        if (isalpha(plntxt[i]) == 0)
        {
            plntxt[i] = plntxt[i];
        }
        // END if

        // printf("DEV printf - plntxt: %s\n", plntxt);
    }

    // printf("DEV printf - plntxt: %s\n", plntxt);
    return plntxt;
}

// routine 3 ASCII codes for A (65) to Z (90) or ASCII codes for a (97) to z (122)
char lowercase_result_to_console(int ascii_idx, int spaces)
{
    // printf("ascii_idx: %i\n", ascii_idx);
    // printf("spaces: %i\n", spaces);

    int range_adjustment = 97; // lowercase codes lower limit
    // int range_adjustment = 65; // uppercase codes lower limit

    int modulo_multiple = 26;

    // return 123456;

    //  a ...  z
    // 97 ... 122

    // For the sake of example, take the character z and shift it by 1
    // In theory 25 to 0 should no longer apply
    // Rather, 122 (z) to 97 (a) is the new it thing

    //   c{SubI} = (p{SubI} + k) % 26
    //   c{SubI} = (25 + 1) % 26;
    //   c{SubI} = 26 % 26;
    //   c{SubI} = 0;

    int new_idx;
    ascii_idx = ascii_idx - range_adjustment;

    int adjustment = ((int) ascii_idx + (int) spaces);
    // printf("adjustment: %i\n", adjustment);

    new_idx = adjustment % modulo_multiple;
    new_idx = new_idx + range_adjustment;

    // printf("new_idx: %i\n", new_idx);

    int cast_idx = (char) new_idx;
    // printf("new_idx: %c\n", cast_idx);
    // return new_idx;
    return cast_idx;

}

// routine 4 ASCII codes for A (65) to Z (90) or ASCII codes for a (97) to z (122)
char uppercase_result_to_console(int ascii_idx, int spaces)
{
    // printf("ascii_idx: %i\n", ascii_idx);
    // printf("spaces: %i\n", spaces);

    // int range_adjustment = 97; // lowercase codes lower limit
    int range_adjustment = 65; // uppercase codes lower limit

    int modulo_multiple = 26;

    // return 123456;

    // A  ...  Z
    // 65 ... 90

    // For the sake of example, take the character Z and shift it by 1
    // In theory 25 to 0 should no longer apply
    // Rather, 90 (Z) to 65 (A) is the new it thing

    //   c{SubI} = (p{SubI} + k) % 26
    //   c{SubI} = (25 + 1) % 26;
    //   c{SubI} = 26 % 26;
    //   c{SubI} = 0;

    int new_idx;
    ascii_idx = ascii_idx - range_adjustment;

    int adjustment = ((int) ascii_idx + (int) spaces);
    // printf("adjustment: %i\n", adjustment);

    new_idx = adjustment % modulo_multiple;
    new_idx = new_idx + range_adjustment;

    // printf("new_idx: %i\n", new_idx);

    int cast_idx = (char) new_idx;
    // printf("new_idx: %c\n", cast_idx);
    // return new_idx;
    return cast_idx;

}