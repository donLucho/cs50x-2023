// Optional Lab(s) 2 by Luis Artavia - password
// draft processed on June 28, 2023
// Composed on: July 5, 2023
// Practice document not intended for evaluation

// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Hoisted function name declarations
bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below

// If the password contains at least one upper case letter, one lower case letter, a number, and a symbol (meaning a printable character that’s not a letter or number, such as ‘!’, ‘$’ and ‘#’), the function should return true . If not it should return false .

bool valid(string password)
{
    // printf("%s\n", password);

    int length = strlen(password);
    // printf("%i\n", length);

    bool isvalid = false;
    bool haslower = false;
    bool hasupper = false;
    bool hasnumber = false;
    bool hassymbol = false;

    // CYCLE THROUGH string password with a loop
    for (int i = 0; i < length; i++)
    {
        // isupper
        if (isupper(password[i]))
        {
            hasupper = true;
        }
        // isdigit
        if (isdigit(password[i]))
        {
            hasnumber = true;
        }
        // ispunct
        if (ispunct(password[i]))
        {
            hassymbol = true;
        }
        // islower
        if (islower(password[i]))
        {
            haslower = true;
        }
    }
    // printf("\n");
    if (haslower == true && hasupper == true && hasnumber == true && hassymbol == true)
    {
        isvalid = true;
    }

    // return false;
    // return "1 2 buckle my shoe!";
    // return password;

    return isvalid;
}