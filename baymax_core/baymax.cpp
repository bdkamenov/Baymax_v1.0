#include <iostream>
#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>

#include "graphics/window.h"
#include "maths/maths.h"


using namespace baymax;
using namespace graphics;
using namespace maths;

int main()
{
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::init(plog::debug, &consoleAppender);

    vec2 a(3.4f, 4.5f);
    vec2 b(3, 3);

    std::cout << a+b << std::endl;

    Window window("Baymax", 800, 600);
    glClearColor(0.7, 0.2, 0.3, 1.0);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(v ao);

    while(!window.closed())
    {
        window.clear();

        if(window.isButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
        LOG_INFO << "PRESSED_KEY_A ";

        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0, 0.5);
        glVertex2f(0.5, -0.5);
        glEnd();

        glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
        window.update();
    }

    return 0;
}