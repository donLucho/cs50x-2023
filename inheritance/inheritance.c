// Required Lab(s) 5 by Luis Artavia - Inheritance
// draft processed on: August 22, 2023
// submitted for grade on: August 22, 2023

// Simulate genetic inheritance of blood type

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
} person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person (1/9)
    person *ptr = malloc(sizeof(person));

    // printf("\nDEV ONLY ~ generations: %i; &ptr: %p; \n", generations, &ptr);

    // generations 3 = current person (1)
    // generations 2 = current person's parents (2)
    // generations 1 = current person's grand-parents (4)

    // If there are still generations left to create
    if (generations > 1)
    {
        // Create two new parents for current person by recursively calling create_family
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        // ■ Each person should have parents assigned to them. The oldest generation should have both parents set to NULL , and
        // younger generations should have parents be an array of two pointers, each pointing to a different parent.

        // TODO: Set parent pointers for current person (2/9)
        ptr->parents[0] = parent0;
        ptr->parents[1] = parent1;

        // ■ Each person should have alleles assigned to them. The oldest generation should have alleles randomly chosen (as by
        // calling the random_allele function), and younger generations should inherit one allele (chosen at random) from each
        // parent.

        // TODO: Randomly assign current person's alleles based on the alleles of their parents (3/9)

        int parent_zero_rando = ptr->parents[0]->alleles[rand() % 2];
        int parent_one_rando = ptr->parents[1]->alleles[rand() % 2];
        ptr->alleles[0] = parent_zero_rando;
        ptr->alleles[1] = parent_one_rando;

        // printf("DEV ONLY ~ generations: %i; &ptr->alleles[0]: %p; &ptr->alleles[1]: %p; \n", generations, &ptr->alleles[0],
        // &ptr->alleles[1]); printf("DEV ONLY ~ generations: %i; ptr->alleles[0]: %c; ptr->alleles[1]: %c; \n", generations, (char)
        // ptr->alleles[0], (char) ptr->alleles[1]);
    }

    // If there are no generations left to create

    // ■ Otherwise (if generations == 1 ), then there will be no parent data for this person. Both parents of your new person should
    // be set to NULL , and each allele should be generated randomly.

    // "BASE CASE" per Bryan
    else
    {
        // TODO: Set parent pointers to NULL (4/9)
        ptr->parents[0] = NULL;
        ptr->parents[1] = NULL;

        // TODO: Randomly assign alleles (5/9)
        ptr->alleles[0] = random_allele();
        ptr->alleles[1] = random_allele();

        // printf("DEV ONLY ~ generations: %i; &ptr->alleles[0]: %p; &ptr->alleles[1]: %p; \n", generations, &ptr->alleles[0],
        // &ptr->alleles[1]); printf("DEV ONLY ~ generations: %i; ptr->alleles[0]: %c; ptr->alleles[1]: %c; \n", generations, (char)
        // ptr->alleles[0], (char) ptr->alleles[1]);
    }

    // ■ Finally, your function should return a pointer for the person that was allocated.

    // TODO: Return newly created person (6/9)
    // return NULL;

    return ptr;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // ■ Since this is a recursive function, you should �rst handle the base case. If the input to the function is NULL , then
    // there’s nothing to free, so your function can return immediately.
    // TODO: Handle base case (7/9)

    if (p == NULL)
    {
        return;
    }

    // ■ Otherwise, you should recursively free both of the person’s parents [...]
    // TODO: Free parents recursively (8/9)

    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // ■ [...] before free ing the child.
    // TODO: Free child (9/9)

    free(p);
}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    // Print parents of current generation
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
