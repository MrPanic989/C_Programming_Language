#include <stdio.h>

//Call by value
float add1(float variable1)
{
    printf("Memory address of 'variable1' is: %p\n", &variable1); //The address of 'variable1'
    ++variable1;

    return variable1;
}
/*As you can see, variable1 and variable2 from the two different functions have the same address. How is it possible?
That's because both variables are on the stack memory.
First the add1 function is called and the local variable is created there on the first free stack address.
After leaving the add1 function, the memory on the stack is released again and this address is then free for
the local variable in the add2 function.
*/
//Call by reference
void add2(float* variable2)     //Variable2 POINTS at the address of 'main_variable'.
{
    printf("Memory address of 'variable2' is: %p\n", &variable2); //The actual address of the pointer variable 'variable2'.
    printf("The value of 'variable2' is: %p\n", variable2);   //It is the address of the 'main_variable'

    *variable2 = *variable2 + 2.0f;     //We take the actual value of 'main_variable' with the dereferenced notation.
}


int main(void)
{
    float main_variable = 0.0f;

    printf("The value of the 'main_variable' is: %f\n", main_variable);
    printf("The address of the main_variable is: %p\n\n", &main_variable);

    main_variable = add1(main_variable);
    printf("The new value of the 'main_variable' is: %f\n\n", main_variable);

    add2(&main_variable);   //As parameter we put our memory address of 'main_variable', therefore the '&' address operator.
    printf("The new value of the 'main_variable is: %f\n'", main_variable);

    return 0;
}
