#include "view.h"

void View::addDrawable(IDrawable *elem) {
    objects.push_back(std::shared_ptr<IDrawable>{elem});
}

void View::draw() {
    for (auto elem : objects) {
        elem->draw();
    }
}
