#include "pad.h"

float Pad::tryCollide(Vector start, Vector speed, float time) {
    return surface.tryCollide(start, speed, time);
}

void Pad::doCollide(Vector &start, Vector &speed, float &time, float dist) {
    surface.doCollide(start, speed, time, dist);
}
