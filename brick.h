#ifndef BRICK_H_INCLUDED
#define BRICK_H_INCLUDED

#include <vector>

#include "vector.h"
#include "wall.h"
#include "game.h"
#include "view.h"

class Brick : public ICollidable {
    std::vector<Wall> walls;
    Vector position;
    float width, height;
    Game &game;
    int collidedNum;

public:
    Brick(float x, float y, float width, float height, Game& game, View& view);

    float tryCollide(Vector start, Vector speed, float time) override final;
    void doCollide(Vector &start, Vector &speed, float &time, float dist) override final;

    Vector getPosition() { return position; }
    float getWidth() { return width; }
    float getHeight() { return height; }
};

#endif // BRICK_H_INCLUDED
