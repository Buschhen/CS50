#include <cs50.h>
#include <stdio.h>

int main(void)
{   
    //initalize int
    int number = 0;
    do{
    // get number from user
    number = get_int("Height: ");
    //check if number is between 1 and 8
    }while(number < 1 || number > 8);
    printf("\n");
    for(int i = 0; i < number+1; i++){
//        int counter = 1
//        for(int spaceleft = 0; spaceleft > i){
//            printf(" ")
//        }
        for(int left = 0; left<1*i;left++){
            printf("#");
        }
        printf("  ");
        for(int right = 0; right <1*i;right++){
            printf("#");
        }

    }        printf("\n");
}
