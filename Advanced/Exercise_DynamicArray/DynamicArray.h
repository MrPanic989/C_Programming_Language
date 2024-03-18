#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#define INIT_CAPACITY 10u   //our array starts with capacity of 10
#define GROWTH_FACTOR 2u    //if length == capacity, we reallocate the mamory and multiply it by 2
#define SHRINK_FACTOR 2u

typedef struct
{
    float* data;
    unsigned int length;
    unsigned int capacity;  //the number which we want to allocate on the heap. capacity >= length
} dynamic_array_t;


dynamic_array_t* createDynamicArray();
void* freeDynamicArray(dynamic_array_t* array);

void expandDynamicArray(dynamic_array_t* array);
void shrinkDynamicArray(dynamic_array_t* array);

void pushValue(dynamic_array_t* array, const float value);
float popValue(dynamic_array_t* array);

void clearDynamicArray(dynamic_array_t* array);
void printDynamicArray(const dynamic_array_t* array);

#endif
