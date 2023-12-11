#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "lib.h"

void unique_elements(int32_t *array, size_t length)
{
    if (array == NULL)
    {
        return;
    }

    for (size_t i = 0; i < length; i++)
    {
        bool unique = true;
        int32_t current_value = array[i];

        for (size_t j = 0; j < length; j++)
        {
            if (i == j)
            {
                continue;
            }

            if (current_value == array[j])
            {
                unique = false;
            }
        }

        if (unique == true)
        {
            printf("Unique element: %d\n", current_value);
        }
    }
}

void remove_duplicates(int32_t *array, size_t *length)
{
    if(array == NULL)
    {
        return;
    }

    for(size_t i = 0; i < *length; ++i)
    {
        if(i == (*length - 1))          //If i is the last element, then determine the function
        {                               //because we cannot move on with the inner for loop.
            return;
        }
        for(size_t j = i + 1; j < *length; j++)
        {
            if(array[i] == array[j])        //If we find two identical elements, we will swap them out
            {
                for(size_t k = i; k < (*length - 1); ++k)
                {
                    int32_t swap = array[k];
                    array[k] = array[k + 1];
                    array[k + 1] = swap;
                }
                *length -= 1;   //After swaping identical elements, we have to reduce the length of the array
                j = i;
            }
        }
    }
}

void rotate_left(int32_t *array, size_t length)
{
    if(array == NULL)
    {
        return;
    }

    int32_t last = array[0];
    for(size_t i = 0; i < length; ++i)
    {
        if(i == length - 1)
        {
            array[i] = last;
            return;
        }
        int32_t swap = array[i];
        array[i] = array[i + 1];
        array[i + 1] = swap;
    }
}

void rotate_right(int32_t *array, size_t length)
{
    if(array == NULL)
    {
        return;
    }

    for(size_t i = length - 1; i > 0; --i)
    {
        int32_t swap = array[i];
        array[i] = array[i - 1];
        array[i - 1] = swap;
    }
}

void sort_array(int32_t *array, size_t length)
{
    if(array == NULL)
    {
        return;
    }

    for(size_t i = 0; i < length; ++i)
    {
        if(i == length - 1)
        {
            return;
        }
        for(size_t j = i + 1; j < length; ++j)
        {
            if(array[i] > array[j])
            {
                int32_t swap = array[i];
                array[i] = array[j];
                array[j] = swap;
            }
        }
    }
}
