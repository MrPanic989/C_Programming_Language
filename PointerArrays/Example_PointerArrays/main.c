#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int length = 3;
    /*Array sizes can also be set using variables,
    but then initialization can no longer be done using a set bracket!
    int array[length] = {0};    is invalid
    To overcome this issue, we can allocate memory on the heap!
    */

   //Integer pointer 'array' is still on the stack, while malloc() returns the memory address on the heap memory.
    int* array = (int*)malloc(length * sizeof(int));    //We are allocating 12 bytes ( 3 * 4byte)

    for(int i = 0; i < length; ++i)
    {
        array[i] = i;
    }

    //....

    for(int i = 0; i < length; ++i)
    {
        printf("%d\n", array[i]);
    }

    free(array);    //With the free() function, we free up memory on the heap
    array = NULL;   //Just to be 100 percent sure, our array has the value NULL at the end.

    return 0;
}
