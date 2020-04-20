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
    for (int i = 0; i < height - 3;i += 3)
    {
        for (int j = 0; j < width - 3; j += 3)
        {
            int avr_red_r = 0;
            int avr_green_r = 0;
            int avr_blue_r = 0;
            for (int a = -1; a < 2; a++)
            {
                for (int b = -1; b < 2; b++)
                {
                    avr_red_r += image[i + a][j + b].rgbtRed;
                    avr_green_r += image[i + a][j + b].rgbtGreen;
                    avr_blue_r += image[i + a][j + b].rgbtBlue;
                }
            }
            for (int a = -1; a < 2; a++)
            {
                for (int b = -1; b < 2; b++)
                {
                    image[i + a][j + b].rgbtRed = avr_red_r / 9;
                    image[i + a][j + b].rgbtGreen = avr_green_r / 9;
                    image[i + a][j + b].rgbtBlue = avr_blue_r / 9;
                }
            }
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

