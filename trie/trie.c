// Optional Lab(s) 5 by Luis Artavia - Trie
// draft processed on: August 21, 2023
// Composed on: August 21, 2023
// Practice document not intended for evaluation
// "NO CHECK50 FOR THIS ONE"

// Saves popular dog names in a trie
// https://www.dailypaws.com/dogs-puppies/dog-names/common-dog-names

#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_ALPHABET 26
#define MAXCHAR 20

typedef struct node
{
    bool is_word;
    struct node *children[SIZE_OF_ALPHABET];
}
node;

// Function prototypes
bool check(char *word);
bool unload(void);
void unloader(node *current);

// Root of trie
node *root;

// Buffer to read dog names into
char name[MAXCHAR];

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./trie infile\n");
        return 1;
    }

    // File with names
    FILE *infile = fopen(argv[1], "r");
    if (!infile)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // Allocate root of trie
    root = malloc(sizeof(node));

    if (root == NULL)
    {
        return 1;
    }

    root->is_word = false;

    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    {
        root->children[i] = NULL;
    }

    // Add words to the trie
    while (fscanf(infile, "%s", name) == 1) 
    {
        node *cursor = root;

        for (int i = 0, n = strlen(name); i < n; i++)
        {
            int index = tolower(name[i]) - 'a';

            if (cursor->children[index] == NULL)
            {

                // Make node
                node *new = malloc(sizeof(node));

                new->is_word = false;

                for (int j = 0; j < SIZE_OF_ALPHABET; j++)
                {
                    new->children[j] = NULL;
                }

                cursor->children[index] = new;
            }

            // Go to node which we may have just been made
            cursor = cursor->children[index];
        }

        // if we are at the end of the word, mark it as being a word
        cursor->is_word = true;
    }

    if (check(get_string("Check word: ")))
    {
        printf("Found!\n");
    }
    else
    {
        printf("Not Found.\n");
    }

    if (!unload())
    {
        printf("Problem freeing memory!\n");
        return 1;
    }

    fclose(infile);
}

// TODO: Complete the check function, return true if found, false if not found
bool check(char* word)
{
    // HINT: "■ You probably want to start by setting a node pointer, cursor to the root of the trie."
    node *ptr = root;

    // HINT: "■ Iterate through every letter in the argument word and, as you do, determine the array index that corresponds to that letter."
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        
        // HINT: ■ Remember that the lookup should be case-insensitive. For instance, A and a should correspond to 0, B and b corresponds to 1, etc.
        int index = tolower(word[i]) - 'a';

        // It has to be a character within RANGE or else a vicious cycle of VALGRIND errors consisting of "Invalid read/Invalid write" will ensue
        // And, this error has priority over the NULL address check or else VALGRIND produces "Invalid read of size 8" error(s) b/c of said check AND get_string at LINE 97
        if (index < 0 || index >= SIZE_OF_ALPHABET)
        {
            // printf("DEV ONLY ~ index: %i; \n", index);
            // printf("A phoneme other than a letter was used. WRONG!\n");
            printf("DEV ONLY ~ WRONG! A non-alphabetical phoneme was used (i.e. - index: %i). \n", index);
            return false;
        }

        // HINT: ■ You can use the index for a letter to check if children[index] is a NULL pointer, meaning the word does not exist in the trie.
        if (ptr->children[index] == NULL)
        {
            // printf("DEV ONLY ~ ptr->children[index]: %p; \n", ptr->children[index]);
            // printf("A phoneme other than a letter was used. WRONG!\n");
            printf("DEV ONLY ~ WRONG! The letter %c in this specific name and position is NULL (i.e. - ptr->children[%i]: %p) \n", (char) word[i], index, ptr->children[index] );
            return false;
        }

        // HINT: ■ If children[index] is in fact a node, you can reset cursor to this node and check for the next letter in its children nodes.
        printf("DEV ONLY ~ index: %i; ptr->children[index]: %p; \n", index,  ptr->children[index] );

        ptr = ptr->children[index];
    }

    return ptr->is_word = true;
    // return ptr->is_word;

    // return false;
}

// Unload trie from memory
bool unload(void)
{

    // The recursive function handles all of the freeing
    unloader(root);

    return true;
}

void unloader(node* current)
{
    
    // Iterate over all the children to see if they point to anything and go
    // there if they do point
    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    {
        if (current->children[i] != NULL)
        {
            unloader(current->children[i]);
        }
    }

    // After we check all the children point to null we can get rid of the node
    // and return to the previous iteration of this function.

    free(current);
}

// make trie
// ./trie dog_names.txt
// Max
// Mac
// Ma7