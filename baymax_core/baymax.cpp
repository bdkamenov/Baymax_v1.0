#include <iostream>
#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>

#include "graphics/window.h"
#include "maths/maths.h"
#include "graphics/shader.h"

using namespace baymax;
using namespace graphics;
using namespace maths;

int main()
{
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::init(plog::debug, &consoleAppender);

    Window window("Baymax", 800, 600);
    glClearColor(0.7, 0.2, 0.3, 1.0);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLfloat vertices[] =
            {
                    -0.5f, -0.5f, 0.0f,
                    0.5f, -0.5f, 0.0f,
                    0.0f,  0.5f, 0.0f
            };

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

   // matr4 ortho = matr4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
    matr4 ortho = matr4::orthographic(0.1f, 1.0f, 1.0f, 1.0f, -1.0f, 1.0f);
    Shader shader("/home/bkamenov/Programming/projects/Baymax_v1.0/shaders/basic.vert",
                  "/home/bkamenov/Programming/projects/Baymax_v1.0/shaders/basic.frag");
    shader.enable();
    shader.setUniformMat4("pr_matrix", ortho);
//    shader.setUniformMat4("ml_matrix", matr4::translate(vec3(4, 3, 0)));
//    shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
//    shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));


    while(!window.closed())
    {
        window.clear();

//        if(window.isButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
//        LOG_INFO << "PRESSED_KEY_A ";
//
//        glBegin(GL_TRIANGLES);
//        glVertex2f(-0.5, -0.5);
//        glVertex2f(0, 0.5);
//        glVertex2f(0.5, -0.5);
//        glEnd();
//
//        glDrawArrays(GL_ARRAY_BUFFER, 0, 6);

        double x, y;
        window.getMousePosition(x, y);
        shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
        glDrawArrays(GL_TRIANGLES, 0, 6);

        window.update();
    }

    return 0;
}