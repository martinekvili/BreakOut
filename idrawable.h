#ifndef IDRAWABLE_H_INCLUDED
#define IDRAWABLE_H_INCLUDED

#include "graphics.h"

struct IDrawable {
    virtual void draw() = 0;

    virtual ~IDrawable() {}
};

#endif // IDRAWABLE_H_INCLUDED
