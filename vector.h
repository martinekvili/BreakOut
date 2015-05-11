#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <cmath>

struct Vector {
    float x, y;

    Vector() : x{0}, y{0} {}
    Vector(float x, float y) : x{x}, y{y} {}

    Vector operator* (float n);
    Vector operator+ (const Vector& other);
    Vector& operator*= (float n);
    Vector& operator+= (const Vector& other);

    float length();
};

#endif // VECTOR_H_INCLUDED
