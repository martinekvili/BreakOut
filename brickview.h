#ifndef BRICKVIEW_H_INCLUDED
#define BRICKVIEW_H_INCLUDED

#include "graphics.h"
#include "idrawable.h"
#include "vector.h"

/**
 * A téglákat megjelenítõ osztály.
 */
class BrickView : public IDrawable {
    /**
     * A tégla pozíciója (bal alsó sarok).
     */
    Vector position;

    /**
     * A tégla szélessége.
     */
    float width;

    /**
     * A tégla magassága.
     */
    float height;

public:
    /**
     * A konstruktor.
     * @param position A tégla pozíciója.
     * @param width A tégla szélessége.
     * @param height A tégla magassága.
     */
    BrickView(Vector position, float width, float height) :
        position{position}, width{width}, height{height} {}

    /**
     * A kirajzoló függvény.
     *
     * Egy piros téglalapot rajzol a tégla helyére.
     */
    void draw() override final;
};

#endif // BRICKVIEW_H_INCLUDED
