#ifndef PAD_H_INCLUDED
#define PAD_H_INCLUDED

#include <memory>

#include "wall.h"

class View;
class Game;

/**
 * Az ütőt reprezentáló osztály.
 */
class Pad final : public ICollidable {
    /**
     * Az ütő felső oldala.
     *
     * Ezzel lehet ütközni, erről pattan vissza a golyó.
     */
    Wall surface;

    /**
     * A játék objektum.
     */
    Game &game;

public:
    /**
     * A konstruktor.
     *
     * Bejegyzi a saját megjelenítőjét a View-nak.
     * Mivel ez csak a játék végén semmisül meg, így nem kell jeleznünk a
     * View-nak egy esetleges játék közbeni megsemmisülést, így nem tárolunk
     * referenciát a View-ra, sem pedig a megjelenítő objektumára.
     *
     * @param game A játék.
     * @param view A megjelenítő.
     */
    Pad(Game &game, View &view);

    /**
     * Az ütközésdetektáló függvény.
     *
     * Csak simán delegálja a surface ilyen függvényét.
     *
     * @param start A labda pozíciója.
     * @param speed A labda sebessége.
     * @param time A maximális távolság.
     * @return A legközelebbi távolság (-1, ha nincs ilyen).
     */
    float tryCollide(Vector start, Vector speed, float time) override final;

    /**
     * Az ütközést elvégzõ függvény.
     *
     * Beállítja a helyet és a sebességet a megfelelõ értékre,
     * és levonja az össz idõbõl az elhasznált mennyiséget.
     * Ez is csak delegálja a surface függvényét.
     *
     * @param start A labda helye.
     * @param speed A labda sebessége.
     * @param time A maximális távolság.
     * @param dist Az elõzõleg kiszámolt távolság.
     */
    void doCollide(Vector &start, Vector &speed, float &time, float dist) override final;

    /**
     * Függvény amivel meg tudjuk adni az ütő helyét.
     *
     * Ezt hívja az egérmozgatás callback-je (közvetve).
     *
     * @param x Az x koordináta.
     * @param y Az y koordináta.
     */
    void setPosition(float x, float y) { surface.setPosition(Vector{x - 10, 2.5}); }

    /**
     * A pozíciót lekérdező függvény.
     * @return A pozíció.
     */
    Vector getPosition() { return surface.getPosition(); }
};

#endif // PAD_H_INCLUDED
