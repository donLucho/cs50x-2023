// Optional Lab(s) 4 by Luis Artavia - License
// draft processed on: August 6, 2023, August 7, 2023
// Composed on: August 2, 2023
// Practice document not intended for evaluation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[7];

    // Create array to store plate numbers
    char *plates[8];

    // declare this outside of the while loop save it becomes inaccessible by deference of inherent closure
    for (int i = 0; i < 8; i++)
    {
        plates[i] = malloc(7);
    }

    FILE *infile = fopen(argv[1], "r");

    int idx = 0;
    while (fread(buffer, 1, 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';

        /*
        printf("\nDEV ONLY ~ sizeof(buffer): %lu\n", sizeof(buffer)); // returns 7
        printf("DEV ONLY ~ buffer: %s\n", buffer);                    // returns (null)
        printf("DEV ONLY ~ &buffer: %p\n", &buffer);                  // returns 0x1A
        */

        /*
        printf("\nDEV ONLY ~ sizeof(plates): %lu\n", sizeof(plates)); // returns 64
        printf("DEV ONLY ~ *plates: %s\n", *plates);                  // returns (null)
        printf("DEV ONLY ~ &plates: %p\n", &plates);                  // returns 0xFF
        */

        // Save plate number in array
        // plates[idx] = buffer; // original assignment
        strcpy(plates[idx], buffer); // corrected assignment

        idx++;
    }

    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);
    }

    fclose(infile);

    // free(plates);
    // The above statement is inadequate and valgrind LEAK SUMMARY states "definitely lost: 56 bytes in 8 blocks"
    // Hence, make another loop and attempt to bore into each value by using the keys and free memory in this way

    for (int i = 0; i < 8; i++)
    {
        free(plates[i]);
    }

    return 0;
}
