#include <stdio.h>
#include <stdlib.h>

#define ARR_DTYPE double

int comp(const void *value1, const void *value2)    //comp() from stdlib.h takes two void const*
{                                                   //because it has to work for all data types
    ARR_DTYPE left = *((ARR_DTYPE *)value1);    //We have to cast it to our data type from the case
    ARR_DTYPE right = *((ARR_DTYPE *)value2);   //and to dereference it to get the values

    if (left > right)
    {
        return 1;   //if left > right then swap those two elements. That means that this list
    }               //will be ascending sorted. (1 == yes, swap)
    else if (right > left)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

#define ARR_LEN 4U

int main()
{
    ARR_DTYPE data[ARR_LEN] = {-2.0, 3.0, -1.0, 12.0};

    //qsort() from stdlib.h taks the address from the first element that should be sorted, how many
    //elements should be sorted, how big the elements are, and the pointer to a function, in our case the comp()
    qsort(&data, ARR_LEN, sizeof(ARR_DTYPE), comp);

    for (unsigned int i = 0; i < ARR_LEN; i++)
    {
        printf("data[%d] = %f\n", i, data[i]);
    }

    return 0;
}
