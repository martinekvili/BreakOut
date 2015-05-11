#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED

#include "icollidable.h"

class Wall final : public ICollidable {
public:
    enum Direction {
        horizontal,
        vertical
    };

private:
    Vector position;
    float length;
    Direction direction;

public:
    Wall(Vector position, float length, Direction direction) : position{position}, length{length}, direction{direction} {}

    float tryCollide(Vector start, Vector speed, float time) override final;
    void doCollide(Vector &start, Vector &speed, float &time, float dist) override final;

    void setPosition(Vector newPos) { position = newPos; }
};

#endif // WALL_H_INCLUDED
