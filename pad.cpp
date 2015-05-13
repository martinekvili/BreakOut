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
     * Att�l f�gg�en, hogy melyik oldal�n pattan az �t�nek a goly�,
     * m�s sebess�get �ll�tunk be neki.
     * Ha a bal fel�n, akkor arra megy a labda 45�-os sz�gben,
     * ha a jobb fel�n, akkor arra.
     */
    Vector tmp = Ball::getDefaultSpeedInRound(game.getRound());
    if (start.x < getPosition().x + 10) {
        speed = Vector{-tmp.x, tmp.y};
    } else {
        speed = tmp;
    }
}
