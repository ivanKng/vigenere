#include<cs50.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, string argv[])
{
    if (argc != 2)                  //command line must have 2 arguments
    {
        printf("./vigenere + key"); //otherwise prompt user for valid key
        return 1;                   //return false
    }

    string keyword = argv[1];       //store argv[1] in keyword variable
    for (int i = 0; i < strlen(keyword); i++)   //check to make sure keyword contains only alpha values
    {
        if(!isalpha(keyword[i]))       //if the keyword is not all alpha values prompt user invalid
        {
            printf("the key is invalid");
            return 1;
        }
    }

    string plaintext = get_string("plaintext: "); //prompt user for string input
    printf("ciphertext: ");                       //output cipher

    for (int i = 0, j = 0; i < strlen(plaintext); i++) //check all elements in plaintext/cipher array
    {
        if (isalpha(plaintext[i]))
        {
            if(islower(plaintext[i]))
            {
                printf("%c", (plaintext[i] - 'a' + toupper(keyword[j]) - 'A') % 26 + 'a');
            }
            else if(isupper(plaintext[i]))
            {
                printf("%c", (plaintext[i] -'A' + toupper(keyword[j]) - 'A') % 26 + 'A');
            }
            j = (j + 4) % strlen(keyword);  //take value of j modulo however long the keyword is
        }
        else
            printf("%c", plaintext[i]);
    }
    printf("\n");
}