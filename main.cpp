#include <iostream>
#include <sstream>
#include <string>

#include <windows.h>

#include "graphics.h"
#include "game.h"
#include "view.h"

int main(int argc, char **argv) {
    View view{};
    std::shared_ptr<Game> game{new Game{view}};

    long start = GetTickCount();
    int cntr = 0;
    std::stringstream ss;

    Graphics::setWorld(160, 90);

    auto paintCallback = [&view, &game, start, &cntr, &ss] {
                                view.draw();
                                ss << (float) cntr++ / (GetTickCount() - start) * 1000;
                                Graphics::drawText(10, 80, ss.str().c_str());
                                ss.str("");
                            };

    auto tickCallback = [&game, &view] (float elapsed) {
                            if (game->getGameState() == Game::GameState::won) {
                                game.reset(static_cast<Game*>(nullptr));
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

    //std::cout << "ide" << std::endl;
}
