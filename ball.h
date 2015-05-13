#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "vector.h"

class Game;
class View;
class BallView;

/**
 * A labd�t reprezent�l� oszt�ly.
 *
 * A j�t�k folyam�n ez az egyetlen "anim�lt" objektum,
 * �gy csak ennek van step f�ggv�nye, ami az eltelt id�t veszi �t.
 */
class Ball {
    /**
     * A labda poz�ci�ja.
     */
    Vector position;

    /**
     * A labda sebess�ge.
     */
    Vector speed;

    /**
     * A labd�t tartalmaz� Game objektum.
     */
    Game& game;

    /**
     * Az aktu�lis megjelen�t� objektum.
     */
    View& view;

    /**
     * A labda megjelen�t�s�re szolg�l� objektum c�me.
     *
     * Az�rt csak egy pointert t�rolunk r�la, mivel ez am�gy a View-ban
     * menedzselt objektumk�nt van elt�rolva, teh�t a megsemmis�t�se ott fog t�rt�nni,
     * itt csak az�rt van r� sz�ks�g, hogy jelezni tudjuk a View-nak, hogy m�r
     * elpuszt�thatja, mivel a labda leesett.
     */
    BallView *myView;

public:
    /**
     * Az alap�rtelmezett sebess�get megad� statikus f�ggv�ny.
     */
    static Vector getDefaultSpeedInRound(int roundNum);

    /**
     * A konstruktor.
     *
     * Elk�sz�ti �s bejegyzi a saj�t megjelen�t� objektum�t.
     */
    Ball(Vector position, Vector speed, Game& game, View& view);

    /**
     * A destruktor.
     *
     * Jelzi a View-nak, hogy elpuszt�thatja a megjelen�t� objektumot.
     */
    ~Ball();

    /**
     * A poz�ci� be�ll�t�s�ra szolg�l� f�ggv�ny.
     *
     * Akkor haszn�ljuk, amikor a labda az �t�vel egy�tt mozog.
     */
    void setPosition(float x, float y) { position = Vector {x, 4}; }

    /**
     * A poz�ci� lek�r�s�re szolg�l� f�ggv�ny.
     *
     * A megjelen�t� objektum haszn�lja.
     */
    Vector getPosition() { return position; }

    /**
     * Az anim�l�sra szolg�l� f�ggv�ny.
     *
     * Megkapja az eltelt id�intervallumot, �s ez alapj�n v�gigzongor�zza,
     * hogy kikkel, hogyan �tk�z�tt, �s ez�ltal hi lett az �j poz�ci�ja,
     * �s a megv�ltozott sebess�ge.
     */
    void step(float elapsed);
};

#endif // BALL_H_INCLUDED
