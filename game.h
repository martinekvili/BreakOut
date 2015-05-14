#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <vector>
#include <memory>
#include <algorithm>

#include "icollidable.h"
#include "wall.h"
#include "ball.h"
#include "pad.h"

class View;

/**
 * A játékot reprezentáló osztály.
 */
class Game {
public:
    /**
     * A játék állapotai.
     */
    enum GameState {
        notstarted,
        running,
        won,
        lost
    };

private:
    /**
     * A megjelenítõ objektum.
     */
    View& view;

    /**
     * Az aktuális labda.
     */
    std::shared_ptr<Ball> ball;

    /**
     * Az ütõ.
     *
     * Azért van szükség, hogy külön is ismerjük, hogy elérjük a plusz
     * funkcionalitását.
     */
    std::shared_ptr<Pad> pad;

    /**
     * Az ütközhetõ objektumok.
     */
    std::vector<std::shared_ptr<ICollidable>> objects;

    /**
     * A játék jelenlegi állapota.
     */
    GameState gameState;

    /**
     * A még meglévõ téglák száma.
     */
    int brickCounter;

    /**
     * A pontok számlálója.
     */
    int points;

    /**
     * A meglévõ életek száma.
     */
    int lives;

    /**
     * A körök számlálója.
     */
    int round;

    /**
     * Új ütközhetõ objektumot hozzáadó függvény.
     * @param elem Az objektum pointere.
     * @param isCounted Növejlük-e a brickCounter-t.
     */
    void addObject(std::shared_ptr<ICollidable> elem, bool isCounted = false);

    /**
     * A pályát felépítõ függvény.
     * @param view A megjelenítõ.
     */
    void buildWall(View& view);

public:
    /**
     * A konstruktor.
     *
     * Felépíti a pályát, létrehozza a labdát és az ütõt.
     *
     * @param view A megjelenítõ.
     * @param points A pontok száma (alapértelmezetten 0).
     * @param lives Az életek száma (alapértelmezetten 5).
     * @param round A kör sorszáma (alapértelmezetten 0).
     */
    Game(View& view, int points = 0, int lives = 5, int round = 0);

    /**
     * Az ütközhetõ objektumokkat megadó függvény.
     * @return Az ütközhetõ objektumok listája.
     */
    std::vector<std::shared_ptr<ICollidable>> getCollidables() { return objects; }

    /**
     * Az animáló függvény.
     *
     * Tulajdonképpen csak tovább hív a labda animáló függvényébe,
     * lévén nincs más animált objektum.
     *
     * @param elapsed Az eltelt idõ másodpercben.
     */
    void step(float elapsed);

    /**
     * Az ütõ helyét beállítõ függvény.
     * @param x Az x koordináta.
     * @param y Az y koordináta.
     */
    void setPadPosition(float x, float y);

    /**
     * A játékállapotot beállító függvény.
     * @param state A beállítandó állapot.
     */
    void setGameState(GameState state) { gameState = state; }

    /**
     * A játékállapotot lekérõ függvény.
     * @return Az aktuális állapot.
     */
    GameState getGameState() { return gameState; }

    /**
     * Az ütközhetõ objektumot kitörlõ függvény.
     * @param A kitörlendõ objektum.
     */
    void removeObject(ICollidable *elem);

    /**
     * A pontokat növelõ függvény.
     */
    void incrementPoints() { points += 10; }

    /**
     * A pontokat lekérdezõ függvény.
     * @return A pontok száma.
     */
    int getPoints() { return points; }

    /**
     * Az életeket csökkentõ függvény.
     */
    void decrementLives();

    /**
     * Az életeket lekérdezõ függvény.
     * @return Az életek száma.
     */
    int getLives() { return lives; }

    /**
     * A kör sorszámát lekérdezõ függvény.
     * @return A kör sorszáma.
     */
    int getRound() { return round; }
};

#endif // GAME_H_INCLUDED
