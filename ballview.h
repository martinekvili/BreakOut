#ifndef BALLVIEW_H_INCLUDED
#define BALLVIEW_H_INCLUDED

#include "graphics.h"
#include "ball.h"
#include "idrawable.h"

/**
 * A labda megjelen�t�s�re szolg�l� oszt�ly.
 */
class BallView final : public IDrawable {
    /**
     * A labda amit megjelen�t.
     */
    Ball& ball;

public:
    /**
     * A konstruktor.
     * @param ball A megjelen�tend� labda.
     */
    BallView(Ball& ball) : ball(ball) {}

    /**
     * A kirajzol� f�ggv�ny.
     *
     * Egy z�ld k�rt rajzol ki a labda hely�re.
     */
    void draw() override final;
};

#endif // BALLVIEW_H_INCLUDED
