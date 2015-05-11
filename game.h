#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <vector>
#include <memory>

#include "isteppable.h"
#include "icollidable.h"
#include "wall.h"
#include "view.h"

class Game {
    std::shared_ptr<ISteppable> ball;
//    Pad pad;
    std::vector<std::shared_ptr<ICollidable>> objects;

    int points;

    void addObject(ICollidable *elem);

public:
    Game(View& view);

    Game(const Game& other) = delete;
    Game& operator= (const Game& other) = delete;

    std::vector<std::shared_ptr<ICollidable>> getCollidables();

    void step(float elapsed);
};

#endif // GAME_H_INCLUDED
