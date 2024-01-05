#include <stdio.h>
#include <string.h>
#include <stdbool.h>

size_t string_length(char* str)     //Gets char pointer on the first character of the string, and returns number of letters.
{
    if(str == NULL)
    {
        return 0;
    }

    size_t i = 0;

    while(*str != '\0')     //While string dereferenced, that is the value of the string is unlike null character,
    {                       //iterate through the array and increment the variable i at the same time.
        str++;
        i++;
    }

    return i;
}

bool strings_identical(char* arr1, char* arr2)
{
    if(arr1 == NULL || arr2 == NULL)
    {
        return false;
    }

    while((*arr1 != '\0') && (*arr2 != '\0'))   //As long as both of the strings are not at the end yet
    {
        if(*arr1 != *arr2)  //If the values are not equal
        {
            return false;
        }

        arr1++;
        arr2++;
    }

    if((*arr1 != '\0') || (*arr2 != '\0'))  //If one of the two isn't at the end of the string yet, that means that they are not equal
    {
        return false;
    }

    return true;
}


int main(void)
{
    char name[] = "Michael";
    char lastname[] = "Michaele";

    bool check = strings_identical(name, lastname);

    printf("Name: %s\n", name);     //Print out string
    printf("Lastname: %s\n", lastname);

    size_t name_length_function = string_length(name);
    size_t name_strlen = strlen(name);

    size_t lastname_length_function = string_length(lastname);
    size_t lastname_strlen = strlen(lastname);

    printf("Result of our function for name: %lu\nResult of strlen for name: %lu\n", name_length_function, name_strlen);
    printf("Result of our function for lastname: %lu\nResult of strlen for lastname: %lu\n", lastname_length_function, lastname_strlen);

    printf("These two strings are identical. Is thaht correct?: %s\n", check ? "true" : "false");
                                        //If check returns the bool value 'true' then print out "true", else print out "false"
    return 0;
}
