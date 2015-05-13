#ifndef ICOLLIDABLE_H_INCLUDED
#define ICOLLIDABLE_H_INCLUDED

#include "vector.h"

/**
 * Az ütközhető osztályok interfésze.
 */
struct ICollidable {
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
    virtual float tryCollide(Vector start, Vector speed, float time) = 0;

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
    virtual void doCollide(Vector &start, Vector &speed, float &time, float dist) = 0;

    virtual ~ICollidable() {}
};

#endif // ICOLLIDABLE_H_INCLUDED
