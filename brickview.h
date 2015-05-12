#ifndef BRICKVIEW_H_INCLUDED
#define BRICKVIEW_H_INCLUDED

#include "graphics.h"
#include "idrawable.h"
#include "brick.h"

class BrickView : public IDrawable {
    Brick& brick;

public:
    BrickView(Brick& brick) : brick(brick) {}

    void draw() override final;
};

#endif // BRICKVIEW_H_INCLUDED
