#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED

#include <vector>
#include <memory>
#include <algorithm>
#include <sstream>
#include <string>

#include "idrawable.h"
#include "game.h"

/**
 * A megjelenítõ osztály.
 */
class View {
    /**
     * A megjelenítendõ objektumok.
     */
    std::vector<std::shared_ptr<IDrawable>> objects;

    /**
     * A játék amit megjelenítünk.
     */
    Game *game;

public:
    /**
     * Konstruktor.
     */
    View() : game{nullptr} {}

    /**
     * Kirajzolható objektumot hozzáadó függvény.
     *
     * Becsomagolja a pointert, és hozzáadja a vectorhoz.
     *
     * @param elem A hozzáadandó objektum.
     */
    void addDrawable(std::shared_ptr<IDrawable> elem);

    /**
     * Kirajzolható objektumot törlõ függvény.
     * @param elem A törlendõ objektum.
     */
    void removeDrawable(std::shared_ptr<IDrawable> elem);

    /**
     * A kirajzoló függvény.
     *
     * Végigmegy minden kirajzolható objektumon, és kirajzolja õket,
     * majd pedig még néhény adatot a játékról: pontszám, életek, stb.
     * Ha már vége a játéknak, akkor pedig a "Game over" képernyõt
     * jeleníti meg.
     */
    void draw();

    /**
     * Egy új játék beállítására szolgáló függvény.
     *
     * Ha új játékot állítunk be, miután már egy másik volt beállítva,
     * akkor törli a teljes objects tömböt.
     */
    void setGame(Game *game);
};

#endif // VIEW_H_INCLUDED
