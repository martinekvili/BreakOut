#include "wall.h"

float Wall::tryCollide(Vector start, Vector speed, float time) {
    float dist;

    if (direction == horizontal) {
        dist = (position.y - start.y) / speed.y;

        float newx = start.x + speed.x * dist;
        if (newx < position.x || newx > position.x + length) {
            return -1.1;
        }
    } else {
        dist = (position.x - start.x) / speed.x;

        float newy = start.y + speed.y * dist;
        if (newy < position.y || newy > position.y + length) {
            return -1.1;
        }
    }

    return (dist < 0 || dist > time) ? -1.1 : dist;
}

void Wall::doCollide(Vector &start, Vector &speed, float &time, float dist) {
    if (direction == horizontal) {
        start.y = position.y;
        speed.y *= -1;
    } else {
        start.x = position.x;
        speed.x *= -1;
    }

    // Egy picit elõrébb mozdítjuk a számítássi pontosság miatt
    start += speed * 0.001;

    time -= dist + 0.001;
}
