#include "graphics.h"
#include "game.h"
#include "view.h"

/**
 * A program belépési pontja.
 *
 * Ez a függvény szolgál belépési pontként, és controllerként is,
 * azaz õ végzi el a program inicializálását, majd pedig játék közben
 * õ kapja meg a GUI-tõl az információkat, amik alapján mozgatja a modellt,
 * és a kirajzolásnál pedig szintén õ hívja meg a View-t.
 *
 * A grafikus megjelenítõnek adandó callback függvények lambda kifejezések.
 */
int main(int argc, char **argv) {
    // A program megjelenítõje
    View view{};

    /*
     * Maga a játék.
     *
     * Azért van indirekció, mivel ezt cserélgetjük: minden újabb kör
     * újabb játék objektumot jelent.
     */
    std::shared_ptr<Game> game = std::make_shared<Game>(view);

    Graphics::setWorld(160, 90);

    // A kirajzolást kezelõ callback - továbbhív a View-ba.
    auto paintCallback = [&view] { view.draw(); };

    /*
     * Az animálást végzõ callback.
     *
     * Alapesetben csak simán tovább hív a Game-be,
     * kivéve ha lebontottunk mindent, akkor új játékot kezd.
     */
    auto tickCallback = [&game, &view] (float elapsed) {
                            if (game->getGameState() == Game::GameState::won) {
                                game.reset(new Game{view, game->getPoints(), game->getLives(), game->getRound() + 1});
                            } else {
                                game->step(elapsed);
                            }
                        };

    // Az egérmozgást végzõ callback: csak tovább hív a Game-be.
    auto mouseMotionCallback = [&game] (float x, float y) { game->setPadPosition(x, y); };

    // A balklikket kezelõ callback: ha még nem indult el a játék, akkor elindítja.
    auto leftClickCallback = [&game] {
                                if (game->getGameState() == Game::GameState::notstarted) {
                                    game->setGameState(Game::GameState::running);
                                }
                            };

    Graphics::setCallbacks( paintCallback,
                            mouseMotionCallback,
                            leftClickCallback,
                            tickCallback );

    /*
     * A játékot elindító függvényhívás.
     *
     * Akkor és csak akkor tér vissza, amikor a felhasználó
     * ki x-elni az ablakot.
     */
    Graphics::initialize(&argc, argv, 960, 540);
}
