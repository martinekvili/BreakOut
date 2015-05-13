#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "isteppable.h"
#include "vector.h"

class Game;
class View;
class BallView;

class Ball {
    Vector position;
    Vector speed;

    Game& game;
    View& view;

    BallView *myView;

public:
    Ball(Vector position, Vector speed, Game& game, View& view);
    //Ball& operator= (Ball&& other);
    ~Ball();

    void setPosition(float x, float y) { position = Vector {x, 4}; }
    Vector getPosition() { return position; }

    void step(float elapsed);

    static Vector getDefaultSpeedInRound(int roundNum);
};

#endif // BALL_H_INCLUDED
