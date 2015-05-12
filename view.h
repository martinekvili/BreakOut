#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED

#include <vector>
#include <memory>
#include <algorithm>

#include "idrawable.h"

class View {
    std::vector<std::shared_ptr<IDrawable>> objects;

public:
    void addDrawable(IDrawable *elem);
    void removeDrawable(IDrawable *elem);

    void draw();
};

#endif // VIEW_H_INCLUDED
