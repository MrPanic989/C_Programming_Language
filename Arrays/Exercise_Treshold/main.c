/*The task of this exercise is to look up the array for a threshold and count values that are below
and also count up values that are above that margin.
*/
#include <stdio.h>
#include <stdint.h>

void count_threshold_elements(float array[], uint32_t length, float threshold, uint32_t* num_below, uint32_t* num_above);
void fill_up_array(float array[], uint32_t size);

int main(void)
{
    float threshold = 0.0f;
    uint32_t num_below = 0u;
    uint32_t num_above = 0u;
    uint32_t length = 0u;

    printf("How large should this array be? ");
    scanf("%u", &length);

    float vec[length];

    fill_up_array(vec, length);

    printf("The values in the array are: ");
    for(uint32_t i = 0; i < length; i++)
    {
        printf("%f ", vec[i]);
    }
    printf("\n");

    printf("Pleas enter now a value that shoul use as a margin: ");
    scanf("%f", &threshold);

    count_threshold_elements(vec, length, threshold, &num_below, &num_above );

    printf("There are %u number(s) that are below that margin and %u number(s) that are above!\n", num_below, num_above);

    return 0;
}

void fill_up_array(float array[], uint32_t size)    //This function will 'randomly' fill up the array.
{
    float value = 1.23f;
     for(uint32_t i = 0u; i < size; i++)
    {
        if( i % 2 == 0)
        {
            value = value * value * 1.3f;
        }
        else
        {
            value = value / 1.4f;
        }
        array[i] = value;
    }
}

void count_threshold_elements(float array[], uint32_t length, float threshold, uint32_t* num_below, uint32_t* num_above)
{
    if(length == 0)
    {
        return;
    }

    for(uint32_t i = 0; i < length; i++)
    {
        if(array[i] < threshold)
        {
            (*num_below)++;
        }
        else if(array[i] > threshold)
        {
            (*num_above)++;
        }
    }
}
