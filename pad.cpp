#include "pad.h"

#include "game.h"
#include "ball.h"
#include "view.h"
#include "padview.h"

Pad::Pad(Game &game, View& view) : surface{Vector{70, 2.5}, 20, Wall::Direction::horizontal}, game(game) {
    view.addDrawable(new PadView{*this});
}

float Pad::tryCollide(Vector start, Vector speed, float time) {
    return surface.tryCollide(start, speed, time);
}

void Pad::doCollide(Vector &start, Vector &speed, float &time, float dist) {
    surface.doCollide(start, speed, time, dist);

    /*
     * Attól függõen, hogy melyik oldalán pattan az ütõnek a golyó,
     * más sebességet állítunk be neki.
     * Ha a bal felén, akkor arra megy a labda 45°-os szögben,
     * ha a jobb felén, akkor arra.
     */
    Vector tmp = Ball::getDefaultSpeedInRound(game.getRound());
    if (start.x < getPosition().x + 10) {
        speed = Vector{-tmp.x, tmp.y};
    } else {
        speed = tmp;
    }
}
