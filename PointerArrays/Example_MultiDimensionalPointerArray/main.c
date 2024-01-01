#include <stdio.h>
#include <stdlib.h>     //For malloc() and free()

int* createArray(unsigned int length, int value)    //Function to create an array. It returns the heap address of the memory allocated.
{
    int* array = (int*)malloc(length * sizeof(int));    //Integer pointer which points out the address on heap allocated with malloc

    if(array == NULL)
    {
        return NULL;    //If the allocation of the heap memory wasn't successful, it should return the NULL value.
    }

    for(unsigned int i = 0; i < length; ++i)
    {
        array[i] = value;
    }

    return array;   //We are returning the memory address as value.
}

void printArray(int* array, unsigned int length)
{
    if(array == NULL)
    {
        return;
    }

    for(unsigned int i = 0; i < length; ++i)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}

int* freeArray(int* array)  //Function to free the heap memory which isn't needed anymore.
{
    if(array != NULL)
    {                   //If the array doesn't already point on an invalid address, that is NULL, then we should give it free.
        free(array);
    }

    return NULL;
}

int** createMatrix(unsigned int num_rows, unsigned int num_cols, int value)
{
    int** matrix = (int**)malloc(num_rows * sizeof(int*));  //Pointer of pointers which points on different memory on the heap.
                //Firstly we have to allocate memory on the heap for two(num_rows) pointers
    for(unsigned int i = 0; i < num_rows; ++i)
    {
        matrix[i] = createArray(num_cols, value);   //matrix[i] is nothing else than a pointer that points on another memory location on the heap.
    }

    return matrix;  //We are returning the firs memory address of the two pointers.
}

void printMatrix(int** matrix, unsigned int num_rows, unsigned int num_cols)
{
    if(matrix == NULL)
    {
        return;
    }

    for(unsigned int i = 0; i < num_rows; ++i)
    {
        /*
        for(unsigned int j = 0; j < num_cols; ++j)
        {
            printf("%d ", matrix[i][j]);
        }
        */
       printArray(matrix[i], num_cols);
    }
}

int** freeMatrix(int** matrix, unsigned int num_rows)
{
    for(unsigned int i = 0; i < num_rows; ++i)
    {
        matrix[i] = freeArray(matrix[i]);
    }

    free(matrix);
    return NULL;
}

int main(void)
{
    unsigned int length = 3;

    int* array = createArray(length, 1);

    printArray(array, length);

    array = freeArray(array);

    int** matrix = createMatrix(2, 3, 133);

    printMatrix(matrix, 2, 3);

    matrix = freeMatrix(matrix, 2);

    return 0;
}
