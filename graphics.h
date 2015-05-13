#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include <GL/gl.h>
#include <GL/freeglut.h>
#include <functional>
#include <cmath>

/**
 * A grafik�t kezel� oszt�ly.
 *
 * Egy minimalista API-t biztos�t az OpenGL �s a GLUT felett.
 * Statikusnak kell lennie, hogy a met�dusokat �tadhassuk az
 * OpenGL-nek callback f�ggv�nyk�nt.
 */
class Graphics {
    /**
     * A vil�g sz�less�ge.
     */
    static int worldWidth;

    /**
     * A vil�g magass�ga.
     */
    static int worldHeight;

    /**
     * Az utols� leszimul�lt id�pont.
     */
    static int startTime;

    /**
     * Flag, ami jelzi, hogy fut-e m�g a program.
     */
    static bool running;

    /**
     * A kirajzol� callback f�ggv�ny.
     */
    static std::function<void()> onDisplayCallback;

    /**
     * Az eg�rmozg�sra h�vott callback f�ggv�ny.
     */
    static std::function<void(float, float)> mouseMotionCallback;

    /**
     * Az anim�l�shoz haszn�lt callback f�ggv�ny.
     */
    static std::function<void(float)> idleCallback;

    /**
     * A balklikk callback f�ggv�nye.
     */
    static std::function<void()> leftClickCallback;

    /**
     * Az OpenGL-nek �tadott eg�rkattint�st kezel� callback.
     */
    static void onMouse(int button, int state, int x, int y);

    /**
     * Az OpenGL-nek �tadott eg�rmozg�st kezel� callback.
     */
    static void onMouseMotion(int x, int y);

    /**
     * Az OpenGL-nek �tadott ablakbez�r�st kezel� callback.
     */
    static void onClose();

    /**
     * Az OpenGL-nek �tadott megjelen�t�st v�gz� callback.
     */
    static void onDisplay();

    /**
     * Az OpenGL-nek �tadott id�z�tett callback.
     */
    static void onTick(int);

public:
    /**
     * Sz�n strukt�ra.
     *
     * Csup�n egys�gbez�r�s szerepe van.
     */
    struct Color {
        float r, g, b;

        Color(float r, float g, float b) : r{r}, g{g}, b{b} {}
    };

    /**
     * A vil�g �rt�keit be�ll�t� f�ggv�ny.
     * @param worldWidth A vil�g sz�les�ge.
     * @param wolrdHeight A vil�g magass�ga.
     */
    static void setWorld(int worldWidth, int worldHeight);

    /**
     * A callback f�ggv�nyeket be�ll�t� f�ggv�ny.
     * @param onDisplayCallback A kirajzol�st v�gz� callback.
     * @param mouseMotionCallback Az eg�rmozg�st kezel� callback.
     * @param leftClickCallback A kattint�st kezel� callback.
     * @param idleCallback Az anim�l�st kezel� callback.
     */
    static void setCallbacks(std::function<void()> onDisplayCallback,
                             std::function<void(float, float)> mouseMotionCallback,
                             std::function<void()> leftClickCallback,
                             std::function<void(float)> idleCallback);

    /**
     * Az inicializ�l� f�ggv�ny.
     * @param screenWidth A kezdeti ablak sz�less�ge.
     * @param screenHeight A kezdeti ablak magass�ga.
     */
    static void initialize(int* argc, char** argv, int screenWidth, int screenHeight);

    /**
     * T�glalapot rajzol� f�ggv�ny.
     * @param x Az x koordin�ta.
     * @param y Az y koordin�ta.
     * @param width A t�glalap sz�less�ge.
     * @param heigth A t�glalap magass�ga.
     * @param color A sz�n.
     */
    static void drawRect(float x, float y, float width, float height, Color color);

    /**
     * K�rt rajzol� f�ggv�ny.
     * @param x Az x koordin�ta.
     * @param y Az y koordin�ta.
     * @param r A k�r sugara.
     * @param color A sz�n.
     */
    static void drawCircle(float x, float y, float r, Color color);

    /**
     * Sz�veget ki�r� f�ggv�ny.
     * @param x Az x koordin�ta.
     * @param y Az y koordin�ta.
     * @param text A ki�rand� sz�veg.
     */
    static void drawText(float x, float y, const char* text);
};

#endif // GRAPHICS_H_INCLUDED
