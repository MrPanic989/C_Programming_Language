#include <stdio.h>

int main(void)
{
    unsigned int age1 = 0u;
    unsigned int age2 = 0u;

    printf("Please enter the two number you want to compare: ");
    scanf("%u%u", &age1, &age2);

    printf("Let us see who is the older one!\n");

    //Version 1:
    unsigned int older;
    if (age1 > age2)
    {
        older = age1;
    }
    else
    {
        older = age2;
    }
    printf("%u is older!\n", older);

    //Version 2:                if    ? then : else
    unsigned int older2 = age1 > age2 ? age1 : age2;
    printf("%u is older!\n", older2);

    /*
    These two version are exactly the same. The ternary operator come handy if you want to initialize a variable
    but the value depends on some statements.
    */

    return 0;
}
