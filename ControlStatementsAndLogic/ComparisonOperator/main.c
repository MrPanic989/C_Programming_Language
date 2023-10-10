#include <stdio.h>
#include <stdbool.h>  //This library is needed if we want to use the bool operator.

int main()
{
    int a = 0;
    int b = 0;

    bool comparison = false; //boolean can represent the two states: true or false ( 1 or 0 )

    printf("Please enter the two numbers you want to compare: ");
    scanf("%d %d", &a, &b);
    //printf("%d %d", a, b);

    comparison = a > b; //Is a greater than b?
    /*if(comparison == true)
    {
        printf("\nThe number %d is greater than %d!", a, b);
    }
    else
    {
        printf("\nThe number %d is smaller than %d!", a, b);
    }
        What if those two numbers are equal?
    */
   printf("a > b = %d\n", comparison);

   comparison = a < b; //Is a smaller than b?
   printf("a < b = %d\n", comparison);

   comparison = a == b; //With '==' one is comparing the two subjects. So, are a and b equal?
   printf("a == b = %d\n", comparison);

   comparison = a != b; //'!=' means: a is NOT equal to b!
   printf("a != b = %d\n", comparison);

   comparison = a >= b; //Is a greater than or equal to b?
   printf("a >= b = %d\n", comparison);

   comparison = a <= b; //Is a smaller than or equal to b?
   printf("a <= b = %d\n", comparison);

    return 0;
}
