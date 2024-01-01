/*In this exercise we will "compute" a transpose matrix.
This is just another example of what you can use 2d arrays for.

Program a function that returns an transposed matrix (2d array) of an input matrix (2d array).

Matrix M:
[[0, 1, 2],
[0, 2, 4]]

Matrix M_Transposed:
[[0, 0],
[1, 2],
[2, 4]]
*/
#include <stdio.h>
#include <stdlib.h>

int* createArray(unsigned int length, int value)
{
    int* array = (int*)malloc(length * sizeof(int));

    if(array == NULL)
    {
        return NULL;
    }

    for(unsigned int i = 0; i < length; ++i)
    {
        array[i] = value;
    }

    return array;
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

int* freeArray(int* array)
{
    if(array != NULL)
    {
        free(array);
    }

    return NULL;
}

int** createMatrix(unsigned int num_row, unsigned int num_col, int value)
{
    int** matrix = (int**)malloc(num_row * sizeof(int*));

    if(matrix == NULL)
    {
        return NULL;
    }

    for(unsigned int i = 0; i < num_row; ++i)
    {
        matrix[i] = createArray(num_col, value);
    }

    return matrix;
}

void fillUpMatrix(int** matrix, unsigned int num_row, unsigned int num_col)
{
    for(unsigned int i = 0; i < num_row; ++i)
    {
        for(unsigned int j = 0; j < num_col; ++j)
        {
            matrix[i][j] = (i + 1u) * j;
        }
    }

}

void printMatrix(int** matrix, unsigned int num_row, unsigned int num_col)
{
    if(matrix == NULL)
    {
        return;
    }

    for(unsigned int i = 0; i < num_row; ++i)
    {
        printArray(matrix[i], num_col);
    }

    printf("\n");
}

int** freeMatrix(int** matrix, unsigned int num_row)
{
    if(matrix != NULL)
    {
        for(unsigned int i = 0; i < num_row; ++i)
        {
            matrix[i] = freeArray(matrix[i]);
        }
    }

    free(matrix);
    return NULL;
}

int** transposeMatrix(int** matrix, unsigned int num_row, unsigned int num_col)
{
    /*
    int** matrix_T = (int**)malloc(num_col * sizeof(int*));
    int value = 1;

    if(matrix_T == NULL)
    {
        return NULL;
    }
    */

   int value = 1;
   int** matrix_T = createMatrix(num_col, num_row, value);

    for(unsigned int i = 0; i < num_row; ++i)
    {
        //matrix_T[i] = createArray(num_row, value);
        for(unsigned int j = 0; j < num_col; ++j)
        {
            matrix_T[j][i] = matrix[i][j];
        }
    }

    return matrix_T;
}

int main(void)
{
    unsigned int num_row = 2;
    unsigned int num_col = 3;

    int** matrix = createMatrix(num_row, num_col, 1);
    printMatrix(matrix, num_row, num_col);

    fillUpMatrix(matrix, num_row, num_col);
    printMatrix(matrix, num_row, num_col);

    int** matrix_transpose = transposeMatrix(matrix, num_row, num_col);
    printMatrix(matrix_transpose, num_col, num_row);

    matrix = freeMatrix(matrix, num_row);
    matrix_transpose = freeMatrix(matrix_transpose, num_col);

    return 0;
}
