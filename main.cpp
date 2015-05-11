#include <iostream>

#include "graphics.h"
#include "game.h"
#include "view.h"

int main(int argc, char **argv) {
    //float x = 0, y = 0;
    View view{};
    Game game{view};

    Graphics::setValues(960, 540, 160, 90);

    auto paintCallback = [&view] { view.draw(); };
    auto tickCallback = [&game] (float elapsed) { game.step(elapsed); };
    auto mouseMotionCallback = [&game] (float x, float y) { game.setPadPosition(x, y); };

    Graphics::setCallbacks( paintCallback,
                            mouseMotionCallback,
                            tickCallback );

    Graphics::initialize(&argc, argv);
}
