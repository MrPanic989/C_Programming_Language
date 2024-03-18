#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "DynamicArray.h"


dynamic_array_t* createDynamicArray()
{
    dynamic_array_t* array = (dynamic_array_t*)malloc(sizeof(dynamic_array_t));

    if(array == NULL)
    {
        return NULL;
    }

    array->length = 0u;
    array->capacity = INIT_CAPACITY;
    //now we have to reserv memory for the float heap array
    float* data = (float*)malloc(array->capacity * sizeof(float));

    if(data == NULL)
    {
        free(array);
        return NULL;
    }

    array->data = data;

    return array;
}

void* freeDynamicArray(dynamic_array_t* array)
{
    if(array != NULL)
    {
        free(array->data);  //first we have to free the memory for data, before we 'cut' the connection
        array->data = NULL;    //to our dynamic_array_t data struct

        free(array);
        array = NULL;
    }

    return NULL;
}

void expandDynamicArray(dynamic_array_t* array)
{
    array->capacity *= GROWTH_FACTOR;

    /*void *realloc(void *ptr, size_t size);
    realloc deallocates the old object pointed to by ptr and returns a pointer to
    a new object that has the size specified by size. The contents of the new object is
    identical to that of the old object prior to deallocation,
    up to the lesser of the new and old sizes.
    */
    float* new_data = (float*)realloc(array->data, array->capacity * sizeof(float));

    if(new_data == NULL)
    {
        return;
    }

    array->data = new_data;

}

void shrinkDynamicArray(dynamic_array_t* array)
{
    array->capacity /= SHRINK_FACTOR;

    float* new_data = (float*)realloc(array->data, array->capacity * sizeof(float));

    if(new_data == NULL)
    {
        return;
    }

    array->data = new_data;
}

void pushValue(dynamic_array_t* array, const float value)
{
    array->data[array->length] = value;
    ++array->length;    //pointer arithmetics. we move the pointer one step further

    if(array->length == array->capacity)
    {
        expandDynamicArray(array);  //if we reach the full capacity, we have to realloc and expand our memory
    }

}

float popValue(dynamic_array_t* array)
{
    const unsigned int index = array->length - 1u;
    const float value = array->data[index];

    array->data[index] = 0.0f;
    --array->length;

    //E.g. length = 4; capacity = 10
    if(array->length < (array->capacity / SHRINK_FACTOR))
    {
        shrinkDynamicArray(array);
    }

    return value;
}

void clearDynamicArray(dynamic_array_t* array)
{
    if(array == NULL || array->data == NULL)
    {
        return;
    }

    free(array->data);
    array->data = NULL;
    array->length = 0u; //due to the fact that our pointer doesn't point at anything at all

}

void printDynamicArray(const dynamic_array_t* array)
{
    printf("Length: %u, Capacity: %u\n", array->length, array->capacity);

    for(unsigned int i = 0; i < array->length; ++i)
    {
        printf("%f ", array->data[i]);
    }

    printf("\n\n");
}
