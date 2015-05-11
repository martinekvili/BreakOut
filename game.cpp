#include "game.h"

std::vector<std::shared_ptr<ICollidable>> Game::getCollidables() {
    return objects;
}
