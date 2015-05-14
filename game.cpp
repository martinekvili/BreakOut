#include "game.h"

#include "ball.h"
#include "brick.h"

void Game::addObject(std::shared_ptr<ICollidable> elem, bool isCounted) {
    objects.push_back(elem);

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

    // Ha nem maradt több tégla, akkor nyertünk
    brickCounter--;
    if (brickCounter == 0) {
        gameState = GameState::won;
    }
}

void Game::buildWall(View& view) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            addObject(std::make_shared<Brick>(j * 16.0f + 0.1f, 54.0f + i * 9.0f + 0.1f, 15.8f, 8.8f, *this, view), true);
        }
    }
}

Game::Game(View& view, int points, int lives, int round) :
        view(view), gameState{GameState::notstarted}, brickCounter{0}, points{points}, lives{lives}, round{round} {
    view.setGame(this);

    ball = std::make_shared<Ball>(Vector{80, 4}, Ball::getDefaultSpeedInRound(round), *this, view);

    pad = std::make_shared<Pad>(*this, view);

    addObject(pad);
    addObject(std::make_shared<Wall>(Vector{0, 0}, 90, Wall::Direction::vertical));
    addObject(std::make_shared<Wall>(Vector{160, 0}, 90, Wall::Direction::vertical));
    addObject(std::make_shared<Wall>(Vector{0, 90}, 160, Wall::Direction::horizontal));

    buildWall(view);
}

void Game::step(float elapsed) {
    if (gameState == GameState::running) {
        ball->step(elapsed);
    }
}

void Game::setPadPosition(float x, float y) {
    pad->setPosition(x, y);

    // Ha még nincs elindítva a játék, akkor az ütõvel mozgatjuk a labdát
    if (gameState == GameState::notstarted) {
        ball->setPosition(x, y);
    }
}

void Game::decrementLives() {
    lives--;

    if (lives == 0) {
        gameState = GameState::lost;
    } else {
        // Ha még nincs vége a játéknak, akkor új labdát kapunk
        ball.reset(new Ball{Vector{pad->getPosition().x + 10.0f, pad->getPosition().y + 1.5f},
                                                    Ball::getDefaultSpeedInRound(round), *this, view});

        gameState = GameState::notstarted;
    }
}
