/**************************************************************************************************
 Name        : readability.c
 Author      : Youssef Nashaat
 Created on	 : Aug 28, 2022
 Description : Counting the letters and words and sentences for any paragraph.
 **************************************************************************************************/
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);



int main(void)
{
    string text = get_string("Please enter your text: ");
    int letters = count_letters(text);          //Counting letters
    int words = count_words(text);              //Counting words
    int sentences = count_sentences(text);      //Counting sentences

    //Getting parameters L and S
    float L = (float)letters / (float)words * 100.0;
    float S = (float)sentences / (float)words * 100.0;


    //Calculating index
    float index = 0.0588 * L - 0.296 * S - 15.8;


    //Printing Grade depending on index
    if (index < 16 && index >= 1)
    {
        printf("Grade %.0f\n", index);
    }

    else if (index < 0)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        printf("Grade 16+\n");
    }

}


//Counting letters in text
int count_letters(string text)
{
    int letter = 0;

    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if (((int)text[i] >= 65 && (int)text[i] <= 90) || ((int)text[i] >= 97 && (int)text[i] <= 122))
        {
            letter++;
        }
    }
    return letter;

}


//Counting words in text
int count_words(string text)
{
    int word = 0;

    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if ((text[i] != 32) && (text[i + 1] == 32))
        {
            word++;
        }
    }
    return word + 1;
}


//Counting sentences in text
int count_sentences(string text)
{
    int sentence = 0;

    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if ((int)text[i] == 33 || (int)text[i] == 46 || (int)text[i] == 63)
        {
            sentence++;
        }
    }
    return sentence;
}

