#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "isteppable.h"
#include "game.h"

class Ball : public ISteppable {
    Vector position;
    Vector speed;

    Game& game;

public:
    Ball(Vector position, Vector speed, Game& game) : position{position}, speed{speed}, game(game) {}

    void step(int elapsed);
};

#endif // BALL_H_INCLUDED
