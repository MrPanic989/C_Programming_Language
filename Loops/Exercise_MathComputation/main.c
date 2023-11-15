/*In this exercise, you have to use the datatypes **double** and **int** for certain computations.

## Calculate Pi

With the following formula, you can compute $\frac{\pi}{4}$.
Implement the formula in the function with $n$ = **num_iterations**.
Use a for-loop to sum up the values.

$x = \frac{\pi}{4} = \sum_{k=0}^$n$ \frac{1}{(4k + 1)} - \frac{1}{(4k + 3)}$

At the end multiply by 4 before you return the value.
So the returned value will be an approximation of $\pi$ and not $\frac{\pi}{4}$.

Implement this formula with a user-defined number of iterations.

## Decimal to Binary

Implement the logic that prints out the binary representation of a positive decimal number.

E.g. the decimal number 142 would be 10001110 in binary.

If you do not know how the binary system works, refer to the Wikipedia [link](https://en.wikipedia.org/wiki/Binary_number).
Since this knowledge is not only important for this exercise but in general for a programmer.
*/
#include <stdio.h>
#include <math.h>       //For the pow() function

int main(void)
{
    double pi_approximation = 0.0;
    double value_per_loop = 0.0;
    double denominator1 = 0.0;
    double denominator2 = 0.0;
    int number_iterations = 0;

    double pi = 3.14159265358979323846;

    printf("Please enter the number of loops you want to iterate: ");
    scanf("%d", &number_iterations);

    for(int i = 0; i < number_iterations; i++)
    {
        denominator1 = (4 * i) + 1;
        denominator2 = (4 * i) + 3;
        printf("Denominator 1: %lf. Denominator 2: %lf\n", denominator1, denominator2);
        value_per_loop = (1 / denominator1) - (1 / denominator2);

        pi_approximation = pi_approximation + value_per_loop;
        printf("PI in this loop: %.15lf\n", pi_approximation);  //.15 because the data type double can represent 17 characters in total, that is leading number, the ., and 15 afuterwards.
    }

    pi_approximation = 4 * pi_approximation;

    printf("The approximation of PI in this case is: %.15lf\n", pi_approximation);
    printf("The correct value of PI is: %.15lf\n\n", pi);

    //Decimal to binary

    int decimal_number = 0;

    printf("Please enter a number you want to convert to binary representation: ");
    scanf("%d", &decimal_number);

    while (decimal_number < 0)
    {
        printf("The number has to be posotive! Please enter a valid number: ");
        scanf("%d", &decimal_number);
    }

    printf("The decimal number %d has the following binary representation: ", decimal_number);

    for(int i = 15; i >= 0; i--)        //with 0 to 15 spaces we cover the binary representation of 2 bytes
    {
        int binary_value = (int)pow(2, i);
        /*Firstly in each iteration we have to calculate the first, or the outside left binary value: 2 to the power of 15 = 32768.
          Is it greater than the decimal number, which is our input? Let's say, our input is 23466. So, is 23466 < 32768? Yes, so we print '0' out.
          Next iteration: 2 to the power of 14 = 16384. Is it greater than our input 23466? No, that means 16384 is "included" in our input 23466.
          We print out '1' and have to reduce the input by that value.
          And so on until the condition for the loop is not given anymore.
        */

        if(decimal_number < binary_value)
        {
            printf("0 ");
        }
        else
        {
            printf("1 ");
            decimal_number -= binary_value;
        }
    }

    printf("\n");

    return 0;
}
