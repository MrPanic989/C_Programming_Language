#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include "lib.h"

void getNumbers(int32_t* input1, int32_t* input2)
{
    printf("Please enter two number for the binomial formula: ");
    scanf("%d%d", input1, input2);
}

void binom(int32_t input1, int32_t input2, int32_t* output)
{
    int32_t sum = input1 + input2;

    *output = (int32_t)pow((int32_t)sum, (int32_t)2);
}
