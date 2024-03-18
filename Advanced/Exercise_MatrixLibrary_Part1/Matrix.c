#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "Matrix.h"

Matrix* createMatrix(const size_t num_rows, const size_t num_cols, const float value)
{
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));   //create Matrix struct on the heap

    if(matrix == NULL)
    {
        return NULL;
    }

    float* data = (float*)malloc(num_rows * num_cols * sizeof(float));  //create the 1d array on the heap

    if(data == NULL)
    {
        free(matrix);
        return NULL;
    }

    for(size_t i = 0; i < num_cols * num_rows; ++i)
    {
        data[i] = value;
    }

    matrix->data = data;
    matrix->num_cols = num_cols;
    matrix->num_rows = num_rows;

    return matrix;
}

Matrix* freeMatrix(Matrix* matrix)
{
    if(matrix == NULL)
    {
        return NULL;
    }

    if(matrix->data != NULL)
    {
        free(matrix->data);
        matrix->data = NULL;
    }

    free(matrix);

    return NULL;
}

size_t matrixIndex(const size_t num_cols, const size_t i, const size_t j)
{
    return i * num_cols + j;
    /*calculation formula for the indices of the 1d array from 2d
            j = 0   j = 1   j = 2
    i = 0     0       1       2     =>  1d_idx = i * num_cols + j = 1 * 3 + 1 = 4
    i = 1     3       4*      5         1d: 0, 1, 2, 3, 4, 5
    */
}

size_t matrixNumElements(const Matrix* matrix)
{
    return matrix->num_cols * matrix->num_rows;
}

bool matrixSameSize(const Matrix* matrix1, const Matrix* matrix2)
{
    return ((matrix1->num_rows == matrix2->num_rows) && (matrix1->num_cols == matrix2->num_cols));
}

void printMatrix(const Matrix* matrix)
{
    for(size_t i = 0; i < matrix->num_rows; ++i)
    {
        for(size_t j = 0; j < matrix->num_cols; ++j)
        {
            const size_t idx = matrixIndex(matrix->num_cols, i , j);

            printf("%f, ", matrix->data[idx]);
        }
        printf("\n");
    }
    printf("\n");
}
