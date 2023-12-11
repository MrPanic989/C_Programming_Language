#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "lib.h"

bool all_of(int32_t *array, size_t length, int32_t value)
{
    if(array == NULL)
    {
        return false;
    }

    for(size_t i = 0; i < length; ++i)
    {
        if(value == array[i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool any_of(int32_t *array, size_t length, int32_t value)
{
    if(array == NULL)
    {
        return false;
    }

    for(size_t i = 0; i < length; ++i)
    {
        if(value == array[i])
        {
            return true;
        }
    }

    return false;
}

bool none_of(int32_t *array, size_t length, int32_t value)
{
    if(array == NULL)
    {
        return false;
    }

    for(size_t i = 0; i < length; ++i)
    {
       if(value != array[i])
       {
            continue;
       }
       else
       {
            return false;
       }
    }

    return true;
}

size_t count(int32_t *array, size_t length, int32_t value)
{
    if(array == NULL)
    {
        return -1;
    }

    size_t count_times = 0;

    for(size_t i = 0; i < length; ++i)
    {
        if(value == array[i])
        {
            count_times++;
        }
    }

    return count_times;
}
