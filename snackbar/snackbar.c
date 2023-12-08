// Optional Lab(s) 3 by Luis Artavia - Snackbar
// draft processed on: July 12 & July 13, 2023
// Composed on: July 14, 2023
// Practice document not intended for evaluation

// Practice using structs
// Practice writing a linear search function

/**
 * Beach Burger Shack has the following 10 items on their menu
 * Burger: $9.5
 * Vegan Burger: $11
 * Hot Dog: $5
 * Cheese Dog: $7
 * Fries: $5
 * Cheese Fries: $6
 * Cold Pressed Juice: $7
 * Cold Brew: $3
 * Water: $2
 * Soda: $2
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Hoisted CONSTANTS
// Number of menu items
#define NUM_ITEMS 10

// Hoisted type definitions

// Define a new struct called "menu_item"
// Menu items have item name and price
typedef struct
{
    string item;
    float price;
}
menu_item;

// Hoisted variables

// Array of menu items
menu_item menu[NUM_ITEMS];

// Hoisted prototype names of custom objects

// TODO - Prompt the user for a menu_item - 'get_menu_item' is now 'add_menu_item'
menu_item add_menu_item(string item, float price);

// Hoisted prototype names

// Add items to menu
void add_items(void);

// Calculate total cost
float get_cost(string item);

int main(void)
{
    add_items();

    printf("\nWelcome to Beach Burger Shack!\n");
    printf("Choose from the following menu to order. Press enter when done.\n\n");

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        printf("%s: $%.2f\n", menu[i].item, menu[i].price);
    }
    printf("\n");

    float total = 0;
    while (true)
    {
        string item = get_string("Enter a food item: ");
        if (strlen(item) == 0)
        {
            printf("\n");
            break;
        }

        total += get_cost(item);
    }

    printf("Your total cost is: $%.2f\n", total);
}

// TODO - Prompt the user for a menu_item - 'get_menu_item' is now 'add_menu_item'
menu_item add_menu_item(string item, float price)
{
    menu_item m;
    m.item = item;
    m.price = price;
    return m;
}

// TODO - Add at least the first for items to the menu array; add items to menu
void add_items(void)
{
    menu_item snackIdx0 = add_menu_item("Burger", 9.50);
    menu_item snackIdx1 = add_menu_item("Vegan Burger", 11.00);
    menu_item snackIdx2 = add_menu_item("Hot Dog", 5.00);
    menu_item snackIdx3 = add_menu_item("Cheese Dog", 7.00);
    menu_item snackIdx4 = add_menu_item("Fries", 5.00);
    menu_item snackIdx5 = add_menu_item("Cheese Fries", 6.00);
    menu_item snackIdx6 = add_menu_item("Cold Pressed Juice", 7.00);
    menu_item snackIdx7 = add_menu_item("Cold Brew", 3.00);
    menu_item snackIdx8 = add_menu_item("Water", 2.00);
    menu_item snackIdx9 = add_menu_item("Soda", 2.00);

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        if (i == 0)
        {
            menu[i] = snackIdx0;
        }
        if (i == 1)
        {
            menu[i] = snackIdx1;
        }
        if (i == 2)
        {
            menu[i] = snackIdx2;
        }
        if (i == 3)
        {
            menu[i] = snackIdx3;
        }
        if (i == 4)
        {
            menu[i] = snackIdx4;
        }
        if (i == 5)
        {
            menu[i] = snackIdx5;
        }
        if (i == 6)
        {
            menu[i] = snackIdx6;
        }
        if (i == 7)
        {
            menu[i] = snackIdx7;
        }
        if (i == 8)
        {
            menu[i] = snackIdx8;
        }
        if (i == 9)
        {
            menu[i] = snackIdx9;
        }
    }
    return;
}

// TODO - Search through the menu array to find an item's cost; calculate total cost
float get_cost(string item)
{
    // find the corresponding menu[index] that contains item, return cost from that object

    float my_cost;

    int mylenmax = sizeof(menu) / sizeof(menu[0]);
    // printf("mylenmax: %i\n", mylenmax);

    for (int i = 0; i < mylenmax; i++)
    {
        // Compare names[of ith] instance to user-furnished name
        // Compare menu_item[of ith][.]"item" property instance to user-furnished "item"

        // if (menu[i].item == item) // buu
        if (strcmp(menu[i].item, item) == 0)
        {
            string item_name = menu[i].item;
            // printf("DEV CONSOLE ONLY: %s was located.\n", item_name);

            float item_price = menu[i].price;
            // printf("DEV CONSOLE ONLY: Item will cost $%f.\n", item_price);
            // printf("DEV CONSOLE ONLY: Item %s will cost you $%f.\n", item_name, item_price);
            // printf("DEV CONSOLE ONLY: Item %s will cost you $%.2f.\n", item_name, item_price);

            my_cost = menu[i].price;
            // printf("my_cost: %f\n", my_cost);
            // printf("my_cost: $%.2f\n", my_cost);

        }
    }

    return my_cost;
}