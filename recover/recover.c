// Required Problem set 4 by Luis Artavia - Recover
// draft processed on: August 10, 2023; August 11, 2023;
// submitted for grade on: August 11, 2023

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Hoisted items
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Check for improper usage, otherwise, get filename length
    if (argc != 2)
    {
        printf("Improper usage: Try ./recover card.raw\n");
        return 1;
    }

    // Open file
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("Input file does not exist. Gracefully closing now.\n");
        return 1;
    }

    // Apply limited number of spaces to a variable
    uint8_t buffer[BLOCK_SIZE];

    // create counter
    int count = 0;

    // instantiate variable for recyclable jpeg pointer -- outptr must be outside of while loop for fclose(outptr) to be properly
    // applied
    FILE *outptr = NULL;

    // Establish formatted string convention (000.jpg + \0) = 8
    char filename[8];

    unsigned int bitsize = sizeof(uint8_t);
    // printf("DEV ONLY ~ bitsize: %u; \n", bitsize); // returns 1

    while (fread(buffer, bitsize, BLOCK_SIZE, inptr) == BLOCK_SIZE)
    {
        // locate each first four blocks denoting jpeg "magic numbers"
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // returns 0 to 49 AND "Segmentation fault (core dumped)"
            // printf("DEV ONLY ~ count: %i; \n", count);

            // rattles off 0 to 49 AND hexadecimal equivalents
            // printf("DEV ONLY ~ count: %i; buffer[0]: %hhu; buffer[1]: %hhu; buffer[2]: %hhu; buffer[3]: %hhu; \n", count,
            // buffer[0], buffer[1], buffer[2], buffer[3] );

            // DEV ONLY
            // count = count + 1;

            // if first JPEG
            if (count == 0)
            {
                // scanf [ https://manual.cs50.io/3/scanf ] is what I need but leaves a lot to be desired but
                // fscanf [ https://manual.cs50.io/3/fscanf ] provides more depth w/ "conversion specification"
                // "%03i.jpg" contains three integers with an obligatory leading 0 (i.e. -- 000.jpg to 099.jpg)

                // allocate memory to filename
                sprintf(filename, "%03i.jpg", count);

                // assign destination to accessible pointer
                outptr = fopen(filename, "w");

                // write to destination
                fwrite(buffer, bitsize, BLOCK_SIZE, outptr);

                // increment the counter
                count = count + 1;

            } // first image has to be written to fruition

            // if NOT first but subsequent JPEG
            else if (count > 0)
            {
                // close the previous jpeg filewrite
                fclose(outptr);

                // write to memory
                sprintf(filename, "%03i.jpg", count);

                // assign destination to accessible pointer
                outptr = fopen(filename, "w");

                // write to destination
                fwrite(buffer, bitsize, BLOCK_SIZE, outptr);

                // increment the counter
                count = count + 1;

            } // subsequent image(s)

        } // END magic numbers

        // loop will not locate any more magic numbers, hence, coax fwrite to exhaust/satisfy while loop and close the FINAL image
        // (a\k\a '049.jpg' in an ideal world and according to console statement created above)

        // too HARDCODED, hackish and brittle
        // if (count == 49) // 0 to 49 are written but they contain BLACK pixels - BUUU!
        // else if (count == 49) // 0 to 49 are written but they ALSO have rgb(0,0,0) - BUUU!
        // if (count > 0) // best result so far but they, too, have majority rgb(0,0,0) PX - BUUU!

        // "count > 0" is sufficiently vague in order to allow the final image to write final image - BONANZA!
        else if (count > 0)
        {
            fwrite(buffer, bitsize, BLOCK_SIZE, outptr);
            // fclose(outptr); // 1 -- writes are incomplete BUUU!

        } // end to exhaustion

        // fclose(outptr); // 2 -- leaky BUUU!

    } // end while

    fclose(inptr);
    fclose(outptr); // 3 -- legit

    // printf("DEV ONLY ~ DONEZO!\n" );
    return 0;
}