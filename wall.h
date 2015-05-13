#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED

#include "icollidable.h"

/**
 * A falat reprezentáló osztály.
 */
class Wall final : public ICollidable {
public:
    /**
     * A fal iránya.
     */
    enum Direction {
        horizontal,
        vertical
    };

private:
    /**
     * A fal pozíciója (kezdőpont).
     */
    Vector position;

    /**
     * A fal hossza.
     */
    float length;

    /**
     * A fal iránya.
     */
    Direction direction;

public:
    /**
     * Konstruktor.
     * @param position A fal pozíciója (kezdőpont).
     * @param length A fal hossza.
     * @param direction A fal iránya.
     */
    Wall(Vector position, float length, Direction direction) : position{position}, length{length}, direction{direction} {}

    /**
     * Az ütközésdetektáló függvény.
     *
     * Visszatér a labdától való távolsággal.
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
     * és levonja az összidõbõl az elhasznált mennyiséget.
     *
     * @param start A labda helye.
     * @param speed A labda sebessége.
     * @param time A maximális távolság.
     * @param dist Az elõzõleg kiszámolt távolság.
     */
    void doCollide(Vector &start, Vector &speed, float &time, float dist) override final;

    /**
     * A fal helyének változtatására szolgáló függvény.
     *
     * Csak az ütő pattanó felületéhez használjuk.
     *
     * @param newPos Az új pozíció.
     */
    void setPosition(Vector newPos) { position = newPos; }

    /**
     * A pozíció lekérdezésére szolgáló függvény.
     * @return A pozíció.
     */
    Vector getPosition() { return position; }
};

#endif // WALL_H_INCLUDED
