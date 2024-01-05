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
//This implementation represents the strncat
char* concatinate_n_string(char* destination, char* source, size_t nr)
{
    if((source == NULL) || nr == 0)
    {
        return destination;
    }

    if(destination == NULL)
    {
        return NULL;
    }

    size_t length = string_length(destination);
    destination = destination + length;     //We have moved the pointer from the index 0 to the index of
    //the null character of our destination string. That is the place where we want to concatinate the second string.

    size_t i = 0;
    while((*source != '\0') && (i < nr - 1))    //As long as we don't reach the end of the source string, that is '\0'
    {                                       //and as long we don't reach second to last place, because we have to copy the
        *destination = *source;             //null character as well, we iterate the loop and set the value of the first string to
        destination++;                      //the value of the second string
        source++;
        i++;
    }

    *destination = '\0';

    return destination;
}

//This implementation represents the strcat function
char* concatinate_string(char* destination, char* source)
{
    if((source == NULL))
    {
        return destination;
    }

    if(destination == NULL)
    {
        return NULL;
    }

    size_t length_destination = string_length(destination);
    destination = destination + length_destination;     //We have moved the pointer from the index 0 to the index of
    //the null character of our destination string. That is the place where we want to concatinate the second string.

    while(*source != '\0')    //As long as we don't reach the end of the source string, that is '\0'
    {                                       //we iterate the loop and set the value of the first string to
        *destination = *source;             //the value of the second string
        destination++;
        source++;

    }

    *destination = '\0';    //After we leaved the loop, that is we reached the end of the source string and
                            //contemporaneous the end of the destination string, we have to set the null character.
    return destination;
}


int main(void)
{
    char name[36] = "Michael";
    char lastname[16] = "Michaele";
    char name1[36] = "Michael";
    char lastname1[16] = "Simmatschek";

    printf("Name: %s\n", name);     //Print out string
    printf("Lastname: %s\n", lastname);

    size_t name_length_function = string_length(name);
    size_t name_strlen = strlen(name);

    size_t lastname_length_function = string_length(lastname);
    size_t lastname_strlen = strlen(lastname);

    printf("Result of our function for name: %lu\nResult of strlen for name: %lu\n", name_length_function, name_strlen);
    printf("Result of our function for lastname: %lu\nResult of strlen for lastname: %lu\n", lastname_length_function, lastname_strlen);

    bool check = strings_identical(name, lastname);
    printf("These two strings are identical. Is thaht correct?: %s\n", check ? "true" : "false");
                                        //If check returns the bool value 'true' then print out "true", else print out "false"

    printf("Are the name and name1 strings identical?: %s\n", strings_identical(name, name1) ? "true" : "false");

    concatinate_n_string(name, " ", 2);
    concatinate_n_string(name, lastname, 16);
    printf("The full name is: %s\n", name);

    concatinate_string(name1, " ");
    concatinate_string(name1, lastname1);
    printf("The full name of the second person is: %s\n", name1);

    return 0;
}
