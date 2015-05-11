#include <iostream>

#include "graphics.h"

int main(int argc, char **argv) {
    float x = 0, y = 0;

    Graphics::setValues(960, 540, 160, 90);
    Graphics::setCallbacks(
                [&x, &y] {
                    Graphics::drawCircle(x, y, 2.5, Graphics::Color{1.0, 0, 0});
                    Graphics::drawRect(x - 10, 0, 20, 5, Graphics::Color(0, 1.0, 0));
                },
                [&x, &y] (float xo, float yo) {
                    x = xo; y = yo;
                });

    Graphics::initialize(&argc, argv);
}
