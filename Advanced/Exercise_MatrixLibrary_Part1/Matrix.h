#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>

typedef struct
{
    float* data;    //It is a one dimensional array, therefore float* and not float** like for 2d
    size_t num_rows;
    size_t num_cols;
} Matrix;


Matrix* createMatrix(const size_t num_rows, const size_t num_cols, const float value);
Matrix* freeMatrix(Matrix* matrix);
size_t matrixIndex(const size_t num_cols, const size_t i, const size_t j);
size_t matrixNumElements(const Matrix* matrix);
bool matrixSameSize(const Matrix* matrix1, const Matrix* matrix2);
void printMatrix(const Matrix* matrix);

#endif
