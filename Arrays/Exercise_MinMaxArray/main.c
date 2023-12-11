/*Tasks of the programming exercise:
- Create a function that calculates the minimum of an integer array and returns it
- Create a function that calculates the maximum of an integer array and returns it

Example
This means that for an array with the values [1,2,3] the following output comes out:
Min: 1
Max: 3
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "lib.h"

int main(void)
{
    uint32_t length = 0u;
    int minNumber = 99999;
    int maxNumber = 1;

    do
    {
        printf("Please enter the size of the array from 1 to 10: ");
        scanf("%u", &length);

        if((length >= 1u) && (length <= 10u))
        {
            break;
        }
        else
        {
            printf("Try again.\n");
            continue;
        }
    } while (true);

    int vector[length];

    fill_up_array(vector, length);

    print_out_array(vector, length);

    find_minimum(vector, length, &minNumber);
    printf("The smallest number of this array is: %d\n", minNumber);

    find_maximum(vector, length, &maxNumber);
    printf("The largest number of this array is: %d\n", maxNumber);

    return 0;
}
