#include "helpers.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <math.h>

RGBTRIPLE average_pixel(RGBTRIPLE arr[height][width]);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int new_rgbt_value = round((image[i][j].rgbtBlue  +  image[i][j].rgbtGreen  +   image[i][j].rgbtRed) / 3);

            image[i][j].rgbtBlue  = new_rgbt_value;

            image[i][j].rgbtGreen  = new_rgbt_value;

            image[i][j].rgbtRed  = new_rgbt_value;
        }

    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;

            int originalBlue = image[i][j].rgbtBlue;

            int originalGreen = image[i][j].rgbtGreen;

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);

            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);

            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if (sepiaRed > 255)
            {
                sepiaRed  = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen  = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue  = 255;
            }

            image[i][j].rgbtBlue  = sepiaBlue;

            image[i][j].rgbtGreen  = sepiaGreen;

            image[i][j].rgbtRed  = sepiaRed;

        }
    }



//
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE placeholder;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            placeholder = image[i][j];

            image[i][j] = image[i][width - (j + 1)];

            image[i][width - (j + 1)] = placeholder;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    image[height][width] = malloc(sizeof(image[height][width]));

    copied_image[height][width] = malloc(sizeof(image[height][width] + 1));

    for (int i = 0; i < height + 1; i++)
    {
        for (int j = 0; j < width + 1; j++)
        {
            copied_image[i][j] = image[i][j];
        }
    }

    // check right corner
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
        }
    }




    //check left corner
    //check bottom right corner
    //check bottom left corner
}
