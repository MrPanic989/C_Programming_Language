/*Tasks of the programming exercise:
- Create a function called “binom”
- Pass the two variables int a and int b via call by value
- Pass the variable c via call by reference
- The function is intended to calculate the first binomial formula: (a+b)^2
- The result should be written in c
*/
#include <stdio.h>

#include "lib.h"

int main(void)
{
    int32_t variable1 = 0;
    int32_t variable2 = 0;
    int32_t variable3 = 0;

    getNumbers(&variable1, &variable2);

    printf("The result of binomial formula for the two numbers %d and %d is:\n", variable1, variable2);

    binom(variable1, variable2, &variable3);
    printf("(a + b)^2 = a^2 + 2ab + b^2 = %d\n", variable3);

    return 0;
}
