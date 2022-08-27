#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Getting user's name
    string name = get_string("What's your name? ");

    //Printing Hello, user's name
    printf("Hello, %s \n", name);
}
