#ifndef BALLVIEW_H_INCLUDED
#define BALLVIEW_H_INCLUDED

#include "graphics.h"
#include "ball.h"
#include "idrawable.h"

/**
 * A labda megjelenítésére szolgáló osztály.
 */
class BallView final : public IDrawable {
    /**
     * A labda amit megjelenít.
     */
    Ball& ball;

public:
    /**
     * A konstruktor.
     * @param ball A megjelenítendõ labda.
     */
    BallView(Ball& ball) : ball(ball) {}

    /**
     * A kirajzoló függvény.
     *
     * Egy zöld kört rajzol ki a labda helyére.
     */
    void draw() override final;
};

#endif // BALLVIEW_H_INCLUDED
