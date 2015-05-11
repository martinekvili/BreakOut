#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "isteppable.h"
#include "game.h"

class Ball final : public ISteppable {
    Vector position;
    Vector speed;

    Game& game;

public:
    Ball(Vector position, Vector speed, Game& game) : position{position}, speed{speed}, game(game) {}

    Vector getPosition() { return position; }

    void step(float elapsed) override final;
};

#endif // BALL_H_INCLUDED
