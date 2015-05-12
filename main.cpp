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

    auto paintCallback = [&view, start, &cntr, &ss] {
                                view.draw();
                                ss << (float) cntr++ / (GetTickCount() - start) * 1000;
                                Graphics::drawText(10, 80, ss.str().c_str());
                                ss.str("");
                                };
    auto tickCallback = [&game] (float elapsed) { game.step(elapsed); };
    auto mouseMotionCallback = [&game] (float x, float y) { game.setPadPosition(x, y); };

    Graphics::setCallbacks( paintCallback,
                            mouseMotionCallback,
                            tickCallback );

    Graphics::initialize(&argc, argv);
}
