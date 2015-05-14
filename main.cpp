#include "graphics.h"
#include "game.h"
#include "view.h"

/**
 * A program bel�p�si pontja.
 *
 * Ez a f�ggv�ny szolg�l bel�p�si pontk�nt, �s controllerk�nt is,
 * azaz � v�gzi el a program inicializ�l�s�t, majd pedig j�t�k k�zben
 * � kapja meg a GUI-t�l az inform�ci�kat, amik alapj�n mozgatja a modellt,
 * �s a kirajzol�sn�l pedig szint�n � h�vja meg a View-t.
 *
 * A grafikus megjelen�t�nek adand� callback f�ggv�nyek lambda kifejez�sek.
 */
int main(int argc, char **argv) {
    // A program megjelen�t�je
    View view{};

    /*
     * Maga a j�t�k.
     *
     * Az�rt van indirekci�, mivel ezt cser�lgetj�k: minden �jabb k�r
     * �jabb j�t�k objektumot jelent.
     */
    std::shared_ptr<Game> game = std::make_shared<Game>(view);

    Graphics::setWorld(160, 90);

    // A kirajzol�st kezel� callback - tov�bbh�v a View-ba.
    auto paintCallback = [&view] { view.draw(); };

    /*
     * Az anim�l�st v�gz� callback.
     *
     * Alapesetben csak sim�n tov�bb h�v a Game-be,
     * kiv�ve ha lebontottunk mindent, akkor �j j�t�kot kezd.
     */
    auto tickCallback = [&game, &view] (float elapsed) {
                            if (game->getGameState() == Game::GameState::won) {
                                game.reset(new Game{view, game->getPoints(), game->getLives(), game->getRound() + 1});
                            } else {
                                game->step(elapsed);
                            }
                        };

    // Az eg�rmozg�st v�gz� callback: csak tov�bb h�v a Game-be.
    auto mouseMotionCallback = [&game] (float x, float y) { game->setPadPosition(x, y); };

    // A balklikket kezel� callback: ha m�g nem indult el a j�t�k, akkor elind�tja.
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
     * A j�t�kot elind�t� f�ggv�nyh�v�s.
     *
     * Akkor �s csak akkor t�r vissza, amikor a felhaszn�l�
     * ki x-elni az ablakot.
     */
    Graphics::initialize(&argc, argv, 960, 540);
}
