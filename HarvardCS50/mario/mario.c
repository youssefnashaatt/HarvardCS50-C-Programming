/**************************************************************************************************
 Name        : mario.c
 Author      : Youssef Nashaat
 Created on	 : Aug 28, 2022
 Description : Drawing a full pyramid with hashtags
 **************************************************************************************************/
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height? ");
    }

    while (n <= 0 || n > 8);

    int k = n;

    while (n != 0)
    {
        //Space Loop
        for (int i = (n - 1); i > 0; i--)
        {
            printf(" ");
        }

        //Hashtag Loop
        for (int j = k; j >= n; j--)
        {
            printf("#");
        }

        //In between Spaces
        printf("  ");

        //Second Hashtag Loop
        for (int j = k; j >= n; j--)
        {
            printf("#");
        }

        printf("\n");

        n--;

    }


}
