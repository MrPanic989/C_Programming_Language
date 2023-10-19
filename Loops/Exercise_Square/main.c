/*Square: read side length 'a' from the user
- Check: Whether the user entered a "valid" number
- Give the user the opportunity to enter the number for as long as possible until it is valid
- Calculate the perimeter and area of the square
- Then print these values in the console

 u = 4 * a
 a = a^2
*/
#include <stdio.h>
#include <math.h>

int main()
{
    double length = 0.0;        //Data type 'double' just because the function pow() from the <math.h> library
    double perimeter = 0.0;     //uses 'double' as type.
    double area = 0.0;

    do      //The 'do-while' loop because the user has to enter a value at least once and for that case we use the 'do-while' loop.
    {
        printf("Please enter a valid length for which you want to calculate the perimeter and area of the square: ");
        scanf("%lf", &length);

        if (length >= 0.0)          //If the input is valid, we calculate the perimeter and area of the square
        {
            perimeter = 4.0 * length;
            area = pow(length, 2.0);
        }
        else
        {
            printf("Your input is invalid! The side cannot be negative.\n");
        }                       //If the input is invalid, we check the condition and enter into the loop again
    } while ( length < 0.0);    //as long the condition is true, that means as long as the input is invalid.

    printf("The perimeter of the square you have created is %lf. The area is %lf!\n", perimeter, area);

    return 0;
}
