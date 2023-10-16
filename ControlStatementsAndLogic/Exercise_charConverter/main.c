/*In this exercise, you have to use the datatype char to convert/check certain char values.

Implement the following checks:
- is numeric character
- is alpha character
- is alpha numeric character
- is upper case character
- is lower case character

Meaning of the function names:
-Numeric: 0-9 (digits)
-Alpha: a-z, A-Z (alphabeth characters)
-Upper Case: A-Z
-Lower Case: a-z

Note:
The shift from Upper Case to Lower Case is 32 in the ASCII table.
E.g. 'A' -> 'a' by subtracting 32 E.g. 'a' -> 'A' by adding 32

You do not have to look up the ASCII table for this exercise, but you can do so.

Afterward, implement the following conversion:
- to upper case character
- to lower case character
*/
#include <stdio.h>
#include <stdbool.h>

bool numeric(char value)            //This function checks if the character is a number
{
    if((value >= '0') && (value <= '9'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool upper_case(char value)         //This function checks if the character is a capital letter
{
    if((value >= 'A') && (value <= 'Z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool lower_case(char value)         //This function checks if the character is a lowercase letter
{
    if((value >= 'a') && (value <= 'z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool alpha(char value)              //This function checks if the character is a letter at all.
{                                   //It calls up the two functions 'upper_case()' and 'lower_case()'
    if(upper_case(value) || lower_case(value))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char character;

    printf("Please enter a character which is represent in the ASCII table: ");
    scanf("%c", &character);

    bool numeric_character = numeric(character);   //We want also to check if the character is alpha numeric, so we
    if(numeric_character)                          //have to save the return value of the numeric() function
    {
        printf("Your character is a numeric character!\n");
    }
    else
    {
        printf("Your character is not a number! Let's find out what type of a character it really is.\n");
    }

    bool alpha_character = alpha(character);        //We also want to save the return value of the alpha() function.
    if(alpha_character)
    {
        printf("Your character is a alphabeth character!\n");
    }
    else
    {
        printf("Your character is not a letter!\n");
    }

    if(numeric_character || alpha_character)    //Now we can check if the character is alpha numeric with the
    {                                           //previously saved return values.
        printf("Your input is an alpha numeric character!\n");
    }
    else
    {
        printf("Your input is a special character!\n");
    }

    if(upper_case(character))
    {
        printf("Your character is an upper case letter!\n");

        printf("\tIn lower case: %c\n", character + 32);        //If the character is a capital letter, we want
    }                                                           //also to print it out in lower case.
    else
    {
        printf("Your character is not a upper case letter!\n");
    }

    if(lower_case(character))
    {
        printf("Your character is a lower case letter!\n");

        printf("\tIn upper case: %c\n", character - 32);    //And if the character is a lower case letter, we want
    }                                                       //to print it out in upper case.
    else
    {
        printf("Your character is not a lower case letter!\n");
    }

    return 0;
}
