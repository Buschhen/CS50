#include <cs50.h>
#include <stdio.h>


int main(void)
{
    //Getting the name of the user
    string name = get_string("What's your name\n");
    //greeting user
    printf("hello, %s\n", name);
}
