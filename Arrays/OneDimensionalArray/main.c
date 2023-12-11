/*The task is to read values fot the two float arrays and then sum up the values
at the same position in those arrays, e.g. value array1[0] + value array2[0], and save the
result in a third array and print those values out.
*/
#include <stdint.h>
#include <stdio.h>

#define NUMBER_OF_VECTORS 3

void get_values(float array[], uint32_t size);
void print_values(float array[], uint32_t size);

int main(void)
{           //Reserve 12bytes in memory: 3 * size of float = 3 * 4 = 12 bytes
    float vector1[NUMBER_OF_VECTORS] = {0.0f, 0.0f, 0.0f};
    float vector2[NUMBER_OF_VECTORS] = {0.0f, 0.0f, 0.0f};
    float total_sum[NUMBER_OF_VECTORS];

                    // 12bytes / size of the first element in vector1 = 12 / 4 = 3
    uint32_t size1 = sizeof(vector1) / sizeof(vector1[0]);
    printf("Let us get values for the first array!\n");
    get_values(vector1, size1);

    uint32_t size2 = sizeof(vector2) / sizeof(vector2[0]);
    printf("Let us get values for the second array!\n");
    get_values(vector2, size2);

    printf("The values of the first arrey are: \n");
    print_values(vector1, size1);

    printf("The values of the second array are: \n");
    print_values(vector2, size2);

    uint32_t sum_size = sizeof(total_sum) / sizeof(total_sum[0]);
    for(uint32_t i = 0; i < sum_size; i++)
    {
        total_sum[i] = vector1[i] + vector2[i];
    }

    printf("The total sum at each position is: \n");
    print_values(total_sum, sum_size);

    return 0;
}

void get_values(float array[], uint32_t size)
{
    for(uint32_t i = 0; i < size; i++)
    {
        printf("Value %u: ", i + 1);
        scanf("%f", &array[i]);
    }
    printf("\n");
}

void print_values(float array[], uint32_t size)
{
    for(uint32_t i = 0; i < size; i++)
    {
        printf("Value %u: %f\n", i + 1u, array[i]);
    }
    printf("\n");
}
