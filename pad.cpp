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
}
