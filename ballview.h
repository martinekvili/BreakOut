#ifndef BALLVIEW_H_INCLUDED
#define BALLVIEW_H_INCLUDED

#include "graphics.h"
#include "ball.h"
#include "idrawable.h"

class BallView final : public IDrawable {
    Ball& ball;

public:
    BallView(Ball& ball) : ball(ball) {}

    void draw() override final;
};

#endif // BALLVIEW_H_INCLUDED
