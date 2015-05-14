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
 * A j�t�kot reprezent�l� oszt�ly.
 */
class Game {
public:
    /**
     * A j�t�k �llapotai.
     */
    enum GameState {
        notstarted,
        running,
        won,
        lost
    };

private:
    /**
     * A megjelen�t� objektum.
     */
    View& view;

    /**
     * Az aktu�lis labda.
     */
    std::shared_ptr<Ball> ball;

    /**
     * Az �t�.
     *
     * Az�rt van sz�ks�g, hogy k�l�n is ismerj�k, hogy el�rj�k a plusz
     * funkcionalit�s�t.
     */
    std::shared_ptr<Pad> pad;

    /**
     * Az �tk�zhet� objektumok.
     */
    std::vector<std::shared_ptr<ICollidable>> objects;

    /**
     * A j�t�k jelenlegi �llapota.
     */
    GameState gameState;

    /**
     * A m�g megl�v� t�gl�k sz�ma.
     */
    int brickCounter;

    /**
     * A pontok sz�ml�l�ja.
     */
    int points;

    /**
     * A megl�v� �letek sz�ma.
     */
    int lives;

    /**
     * A k�r�k sz�ml�l�ja.
     */
    int round;

    /**
     * �j �tk�zhet� objektumot hozz�ad� f�ggv�ny.
     * @param elem Az objektum pointere.
     * @param isCounted N�vejl�k-e a brickCounter-t.
     */
    void addObject(std::shared_ptr<ICollidable> elem, bool isCounted = false);

    /**
     * A p�ly�t fel�p�t� f�ggv�ny.
     * @param view A megjelen�t�.
     */
    void buildWall(View& view);

public:
    /**
     * A konstruktor.
     *
     * Fel�p�ti a p�ly�t, l�trehozza a labd�t �s az �t�t.
     *
     * @param view A megjelen�t�.
     * @param points A pontok sz�ma (alap�rtelmezetten 0).
     * @param lives Az �letek sz�ma (alap�rtelmezetten 5).
     * @param round A k�r sorsz�ma (alap�rtelmezetten 0).
     */
    Game(View& view, int points = 0, int lives = 5, int round = 0);

    /**
     * Az �tk�zhet� objektumokkat megad� f�ggv�ny.
     * @return Az �tk�zhet� objektumok list�ja.
     */
    std::vector<std::shared_ptr<ICollidable>> getCollidables() { return objects; }

    /**
     * Az anim�l� f�ggv�ny.
     *
     * Tulajdonk�ppen csak tov�bb h�v a labda anim�l� f�ggv�ny�be,
     * l�v�n nincs m�s anim�lt objektum.
     *
     * @param elapsed Az eltelt id� m�sodpercben.
     */
    void step(float elapsed);

    /**
     * Az �t� hely�t be�ll�t� f�ggv�ny.
     * @param x Az x koordin�ta.
     * @param y Az y koordin�ta.
     */
    void setPadPosition(float x, float y);

    /**
     * A j�t�k�llapotot be�ll�t� f�ggv�ny.
     * @param state A be�ll�tand� �llapot.
     */
    void setGameState(GameState state) { gameState = state; }

    /**
     * A j�t�k�llapotot lek�r� f�ggv�ny.
     * @return Az aktu�lis �llapot.
     */
    GameState getGameState() { return gameState; }

    /**
     * Az �tk�zhet� objektumot kit�rl� f�ggv�ny.
     * @param A kit�rlend� objektum.
     */
    void removeObject(ICollidable *elem);

    /**
     * A pontokat n�vel� f�ggv�ny.
     */
    void incrementPoints() { points += 10; }

    /**
     * A pontokat lek�rdez� f�ggv�ny.
     * @return A pontok sz�ma.
     */
    int getPoints() { return points; }

    /**
     * Az �leteket cs�kkent� f�ggv�ny.
     */
    void decrementLives();

    /**
     * Az �leteket lek�rdez� f�ggv�ny.
     * @return Az �letek sz�ma.
     */
    int getLives() { return lives; }

    /**
     * A k�r sorsz�m�t lek�rdez� f�ggv�ny.
     * @return A k�r sorsz�ma.
     */
    int getRound() { return round; }
};

#endif // GAME_H_INCLUDED
