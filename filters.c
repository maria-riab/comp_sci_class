#include "helpers.h"
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <cs50.h>
# include <math.h>

void swap(RGBTRIPLE* a, RGBTRIPLE* b);

bool is_real_pixel(int i, int j, int height, int width);

RGBTRIPLE blurring(int i, int j, int height, int width, RGBTRIPLE image[height][width]);


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int new_rgbt_value = round(( (float) image[i][j].rgbtBlue +  image[i][j].rgbtGreen  +   image[i][j].rgbtRed) / 3);

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

void swap(RGBTRIPLE* a, RGBTRIPLE* b)
{
    RGBTRIPLE placeholder = *a;
    *a = *b;
    *b = placeholder;

}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            swap(&image[i][j], &image[i][width - j - 1]);

        }
    }
}



// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    
    // put new blurred pixel into image copy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = blurring(i, j, height, width, image);
        }
    }
    
    // copy blurred image to original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    } 
}





RGBTRIPLE blurring(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    //initalize variables that will keep track of new red green and blue values
    
    int avrR; int avrG; int avrB; avrR = avrG = avrB = 0;
    int p_count = 0;
    
    // iterate in a 3x3 grid around the pixel
    for (int k = -1; k <= 1; k++)
    {
        for (int m = -1; m <= 1; m++)
        {
            //new i and j are coordinates for a pixel in the 3x3
            int new_i = i + k;
            int new_j = j + m;

            if (is_real_pixel(new_i, new_j, height, width))
            {
                p_count++;

                avrR +=  image[new_i][new_j].rgbtRed;

                avrG +=  image[new_i][new_j].rgbtGreen;

                avrB +=  image[new_i][new_j].rgbtBlue;
            }
        }
    }
    
    
    RGBTRIPLE blurred;
    
    blurred.rgbtRed = round((float)avrR / p_count);

    blurred.rgbtGreen = round((float)avrG / p_count);

    blurred.rgbtBlue = round((float)avrB / p_count);

    return blurred;
}

    

bool is_real_pixel(int i, int j, int height, int width)
{
    // if pixel is within the image return true
    
    if ((i >= 0 && i < height) && (j >= 0 && j < width))
    {
        return true;
    }
    return false;
}