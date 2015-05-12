#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED

#include <vector>
#include <memory>
#include <algorithm>
#include <sstream>
#include <string>

class Game;

#include "idrawable.h"
#include "game.h"

class View {
    std::vector<std::shared_ptr<IDrawable>> objects;

    Game *game;

public:
    View() : game{nullptr} {}

    void addDrawable(IDrawable *elem);
    void removeDrawable(IDrawable *elem);

    void draw();

    void setGame(Game *game);
};

#endif // VIEW_H_INCLUDED
