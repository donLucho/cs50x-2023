// Required Problem set 5 by Luis Artavia - speller (dictionary.c)
// draft processed on: August 22, 2023, August 23, 2023, August 24, 2023
// submitted for grade on: August 24, 2023

// Implements a dictionary's functionality

/**
 * "Though Speller’s walkthrough indicates it is reasonable to use a hash function found online, this video is from an older version
 * of the problem where we allowed this. Per the specification above, the hash function you write should ultimately be your own; you
 * may not use a hash function you find online. Be sure to cite any external sources you referenced in writing your hash function."
 * -- [ https://cs50.harvard.edu/x/2023/psets/5/speller/ ]
 */

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

/**
 * malloc - https://manual.cs50.io/3/fopen
 */
#include <stdlib.h>

/**
 * DEV ONLY ~ printf - https://manual.cs50.io/3/printf
 * fopen - https://manual.cs50.io/3/fopen
 * fscanf - https://manual.cs50.io/3/fscanf
 */
#include <stdio.h>

/**
 * strcpy - https://manual.cs50.io/3/strcpy
 */
#include <string.h>

/**
 * strcasecmp - https://manual.cs50.io/3/strcasecmp
 */
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
// DEV                               speller50 >>> TIME IN check: 0.00 (wordsworth) | 0.06 (constitution)
// const unsigned int N = 26; // ORIGINAL VALUE ...TIME IN check: 0.27 (wordsworth) | 12.86 (constitution)
// const unsigned int N = 26 * 2; // TEST NEW   ...TIME IN check: 0.13 (wordsworth) | 5.64 (constitution)
const unsigned int N = 26 * 40; // TEST NEW  ...TIME IN check: 0.01 (wordsworth) | 0.34 (constitution)

// Hash table
node *table[N];

/*
 * Establish counter to keep track of words per Brian Yu
 */
unsigned int count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // return false;

    /**
     * Designate hash table assignment (as cursor) called idx with a non-negative (unsigned) integer
     */

    unsigned int idx = hash(word);

    node *ptr = table[idx];

    while (ptr != NULL)
    {
        if (strcasecmp(word, ptr->word) == 0)
        {
            return true;
        }

        // if no match, move consecutively in order
        ptr = ptr->next;
    }
    return false;
}

/**
 * The original version never addressed any likelihood of running, for example, into
 * a right leaning, apostrophe and/or a single-quote; Hence, the requirement
 * of a loop to possibly address non-alphabetical characters
 * and at the very least make assigning buckets more expansive than just the threadbare amount of 26
 *
 * New version
 *
 * Attribution (1a) -> https://www.youtube.com/watch?v=nvzVHwrrub0&t=6m13s
 * Attribution (1b) -> https://cdn.cs50.net/2017/fall/shorts/hash_tables/hash_tables.pdf (page 13 of 60)
 * Attribution (2) -> https://duckduckgo.com/?t=lm&q=c+hash+function+first+two+characters&ia=web
 * Attribution (3) -> https://www.digitalocean.com/community/tutorials/hash-table-in-c-plus-plus
 * Attribution (4) -> https://codereview.stackexchange.com/questions/282066/implementation-of-hash-function-in-c-language
 *
 */
// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // return toupper(word[0]) - 'A';

    // E.G. -- cat || caterpillar
    // printf("DEV ONLY ~ word: %s; \n", word);

    unsigned long bucket = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        // dictionaries/large AND dictionaries/small consist of words in lower case letters... HEE-HAW!!!
        bucket = bucket + tolower(word[i]);

        // printf("DEV ONLY ~ bucket: %lu; \n", bucket);
        // printf("DEV ONLY ~ word[i]: %hhd; \n", word[i]);
    }

    // printf("DEV ONLY ~ bucket: %lu; \n", bucket);
    // printf("DEV ONLY ~ bucket % N: %lu; \n", (bucket % N) );
    // printf("DEV ONLY ~ bucket: %lu; bucket %% N: %lu; \n", bucket, (bucket % N) );

    // DEV ONLY
    // size();
    // printf("DEV ONLY ~ hash >>> size(): %i; \n", size());

    return bucket % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // return false;

    /**
     * Use fopen
     * Remember to check if return value is NULL
     */

    // printf("DEV ONLY ~ N: %u; \n", N);

    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        // printf("DEV ONLY ~ Unable to open file. \n");
        return false;
    }

    /**
     * Read Strings from the File
     *
     * fscanf will return EOF once it reaches end of file
     *
     * EOF
     * attribution (1) -> https://duckduckgo.com/?t=lm&q=c+EOF+example&ia=web
     * attribution (2) -> https://stackoverflow.com/questions/12048576/how-to-find-eof-through-fscanf
     *
     * Create a New Node
     *
     * Use malloc... Remember to check if return value is NULL...Copy word into node using strcpy
     *
     * longest word "pneumonoultramicroscopicsilicovolcanoconiosis" is 45 characters in length not including ‘\0’ or null character
     */
    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));

        // printf("DEV ONLY ~ n size: %lu\n", sizeof(n));

        if (n == NULL)
        {
            // printf("DEV ONLY ~ Memory could not be allocated. \n");
            return false;
        }

        /**
         * Rationale straight from Week 5 Section Exercise
         * called "table" c/o Carter Zenke
         */
        strcpy(n->word, word);

        /**
         * set next node pointer to NULL to cull the garbage
         */
        n->next = NULL;

        unsigned int idx = hash(word);

        /**
         * Rationale straight from Week 5 Section Exercise called "list" c/o Carter Zenke
         * And, "ensure that list points to the node called n created above";
         * Plus, it is important to direct pointer n to idx of the hour that is initially NULL by definition
         */

        if (table[idx] == NULL)
        {
            table[idx] = n;
        }
        else
        {
            n->next = table[idx];
            table[idx] = n;
        }

        count++;
    }

    /**
     * Release memory allocated to file-reader, then, return true
     */
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // return 0;

    /**/
    // printf("DEV ONLY ~ size() >>> count: %i; \n", count);
    int word_num = (count > 0) ? count : 0;
    // printf("DEV ONLY ~ size() >>> word_num: %i; \n", word_num);
    return word_num;
    /**/

    // return count;
}

/**
 * "unload f()" rationale is straight from Week 5 Exercises
 * called "list3.c" and "list4.c" c/o David Malan
 *
 * In essence, "your unload function is going to call free on any memory that you've allocated using malloc and return true"
 *
 * your hash table is really just an array of individual linked lists each of those linked list contains nodes that you have
 * allocated memory for likely using malloc...
 *
 * ...you might imagine iterating over your hash table going over each of those individual linked lists and calling free on all over
 * the nodes
 */

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // return false;

    for (int i = 0; i < N; i++)
    {

        node *ptr = table[i];

        // Print words -- for
        // for (ptr = table[i]; ptr != NULL; ptr = ptr->next)
        // {
        //     printf("ptr->word: %s\n", ptr->word);
        //     printf("DEV ONLY ~ p address: %p\n", &ptr);
        //     printf("DEV ONLY ~ ptr->word size EQ 46 bytes of memory...: %lu\n", sizeof(ptr->word));
        //     printf("DEV ONLY ~ ptr->next size EQ 8 bytes of memory...: %lu\n", sizeof(ptr->next));
        // }

        // ptr = table[i];

        // Free memory -- while
        while (ptr != NULL)
        {
            node *next = ptr->next;
            free(ptr);
            ptr = next;
        }

        if (ptr != NULL)
        {
            return false;
        }

        if (ptr == NULL)
        {
            continue;
        }
    }
    return true;
}
