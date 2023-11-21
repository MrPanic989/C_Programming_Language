//The 'Lib.c' is used for definition of our functions.

#include <stdio.h>
#include "Lib.h"    //We have to include the header file which builds a pair with this file.

int getNumberFromUser()
{
    int number_from_user;

    printf("Please enter an integer number: ");
    scanf("%d", &number_from_user);


    return number_from_user;
}
