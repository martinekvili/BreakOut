#ifndef BRICKVIEW_H_INCLUDED
#define BRICKVIEW_H_INCLUDED

#include "graphics.h"
#include "idrawable.h"
#include "vector.h"

class BrickView : public IDrawable {
    Vector position;
    float width, height;

public:
    BrickView(Vector position, float width, float height) :
        position{position}, width{width}, height{height} {}

    void draw() override final;
};

#endif // BRICKVIEW_H_INCLUDED
