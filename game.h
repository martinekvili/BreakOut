#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <iostream>

#include <vector>
#include <memory>
#include <algorithm>

#include "isteppable.h"
#include "icollidable.h"
#include "wall.h"
#include "pad.h"

class View;

class Game {
public:
    enum GameState {
        notstarted,
        running,
        won,
        lost
    };

private:
    View& view;

    std::shared_ptr<ISteppable> ball;
    Pad *pad;
    std::vector<std::shared_ptr<ICollidable>> objects;

    GameState gameState;
    int brickCounter;
    int points;
    int lives;
    int round;

    void addObject(ICollidable *elem, bool isCounted = false);
    void buildWall(View& view);

public:
    Game(View& view, int points = 0, int lives = 5, int round = 0);

    //Game(const Game& other) = default;
    //Game& operator= (const Game& other) = default;

    Game& operator= (Game && other);

    std::vector<std::shared_ptr<ICollidable>> getCollidables();

    void step(float elapsed);
    void setPadPosition(float x, float y);

    void setGameState(GameState state) { gameState = state; }
    GameState getGameState() { return gameState; }

    void removeObject(ICollidable *elem);

    void incrementPoints() { points += 10; }
    int getPoints() { return points; }

    void decrementLives();
    int getLives() { return lives; }

    int getRound() { return round; }
};

#endif // GAME_H_INCLUDED
