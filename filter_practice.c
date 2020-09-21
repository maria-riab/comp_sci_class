#include "helpers.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <math.h>

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
            
            printf("%x", image[i][j]);
        }
        
    }
}
