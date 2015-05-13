#include "view.h"

void View::addDrawable(IDrawable *elem) {
    objects.push_back(std::shared_ptr<IDrawable>{elem});
}

void View::removeDrawable(IDrawable *elem) {
    auto last = std::remove_if(objects.begin(), objects.end(),
                               [elem] (std::shared_ptr<IDrawable> ptr) {
                                    return ptr.get() == elem;
                               });

    objects.erase(last, objects.end());
}

void View::draw() {
    std::stringstream ss;

    switch (game->getGameState()) {
        case Game::GameState::notstarted :
        case Game::GameState::running :

            for (auto elem : objects) {
                elem->draw();
            }

            ss << game->getPoints();
            Graphics::drawText(150, 85, ss.str().c_str());

            ss.str("");
            ss << "Stage " << game->getRound() + 1;
            Graphics::drawText(25, 85, ss.str().c_str());

            for (int i = 0; i < game->getLives(); i++) {
                Graphics::drawCircle(10 + i * 2.5, 86.0, 1.0, Graphics::Color{0, 1.0, 0});
            }

            break;

        case Game::GameState::lost :

            Graphics::drawText(78, 42, "Game over");
            ss << "Your score is " << game->getPoints() << " points.";
            Graphics::drawText(71, 38, ss.str().c_str());

            break;

        default:
            break;
    }

}

void View::setGame(Game *g) {
    if (game != nullptr) {
        objects.clear();
    }

    game = g;
}
