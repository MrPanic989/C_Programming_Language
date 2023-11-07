/*
1. Read the values for a, b from user
2. Compute the perimeter and area of the rectangle
3. Print the computed values to the console
*/
#include <stdio.h>

int main(void)
{
    float side_a = 0.0F;
    float side_b = 0.0F;
    float perimeter = 0.0F;
    float area = 0.0F;

    printf("Please enter the size of side a: ");
    scanf("%f", &side_a);

    printf("\nNow enter the size of side b, please: ");
    scanf("%f", &side_b);

    perimeter = 2 * (side_a + side_b);
    printf("\nThe perimeter of the rectangle that you have constructed is %.2f\n", perimeter);

    area = side_a * side_b;
    printf("\nThe area of the rectangle you have constructed is %.2f\n", area);

    return 0;
}
