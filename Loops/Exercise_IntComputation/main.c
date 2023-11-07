/*In this exercise, you have to use an int datatype for certain computations.

Implement the following logic:
- Number of decimal digits
        E.g. 128 = 3 Digits
- Cross Sum
    Add up all decimal digits
    E.g. 123 = 6, 1234 = 10
*/
#include <stdio.h>

int main(void)
{
    unsigned int input = 0u;
    unsigned int num_digits = 0u;
    unsigned int cross_sum = 0u;
    unsigned int temp = 0u;

    printf("Please enter any positive number you wish to calculate: ");
    scanf("%u", &input);

    temp = input;   //We declared and initialized the variable 'temp' just to preserve the initial 'input'.
    do     //So we are using here the 'do-while' loop because we want definitely to enter the loop at least once.
    {
        cross_sum = cross_sum + (temp % 10);    //The sum is calculated by adding the remainder of the modulo operation to
                                                //the sum in the loop: e.g. 128 % 10 = 8 --> cross_sum = 0 + 8;
        temp = temp / 10u;                      // temp = 128 / 10, which is the new temp = 12 --> cross_sum = 8 + (12 % 10) = 8 + 2 = 10
        num_digits++;                           //temp = 12 / 10, which is the new temp = 1 (because it's an int type)--> cross_sum = 10 + (12 % 10) = 10 + 1 = 11
        //And everytime we increase                 //temp = 1 / 10 = 0 and now we are breaking the loop because the condition isn't given anymore
        //num_digits by 1 when we divide with 10.
    } while (temp != 0u);

    printf("Your input is a number with %u digits!\n", num_digits);

    printf("The cross sum of your input %u is %u!\n", input, cross_sum);

    return 0;
}
