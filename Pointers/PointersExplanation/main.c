#include <stdio.h>

int main(void)
{
    int variable1 = 7123421; //The integer variable 'variable1' has for value the number 7123421.
    printf("The memory address of 'variable1' is: %p\n", &variable1); //We can find out what its address in memory is with the address operator '&'

    //pointer variable
    int* pointer1 = &variable1; //Pointer variables have for values ALWAYS memory addresses from another variable: they 'point' at another memory address.
    printf("'pointer1' value: %p\n", pointer1);
    printf("pointer1' memory address is: %p\n", &pointer1); //Pointer variables are still variables and have their own memory addresses.
    printf("'pointer1' dereferenced: %d\n", *pointer1); //What is the actual value of the variable where the pointer 'points' at.

    return 0;
}
