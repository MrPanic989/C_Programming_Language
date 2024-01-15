/*Tasks of the programming exercise:
- Declare the Struct struct Vector and a Typedef Vector
    -The structure should store the data array (int's) and the length of the array

The 1D array methods from earlier chapters should be adapted for this struct
- float meanVector(...)
- int minVector(...)
- int maxVector(...)

I have already defined these functions for you:
-int *createArray
-int *freeArray
-void printVector

Test the code for the Max, Min and Mean functions for a created vector
*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Vector
{
    //int data[];
    int* data;      //because we do not know the exact size of the array
    unsigned int length;
}; // { }

// typedef
typedef struct Vector Vector_t;

int *createVector(unsigned int length, int value)
{
    int *data = (int *)malloc(length * sizeof(int));

    if (NULL == data)
    {
        return NULL;
    }

    for (unsigned int i = 0; i < length; i++)
    {
        data[i] = value;
    }

    return data;
}

int *freeVector(Vector_t* vec_pointer)
{
    if(vec_pointer->data != NULL)
    {
        free(vec_pointer->data);
    }

    return NULL;
}


float meanVector(Vector_t* vec_pointer)
{
    if(vec_pointer == NULL || vec_pointer->data == NULL)    //If this vector or the integer in the struct points at NULL
    {
        return -1;
    }

    float avr = 0.0f;

    for(unsigned int i = 0; i < vec_pointer->length; ++i)
    {
        avr += (float)vec_pointer->data[i];
    }

    avr /= (float)vec_pointer->length;

    return avr;
}

int minVector(Vector_t* vec_pointer)
{
    if(vec_pointer == NULL || vec_pointer->data == NULL)
    {
        return -1;
    }

    int min = 9999999;

    for(unsigned int i = 0; i < vec_pointer->length; ++i)
    {
        if(vec_pointer->data[i] < min)
        {
            min = vec_pointer->data[i];
        }
    }

    return min;
}

int maxVector(Vector_t* vec_pointer)
{
    if(vec_pointer == NULL || vec_pointer->data == NULL)
    {
        return -1;
    }

    int max = 0;

    for(unsigned int i = 0; i < vec_pointer->length; ++i)
    {
        if(vec_pointer->data[i] > max)
        {
            max = vec_pointer->data[i];
        }
    }

    return max;
}

void printVector(Vector_t* vec_pointer)
{
    if(vec_pointer == NULL || vec_pointer->data == NULL)
    {
        return;
    }

    for(unsigned int i = 0; i < vec_pointer->length; ++i)
    {
        printf("%d\n", vec_pointer->data[i]);
    }
}

int main()
{
    Vector_t v1 = {.data = createVector(3, 1), .length = 3};
    v1.data[0] = 10;
    v1.data[1] = - 10;
    v1.data[2] = 100;

    printVector(&v1);

    int max_v1 = maxVector(&v1);
    int min_v1 = minVector(&v1);
    float mean_v1 = meanVector(&v1);

    printf("Max: %d\n", max_v1);
    printf("Min: %d\n", min_v1);
    printf("Mean: %f\n", mean_v1);

    v1.data = freeVector(&v1);

    return 0;
}
