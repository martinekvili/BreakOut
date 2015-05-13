#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "isteppable.h"
#include "game.h"

class View;
class BallView;

class Ball final : public ISteppable {
    Vector position;
    Vector speed;

    Game& game;
    View& view;

    BallView *myView;

public:
    Ball(Vector position, Vector speed, Game& game, View& view);
    ~Ball();

    void setPosition(float x, float y) override final { position = Vector {x, 4}; }
    Vector getPosition() { return position; }

    void step(float elapsed) override final;

    static Vector getDefaultSpeedInRound(int roundNum);
};

#endif // BALL_H_INCLUDED
