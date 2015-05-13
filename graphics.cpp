#include "graphics.h"

int Graphics::worldWidth = 0, Graphics::worldHeight = 0;
bool Graphics::running = true;

std::function<void()> Graphics::onDisplayCallback = nullptr;
std::function<void(float, float)> Graphics::mouseMotionCallback = nullptr;
std::function<void(float)> Graphics::idleCallback = nullptr;
std::function<void()> Graphics::leftClickCallback = nullptr;
int Graphics::startTime = 0;

void Graphics::onDisplay() {
    glClearColor(0, 0, 0, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    onDisplayCallback();

    glutSwapBuffers();
}

void Graphics::onMouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {     // Balklikk
        leftClickCallback();
    }
}

void Graphics::onMouseMotion(int x, int y) {
    int width_ = glutGet(GLUT_WINDOW_WIDTH);
    int height_ = glutGet(GLUT_WINDOW_HEIGHT);

    mouseMotionCallback( (float) x / width_ * worldWidth,  (1 - (float) y / height_) * worldHeight );
}

void Graphics::onTick(int) {
    if (!running) {
        return;
    }

    int now = glutGet(GLUT_ELAPSED_TIME);

    // Meghívjuk az eltelt másodpercek számával
    idleCallback((float)(now - startTime) / 1000);

    startTime = now;

    glutPostRedisplay();

    glutTimerFunc(16, onTick, 0);
}

void Graphics::onClose() {
    running = false;
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

void Graphics::drawCircle(float x, float y, float r, Color color) {
    glColor3f(color.r, color.g, color.b);

    glBegin(GL_POLYGON);

    for (float t = 0; t <= 2 * 3.141592; t += 0.1) {
        glVertex2f(x + r * cos(t), y + r * sin(t));
    }

    glEnd();
}

void Graphics::drawText(float x, float y, const char* text) {
    glColor3f(1.0, 1.0, 1.0);

    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(1/70.0, 1/70.0, 1/70.0);

    for( const char* p = text; *p != '\0'; p++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
    }

    glPopMatrix();
}

void Graphics::setWorld(int wW, int wH) {
    worldWidth = wW;
    worldHeight = wH;
}

void Graphics::setCallbacks(std::function<void()> oDC,
                            std::function<void(float, float)> mMC,
                            std::function<void()> lCC,
                            std::function<void(float)> iC) {
    onDisplayCallback = oDC;
    mouseMotionCallback = mMC;
    leftClickCallback = lCC;
    idleCallback = iC;
}

void Graphics::initialize(int* argc, char** argv, int screenWidth, int screenHeight) {
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
    glutPassiveMotionFunc(onMouseMotion);
    glutCloseFunc(onClose);

    startTime = glutGet(GLUT_ELAPSED_TIME);
    // Körülbelül 60 fps
    glutTimerFunc(16, onTick, 0);

    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

    glutMainLoop();
}

