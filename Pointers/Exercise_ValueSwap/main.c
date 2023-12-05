#include <stdio.h>
#include <stdint.h>

/*This function is a perfect showcase why we need pointers. How would we solve the problem of this function
without pointers? We couldn't solve it at all. We have a function which should return four values, but
a function can return only one value per call. The solution is a pointer variable!*/
void swap(int32_t* a, int32_t* b, int32_t* c, int32_t* d);

int main(void)
{
    int32_t value1 = 0;
    int32_t value2 = 0;
    int32_t value3 = 0;
    int32_t value4 = 0;

    printf("Please enter four whole numbers for the variables: ");
    scanf("%d%d%d%d", &value1, &value2, &value3, &value4);

    printf("The numbers are: value1 = %d, value2 = %d, value3 = %d and value4 = %d!\nLet's mix them up!\n", value1, value2, value3, value4);

    int32_t* pointer1 = &value3;
    int32_t* pointer2 = &value4;

    swap(&value1, &value2, pointer1, pointer2); //We call up the function 'swap' with addresses as parameters.

    printf("The new values of the variables are: value1 = %d, value2 = %d, value3 = %d and value4 = %d!\n", value1, value2, value3, value4);

    return 0;
}

void swap(int32_t* a, int32_t* b, int32_t* c, int32_t* d)
{
    int32_t temp = *a;      //Everytime you have a function where you swap things araund, you have to
                            //define a temporary variable and save one of variable to swap into.
    *a = *b;
    *b = *c;
    *c = *d;
    *d = temp;
}
