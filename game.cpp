#include "game.h"

#include "ball.h"
#include "ballview.h"

void Game::addObject(ICollidable *elem) {
    objects.push_back(std::shared_ptr<ICollidable>{elem});
}

Game::Game(View& view) {
    ball = std::shared_ptr<ISteppable>{new Ball(Vector{80, 45}, Vector{100, 100}, *this, view)};

    pad = new Pad();

    addObject(pad);
    addObject(new Wall{Vector{0, 0}, 90, Wall::Direction::vertical});
    addObject(new Wall{Vector{160, 0}, 90, Wall::Direction::vertical});
    //addObject(new Wall{Vector{0, 0}, 160, Wall::Direction::horizontal});
    addObject(new Wall{Vector{0, 90}, 160, Wall::Direction::horizontal});
}

std::vector<std::shared_ptr<ICollidable>> Game::getCollidables() {
    return objects;
}

void Game::step(float elapsed) {
    ball->step(elapsed);
}

void Game::setPadPosition(float x, float y) {
    pad->setPosition(x, y);
}
