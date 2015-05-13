#ifndef PADVIEW_H_INCLUDED
#define PADVIEW_H_INCLUDED

#include "idrawable.h"
#include "pad.h"
#include "graphics.h"

/**
 * Az ütõt megjelenítõ osztály.
 */
class PadView : public IDrawable {
    /**
     * Az ütõ, amit megjelenít.
     */
    Pad& pad;

public:
    /**
     * Konstruktor.
     * @param pad A megjelenítendõ ütõ.
     */
    PadView(Pad& pad) : pad(pad) {}

    /**
     * A kirajzoló függvény.
     */
    void draw() override final;
};

#endif // PADVIEW_H_INCLUDED
