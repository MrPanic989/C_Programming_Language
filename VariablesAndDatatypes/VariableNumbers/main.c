#include <stdio.h>

int main()
{
    //Declaration + initialization
    int firstNumber = 0;          //If we exactly know that our values cannot be negative, than we should
    int secondNumber = 0;         //use the type 'unsigned int' (values from 0 to ~ 4*10^9). E.g. unsigned int my_age = 32U;
    int total = 0;          //int (values from -2*10^8 to 2*10^9) - 32bit or 4 Byte

    float my_balance1 = 1750.23F;    //floating point number. 32bit or 4 Byte
    float new_deposit = 0.0F;

    //double my_balance2 = 1750.23;   //double floating point number. 64bit / 8 Byte (%lf)

    printf("Please enter your first number: ");
    scanf("%d", &firstNumber);
    printf("Your number is: %d\n", firstNumber);

    printf("Please enter your second number: ");
    scanf("%d", &secondNumber);
    printf("Your number is: %d\n", secondNumber);

    total = firstNumber + secondNumber;
    printf("The sum in total is: %d\n", total);

    printf("Please enter the new deposit: ");
    scanf("%f", &new_deposit);
    my_balance1 = my_balance1 + new_deposit;      //On this line we are overwriting the variable my_balance1
    printf("Your new balance is: %.2f\n", my_balance1); //With the command '%.2f', we are limiting the floating number to .2 digits

    //my_balance1 = my_balance1 + new_deposit;      equivalent      to my_balance1 += new_deposit;

    return 0;
}
