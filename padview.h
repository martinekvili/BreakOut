#ifndef PADVIEW_H_INCLUDED
#define PADVIEW_H_INCLUDED

#include "idrawable.h"
#include "pad.h"
#include "graphics.h"

/**
 * Az �t�t megjelen�t� oszt�ly.
 */
class PadView : public IDrawable {
    /**
     * Az �t�, amit megjelen�t.
     */
    Pad& pad;

public:
    /**
     * Konstruktor.
     * @param pad A megjelen�tend� �t�.
     */
    PadView(Pad& pad) : pad(pad) {}

    /**
     * A kirajzol� f�ggv�ny.
     */
    void draw() override final;
};

#endif // PADVIEW_H_INCLUDED
