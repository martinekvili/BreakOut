#include "game.h"

#include "ball.h"
#include "ballview.h"

void Game::addObject(ICollidable *elem) {
    objects.push_back(std::shared_ptr<ICollidable>{elem});
}

Game::Game(View& view) {
    Ball *b = new Ball(Vector{80, 45}, Vector{100, 100}, *this);
    ball = std::shared_ptr<ISteppable>{b};
    view.addDrawable(new BallView(*b));

    addObject(new Wall{0, Wall::Direction::vertical});
    addObject(new Wall{160, Wall::Direction::vertical});
    addObject(new Wall{90, Wall::Direction::horizontal});
    addObject(new Wall{0, Wall::Direction::horizontal});
}

std::vector<std::shared_ptr<ICollidable>> Game::getCollidables() {
    return objects;
}

void Game::step(float elapsed) {
    ball->step(elapsed);
}
