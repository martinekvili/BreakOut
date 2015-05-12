#include "brickview.h"

void BrickView::draw() {
    Graphics::drawRect(brick.getPosition().x, brick.getPosition().y, brick.getWidth(), brick.getHeight(), Graphics::Color{1.0, 0, 0});
}
