/*
- Write an if-else query to check whether an integer is divisible by 3.
- Output a console output for both cases.
- Also output the resulting remainder of the modulo operation.
*/
#include <stdio.h>

int number_mod_three(int value)
{
    int check = value % 3;          //We habe defined the function 'number_mod_three()' to be able to give the
                                    //true result back. If we deal with positive numbers, fine. But if we want to
    if (check < 0)                  //deal with negative numbers, the C compiler just returns a negative remainder of
    {                               //of its positive number. For example: -2 % 3 is 1, but the compiler returns
        check = check + 3;          //the remainder -2, like it is in 2 % 3 = 2. For general purpose, this function should
    }                               //look like this: int number_mod(int value, int mod){
                                    //                int check = value % mod;
    return check;                   //                if(check < 0){
}                                   //                check = (mod < 0) ? check - mod : check + mod;
                                    //                }
int main(void)                          //  	          return check; }
{
    int number = 0;

    printf("Please enter the number you want to check: ");
    scanf("%d", &number);

    int remainder = number_mod_three(number);
    /*
    if (remainder == 1)
    {
        printf("The number %d is not divisible by 3!\n", number);
        printf("The remainder of the modulo operation is %d!\n", remainder);
    }
    else if (remainder == 2)
    {
        printf("The number %d is not divisible by 3!\n", number);
        printf("The remainder of the modulo operation is %d!\n", remainder);
    } */
    if (remainder != 0)
    {
        printf("The number %d is not divisible by 3!\n", number);
        printf("The remainder of the modulo operation is %d!\n", remainder);
    }
    else
    {
        printf("The number %d you have entered is divisible by 3!\n", number);
    }

    return 0;
}
