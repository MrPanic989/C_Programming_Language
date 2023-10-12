#include <stdio.h>

enum Beverage
{
    NO_BEVERAGE,    // = 0          The elements of the enum should be written in capslock because
    WATER,          // = 1          they are global variables. And due to that fact, it is good practice to
    COKE,           // = 2          name the elements like, e.g. BEVERAGE_COKE, that is first the name of the enum
    FANTA,          // = 3          and then the variable name.
    SPRITE,         // = 4
    COFFEE,         // = 5
};

int main()
{
    enum Beverage selected_beverage = NO_BEVERAGE;  //Now we are initializing a variable 'selected_beverage' of the data type 'enum Beverage'
    int selection = 0;

    printf("Select a beverage:\nWater (1), Coke (2), Fanta (3), Sprite (4), Coffee (5)\n");
    scanf("%d", &selection);

    selected_beverage = (enum Beverage)selection;
    /*This intermediate step is necessary because 'enum Beverage' and 'int' are different data types,
    although they are related to each other. However, the 'scanf' function expects a pointer to the variable
    into which the value should be read.
    To fix this, you need to pass a pointer to the 'selected_beverage' variable.
    This happens with “Type Casting”. The cast operator '(enum Beverage)', which casts the value of
    'selection' to the enum type 'enum Beverage'.
    This step is necessary because 'selection' was previously read as 'int', but 'selected_beverage' is of type
    'enum Beverage'.
    */
    switch (selected_beverage)      //switch function is usually used for enumeration, because we have to check
    {                               //every single element of the enum.
        case WATER:
        {
            printf("You selected a water!\n");
            break;      //Withoug 'break' our program would check out and every text from the cases. 'break' works like
        }               //"our case is true, we do what the code says in the case and then we break out of the switch function". There is no need to check out further cases.
        case COKE:
        {
            printf("You selected a Coke!\n");
            break;
        }
        case FANTA:
        {
            printf("You selected a Fanta!\n");
            break;
        }
        case SPRITE:
        {
            printf("You selected a Sprite!\n");
            break;
        }
        case COFFEE:
        {
            printf("You selected a coffee!\n");
            break;
        }
        default:
        {
            printf("You selected an invalid beverage!\n");
            break;
        }
    }

    return 0;
}
