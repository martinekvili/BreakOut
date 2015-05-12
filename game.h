#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <iostream>

#include <vector>
#include <memory>
#include <algorithm>

#include "isteppable.h"
#include "icollidable.h"
#include "wall.h"
#include "view.h"
#include "pad.h"

class Game {
public:
    enum GameState {
        notstarted,
        running,
        won,
        lost
    };

private:
    std::shared_ptr<ISteppable> ball;
    Pad *pad;
    std::vector<std::shared_ptr<ICollidable>> objects;

    GameState gameState;
    int brickCounter;
    int points;

    void addObject(ICollidable *elem, bool isCounted = false);
    void buildWall(View& view);

public:
    Game(View& view);

    Game(const Game& other) = delete;
    Game& operator= (const Game& other) = delete;

    std::vector<std::shared_ptr<ICollidable>> getCollidables();

    void step(float elapsed);
    void setPadPosition(float x, float y);

    void setGameState(GameState state) { gameState = state; }
    GameState getGameState() { return gameState; }

    void removeObject(ICollidable *elem);
};

#endif // GAME_H_INCLUDED
