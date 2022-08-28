/**************************************************************************************************
 Name        : substitution.c
 Author      : Youssef Nashaat
 Created on	 : Aug 28, 2022
 Description : Encryption game to substitute a normal string with an encrypted one.
 **************************************************************************************************/
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char Alphabet_capital[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char Alphabet_lower[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

char upper(char c);
char lower(char c);
bool ckia(string key);
bool check_duplicity(string s);
string encrypting(string text, string key);



int main(int argc, string argv[])
{
    //Assigning argument to key variable
    string key = argv[1];

    //Checking for NULL argument
    if (argv[1] == NULL)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //Checking for more than one argument
    else if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //Checking number of characters
    else if (strlen(key) != 26)
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    //Checking Validity
    else if (ckia(key) == false)
    {
        printf("Invalid characters.\n");
        return 1;
    }

    //Checking Duplicity
    else if (check_duplicity(key) == false)
    {
        printf("Mustn't duplicate characters.\n");
        return 1;
    }



    //Getting plain text from user
    string plain_text = get_string("plaintext: ");

    //Encrypting of plain text
    string encrypted_text = encrypting(plain_text, key);

    //Printing encrypted text
    printf("ciphertext: %s\n", encrypted_text);

    return 0;

}


//Encrypting function
string encrypting(string plain_text, string key)
{
    //Nested loops one for text and another for Alphabetics
    for (int i = 0 ; i < strlen(plain_text) ; i++)
    {
        for (int j = 0 ; j < 26 ; j++)
        {
            if (plain_text[i] == Alphabet_capital[j])
            {
                plain_text[i] = upper(key[j]);
                break;
            }

            else if (plain_text[i] == Alphabet_lower[j])
            {
                plain_text[i] = lower(key[j]);
                break;
            }
        }
    }

    return plain_text;
}


//Converting character to uppercase
char upper(char c)
{
    int boolean = islower(c);

    //Not uppercase
    if (boolean != 0)
    {
        c -= 32;
    }
    return c;
}


//Converting character to lowercase
char lower(char c)
{
    int boolean = islower(c);

    //Not lowercase
    if (boolean == 0)
    {
        c += 32;
    }
    return c;
}


//ckia; check key invalid alphabetic
bool ckia(string key)
{
    for (int i = 0 ; i < 26 ; i++)
    {
        //Not Alphabetic
        if (isalpha(key[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

//Checking for duplicity
bool check_duplicity(string s)
{

    for (int i = 0 ; i < 26 ; i++)
    {
        int n = 0;

        for (int j = 0 ; j < 26 ; j++)
        {
            if (s[i] == s[j])
            {
                n++;
            }
        }

        if (n != 1)
        {
            return false;
        }
    }

    return true;

}
