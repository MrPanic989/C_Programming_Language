#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

bool array_equal(int32_t *array1, size_t length1, int32_t *array2, size_t length2)
{
    if((array1 == NULL) || (array2 == NULL))
    {
        return false;
    }

    if(length1 != length2)
    {
        return false;
    }

    for(size_t i = 0; i < length1; ++i)
    {
        if(array1[i] != array2[i])
        {
            return false;
        }
    }

    return true;

}

void array_clamp(int32_t *array, size_t length, int32_t min_value, int32_t max_value)
{
    if(array == NULL)
    {
        return;
    }

    /*This would be the approach if we wanted to completely change the array.
    size_t new_length = 0;

    for(size_t i = 0; i < length; ++i)
    {
        if(array[i] >= min_value && array[i] <= max_value)
        {
            ++new_length;
        }
    }

    int32_t* new_array = (int32_t*)malloc(new_length * sizeof(int32_t));

    if(new_array == NULL)
    {
        return;
    }

    size_t j = 0;

    for(size_t i = 0; i < new_length; ++i)
    {
        for(; j < length; ++j)
        {
            if(array[j] >= min_value && array[j] <= max_value)
            {
                new_array[i] = array[j];
                break;
            }
        }
        ++j;

        printf("%d ", new_array[i]);
    }

    memcpy(array, new_array, new_length);
    */

   for(size_t i = 0; i < length; ++i)
   {
        if(array[i] < min_value)
        {
            array[i] = min_value;
        }
        else if(array[i] > max_value)
        {
            array[i] = max_value;
        }
   }
}

void array_reverse(int32_t *array, size_t length)
{
    if(array == NULL)
    {
        return;
    }

    size_t j = length - 1;

    for(size_t i = 0; i <= (length / 2); ++i)
    {
        for(; j >= (length / 2);)
        {
            int32_t temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            break;
        }
        --j;
    }
    /*
    size_t half = length / 2;

    for (size_t i = 0; i < half; i++)
    {
        size_t offset_idx = length - i - 1;
        int32_t temp = array[i];

        array[i] = array[offset_idx];
        array[offset_idx] = temp;
    }
    */
}

void array_fill_n(int32_t *array, size_t length, size_t n, int32_t value)
{
    if(array == NULL)
    {
        return;
    }

    if(length < n)
    {
        n = length;
    }

    for(size_t i = 0; i < n; ++i)
    {
        array[i] = value;
    }
}
