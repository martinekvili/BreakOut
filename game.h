#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <vector>
#include <memory>

#include "isteppable.h"
#include "icollidable.h"

class Game {
    std::shared_ptr<ISteppable> ball;
//    Pad pad;
    std::vector<std::shared_ptr<ICollidable>> objects;

    int points;

public:
    //Game();

    Game(const Game& other) = delete;
    Game& operator= (const Game& other) = delete;

    std::vector<std::shared_ptr<ICollidable>> getCollidables();
};

#endif // GAME_H_INCLUDED
