#include "pad.h"

#include "padview.h"

Pad::Pad(View& view) : surface{Vector{70, 2.5}, 20, Wall::Direction::horizontal} {
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
    if (start.x < getPosition().x + 10) {
        speed = Vector{-50, 50};
    } else {
        speed = Vector{50, 50};
    }
}
