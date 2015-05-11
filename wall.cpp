#include "wall.h"

float Wall::tryCollide(Vector start, Vector speed, float time) {
    float dist;

    if (direction == horizontal) {
        dist = (position - start.y) / speed.y;
    } else {
        dist = (position - start.x) / speed.x;
    }

    return (dist < 0 || dist > time) ? -1.1 : dist;
}

void Wall::doCollide(Vector &start, Vector &speed, float &time, float dist) {
    if (direction == horizontal) {
        start.y = position;
        speed.y *= -1;
    } else {
        start.x = position;
        speed.x *= -1;
    }

    // Egy picit elõrébb mozdítjuk a számítássi pontosság miatt
    start += speed * 0.001;

    time -= dist + 0.001;
}
