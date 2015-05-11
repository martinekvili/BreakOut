#include "ball.h"

#include "ballview.h"

Ball::Ball(Vector position, Vector speed, Game& game, View& view) : position{position}, speed{speed}, game(game) {
        view.addDrawable(new BallView{*this});
    }

void Ball::step(float elapsed) {
    /*
     * Először is csekkoljuk, hogy leesett-e a labda, mert ha igen,
     * akkor az egész elkövetkező ütközésdetektálást fölöslegesen végezzük,
     * mert már vége a játéknak.
     */
    if (position.y < 0) {
        game.stop();
    }

    /*
     * Az ütközésdetektálás.
     *
     * Végigmegyünk az ütközhetõ elemeken, és megkeressük azt,
     * akivel elõször ütközik, ha ütközik egyáltalán.
     * Ha találtunk ilyet, akkor az ütközés helyére tesszük a labdát,
     * a megváltozott sebességgel, majd elölrõl kezdjük a folyamatot:
     * hisz lehet, hogy egy idõintervallum alatt több elemmel is ütközött.
     */
    bool collisionHappened;
    do {
        collisionHappened = false;

        auto collidables = game.getCollidables();
        int nearestNum = -1;
        float nearestDist = -1.1;

        for (int i = 0; i < (int) collidables.size(); i++) {
            float dist = collidables[i]->tryCollide(position, speed, elapsed);

            if (dist > 0) {
                if (nearestDist < -1 || dist  < nearestDist) {
                    nearestNum = i;
                    nearestDist = dist;
                }
            }
        }

        if (nearestNum != -1) {
            collidables[nearestNum]->doCollide(position, speed, elapsed, nearestDist);
            collisionHappened = true;
        }

    } while (collisionHappened);

    /*
     * Itt már elvégeztünk minden elvégzendõ ütközést,
     * már csak anniy van hátra, hogy a megmaradt idõt elhasználjuk arra,
     * hogy zavartalanul haladjunk elõre.
     */
     position += speed * elapsed;
}
