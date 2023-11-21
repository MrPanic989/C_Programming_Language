#include <stdio.h>
#include "Lib.h"        //This is how you include a self-written "library"

int main(void)
{
    int user_number = getNumberFromUser();

    printf("The user's number is %d!\n", user_number);

    return 0;
}
