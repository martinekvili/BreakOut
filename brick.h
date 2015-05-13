#ifndef BRICK_H_INCLUDED
#define BRICK_H_INCLUDED

#include <vector>

#include "vector.h"
#include "wall.h"
#include "game.h"
#include "view.h"
#include "brickview.h"

/**
 * A t�gl�kat reprezent�l� oszt�ly.
 */
class Brick : public ICollidable {
    /**
     * A t�gla falai.
     */
    std::vector<Wall> walls;

    /**
     * A t�gla poz�ci�ja (bal als� sarok).
     */
    Vector position;

    /**
     * A t�gla sz�less�ge.
     */
    float width;

    /**
     * A t�gla magass�ga.
     */
    float height;

    /**
     * Az aktu�lis j�t�k objektum.
     */
    Game &game;

    /**
     * Az aktu�lis emgjelen�t� objektum.
     */
    View &view;

    /**
     * A t�gla saj�t megjelen�t� objektuma.
     *
     * Az�rt csak pointert t�rolunk, mivel a View-ban ugyan ezt az
     * objektumot menedzselt k�r�lm�nyek k��z�tt t�roljuk, �gy a
     * megsz�ntet�s�re ott ker�l majd sor.
     * Itt az�rt van r� m�gis sz�ks�g, hogy tudjunk jelezni, hogy
     * mikor kell megsz�ntetni (ezzel az objektummal egy�tt) a
     * megjelen�t�t is.
     */
    BrickView *myView;

    /**
     * Annak a falnak a sorsz�ma, aminek es�lye van r�szt venni a k�vetkez� �tk�z�sben.
     */
    int collidedNum;

public:
    /**
     * A konstruktor.
     *
     * L�trehozza a t�gl�hoz tartoz� falakat, �s a megjelen�t�t is. A megjelen�t�t
     * mejegyzi a View objektumba.
     *
     * @param x A poz�ci� x koordin�t�ja.
     * @param y A poz�ci� y koordin�t�ja.
     * @param width A t�gla sz�less�ge.
     * @param height A t�gle magass�ga.
     * @param game A j�t�k objektum.
     * @param view A megjelen�t� objektum.
     */
    Brick(float x, float y, float width, float height, Game& game, View& view);

    /**
     * A destruktor.
     *
     * Jelzi a View-nak hogy megsz�ntetheti az ehhez tartoz� megjelen�t�t.
     */
    ~Brick();

    /**
     * Az �tk�z�sdetekt�l� f�ggv�ny.
     *
     * Visszat�r a labd�hoz legk�zelebbi fal t�vols�g�val.
     *
     * @param start A labda poz�ci�ja.
     * @param speed A labda sebess�ge.
     * @param time A maxim�lis t�vols�g.
     * @return A legk�zelebbi t�vols�g (-1, ha nincs ilyen).
     */
    float tryCollide(Vector start, Vector speed, float time) override final;

    /**
     * Az �tk�z�st elv�gz� f�ggv�ny.
     *
     * Be�ll�tja a helyet �s a sebess�get a megfelel� �rt�kre,
     * �s levonja az �ssz id�b�l az elhaszn�lt mennyis�get.
     *
     * @param start A labda helye.
     * @param speed A labda sebess�ge.
     * @param time A maxim�lis t�vols�g.
     * @param dist Az el�z�leg kisz�molt t�vols�g.
     */
    void doCollide(Vector &start, Vector &speed, float &time, float dist) override final;
};

#endif // BRICK_H_INCLUDED
