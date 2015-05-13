#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include <GL/gl.h>
#include <GL/freeglut.h>
#include <functional>
#include <cmath>

/**
 * A grafikát kezeló osztály.
 *
 * Egy minimalista API-t biztosít az OpenGL és a GLUT felett.
 * Statikusnak kell lennie, hogy a metódusokat átadhassuk az
 * OpenGL-nek callback függvényként.
 */
class Graphics {
    /**
     * A világ szélessége.
     */
    static int worldWidth;

    /**
     * A világ magassága.
     */
    static int worldHeight;

    /**
     * Az utolsó leszimulált idõpont.
     */
    static int startTime;

    /**
     * Flag, ami jelzi, hogy fut-e még a program.
     */
    static bool running;

    /**
     * A kirajzoló callback függvény.
     */
    static std::function<void()> onDisplayCallback;

    /**
     * Az egérmozgásra hívott callback függvény.
     */
    static std::function<void(float, float)> mouseMotionCallback;

    /**
     * Az animáláshoz használt callback függvény.
     */
    static std::function<void(float)> idleCallback;

    /**
     * A balklikk callback függvénye.
     */
    static std::function<void()> leftClickCallback;

    /**
     * Az OpenGL-nek átadott egérkattintást kezelõ callback.
     */
    static void onMouse(int button, int state, int x, int y);

    /**
     * Az OpenGL-nek átadott egérmozgást kezelõ callback.
     */
    static void onMouseMotion(int x, int y);

    /**
     * Az OpenGL-nek átadott ablakbezárást kezelõ callback.
     */
    static void onClose();

    /**
     * Az OpenGL-nek átadott megjelenítést végzõ callback.
     */
    static void onDisplay();

    /**
     * Az OpenGL-nek átadott idõzített callback.
     */
    static void onTick(int);

public:
    /**
     * Szín struktúra.
     *
     * Csupán egységbezárás szerepe van.
     */
    struct Color {
        float r, g, b;

        Color(float r, float g, float b) : r{r}, g{g}, b{b} {}
    };

    /**
     * A világ értékeit beállító függvény.
     * @param worldWidth A világ szélesége.
     * @param wolrdHeight A világ magassága.
     */
    static void setWorld(int worldWidth, int worldHeight);

    /**
     * A callback függvényeket beállító függvény.
     * @param onDisplayCallback A kirajzolást végzõ callback.
     * @param mouseMotionCallback Az egérmozgást kezelõ callback.
     * @param leftClickCallback A kattintást kezelõ callback.
     * @param idleCallback Az animálást kezelõ callback.
     */
    static void setCallbacks(std::function<void()> onDisplayCallback,
                             std::function<void(float, float)> mouseMotionCallback,
                             std::function<void()> leftClickCallback,
                             std::function<void(float)> idleCallback);

    /**
     * Az inicializáló függvény.
     * @param screenWidth A kezdeti ablak szélessége.
     * @param screenHeight A kezdeti ablak magassága.
     */
    static void initialize(int* argc, char** argv, int screenWidth, int screenHeight);

    /**
     * Téglalapot rajzoló függvény.
     * @param x Az x koordináta.
     * @param y Az y koordináta.
     * @param width A téglalap szélessége.
     * @param heigth A téglalap magassága.
     * @param color A szín.
     */
    static void drawRect(float x, float y, float width, float height, Color color);

    /**
     * Kört rajzoló függvény.
     * @param x Az x koordináta.
     * @param y Az y koordináta.
     * @param r A kör sugara.
     * @param color A szín.
     */
    static void drawCircle(float x, float y, float r, Color color);

    /**
     * Szöveget kiíró függvény.
     * @param x Az x koordináta.
     * @param y Az y koordináta.
     * @param text A kiírandó szöveg.
     */
    static void drawText(float x, float y, const char* text);
};

#endif // GRAPHICS_H_INCLUDED
