#include <stdint.h>
#include "Lib.h"

int32_t largerOfTwoNumbers(int32_t number1, int32_t number2)
{
    if(number1 > number2)
    {
        return number1;
    }

    return number2;
}

int32_t smallerOfTwoNumbers(int32_t number1, int32_t number2)
{
    if(number1 > number2)
    {
        return number2;
    }

    return number1;
}

float averageOfTwoNumbers(int32_t number1, int32_t number2)
{
    float result = (((float)number1 + (float)number2) / 2);

    return result;
}
