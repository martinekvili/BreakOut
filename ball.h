#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "vector.h"

class Game;
class View;
class BallView;

/**
 * A labdát reprezentáló osztály.
 *
 * A játék folyamán ez az egyetlen "animált" objektum,
 * így csak ennek van step függvénye, ami az eltelt idõt veszi át.
 */
class Ball {
    /**
     * A labda pozíciója.
     */
    Vector position;

    /**
     * A labda sebessége.
     */
    Vector speed;

    /**
     * A labdát tartalmazó Game objektum.
     */
    Game& game;

    /**
     * Az aktuális megjelenítõ objektum.
     */
    View& view;

    /**
     * A labda megjelenítésére szolgáló objektum címe.
     *
     * Azért csak egy pointert tárolunk róla, mivel ez amúgy a View-ban
     * menedzselt objektumként van eltárolva, tehát a megsemmisítése ott fog történni,
     * itt csak azért van rá szükség, hogy jelezni tudjuk a View-nak, hogy már
     * elpusztíthatja, mivel a labda leesett.
     */
    BallView *myView;

public:
    /**
     * Az alapértelmezett sebességet megadó statikus függvény.
     *
     * @param roundNum Az aktuális kör sorszáma.
     * @return Az alapértelmezett sebesség az aktuális körben.
     */
    static Vector getDefaultSpeedInRound(int roundNum);

    /**
     * A konstruktor.
     *
     * Elkészíti és bejegyzi a saját megjelenítõ objektumát.
     *
     * @param position A pozíció.
     * @param speed A sebesség.
     * @param game Az aktuális játék objektum.
     * @param view Az aktuális megjelenítő objektum.
     */
    Ball(Vector position, Vector speed, Game& game, View& view);

    /**
     * A destruktor.
     *
     * Jelzi a View-nak, hogy elpusztíthatja a megjelenítõ objektumot.
     */
    ~Ball();

    /**
     * A pozíció beállítására szolgáló függvény.
     *
     * Akkor használjuk, amikor a labda az ütõvel együtt mozog.
     *
     * @param x Az x koordináta.
     * @param y Az y koordináta.
     */
    void setPosition(float x, float y) { position = Vector {x, 4}; }

    /**
     * A pozíció lekérésére szolgáló függvény.
     *
     * A megjelenítõ objektum használja.
     *
     * @return Az aktuális pozíció.
     */
    Vector getPosition() { return position; }

    /**
     * Az animálásra szolgáló függvény.
     *
     * Megkapja az eltelt idõintervallumot, és ez alapján végigzongorázza,
     * hogy kikkel, hogyan ütközött, és ezáltal hi lett az új pozíciója,
     * és a megváltozott sebessége.
     *
     * @param elapsed Az eltelt idő másodpercben mérve.
     */
    void step(float elapsed);
};

#endif // BALL_H_INCLUDED
