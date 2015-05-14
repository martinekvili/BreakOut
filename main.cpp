#include <iostream>
#include <sstream>
#include <string>

#include "graphics.h"
#include "game.h"
#include "view.h"

int main(int argc, char **argv) {
    View view{};
    std::shared_ptr<Game> game = std::make_shared<Game>(view);

    Graphics::setWorld(160, 90);

    auto paintCallback = [&view] {
                                view.draw();
                            };

    auto tickCallback = [&game, &view] (float elapsed) {
                            if (game->getGameState() == Game::GameState::won) {
                                game.reset(new Game{view, game->getPoints(), game->getLives(), game->getRound() + 1});
                            } else {
                                game->step(elapsed);
                            }
                        };

    auto mouseMotionCallback = [&game] (float x, float y) { game->setPadPosition(x, y); };

    auto leftClickCallback = [&game] {
                                if (game->getGameState() == Game::GameState::notstarted) {
                                    game->setGameState(Game::GameState::running);
                                }
                            };

    Graphics::setCallbacks( paintCallback,
                            mouseMotionCallback,
                            leftClickCallback,
                            tickCallback );

    Graphics::initialize(&argc, argv, 960, 540);
}
