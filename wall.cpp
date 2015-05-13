#include "wall.h"

float Wall::tryCollide(Vector start, Vector speed, float time) {
    float dist;

    /*
     * Megvizsgáljuk a labda útjának és a falnak a metszéspontját,
     * és ha még a fal belsejében van, akkor visszatérünk a távolságával.
     * Minden más esetben (nincs így metszéspont: távolodunk, vagy kívül esne
     * a metszéspont a fal belsején), akkor -1-gyel térünk vissza.
     */
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
    /*
     * Teljes visszaverődést szimulálunk, azaz az ütköző irányú
     * komponens pont -1-szeresére változik.
     * A pozíció pedig pont a metszéspontba kerül.
     */
    if (direction == horizontal) {
        start.y = position.y;
        speed.y *= -1;
    } else {
        start.x = position.x;
        speed.x *= -1;
    }

    // Egy picit elõrébb mozdítjuk a számítási pontatlanság miatt
    start += speed * 0.001;

    time -= dist + 0.001;
}
