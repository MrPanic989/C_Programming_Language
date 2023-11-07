/*Circle Example:
- Read the value for r from the user. chek if the input is correct (non-negative length)
- Compute the perimeter and area of the circle
- Print the computed values to the console
*/
#include <stdio.h>
#include <math.h> //We use this library for the power function. All functions in this library are defined as 'double'.

#define PI 3.14159      //One can use the M_PI from math.h but it is undefined in C/C++(20)

int main(void)
{
    double radius = 0.0;        //0.0f would be the sign for float and just 0.0 represent the type double.
    double perimeter = 0.0;
    double area = 0.0;

    printf("Please enter the radius of the circle which you want to calculate: ");
    scanf("%lf", &radius);

    while (radius < 0.0)
    {
        printf("The value %lf is invalid. The radius has to be positive. Please enter a valid value: ", radius);
        scanf("%lf", &radius);
    }

    printf("Thank you! I will now calculate the perimeter and area of the circle based on this radius.\n");

    perimeter = 2.0 * PI * radius;

    area = PI * pow(radius, 2.0);

    printf("Based on the radius, this circle has a perimeter of %.2lf and an area of %.2lf!\n", perimeter, area);

    return 0;
}
