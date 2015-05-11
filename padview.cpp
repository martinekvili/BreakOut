#include "padview.h"

void PadView::draw() {
    Graphics::drawRect(pad.getPosition().x, 0, 20, pad.getPosition().y, Graphics::Color{0, 0, 1.0});
}
