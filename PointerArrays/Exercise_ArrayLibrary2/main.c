/*Implement the following functions:
- bool array_equal(int32_t *array1, size_t length1, int32_t *array2, size_t length2);
    -Check if two arrays have always the same values

- void array_clamp(int32_t *array, size_t length, int32_t min_value, int32_t max_value);
    -Clamp the values of the array to the range [min_value, max_value]

- void array_reverse(int32_t *array, size_t length);
    -Reverse the values of the array inplace (do not create a new array)

- void array_fill_n(int32_t *array, size_t length, size_t n, int32_t value);
    -Fill only n entries of the array with the value

Note: Make sure that the input pointers are valid. The utils.c and utils.h files, and the assert tests
are given.
*/
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib.h"
#include "utils.h"

void test_cases();

int main()
{
    int32_t array1[] = {-3, -2, -1, 0, 1, 2, 3, 5};
    int32_t array2[] = {-3, -2, -1, 0, 1, 2, 4, 5};
    size_t length = sizeof(array1) / sizeof(array1[0]);

    printf("array_equal: %d\n", array_equal(array1, length, array2, length));

    array_clamp(array1, length, -1, 1);
    print_int32_array(array1, length);

    array_fill_n(array2, length, 5, -1337);
    print_int32_array(array2, length);

    array_reverse(array1, length);
    print_int32_array(array1, length);

    array_reverse(array1, length);
    print_int32_array(array1, length);

    test_cases(); // This should not fail

    return 0;
}

void test_cases()
{
    size_t length = 5;
    int32_t array1[] = {-2, -1, 0, 1, 2};
    int32_t array1_clamped[] = {-1, -1, 0, 1, 1};
    int32_t array1_filled[] = {-3, -3, 0, 1, 1};
    int32_t array1_rev[] = {1, 1, 0, -1, -1};

    array_clamp(array1, length, -1, 1);
    assert(ranges_are_same(array1, array1_clamped, length) == true);

    array_fill_n(array1, length, 2, -3);
    assert(ranges_are_same(array1, array1_filled, length) == true);

    array_reverse(array1, length);
    assert(ranges_are_same(array1, array1_rev, length) == false);
}
