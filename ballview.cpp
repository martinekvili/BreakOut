#include "ballview.h"

void BallView::draw() {
    Graphics::drawCircle(ball.getPosition().x, ball.getPosition().y, 1.5, Graphics::Color(0, 1.0, 0));
}
