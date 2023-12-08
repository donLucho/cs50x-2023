// Required Problem set 4 by Luis Artavia - Filter (less)
// draft processed on: August 14, 2023, August 15, 2023
// submitted for grade on: August 16, 2023

// DEV ONLY
// #include <stdio.h>
#include "helpers.h"
#include <math.h>

// image[x][y] - x represents the row(s); y represents the column(s);
// image[height-1][y] - image[height-1][y] represents the last row
// image[x][width-1] - image[x][width-1] represents the last column
// For example, to affect the color with pixel located at image[2][3]
// image[2][3].rgbtRed || // image[2][3].rgbtGreen || // image[2][3].rgbtBlue = newValue (b/t 0 and 255);

/*
grayscale formula
    average = (originalRed + originalGreen + originalBlue) / 3;
*/

// Convert image to grayscale (August 14, 2023)
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // i >> rows >> height
    for (int i = 0; i < height; i++)
    {
        // j >> columns >> width
        for (int j = 0; j < width; j++)
        {
            float pixelsum = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;

            image[i][j].rgbtRed = (int) round(pixelsum / 3);
            image[i][j].rgbtGreen = (int) round(pixelsum / 3);
            image[i][j].rgbtBlue = (int) round(pixelsum / 3);
        }
    }
    return;
}

/*
sepia formula
  sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
  sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
  sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
*/

// Convert image to sepia (August 14, 2023)
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // i >> rows >> height
    for (int i = 0; i < height; i++)
    {
        // j >> columns >> width
        for (int j = 0; j < width; j++)
        {
            float R = image[i][j].rgbtRed;
            float G = image[i][j].rgbtGreen;
            float B = image[i][j].rgbtBlue;

            int newR = (int) round((.393 * R) + (.769 * G) + (.189 * B));
            int newG = (int) round((.349 * R) + (.686 * G) + (.168 * B));
            int newB = (int) round((.272 * R) + (.534 * G) + (.131 * B));

            int pixelmax = 255;
            newR = (newR > pixelmax) ? pixelmax : newR;
            newG = (newG > pixelmax) ? pixelmax : newG;
            newB = (newB > pixelmax) ? pixelmax : newB;

            image[i][j].rgbtRed = newR;
            image[i][j].rgbtGreen = newG;
            image[i][j].rgbtBlue = newB;
        }
    }
    return;
}

/*
reflection formula

    image[x][width-1] - image[x][width-1] represents the last column

    // LKGC -- incrementing array
    void incrementing_reverse_array(int image[], int width)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int tmp = image[j];
            image[j] = image[width - 1 - j];
            image[width - 1 - j] = tmp;
        }
        return;
    }

    // LKGC -- decrementing array
    void decrementing_reverse_array(int image[], int width)
    {
        for (int j = width - 1; j >= width / 2; j--)
        {
            int tmp = image[width - 1 - j];
            image[width - 1 - j] = image[j];
            image[j] = tmp;
        }
        return;
    }

*/

// LKGC -- incrementing array instantiator(s)
// Reflect image horizontally (August 14, 2023)
/* void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // i >> rows >> height
    for (int i = 0; i < height; i++)
    {
        // j >> columns >> width
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmp;
        }
    }
    return;
} */

// LKGC -- decrementing array instantiator(s)
// Reflect image horizontally (August 14, 2023)
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // i >> rows >> height
    for (int i = 0; i < height; i++)
    {
        // j >> columns >> width
        for (int j = width - 1; j >= width / 2; j--)
        {
            RGBTRIPLE tmp = image[i][width - 1 - j];
            image[i][width - 1 - j] = image[i][j];
            image[i][j] = tmp;
        }
    }
    return;
}

/*
blur pseudocode

All of these considerations below should be applied to a copy of "SMILEY.BMP" which is smaller in scale; hence, describing below the
implementation and beginnings of a framework starting with (at least) two loops & several requisites including (yet tbd):

    - REQUISITE A: a new temporary variable of type "RGBTRIPLE"; this is a self contained vehicle used to hold all RGB values at any
point in the context of a loop, during a loop, and after a loop as needed here;

    - REQUISITE B: loop #1 is used "to compute the new value for a pixel":

        - inside of the loop, it is necessary to "calculate the average amount of red, the average amount of green and the average
amount of blue"

        - also, in the same loop, since I need an average, I also need a variable to keep track of a running count to place in the
denominator of the average mentioned above,

            - REQUISITE C: requiring ANOTHER PAIR of loops to monitor when the calculation goes out of bounds from image[0][0] to
image[height-1][width-1], etc

            - the gory details such as addressing "edges and corners [which] naturally will have less than individual 9 pixels to
consider" are distinguished and discounted with "continue" keyword (e.g. - skip altogether)

        - the new calculated values should be contained in one location, and what better way than to apply the "Runoff" lessons in
practice with a new temporary variable of type "RGBTRIPLE" - this [tautologously] neccesitates "REQUISITE A"

    - REQUISITE D: loop #2 is used to apply the new values (similar to reversing array values):

        - Specifically, the task requires that [we] "apply those three averages to the channels that correspond to the pixel in
focus within one row and one column of said pixel"; this is where "REQUISITE A" shines
*/

