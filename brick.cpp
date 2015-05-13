#include "brick.h"

Brick::Brick(float x, float y, float width, float height, Game& game, View& view) :
    position{x, y}, width{width}, height{height}, game(game), view(view), collidedNum{-1} {
    walls.push_back(Wall{Vector{x, y}, width, Wall::Direction::horizontal});
    walls.push_back(Wall{Vector{x, y + height}, width, Wall::Direction::horizontal});
    walls.push_back(Wall{Vector{x, y}, height, Wall::Direction::vertical});
    walls.push_back(Wall{Vector{x + width, y}, height, Wall::Direction::vertical});

    myView = new BrickView{position, width, height};
    view.addDrawable(myView);
}

Brick::~Brick() {
    view.removeDrawable(myView);
}

float Brick::tryCollide(Vector start, Vector speed, float time) {
    collidedNum = -1;
    float dist = -1.1;

    /*
     * Megvizsg�ljuk az �tk�z�st a t�gla mind a 4 fal�val,
     * �s a legk�zelebbi tal�lat t�vols�g�val t�r�nk vissza.
     * Ek�zben elt�roljuk a legk�zelebbi tal�lat sorsz�m�t,
     * �gy ha t�nyleg mi voltunk minden k�z�l a legk�zelebb,
     * akkor nem kell �jra kikeresni, hogy melyik fal lett
     * konkr�tan eltal�lva.
     */
    for (int i = 0; i < (int) walls.size(); i++) {
        float tmp = walls[i].tryCollide(start, speed, time);
        if (tmp > 0) {
            if (dist < -1 || tmp < dist) {
                dist = tmp;
                collidedNum = i;
            }
        }
    }

    return dist;
}

void Brick::doCollide(Vector &start, Vector &speed, float &time, float dist) {
    // Megtessz�k a tal�latot az elmentett fal sorsz�m�val
    walls[collidedNum].doCollide(start, speed, time, dist);

    // �s elpuszt�tjuk ezt a falat
    game.removeObject(this);
    game.incrementPoints();
}
