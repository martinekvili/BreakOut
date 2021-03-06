#include "ball.h"

#include "view.h"
#include "ballview.h"

Vector Ball::getDefaultSpeedInRound(int roundNum) {
    return Vector{50.0f + roundNum * 10.0f, 50.0f + roundNum * 10.0f};
}

Ball::Ball(Vector position, Vector speed, Game& game, View& view) : position{position}, speed{speed}, game(game), view(view) {
    myView = std::make_shared<BallView>(*this);
    view.addDrawable(myView);
}

Ball::~Ball() {
    view.removeDrawable(myView);
}

void Ball::step(float elapsed) {
    /*
     * Először is csekkoljuk, hogy leesett-e a labda, mert ha igen,
     * akkor az egész elkövetkező ütközésdetektálást fölöslegesen végezzük,
     * mert már vége a labdának.
     *
     * De vigyázat, a decrementLives() hívás gyakorlatilag egy
     * delete this, így ezen a ponton muszáj visszatérnünk azonnal
     * a függvényből, különben csúnya memóriakorrupciós hibákat vétünk.
     */
    if (position.y < 0) {
        game.decrementLives();
        return;
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
