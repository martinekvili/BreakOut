#ifndef IDRAWABLE_H_INCLUDED
#define IDRAWABLE_H_INCLUDED

#include "graphics.h"

/**
 * A kirajzolhat� oszt�lyok interf�sze.
 */
struct IDrawable {
    /**
     * A kirajzol� f�ggv�ny.
     */
    virtual void draw() = 0;

    virtual ~IDrawable() {}
};

#endif // IDRAWABLE_H_INCLUDED
