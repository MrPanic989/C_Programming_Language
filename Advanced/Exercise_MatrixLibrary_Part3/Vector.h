#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct
{
    float* data;
    size_t length;
} Vector;

Vector* createVector(const size_t length, const float value);

Vector* freeVector(Vector* vector);

void printVector(const Vector* vector);

Vector* addVector(const Vector* vec1, const Vector* vec2);

Vector* subVector(const Vector* vec1, const Vector* vec2);

float multiplyVector(const Vector* vec1, const Vector* vec2);

Vector* multiplyScalar(const Vector* vec, const float scalar);

Vector* divideScalar(const Vector* vec, const float scalar);

float meanVector(const Vector* vector);

float minVector(const Vector* vector);

float maxVector(const Vector* vector);

#endif
