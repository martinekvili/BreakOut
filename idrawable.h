#ifndef IDRAWABLE_H_INCLUDED
#define IDRAWABLE_H_INCLUDED

#include "graphics.h"

/**
 * A kirajzolható osztályok interfésze.
 */
struct IDrawable {
    /**
     * A kirajzoló függvény.
     */
    virtual void draw() = 0;

    virtual ~IDrawable() {}
};

#endif // IDRAWABLE_H_INCLUDED
