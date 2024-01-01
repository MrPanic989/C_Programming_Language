/*Implement the following functions:
- void iota(int32_t *array, size_t length, int32_t start_value);
    -Set the elements of an array with incrementing numbers, starting at start_value
     E.g. length = 4, start_value = 1 => [1, 2, 3, 4]
     E.g. length = 6, start_value = -2 => [-2, -1, 0, 1, 2, 3]

- int32_t *inclusive_scan(int32_t *array, size_t length);
    -Sum up all elements in the array for index n from index 0 to n
     Store the result in a result array at index n
     Example:
     [1, 2, 3] => [1, 3, 6]
     [3, 4, 5] => [3, 7, 12]

Note: Make sure that the input pointers are valid. Files utils.c and utils.h are given.
*/
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib.h"
#include "utils.h"

int main()
{
    int32_t array[8] = {0};
    size_t length = 8;

    iota(array, length, 0);
    print_int32_array(array, length);

    int32_t* inc_scan_values = inclusive_scan(array, length);
    printf("inclusive_scan: \n");
    print_int32_array(inc_scan_values, length);

    free(inc_scan_values);
    inc_scan_values = NULL;

    return 0;
}
