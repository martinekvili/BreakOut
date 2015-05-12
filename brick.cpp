#include "brick.h"

#include "brickview.h"

Brick::Brick(float x, float y, float width, float height, Game& game, View& view) :
    position{x, y}, width{width}, height{height}, game(game), collidedNum{-1} {
    walls.push_back(Wall{Vector{x, y}, width, Wall::Direction::horizontal});
    walls.push_back(Wall{Vector{x, y + height}, width, Wall::Direction::horizontal});
    walls.push_back(Wall{Vector{x, y}, height, Wall::Direction::vertical});
    walls.push_back(Wall{Vector{x + width, y}, height, Wall::Direction::vertical});

    view.addDrawable(new BrickView{*this});
}

float Brick::tryCollide(Vector start, Vector speed, float time) {
    collidedNum = -1;
    float dist = -1.1;

    for (int i = 0; i < (int) walls.size(); i++) {
        float tmp = walls[i].tryCollide(start, speed, time);
        if (tmp > 0) {
            if (dist < -1 || tmp < dist) {
                dist = tmp;
                collidedNum = i;
            }
        }
    }

    return dist;
}

void Brick::doCollide(Vector &start, Vector &speed, float &time, float dist) {
    if (collidedNum == -1) {
        throw "wrong collision";
    }

    walls[collidedNum].doCollide(start, speed, time, dist);

    // TODO: kill me
}
