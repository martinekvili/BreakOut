#include "game.h"

#include "ball.h"
#include "brick.h"

void Game::addObject(ICollidable *elem, bool isCounted) {
    objects.push_back(std::shared_ptr<ICollidable>{elem});

    if (isCounted) {
        brickCounter++;
    }
}

void Game::removeObject(ICollidable *elem) {
    auto last = std::remove_if(objects.begin(), objects.end(),
                               [elem] (std::shared_ptr<ICollidable> ptr) {
                                    return ptr.get() == elem;
                               });

    objects.erase(last, objects.end());

    brickCounter--;
}

void Game::buildWall(View& view) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            addObject(new Brick{j * 16.0f + 0.1f, 54.0f + i * 9.0f + 0.1f, 15.8f, 8.8f, *this, view}, true);
        }
    }
}

Game::Game(View& view) : isRunning{true}, brickCounter{0} {
    ball = std::shared_ptr<ISteppable>{new Ball(Vector{80, 20}, Vector{50, 50}, *this, view)};

    pad = new Pad(view);

    addObject(pad);
    addObject(new Wall{Vector{0, 0}, 90, Wall::Direction::vertical});
    addObject(new Wall{Vector{160, 0}, 90, Wall::Direction::vertical});
    //addObject(new Wall{Vector{0, 0}, 160, Wall::Direction::horizontal});
    addObject(new Wall{Vector{0, 90}, 160, Wall::Direction::horizontal});

    buildWall(view);
}

std::vector<std::shared_ptr<ICollidable>> Game::getCollidables() {
    return objects;
}

void Game::step(float elapsed) {
    if (isRunning && brickCounter > 0) {
        ball->step(elapsed);
    }
}

void Game::setPadPosition(float x, float y) {
    pad->setPosition(x, y);
}

void Game::stop() {
    isRunning = false;
}
