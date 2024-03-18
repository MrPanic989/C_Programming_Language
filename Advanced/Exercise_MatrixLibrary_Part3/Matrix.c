#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <float.h>

#include "Matrix.h"
#include "Vector.h"

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

bool matrixMultiplyPossible(const Matrix* matrix1, const Matrix* matrix2)
{
    return (matrix1->num_cols == matrix2->num_rows); //(M, N) * (N, P) => (M, P)matrix
}

Matrix* addMatrix(const Matrix* matrix1, const Matrix* matrix2)
{
    if(matrix1 == NULL || matrix2 == NULL || !matrixSameSize(matrix1, matrix2))
    {
        return NULL;
    }

    Matrix* result = createMatrix(matrix1->num_rows, matrix1->num_cols, 0.0f);

    if(result == NULL)
    {
        return NULL;
    }

    for(size_t i = 0; i < matrix1->num_rows; ++i)
    {
        for(size_t j = 0; j < matrix1->num_cols; ++j)
        {
            const size_t idx = matrixIndex(matrix1->num_cols, i, j);

            result->data[idx] = matrix1->data[idx] + matrix2->data[idx];
        }
    }

    return result;
}

Matrix* subMatrix(const Matrix* matrix1, const Matrix* matrix2)
{
    if(matrix1 == NULL || matrix2 == NULL || !matrixSameSize(matrix1, matrix2))
    {
        return NULL;
    }

    Matrix* result = createMatrix(matrix1->num_rows, matrix1->num_cols, 0.0f);

    if(result == NULL)
    {
        return NULL;
    }

    for(size_t i = 0; i < matrix1->num_rows; ++i)
    {
        for(size_t j = 0; j < matrix1->num_cols; ++j)
        {
            const size_t idx = matrixIndex(matrix1->num_cols, i, j);

            result->data[idx] = matrix1->data[idx] - matrix2->data[idx];
        }
    }

    return result;
}

Matrix* multiplyMatrix(const Matrix* matrix1, const Matrix* matrix2)
{
    if(matrix1 == NULL || matrix2 == NULL || !matrixMultiplyPossible(matrix1, matrix2))
    {
        return NULL;
    }

    Matrix* result = createMatrix(matrix1->num_rows, matrix2->num_cols, 0.0f);

    if(result == NULL)
    {
        return NULL;
    }

    for(size_t i = 0; i < matrix1->num_rows; ++i)
    {
        for(size_t j = 0; j < matrix2->num_cols; ++j)
        {
            const size_t index_ij = matrixIndex(matrix2->num_cols, i, j);
            result->data[index_ij] = 0.0f;

            for (size_t k = 0; k < matrix2->num_rows; k++)
            {
                const size_t index_ik = matrixIndex(matrix2->num_rows, i, k);
                const size_t index_kj = matrixIndex(matrix2->num_cols, k, j);

                result->data[index_ij] = result->data[index_ij] + matrix1->data[index_ik] * matrix2->data[index_kj];
            }
        }
    }

    return result;
}

Matrix* multiplyMatrixByScalar(const Matrix* matrix, const float scalar)
{
    if(matrix == NULL)
    {
        return NULL;
    }

    Matrix* result = createMatrix(matrix->num_rows, matrix->num_cols, 0.0f);

    if(result == NULL)
    {
        return NULL;
    }

    for(size_t i = 0; i < matrix->num_rows; ++i)
    {
        for(size_t j = 0; j < matrix->num_cols; ++j)
        {
            const size_t idx = matrixIndex(matrix->num_cols, i, j);

            result->data[idx] = matrix->data[idx] * scalar;
        }
    }

    return result;
}

Matrix* divideMatrixByScalar(const Matrix* matrix, const float scalar)
{
    if(matrix == NULL || scalar == 0.0f)    //division by zero is forbidden
    {
        return NULL;
    }

    Matrix* result = createMatrix(matrix->num_rows, matrix->num_cols, 0.0f);

    if(result == NULL)
    {
        return NULL;
    }

    for(size_t i = 0; i < matrix->num_rows; ++i)
    {
        for(size_t j = 0; j < matrix->num_cols; ++j)
        {
            const size_t idx = matrixIndex(matrix->num_cols, i, j);

            result->data[idx] = matrix->data[idx] / scalar;
        }
    }

    return result;
}

