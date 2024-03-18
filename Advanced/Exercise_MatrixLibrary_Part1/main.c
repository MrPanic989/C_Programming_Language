/*Create a matrix struct with the following properties:
- float pointer to 1d heap array
- number of rows
- number of cols

Implement the following functions for a matrix library:
- Matrix *createMatrix(const size_t num_rows, const size_t num_cols, const float value);
    -The matrix (which has 2d indices (i, j)) should be stored as a 1D array on the heap

- Matrix *freeMatrix(Matrix *matrix);
    -Free the allocated heap memory

- size_t matrixIndex(const size_t num_cols, const size_t i, const size_t j);
    -Return the 1D-array index for the index (i, j)
    -Note: I talked about this use case in the main course

- size_t matrixNumElements(const Matrix *matrix);
    -Return the number of elements of the array

- bool matrixSameSize(const Matrix *matrix1, const Matrix *matrix2);
    -Return true if two arrays have the same sizes

- void printMatrix(const Matrix *matrix);
    -Pretty print the matrix elements to the console
*/
#include <stdio.h>

#include "Matrix.h"

int main(void)
{
    Matrix* m1 = createMatrix(3, 3, -1.0f);
    Matrix* m2 = createMatrix(3, 3, +1.0f);
    printMatrix(m1);
    printMatrix(m2);

    freeMatrix(m1);
    freeMatrix(m2);

    return 0;
}
