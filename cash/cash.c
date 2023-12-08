// Problem set 1 - Cash

#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

// Hoisted declarations
int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

// Ask how many cents the customer is owed
int get_cents(void)
{
    // Prompt user for amount in change
    int changeprompt;
    printf("\nEnter amount due.\n");
    do
    {
        printf("You should enter a whole number (e.g. - a positive integer).\n");
        printf("For example, $0.91 (ninety-one cents) should \nbe expressed as \"91\" (without the dollar sign, too).\n\n");
        changeprompt = get_int("Enter amount of change that is due: ");
    }
    while (changeprompt < 1);

    return changeprompt;
}

// Calculate the number of quarters to give the customer
int calculate_quarters(int cents)
{
    int quarters;
    if (cents >= 25)
    {
        quarters = cents / 25;
    }

    if (cents < 25)
    {
        quarters = 0;
    }
    return quarters;
}

// Calculate the number of dimes to give the customer
int calculate_dimes(int cents)
{
    int dimes;
    if (cents >= 10)
    {
        dimes = cents / 10;
    }

    if (cents < 10)
    {
        dimes = 0;
    }
    return dimes;
}

// Calculate the number of nickels to give the customer
int calculate_nickels(int cents)
{
    int nickels;
    if (cents >= 5)
    {
        nickels = cents / 5;
    }

    if (cents < 5)
    {
        nickels = 0;
    }
    return nickels;
}

// Calculate the number of pennies to give the customer
int calculate_pennies(int cents)
{
    int pennies;
    if (cents >= 1)
    {
        pennies = cents / 1;
    }

    if (cents < 1)
    {
        pennies = 0;
    }
    return pennies;
}
