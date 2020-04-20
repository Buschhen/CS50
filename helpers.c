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
            temp[j][i].rgbtBlue = round(sumBlue / counter);
            temp[j][i].rgbtGreen = round(sumGreen / counter);
            temp[j][i].rgbtRed = round(sumRed / counter);
        }
    }

    //copies values from temporary table
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

