/*Implement the following functions for a matrix library:
- bool matrixMultiplyPossible(const Matrix *matrix1, const Matrix *matrix2);
    -check if the dimensions match with matrixMultiplyPossible

- Matrix *addMatrix(const Matrix *matrix1, const Matrix *matrix2);
    -Add two matrices, check if the dimensions match with matrixSameSize

- Matrix *subMatrix(const Matrix *matrix1, const Matrix *matrix2);
    -Subtract two matrices, check if the dimensions match with matrixSameSize

- Matrix *multiplyMatrix(const Matrix *matrix1, const Matrix *matrix2);
    -Multiply two matrices, check if the dimensions match with matrixMultiplyPossible

- Matrix *multiplyMatrixByScalar(const Matrix *matrix, const float scalar);
    -Multiply matrix element-wise with a scalar value

- Matrix *divideMatrixByScalar(const Matrix *matrix, const float scalar);
    -Divide matrix element-wise with a scalar value, check for division-by-zero
*/
#include <stdio.h>

#include "Matrix.h"

int main(void)
{
    Matrix* m1 = createMatrix(3, 3, -1.0f);
    Matrix* m2 = createMatrix(3, 3, +1.0f);

    Matrix* m3 = addMatrix(m1, m2);
    printMatrix(m1);
    printf("+\n");
    printMatrix(m2);
    printf("=\n");
    printMatrix(m3);

    Matrix* m4 = subMatrix(m3, m1);
    printMatrix(m3);
    printf("-\n");
    printMatrix(m1);
    printf("=\n");
    printMatrix(m4);

    Matrix* m5 = multiplyMatrix(m1, m2);
    printMatrix(m1);
    printf("*\n");
    printMatrix(m2);
    printf("=\n");
    printMatrix(m5);

    freeMatrix(m1);
    freeMatrix(m2);
    freeMatrix(m3);
    freeMatrix(m4);
    freeMatrix(m5);

    return 0;
}
