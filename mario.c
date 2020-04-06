#include <cs50.h>
#include <stdio.h>

int main(void)
{   
    //initalize int
    int number = 0;
    do
    {
        // get number from user
        number = get_int("Height: ");
        //check if number is between 1 and 8
    }
    while (number < 1 || number > 8);
    for (int i = 1; i <= number ; i++)
    {
        //spaces on the left side of the pyramid
        for (int spaceleft = number - i; spaceleft > 0; spaceleft--)
        {
            printf(" ");
        }
        //right side of the pyramid
        for (int left = 0; left < 1 * i ; left++)
        {
            printf("#");
        }
        if (i > 0)
        {
            printf("  ");
        }
        //left side of pyramid
        for (int right = 0; right < 1 * i ; right++)
        {
            printf("#");
        }
        if (i > 0)
        {
            printf("\n");
        }
    }

}
