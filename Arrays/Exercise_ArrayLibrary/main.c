/*Implement the following functions:
- void unique_elements(int32_t *array, size_t length);
    -Print out all unique elements (no duplicates) in the array

- void remove_duplicates(int32_t *array, size_t *length);
    -Remove all duplicates in the array
     By Remove I mean move the element to the end of the array and
     decrease the length of the array by one, hence the value is not used anymore

- void rotate_left(int32_t *array, size_t length);
    -Rotate all elements of the array to the left
     Rotate Left: [1, 2, 3] => [2, 3, 1]

- void rotate_right(int32_t *array, size_t length);
    -Rotate all elements of the array to the right
     Rotate Right: [1, 2, 3] => [3, 1, 2]

Note: Make sure that the input pointers are valid.
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#include "lib.h"

void test_cases();

int main()
{
    int32_t array[] = {1, 3, 3, 2, 9, 5, 4, 1, 2, 1, 1, 2, 3, 1, 2, 4, 3, 4};
    size_t length = sizeof(array) / sizeof(array[0]);

    printf("unique_elements: \n");
    unique_elements(array, length);

    remove_duplicates(array, &length);
    print_int32_array(array, length);

    sort_array(array, length);
    print_int32_array(array, length);

    rotate_left(array, length);
    print_int32_array(array, length);

    rotate_right(array, length);
    print_int32_array(array, length);

    test_cases();

    return 0;
}

void test_cases()
{
    size_t length = 6;
    int32_t array[] = {1, 1, 2, 3, 3, 4};
    int32_t array_cpy[] = {1, 1, 2, 3, 3, 4};
    int32_t array_del[] = {1, 2, 3, 4};

    rotate_left(array_cpy, length);
    assert(ranges_are_same(array, array_cpy, length) == false);
    rotate_right(array_cpy, length);
    assert(ranges_are_same(array, array_cpy, length) == true);

    remove_duplicates(array_cpy, &length);
    assert(ranges_are_same(array_cpy, array_del, length) == true);
    assert(ranges_are_same(array, array_del, length) == false);
}
