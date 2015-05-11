#include "vector.h"

Vector Vector::operator* (float n) {
    return Vector{x * n, y * n};
}

Vector Vector::operator+ (const Vector& other) {
    return Vector{x + other.x, y + other.y};
}

Vector& Vector::operator*= (float n) {
    *this = *this * n;
    return *this;
}

Vector& Vector::operator+= (const Vector& other) {
    *this = *this + other;
    return *this;
}
