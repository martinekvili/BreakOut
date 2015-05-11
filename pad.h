#ifndef PAD_H_INCLUDED
#define PAD_H_INCLUDED

#include "wall.h"

class Pad final : public ICollidable {
    Wall surface;

public:
    Pad() : surface{Vector{70, 0}, 20, Wall::Direction::horizontal} {}

    float tryCollide(Vector start, Vector speed, float time) override final;
    void doCollide(Vector &start, Vector &speed, float &time, float dist) override final;

    void setPosition(float x, float y) { surface.setPosition(Vector{x - 10, 0}); }
};

#endif // PAD_H_INCLUDED
