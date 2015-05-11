#ifndef ICOLLIDABLE_H_INCLUDED
#define ICOLLIDABLE_H_INCLUDED

#include "vector.h"

struct ICollidable {
    virtual float tryCollide(Vector start, Vector speed, float time) = 0;
    virtual void doCollide(Vector &start, Vector &speed, float &time, float dist) = 0;

    virtual ~ICollidable() {}
};

#endif // ICOLLIDABLE_H_INCLUDED
