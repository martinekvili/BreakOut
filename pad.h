#ifndef PAD_H_INCLUDED
#define PAD_H_INCLUDED

#include "wall.h"
#include "view.h"

class Pad final : public ICollidable {
    Wall surface;

public:
    Pad(View &view);

    float tryCollide(Vector start, Vector speed, float time) override final;
    void doCollide(Vector &start, Vector &speed, float &time, float dist) override final;

    void setPosition(float x, float y) { surface.setPosition(Vector{x - 10, 2.5}); }
    Vector getPosition() { return surface.getPosition(); }
};

#endif // PAD_H_INCLUDED
