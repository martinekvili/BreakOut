#include <iostream>
#include <sstream>
#include <string>

#include <windows.h>

#include "graphics.h"
#include "game.h"
#include "view.h"

int main(int argc, char **argv) {
    //float x = 0, y = 0;
    View view{};
    Game game{view};

    long start = GetTickCount();
    int cntr = 0;
    std::stringstream ss;

    Graphics::setValues(960, 540, 160, 90);

    auto paintCallback = [&view, &game, start, &cntr, &ss] {
                                switch (game.getGameState()) {
                                    case Game::GameState::notstarted :
                                    case Game::GameState::running :
                                        view.draw();
                                        ss << (float) cntr++ / (GetTickCount() - start) * 1000;
                                        Graphics::drawText(10, 80, ss.str().c_str());
                                        ss.str("");
                                        break;

                                    case Game::GameState::lost :
                                        Graphics::drawText(80, 40, "Game over");
                                        break;

                                    case Game::GameState::won :
                                        Graphics::drawText(80, 40, "You won!");
                                        break;
                                }
                                };

    auto tickCallback = [&game, &view] (float elapsed) {
                            if (game.getGameState() == Game::GameState::won) {
                                //game = Game{view, game.getPoints()};
                            } else {
                                game.step(elapsed);
                            }
                            };

    auto mouseMotionCallback = [&game] (float x, float y) { game.setPadPosition(x, y); };

    auto leftClickCallback = [&game] (float x, float y) { game.setGameState(Game::GameState::running); };

    Graphics::setCallbacks( paintCallback,
                            mouseMotionCallback,
                            leftClickCallback,
                            tickCallback );

    Graphics::initialize(&argc, argv);

    std::cout << "ide" << std::endl;
}
