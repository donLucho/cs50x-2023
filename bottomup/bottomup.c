// Optional Lab(s) 4 by Luis Artavia - Bottomup
// draft processed on: August 8, 2023
// Composed on: August 2, 2023
// Practice document not intended for evaluation

// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: copy infile outfile\n");
        return 1;
    }

    // Remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

    // Open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // Open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf("Could not create %s.\n", outfile);
        return 3;
    }

    // Read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // The second of these headers called BITMAPINFOHEADER is 40 bytes long (320 bits) - 1 byte equals 8 bits

    // Read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // DEV ONLY ~ consoles go here to "ensure" myself of anything
    // uint32_t - %u
    // int32_t  - %i
    // uint16_t - %hu

    /*
    printf("\n\n");
    printf("DEV ONLY ~ bf more\n");
    printf("DEV ONLY ~ &bf: %p\n", &bf);                    // returns 0x7ffdc8ff4060
    printf("DEV ONLY ~ sizeof(bf): %lu;\n", sizeof(bf) );   // returns 14 (bytes or 112 bits)
    printf("bf.bfType: %hu\n", bf.bfType);                  // uint16_t - returns 19978
    printf("bf.bfSize: %u\n", bf.bfSize);                   // uint32_t - returns 5972024
    printf("bf.bfReserved1: %hu\n", bf.bfReserved1);        // uint16_t - returns 0
    printf("bf.bfReserved2: %hu\n", bf.bfReserved2);        // uint16_t - returns 0
    printf("bf.bfOffBits: %u\n", bf.bfOffBits);             // uint32_t - returns 54

    printf("\n");
    printf("DEV ONLY ~ bi more\n");
    printf("DEV ONLY ~ &bi: %p\n", &bi);                    // returns 0x7ffdc8ff4038
    printf("DEV ONLY ~ sizeof(bi): %lu;\n", sizeof(bi) );   // returns 40 (bytes or 320 bits)
    printf("bi.biSize: %u\n", bi.biSize);                   // uint32_t - returns 40
    printf("bi.biWidth: %i\n", bi.biWidth);                 // int32_t  - returns 1728
    printf("bi.biHeight: %i\n", bi.biHeight);               // int32_t  - returns -1152 (this appears to confirm my hunch)
    printf("bi.biPlanes: %hu\n", bi.biPlanes);              // uint16_t - returns 1
    printf("bi.biBitCount: %hu\n", bi.biBitCount);          // uint16_t - returns 24
    printf("bi.biCompression: %u\n", bi.biCompression);     // uint32_t - returns 0
    printf("bi.biSizeImage: %u\n", bi.biSizeImage);         // uint32_t - returns 5971970
    printf("bi.biXPelsPerMeter: %i\n", bi.biXPelsPerMeter); // int32_t  - returns 11811
    printf("bi.biYPelsPerMeter: %i\n", bi.biYPelsPerMeter); // int32_t  - returns 11811
    printf("bi.biClrUsed: %u\n", bi.biClrUsed);             // uint32_t - returns 0
    printf("bi.biClrImportant: %u\n", bi.biClrImportant);   // uint32_t - returns 0
    */

    // Ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        printf("Unsupported file format.\n");
        return 4;
    }

    // my first attempt at curing the defective code
    bi.biHeight = (-1 * bi.biHeight);

    /*
    printf("\n");
    printf("DEV ONLY ~ BITMAPFILEHEADER more\n");
    printf("DEV ONLY ~ sizeof(BITMAPFILEHEADER): %lu;\n", sizeof(BITMAPFILEHEADER) );  // returns 14

    printf("\n");
    printf("DEV ONLY ~ BITMAPINFOHEADER more\n");
    printf("DEV ONLY ~ sizeof(BITMAPINFOHEADER): %lu;\n", sizeof(BITMAPINFOHEADER) );  // returns 40

    printf("\n");
    printf("DEV ONLY ~ RGBTRIPLE more\n");
    printf("DEV ONLY ~ sizeof(RGBTRIPLE): %lu;\n", sizeof(RGBTRIPLE) );  // returns 3
    */

    /**/
    // Write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // Write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // Determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // Iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // Iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // Temporary storage
            RGBTRIPLE triple;

            // Read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // Write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        // Skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // Then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    /**/

    // Close infile
    fclose(inptr);

    // Close outfile
    fclose(outptr);

    // Success
    return 0;
}
