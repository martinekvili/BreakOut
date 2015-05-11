#include "ball.h"

void Ball::step(float elapsed) {
    /*
     * Az �tk�z�sdetekt�l�s.
     *
     * V�gigmegy�nk az �tk�zhet� elemeken, �s megkeress�k azt,
     * akivel el�sz�r �tk�zik, ha �tk�zik egy�ltal�n.
     * Ha tal�ltunk ilyet, akkor az �tk�z�s hely�re tessz�k a labd�t,
     * a megv�ltozott sebess�ggel, majd el�lr�l kezdj�k a folyamatot:
     * hisz lehet, hogy egy id�intervallum alatt t�bb elemmel is �tk�z�tt.
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
     * Itt m�r elv�gezt�nk minden elv�gzend� �tk�z�st,
     * m�r csak anniy van h�tra, hogy a megmaradt id�t elhaszn�ljuk arra,
     * hogy zavartalanul haladjunk el�re.
     */
     position += speed * elapsed;
}
