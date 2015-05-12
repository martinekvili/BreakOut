#include "brickview.h"

void BrickView::draw() {
    Graphics::drawRect(position.x, position.y, width, height, Graphics::Color{1.0, 0, 0});
}
