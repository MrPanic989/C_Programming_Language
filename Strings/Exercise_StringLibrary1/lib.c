#include <stdio.h>
#include <string.h>

#include "lib.h"

char* to_upper_case_str(char* text)
{
    if(text == NULL)
    {
        return NULL;
    }

    size_t length = strlen(text);   //sizeof(text) would return size of a pointer but strlen(text)
                                    //returns exactly the length of the array.
    for(size_t i = 0; i < length; ++i)
    {
        if(text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = text[i] - 32;
        }
        else
        {
            continue;
        }
    }

    return text;
}

char* to_lower_case_str(char* text)
{
    if(text == NULL)
    {
        return NULL;
    }

    size_t length = strlen(text);
    //printf("%lu\n", length);
    for(size_t i = 0; i < length; ++i)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = text[i] + 32;
        }
        else
        {
            continue;
        }
    }

    return text;
}

char* char_search(char* text, char character)
{
    if(text == NULL)
    {
        return NULL;
    }

    size_t length = strlen(text);
    size_t index = 0;
    for(size_t i = 0; i < length; ++i)
    {
        if(text[i] == character)
        {
            break;
        }
        index++;

    }

    char* target = text + index;
    if(*target == '\0')
    {
        return NULL;
    }

    return target;
}
