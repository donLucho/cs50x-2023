// Required Lab(s) 4 by Luis Artavia - Smiley
// draft processed on: August 8, 2023
// submitted for grade on: August 9, 2023

#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Make black pixels turn Harvard Ink (#1E1E1E)
            if (image[i][j].rgbtRed == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtBlue == 0x00)
            {
                image[i][j].rgbtRed = 0x1e;
                image[i][j].rgbtGreen = 0x1e;
                image[i][j].rgbtBlue = 0x1e;
            }

            // Make white pixels turn Harvard Crimson (#A51C30)
            if (image[i][j].rgbtRed == 0xff && image[i][j].rgbtGreen == 0xff && image[i][j].rgbtBlue == 0xff)
            {
                image[i][j].rgbtRed = 0xa5;
                image[i][j].rgbtGreen = 0x1c;
                image[i][j].rgbtBlue = 0x30;
            }
        }
    }
}

// make colorize - no need to run "make colorize"
// make helpers  - no need to run "make helpers"
// make - run "make" instead and it takes contents of Makefile to produce the necessary executables;
// and, if changes are made to "helpers.c", "rimraf" the compiled "colorize" file, then, re-run "make"
// finally, run the following -  ./colorize smiley.bmp outfile.bmp