#include <stdio.h>
#include <stdint.h>

#include "lib.h"

void fill_up_array(int array[], uint32_t size)
{
    int value1 = 1;
    int value2 = 2;

    for(uint32_t i = 0; i < size; ++i)
    {
        if(i % 2 == 0)
        {
            value1 = value1 * value2;
            array[i] = value1;
        }
        else
        {
            value2 = (value1 - value2) - 2;
            array[i] = value2;
        }
    }
}

void print_out_array(int array[], uint32_t size)
{
    printf("The array looks like this: ");
    for(uint32_t i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void find_minimum(int array[], uint32_t size, int* min)
{
    for(uint32_t i = 0; i < size; ++i)
    {
        if((array[i]) < (*min))
        {
            *min = array[i];
        }
    }
}

void find_maximum(int array[], uint32_t size, int* max)
{
    for(uint32_t i = 0; i < size; ++i)
    {
        if((array[i]) > (*max))
        {
            *max = array[i];
        }
    }
}
