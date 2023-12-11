/*The task is to add two values at the same index of two twodimensional arrays,
or matrces mathematically, and print the results out.
*/
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    double matrix1[2][3] = {{0.0, 1.0, 2.0}, {3.0, 4.0, 5.0}};    //Matrix with 2 rows and 3 columns
    double matrix2[2][3] = {{10.0, 11.0, 12.0}, {13.0, 14.0, 15.0}};    //Matrix with 2 rows and 3 columns

    for(uint32_t i = 0; i < 2; i++)
    {
        for(uint32_t j = 0; j < 3; j++)
        {
            printf("The sum: matrix1[%u][%u] + matrix2[%u][%u] = %lf + %lf = %lf \n", i, j, i, j,
                matrix1[i][j], matrix2[i][j], matrix1[i][j] + matrix2[i][j]
            );
        }
    }

    return 0;
}
