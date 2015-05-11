#include <iostream>

#include "graphics.h"
#include "game.h"
#include "view.h"

int main(int argc, char **argv) {
    //float x = 0, y = 0;
    View view{};
    Game game{view};

    Graphics::setValues(960, 540, 160, 90);
    /*Graphics::setCallbacks(
                [&x, &y] {
                    Graphics::drawCircle(x, y, 2.5, Graphics::Color{1.0, 0, 0});
                    Graphics::drawRect(x - 10, 0, 20, 5, Graphics::Color(0, 1.0, 0));
                },
                [&x, &y] (float xo, float yo) {
                    x = xo; y = yo;
                });*/

    auto paintCallback = [&view] { view.draw(); };
    auto idleCallback = [&game] (float elapsed) { game.step(elapsed); };
    auto mouseMotionCallback = [&game] (float x, float y) { game.setPadPosition(x, y); };

    Graphics::setCallbacks( paintCallback,
                            mouseMotionCallback,
                            idleCallback );

    Graphics::initialize(&argc, argv);
}
