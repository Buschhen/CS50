#include "helpers.h"
#include <stdio.h>
#include <math.h>
// Convert image to grayscale


//int pixel(int height, int width, int i, int j, image[height][width], int k, int u);
//void makeblur(int height, int width, int i, int j, image[height][width], int avr);

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float temp = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue);
            temp /= 3;
            int num = round(temp);
            image[i][j].rgbtRed = num ;
            image[i][j].rgbtGreen = num ;
            image[i][j].rgbtBlue = num;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for ( int j = 0; j < width / 2; j++)
        {
            int Red = image[i][j].rgbtRed;
            int Green = image[i][j].rgbtGreen;
            int Blue = image[i][j].rgbtBlue;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][width - j - 1].rgbtRed = Red;
            image[i][width - j - 1].rgbtGreen = Green;
            image[i][width - j - 1].rgbtBlue = Blue;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sumBlue;
    int sumGreen;
    int sumRed;
    float counter;
    //create a temporary table of colors to not alter the calculations
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sumBlue = 0;
            sumGreen = 0;
            sumRed = 0;
            counter = 0.00;

            // sums values of the pixel and 8 neighboring ones, skips iteration if it goes outside the pic
            for (int k = -1; k < 2; k++)
            {
                 if (i + k < 0 || i + k > height - 1)
                 {
                     continue;
                 }

                for (int h = -1; h < 2; h++)
                 {
                     if (j + h < 0 || j + h > width - 1)
                     {
                         continue;
                     }

                    sumBlue += image[i + k][j + h].rgbtBlue;
                    sumGreen += image[i + k][j + h].rgbtGreen;
                    sumRed += image[i + k][j + h].rgbtRed;
                    counter++;
                }
            }

            // averages the sum to make picture look blurrier
            temp[i][j].rgbtBlue = round(sumBlue / counter);
            temp[i][j].rgbtGreen = round(sumGreen / counter);
            temp[i][j].rgbtRed = round(sumRed / counter);
        }
    }

    //copies values from temporary table
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
}



// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Clone original image to make calculations
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Main loop to sum up all values for each channel in each pixel relative to Gx and Gy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float rGx, gGx, bGx, rGy, gGy, bGy;
            rGx = gGx = bGx = rGy = gGy = bGy = 0;

            // Up
            if (i > 0)
            {
                rGy += -2 * copy[i-1][j].rgbtRed;
                gGy += -2 * copy[i-1][j].rgbtGreen;
                bGy += -2 * copy[i-1][j].rgbtBlue;
            }
            // Down
            if (i < height - 1)
            {

                rGy += 2 * copy[i+1][j].rgbtRed;
                gGy += 2 * copy[i+1][j].rgbtGreen;
                bGy += 2 * copy[i+1][j].rgbtBlue;
            }
            // Left
            if (j > 0)
            {
                rGx += -2 * copy[i][j-1].rgbtRed;
                gGx += -2 * copy[i][j-1].rgbtGreen;
                bGx += -2 * copy[i][j-1].rgbtBlue;

            }
            // Right
             if (j < height - 1)
            {
                rGx += 2 * copy[i][j+1].rgbtRed;
                gGx += 2 * copy[i][j+1].rgbtGreen;
                bGx += 2 * copy[i][j+1].rgbtBlue;

            }
            // Up left
            if (i > 0 && j > 0)
            {
                // Note: change sign in Gx values here and the result changes side
                rGx += -1 * copy[i-1][j-1].rgbtRed;
                gGx += -1 * copy[i-1][j-1].rgbtGreen;
                bGx += -1 * copy[i-1][j-1].rgbtBlue;
                rGy += -1 * copy[i-1][j-1].rgbtRed;
                gGy += -1 * copy[i-1][j-1].rgbtGreen;
                bGy += -1 * copy[i-1][j-1].rgbtBlue;
            }
            // Up right
            if (i > 0 && j < width - 1)
            {
                rGx += 1 * copy[i-1][j+1].rgbtRed;
                gGx += 1 * copy[i-1][j+1].rgbtGreen;
                bGx += 1 * copy[i-1][j+1].rgbtBlue;
                rGy += -1 * copy[i-1][j+1].rgbtRed;
                gGy += -1 * copy[i-1][j+1].rgbtGreen;
                bGy += -1 * copy[i-1][j+1].rgbtBlue;
            }
            // Bottom right
            if (i < height - 1  && j < width - 1)
            {
                rGx += 1 * copy[i+1][j+1].rgbtRed;
                gGx += 1 * copy[i+1][j+1].rgbtGreen;
                bGx += 1 * copy[i+1][j+1].rgbtBlue;
                rGy += 1 * copy[i+1][j+1].rgbtRed;
                gGy += 1 * copy[i+1][j+1].rgbtGreen;
                bGy += 1 * copy[i+1][j+1].rgbtBlue;
            }
            // Bottom left
            if (i < height - 1  && j > 0)
            {
                rGx += -1 * copy[i+1][j-1].rgbtRed;
                gGx += -1 * copy[i+1][j-1].rgbtGreen;
                bGx += -1 * copy[i+1][j-1].rgbtBlue;
                rGy += 1 * copy[i+1][j-1].rgbtRed;
                gGy += 1 * copy[i+1][j-1].rgbtGreen;
                bGy += 1 * copy[i+1][j-1].rgbtBlue;
            }

            // Compute result
            image[i][j].rgbtRed = (int) cap255(sqrt((rGx*rGx)+(rGy*rGy)));
            image[i][j].rgbtGreen = (int) cap255(sqrt((gGx*gGx)+(gGy*gGy)));
            image[i][j].rgbtBlue = (int) cap255(sqrt((bGx*bGx)+(bGy*bGy)));
        }
    }
    return;
}

// Function to cap results at 255 maximum
int cap255(double n)
{
    int result = 0;

    if (n >= 255)
    {
        result = 255;
    }
    else if(n < 0)
    {
        result = 0;
    }
    else
    {
        result = (int) round(n);
    }
    return (result);
}

