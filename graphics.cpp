#include "graphics.h"

int Graphics::screenWidth = 0, Graphics::screenHeight = 0;
int Graphics::worldWidth = 0, Graphics::worldHeight = 0;

std::function<void()> Graphics::onDisplayCallback = nullptr;
std::function<void(float, float)> Graphics::mouseMotionCallback = nullptr;

void Graphics::onDisplay( ) {
    glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    onDisplayCallback();

    glutSwapBuffers();
}

void Graphics::onKeyboard(unsigned char key, int x, int y) {
}

void Graphics::onKeyboardUp(unsigned char key, int x, int y) {
}

void Graphics::onMouse(int button, int state, int x, int y) {
}

void Graphics::onMouseMotion(int x, int y) {
    mouseMotionCallback( (float) x / screenWidth * worldWidth,  (1 - (float) y / screenHeight) * worldHeight );

    glutPostRedisplay();
}

void Graphics::onIdle() {
}

void Graphics::drawRect(float x, float y, float width, float height, Color color) {
    glColor3f(color.r, color.g, color.b);

    glBegin(GL_QUADS);

    glVertex2f(x, y);
    glVertex2f(x, y + height);
    glVertex2f(x + width, y + height);
    glVertex2f(x + width, y);

    glEnd();
}

void Graphics::setValues(int sW, int sH, int wW, int wH) {
    screenWidth = sW;
    screenHeight = sH;
    worldWidth = wW;
    worldHeight = wH;
}

void Graphics::setCallbacks(std::function<void()> oDC, std::function<void(float, float)> mMC) {
    onDisplayCallback = oDC;
    mouseMotionCallback = mMC;
}

void Graphics::initialize(int* argc, char** argv) {
    glutInit(argc, argv);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);	// 8 bites R,G,B,A + dupla buffer + melyseg buffer

    glutCreateWindow("BreakOut Game");

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, worldWidth, 0, worldHeight);

    glViewport(0, 0, screenWidth, screenHeight);


    glutDisplayFunc(onDisplay);
    glutMouseFunc(onMouse);
    glutIdleFunc(onIdle);
    glutKeyboardFunc(onKeyboard);
    glutKeyboardUpFunc(onKeyboardUp);
    glutPassiveMotionFunc(onMouseMotion);

    glutMainLoop();
}

