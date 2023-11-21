/*The functions should be implemented in Lib.h/Lib.c.
- Program a function that returns the minimum of two integers
- Program a function that returns the maximum of two integers
- Program a function that returns the average of two integer numbers

For example, if the numbers 12 and 8 are entered, the following output can come out:

Pls enter an interger number!
12
Pls enter an interger number!
8
Max{12, 8} = 12
Min{12, 8} = 8
Mean[12, 8] = 10,000000
*/
#include <stdio.h>
#include <stdint.h>
#include "Lib.h"

int main(void)
{
    int32_t firstNumber = 0;
    int32_t secondNumber = 0;

    printf("Please enter the first of the two integer number you want to compare: ");
    scanf("%d", &firstNumber);
    printf("Please enter the second of the two integer number you want to compare: ");
    scanf("%d", &secondNumber);

    printf("The larger number between %d and %d is: %d!\n", firstNumber, secondNumber, largerOfTwoNumbers(firstNumber, secondNumber));
    printf("The smaller number between %d and %d is: %d!\n", firstNumber, secondNumber, smallerOfTwoNumbers(firstNumber, secondNumber));
    printf("The larger number between %d and %d is: %f!\n", firstNumber, secondNumber, averageOfTwoNumbers(firstNumber, secondNumber));

    return 0;
}