Vector* minMatrix(const Matrix* matrix, const Axis axis)
{
    if(matrix == NULL)
    {
        return NULL;
    }

    switch (axis)
    {
        case AXIS_0:
        {
            Vector* result = createVector(matrix->num_cols, 0.0f);

            for(size_t j = 0; j < matrix->num_cols; j++)
            {
                float current_min = FLT_MAX;

                for(size_t i = 0; i < matrix->num_rows; i++)
                {
                    const size_t idx = matrixIndex(matrix->num_cols, i, j);

                    if(matrix->data[idx] < current_min)
                    {
                        current_min = matrix->data[idx];
                    }
                }

                result->data[j] = current_min;
            }

            return result;
        }
        case AXIS_1:
        {
            Vector* result = createVector(matrix->num_rows, 0.0f);

            for(size_t i = 0; i < matrix->num_rows; i++)
            {
                float current_min = FLT_MAX;

                for(size_t j = 0; j < matrix->num_cols; j++)
                {
                    const size_t idx = matrixIndex(matrix->num_cols, i, j);

                    if(matrix->data[idx] < current_min)
                    {
                        current_min = matrix->data[idx];
                    }
                }

                result->data[i] = current_min;
            }

            return result;
        }
        default:
        {
            return NULL;
        }
    }

}

Vector* maxMatrix(const Matrix* matrix, const Axis axis)
{
    if(matrix == NULL)
    {
        return NULL;
    }

    switch (axis)
    {
        case AXIS_0:
        {
            Vector* result = createVector(matrix->num_cols, 0.0f);

            for(size_t j = 0; j < matrix->num_cols; j++)
            {
                float current_max = FLT_MIN;

                for(size_t i = 0; i < matrix->num_rows; i++)
                {
                    const size_t idx = matrixIndex(matrix->num_cols, i, j);

                    if(matrix->data[idx] > current_max)
                    {
                        current_max = matrix->data[idx];
                    }
                }

                result->data[j] = current_max;
            }

            return result;
        }
        case AXIS_1:
        {
            Vector* result = createVector(matrix->num_rows, 0.0f);

            for(size_t i = 0; i < matrix->num_rows; i++)
            {
                float current_max = FLT_MIN;

                for(size_t j = 0; j < matrix->num_cols; j++)
                {
                    const size_t idx = matrixIndex(matrix->num_cols, i, j);

                    if(matrix->data[idx] > current_max)
                    {
                        current_max = matrix->data[idx];
                    }
                }

                result->data[i] = current_max;
            }

            return result;
        }
        default:
        {
            return NULL;
        }
    }
}

Vector* meanMatrix(const Matrix* matrix, const Axis axis)
{
    if(matrix == NULL)
    {
        return NULL;
    }

    switch (axis)
    {
        case AXIS_0:
        {
            Vector* result = createVector(matrix->num_cols, 0.0f);

            for(size_t j = 0; j < matrix->num_cols; j++)
            {
                float sum = 0.0f;

                for(size_t i = 0; i < matrix->num_rows; i++)
                {
                    const size_t idx = matrixIndex(matrix->num_cols, i, j);

                    sum += matrix->data[idx];
                }

                result->data[j] = sum / (float)matrix->num_rows;
            }

            return result;
        }
        case AXIS_1:
        {
            Vector* result = createVector(matrix->num_rows, 0.0f);

            for(size_t i = 0; i < matrix->num_rows; i++)
            {
                float sum = 0.0f;

                for(size_t j = 0; j < matrix->num_cols; j++)
                {
                    const size_t idx = matrixIndex(matrix->num_cols, i, j);

                    sum += matrix->data[idx];
                }

                result->data[i] = sum / (float)matrix->num_cols;
            }

            return result;
        }
        default:
        {
            return NULL;
        }
    }
}
