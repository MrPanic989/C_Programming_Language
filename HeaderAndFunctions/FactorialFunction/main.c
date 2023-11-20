#include <stdio.h>
#include <stdint.h>     //This library is for the pre-defined integer.

uint64_t factorial(uint64_t n);
/*It is of great importantce for the compiler to know that there is a factorial() function
before you call that function up in the main(). So you have to declare that function beforehand.
You can also write the whole function before the main() function instead. Either way, it has to be clear for
the compiler that such a function exists.
*/

int main(void)
{
    uint64_t number = 0UL;              //uint64 is a clear choice, because factorial computations get really large very quick.
    uint64_t result_factorial = 0UL;

    unsigned char decision = 'X';

    do
    {
        printf("Please enter an integer number between 1 and 20: ");
        scanf("%lu", &number);

        if((number >= 1UL) && (number <= 20UL))         //With this line we have actually limited the scope.
        {
            result_factorial = factorial(number);   //Here we are calling up the function with the entered number as attribute.

            printf("%lu! = %lu\n", number, result_factorial);
        }
        else
        {
            printf("The number you have entered is out of scope!\n");

        }

        printf("Do you want to try again: [Y] yes - [N] no? ");
        scanf(" %c", &decision);
        /*It is important when you deal with character datatype to leave a whitespace
        for the input like this " %c", otherwise will the address operator '&'
        take the input confirmation 'ENTER' as a character from the ASCII Table, and from our logic
        if the input is not 'Y' or 'y', it will break the loop and end the program.
        */

        if((decision == 'Y') || (decision == 'y'))
        {
            continue;
        }
        else
        {
            break;
        }

    } while(1);

    return 0;
}

uint64_t factorial(uint64_t n)  //It is a recursive function because it calls itself up.
{
    if(n == 1UL)        //When the value of n reaches 1, the recursive function stops to call itself up and returns 1.
    {
        return 1UL;
    }
    else
    {
        return n * factorial(n - 1UL);
    }
}
/*E.g. 5! = 5 * 4!
               = 4 * 3!
                     = 3 * 2!
                           = 2 * 1!
                                 = 1 | return
                            | 2 * 1 = 2  return
                        | 3 * 2 = 6 return
                | 4 * 6 = 24 return
        5! = 5 * 24 = 120
*/
