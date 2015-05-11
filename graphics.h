#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <functional>
#include <cmath>

class Graphics {
    static int screenWidth, screenHeight;
    static int worldWidth, worldHeight;

    static int startTime;

    static std::function<void()> onDisplayCallback;
    static std::function<void(float, float)> mouseMotionCallback;
    static std::function<void(float)> idleCallback;

    static void onKeyboard(unsigned char key, int x, int y);
    static void onKeyboardUp(unsigned char key, int x, int y);
    static void onMouse(int button, int state, int x, int y);
    static void onMouseMotion(int x, int y);

    static void onDisplay();
    static void onIdle();

public:
    struct Color {
        float r, g, b;

        Color(float r, float g, float b) : r{r}, g{g}, b{b} {}
    };

    static void setValues(int screenWidth, int screenHeight, int worldWidth, int worldHeight);
    static void setCallbacks(std::function<void()> onDisplayCallback,
                             std::function<void(float, float)> mouseMotionCallback,
                             std::function<void(float)> idleCallback);

    static void initialize(int* argc, char** argv);

    static void drawRect(float x, float y, float width, float height, Color color);
    static void drawCircle(float x, float y, float r, Color color);
};

#endif // GRAPHICS_H_INCLUDED
