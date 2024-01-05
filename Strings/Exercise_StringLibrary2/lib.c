#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "lib.h"

bool string_starts_with(char* string, char* substr)
{
    if(string == NULL || substr == NULL)
    {
        return false;
    }

    size_t length = strlen(substr);
    for(size_t i = 0; i < length; ++i)
    {
        if(string[i] != substr[i])
        {
            return false;
        }
    }

    return true;
}

bool string_ends_with(char* string, char* substr)
{
    if(string == NULL || substr == NULL)
    {
        return false;
    }

    size_t length_str = strlen(string);
    size_t length_sub = strlen(substr);

    //We have to iterate through two strings backward and compare them
    size_t j = length_sub;
    size_t range = length_str - length_sub;
    for(size_t i = length_str - 1; i >= range; --i)
    {
        for(; j > 0;)
        if(string[i] != substr[j - 1])
        {
            return false;
        }
        else
        {
            break;
        }
        --j;
    }

    return true;
}

char* string_find_first_not_of(char* string, char* substr)
{
    if(string == NULL)
    {
        return NULL;
    }

    if(substr == NULL)
    {
        return string;
    }

    char* found_substring = strstr(string, substr); //Finds the index of the first letter of substr
    size_t length = strlen(substr);

    found_substring += length;  //We have to move the index of the string by number of letter of the substring
    if(*found_substring == '\0')
    {
        return NULL;    //If it happens to be the null character, we return NULL as result
    }

    return found_substring;
}

char* string_n_copy(char* dest, char* src, size_t count)
{
    if((src == NULL) || count == 0)
    {
        return dest;
    }

    if(dest == NULL)
    {
        return NULL;
    }

    for(size_t i = 0; i < count; ++i)
    {
        dest[i] = src[i];
    }

    /*We don't have to set the last to null character because we already initialized the whole array with '\0'
    dest = dest + count + 1;
    *dest = '\0';
    */

    return dest;
}
