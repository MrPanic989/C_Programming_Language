#include <stdio.h>

int main(void)
{
    int value1 = 0;
    int value2 = 0;

    printf("Please enter the two nambers you want to calculate the remainder for: ");
    scanf("%d%d", &value1, &value2);
    //printf("\n%d %d", value1, value2);

    int modulo = value1 % value2;   //The '%' is in this context the modulo operator. It calculates integer types and represent
                                    //the remainder from a division of two whole numbers.

    int sub = value1 / value2;                  //This two calculations are running in the background when we
    int remainder = value1 - (value2 * sub);    //calculate the modulo, well remainder.
    printf("The result is: %d mod %d = %d\n", value1, value2, remainder);

    printf("The result is: %d mod %d = %d\n", value1, value2, modulo);

    return 0;
}
