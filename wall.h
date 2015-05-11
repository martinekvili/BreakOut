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
    float position;
    Direction direction;

public:
    Wall(float position, Direction direction) : position{position}, direction{direction} {}

    float tryCollide(Vector start, Vector speed, float time) override final;
    void doCollide(Vector &start, Vector &speed, float &time, float dist) override final;

};

#endif // WALL_H_INCLUDED
