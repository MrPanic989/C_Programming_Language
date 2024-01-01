#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "lib.h"

void iota(int32_t* array, size_t length, int32_t start_value)
{
    if(array == NULL)
    {
        return;
    }

    for(size_t i = 0; i < length; ++i)
    {
        array[i] = start_value;
        ++start_value;
    }
}

int32_t* inclusive_scan(int32_t* array, size_t length)
{
    if(array == NULL)
    {
        return NULL;
    }

    int32_t* new_array = (int32_t*)malloc(length * sizeof(int32_t));

    if(new_array == NULL)
    {
        return NULL;
    }

    int32_t sum_up = 0;

    for(size_t i = 0; i < length; ++i)
    {
        sum_up += array[i];

        if(i == 0)
        {
            new_array[i] = array[i];
            continue;
        }

        new_array[i] = sum_up;
    }

    return new_array;
}
