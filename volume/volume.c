// Required Lab(s) 4 by Luis Artavia - Volume
// draft processed on: August 9, 2023
// submitted for grade on: August 9, 2023

// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file

    // uint8_t array declaration called header_buffer
    uint8_t header_buffer[HEADER_SIZE];

    // read argv[1]'s HEADER
    fread(&header_buffer, HEADER_SIZE, 1, input);

    // write argv[2]'s HEADER
    fwrite(&header_buffer, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file

    // int16_t array declaration called datachunk_buffer
    int16_t datachunk_buffer;

    // printf("DEV ONLY ~ sizeof(int16_t): %lu;\n", sizeof(int16_t) ); // returns 2
    // printf("DEV ONLY ~ sizeof(datachunk_buffer): %lu;\n", sizeof(datachunk_buffer) ); // returns 2

    unsigned int signed_int_type_size = sizeof(datachunk_buffer);
    // printf("DEV ONLY ~ signed_int_type_size: %u;\n", signed_int_type_size ); // returns 2

    // read argv[1]'s DATACHUNK
    while (fread(&datachunk_buffer, signed_int_type_size, 1, input))
    {
        // printf("DEV ONLY ~ datachunk_buffer: %hu\n", datachunk_buffer);

        // Apply multiple to chunk data
        datachunk_buffer = factor * datachunk_buffer;

        // write argv[2]'s DATACHUNK
        fwrite(&datachunk_buffer, signed_int_type_size, 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);

    // Apply a pretty little red bow on top :)
    return 0;
}

// make volume_draft_02
// clear && ./volume_draft_02 input.wav output.wav 2.0
// valgrind ./volume_draft_02 input.wav output.wav 2.0