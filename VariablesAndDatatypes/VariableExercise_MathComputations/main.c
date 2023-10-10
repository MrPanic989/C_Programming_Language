/*In this exercise, you have to use the datatype float for certain computations.

Implement the following time computations:
- For x = -2, y = -3
    z1 = x^2 + y^2 - (x * y) + 2
- For x = -2, y = -3
    z2 = (x - y)^3 - 3
- For x = -2, y = -3
    z3 = (2 * x^3 - x^2 * 1/2 - x + 4) / y
*/
#include <stdio.h>
//#include <math.h>    necessary if we want to use 'to the power of' function.
// One could use this library for certain math operations. For example, one could use the
// fuction pow(x, 3), which is more convenient way, instead of using x * x * x.
// But the pow() function is of the type double, and for our task we should use float datatype.

float first_computation(float i, float j)
{
    float result = (i * i) + (j * j) - (i * j) + 2.0F;

    return result;
}

float second_computation(float k, float l)
{
    float result = (k - l) * (k - l) * (k - l) - 3.0F;

    return result;
}

float third_computation(float m, float n)
{
    float numerator = 2.0f * (m * m * m) - ((m * m) / 2) - m + 4.0f;
    float result = numerator / n;

    return result;
}

int main()
{
    float x = 0.0F, y = 0.0F, z1 = 0.0F, z2 = 0.0F, z3 = 0.0F;

    printf("Please enter the value of the variable x: ");
    scanf("%f", &x);
    printf("Please enter the value of the variable y: ");
    scanf("%f", &y);

    z1 = first_computation(x, y);
    printf("The result of the first task is: %f\n", z1);

    z2 = second_computation(x, y);
    printf("The result of the second task is: %f\n", z2);

    z3 = third_computation(x, y);
    printf("The result of the third task is: %f\n", z3);

    return 0;
}
