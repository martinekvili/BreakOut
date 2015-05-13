#ifndef BRICK_H_INCLUDED
#define BRICK_H_INCLUDED

#include <vector>

#include "vector.h"
#include "wall.h"
#include "game.h"
#include "view.h"
#include "brickview.h"

/**
 * A téglákat reprezentáló osztály.
 */
class Brick : public ICollidable {
    /**
     * A tégla falai.
     */
    std::vector<Wall> walls;

    /**
     * A tégla pozíciója (bal alsó sarok).
     */
    Vector position;

    /**
     * A tégla szélessége.
     */
    float width;

    /**
     * A tégla magassága.
     */
    float height;

    /**
     * Az aktuális játék objektum.
     */
    Game &game;

    /**
     * Az aktuális emgjelenítõ objektum.
     */
    View &view;

    /**
     * A tégla saját megjelenítõ objektuma.
     *
     * Azért csak pointert tárolunk, mivel a View-ban ugyan ezt az
     * objektumot menedzselt körülmények köüzött tároljuk, így a
     * megszüntetésére ott kerül majd sor.
     * Itt azért van rá mégis szükség, hogy tudjunk jelezni, hogy
     * mikor kell megszüntetni (ezzel az objektummal együtt) a
     * megjelenítõt is.
     */
    BrickView *myView;

    /**
     * Annak a falnak a sorszáma, aminek esélye van részt venni a következõ ütközésben.
     */
    int collidedNum;

public:
    /**
     * A konstruktor.
     *
     * Létrehozza a téglához tartozó falakat, és a megjelenítõt is. A megjelenítõt
     * mejegyzi a View objektumba.
     *
     * @param x A pozíció x koordinátája.
     * @param y A pozíció y koordinátája.
     * @param width A tégla szélessége.
     * @param height A tégle magassága.
     * @param game A játék objektum.
     * @param view A megjelenítõ objektum.
     */
    Brick(float x, float y, float width, float height, Game& game, View& view);

    /**
     * A destruktor.
     *
     * Jelzi a View-nak hogy megszüntetheti az ehhez tartozó megjelenítõt.
     */
    ~Brick();

    /**
     * Az ütközésdetektáló függvény.
     *
     * Visszatér a labdához legközelebbi fal távolságával.
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
     *
     * @param start A labda helye.
     * @param speed A labda sebessége.
     * @param time A maximális távolság.
     * @param dist Az elõzõleg kiszámolt távolság.
     */
    void doCollide(Vector &start, Vector &speed, float &time, float dist) override final;
};

#endif // BRICK_H_INCLUDED