/*
Addendum / Addenda

###############################

// L to R is outtie, Top to Bottom is innie

// with the exception of edges and natural contours, every 9 block grid (3 x 3) [[0 1 2] [3 *4 5] [6 7 8]]
// where *4 is focus, natural limits are up one row, down one row, left one column, right one column

// translation - in an [x][y] system, if a 9px grid spot number *4 is expressed as image[1][1] the limits are expressed as:
// image[x - 1][y], image[x + 1][y], image[x][y - 1], image[x][y + 1]

// and, the following apply, too:
// image[x - 1][y] cannot be less than image[0][y] (the first row)
// image[x + 1][y] cannot be more than image[height-1][y] (the last row)
// image[x][y - 1] cannot be less than image[x][0]  (the first column)
// image[x][y + 1] cannot be more than image[x][width-1] (the last column)

###############################
*/

// Blur image (August 14, 2023; August 15, 2023), This was painful. Let's not do this again anytime soon!
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    // REQUISITE A: - a new temporary variable of type "RGBTRIPLE"; this is a self contained vehicle used to hold all RGB values at
    // any point in the context of a loop, during a loop, and after a loop as needed here;

    RGBTRIPLE tmp[height][width];

    // REQUISITE B - loop #1 is used "to compute the new value for a pixel": [...]

    // DEV ONLY
    // int pixelIdx = 0;

    // i >> rows >> height
    for (int i = 0; i < height; i++)
    {
        // j >> columns >> width
        for (int j = 0; j < width; j++)
        {
            // printf("DEV ONLY ~ i: %i; j: %i; pixelIdx: %i\n", i, j, pixelIdx);
            // smiley yields 63 (0-based) since it's an 8px by 8px, 64px square image

            // printf("DEV ONLY ~ image[%i][%i].rgbtRed: %i; pixelIdx: %i;\n", i, j, image[i][j].rgbtRed, pixelIdx);
            // printf("DEV ONLY ~ image[%i][%i].rgbtGreen: %i; pixelIdx: %i;\n", i, j, image[i][j].rgbtGreen, pixelIdx);
            // printf("DEV ONLY ~ image[%i][%i].rgbtBlue: %i; pixelIdx: %i;\n", i, j, image[i][j].rgbtBlue, pixelIdx);

            float newRedAggregate = 0.0;
            float newGreenAggregate = 0.0;
            float newBlueAggregate = 0.0;

            int denominator = 0;

            // L to R is outtie, Top to Bottom is innie
            // e.g. - x+(-1), x+0, x+1
            for (int x = -1; x <= 1; x++)
            {
                // e.g. - y+(-1), y+0, y+1
                for (int y = -1; y <= 1; y++)
                {
                    // image[x - 1][y], image[x + 1][y], image[x][y - 1], image[x][y + 1]
                    int newX = i + x;
                    int newY = j + y;

                    // image[x - 1][y] cannot be less than image[0][y] (the first row)
                    if (newX < 0)
                    {
                        continue;
                    }

                    // image[x + 1][y] cannot be more than image[height-1][y] (the last row)
                    if (newX > (height - 1))
                    {
                        continue;
                    }

                    // image[x][y - 1] cannot be less than image[x][0]  (the first column)
                    if (newY < 0)
                    {
                        continue;
                    }

                    // image[x][y + 1] cannot be more than image[x][width-1] (the last column)
                    if (newY > (width - 1))
                    {
                        continue;
                    }

                    // it is necessary to "calculate the average amount of red, the average amount of green and the average amount
                    // of blue"
                    newRedAggregate = newRedAggregate + image[newX][newY].rgbtRed;
                    newGreenAggregate = newGreenAggregate + image[newX][newY].rgbtGreen;
                    newBlueAggregate = newBlueAggregate + image[newX][newY].rgbtBlue;
                    denominator = denominator + 1;
                }

                // calculate the average amount of red, the average amount of green and the average amount of blue, then, apply
                // those three averages to the channels that correspond to the pixel in focus within one row and one column of said
                // pixel

                tmp[i][j].rgbtRed = (int) round(newRedAggregate / denominator);
                tmp[i][j].rgbtGreen = (int) round(newGreenAggregate / denominator);
                tmp[i][j].rgbtBlue = (int) round(newBlueAggregate / denominator);
            }

            // DEV ONLY
            // pixelIdx++;
        }
    }

    // printf("DEV ONLY ~ L to R, Top to Bottom, Total: %i px; \n", pixelIdx);

    // REQUISITE D: loop #2 is used to apply the new values (similar to reversing array values): [...]

    // i >> rows >> height
    for (int i = 0; i < height; i++)
    {
        // j >> columns >> width
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
        }
    }

    return;
}

// local testing CMDs
// E.G. - ./filter [flag] infile outfile

/*
mkdir zetto
make
./filter -g ./images/stadium.bmp ./zetto/stadium-g.bmp
./filter -b ./images/stadium.bmp ./zetto/stadium-b.bmp
./filter -r ./images/stadium.bmp ./zetto/stadium-r.bmp
./filter -s ./images/stadium.bmp ./zetto/stadium-s.bmp

./filter -b ./images/zsmiley2.bmp ./zetto/zsmiley-b.bmp

*/
// rm -f filter && rm -rf ./zetto/*.bmp