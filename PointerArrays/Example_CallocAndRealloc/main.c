#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //Calloc: While malloc() just allocates heap memory, calloc() allocates memory and initializes it with value 0 at the same time.
    int length = 4;
    int* arr = (int*)calloc(length, sizeof(int));
    //int* arr = (int*)malloc(length * sizeof(int));

    for(int i = 0; i < length; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //Realloc: If you need a bigger array than the initial one, you can use realloc().
    length = 6;
    arr = (int*)realloc(arr, length * sizeof(int));

    for(int i = 0; i < length; ++i)
    {
        arr[i] = i;
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;

    return 0;
}
