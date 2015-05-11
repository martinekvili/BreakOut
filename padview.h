#ifndef PADVIEW_H_INCLUDED
#define PADVIEW_H_INCLUDED

#include "idrawable.h"
#include "pad.h"
#include "graphics.h"

class PadView : public IDrawable {
    Pad& pad;

public:
    PadView(Pad& pad) : pad(pad) {}

    void draw() override final;
};

#endif // PADVIEW_H_INCLUDED
