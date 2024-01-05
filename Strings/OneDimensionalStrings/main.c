#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char name1[] = {'D', 'a', 'v', 'i', 'd', '\0'};
    char name2[4] = {'J', 'a', 'n', '\0'};
    char name3[] = "George";
    char name4[64] = {'\0'};
    /*These are 4 ways how one could define a character array. One characteristics of the char array
    is that they must end with the 'zero termination' character.
    The third way is certainly the most convenient way to define a string.
    The fourth approach is the most convenient when you just want to declare the string. As length
    just give in a large power of two number and initialize the array with the zero termination
    character.*/

    char* name5 = (char*)malloc(32 * sizeof(char));
    name5[0] = 'P';
    name5[1] = 'e';
    name5[2] = 't';
    name5[3] = 'e';
    name5[4] = 'r';
    name5[5] = '\0';
    for(unsigned int i = 0; i < 5; ++i)
    {
        printf("%c", name5[i]);
    }
    printf("\n");
    printf("%s\n", name5);  //%s is the way how to read a string. It replaces the whole for loop above.
    printf("%s\n", name1);
    printf("%s\n", name2);
    printf("%s\n", name3);
    printf("%s\n", name4);

    free(name5);
    name5 = NULL;

    return 0;
}
