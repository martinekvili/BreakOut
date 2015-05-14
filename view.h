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
 * A megjelen�t� oszt�ly.
 */
class View {
    /**
     * A megjelen�tend� objektumok.
     */
    std::vector<std::shared_ptr<IDrawable>> objects;

    /**
     * A j�t�k amit megjelen�t�nk.
     */
    Game *game;

public:
    /**
     * Konstruktor.
     */
    View() : game{nullptr} {}

    /**
     * Kirajzolhat� objektumot hozz�ad� f�ggv�ny.
     *
     * Becsomagolja a pointert, �s hozz�adja a vectorhoz.
     *
     * @param elem A hozz�adand� objektum.
     */
    void addDrawable(std::shared_ptr<IDrawable> elem);

    /**
     * Kirajzolhat� objektumot t�rl� f�ggv�ny.
     * @param elem A t�rlend� objektum.
     */
    void removeDrawable(std::shared_ptr<IDrawable> elem);

    /**
     * A kirajzol� f�ggv�ny.
     *
     * V�gigmegy minden kirajzolhat� objektumon, �s kirajzolja �ket,
     * majd pedig m�g n�h�ny adatot a j�t�kr�l: pontsz�m, �letek, stb.
     * Ha m�r v�ge a j�t�knak, akkor pedig a "Game over" k�perny�t
     * jelen�ti meg.
     */
    void draw();

    /**
     * Egy �j j�t�k be�ll�t�s�ra szolg�l� f�ggv�ny.
     *
     * Ha �j j�t�kot �ll�tunk be, miut�n m�r egy m�sik volt be�ll�tva,
     * akkor t�rli a teljes objects t�mb�t.
     */
    void setGame(Game *game);
};

#endif // VIEW_H_INCLUDED
