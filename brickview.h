#ifndef BRICKVIEW_H_INCLUDED
#define BRICKVIEW_H_INCLUDED

#include "graphics.h"
#include "idrawable.h"
#include "vector.h"

/**
 * A t�gl�kat megjelen�t� oszt�ly.
 */
class BrickView : public IDrawable {
    /**
     * A t�gla poz�ci�ja (bal als� sarok).
     */
    Vector position;

    /**
     * A t�gla sz�less�ge.
     */
    float width;

    /**
     * A t�gla magass�ga.
     */
    float height;

public:
    /**
     * A konstruktor.
     * @param position A t�gla poz�ci�ja.
     * @param width A t�gla sz�less�ge.
     * @param height A t�gla magass�ga.
     */
    BrickView(Vector position, float width, float height) :
        position{position}, width{width}, height{height} {}

    /**
     * A kirajzol� f�ggv�ny.
     *
     * Egy piros t�glalapot rajzol a t�gla hely�re.
     */
    void draw() override final;
};

#endif // BRICKVIEW_H_INCLUDED
