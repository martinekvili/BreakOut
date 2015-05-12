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
    for (auto elem : objects) {
        elem->draw();
    }
}
