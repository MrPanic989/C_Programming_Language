#include <stdio.h>
#include <string.h>

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


int main(void)
{
    char name[] = "Michael";
    char lastname[] = "Blaczykowsky";

    printf("Name: %s\n", name);     //Print out string
    printf("Lastname: %s\n", lastname);

    size_t name_length_function = string_length(name);
    size_t name_strlen = strlen(name);

    size_t lastname_length_function = string_length(lastname);
    size_t lastname_strlen = strlen(lastname);

    printf("Result of our function for name: %lu\nResult of strlen for name: %lu\n", name_length_function, name_strlen);
    printf("Result of our function for lastname: %lu\nResult of strlen for lastname: %lu\n", lastname_length_function, lastname_strlen);

    return 0;
}
