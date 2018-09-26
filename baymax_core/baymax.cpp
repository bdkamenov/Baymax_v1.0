#include <iostream>
#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>

#include "graphics/window.h"
#include "graphics/shader.h"
#include "graphics/buffers/buffers.h"
#include "maths/maths.h"

using namespace baymax;
using namespace graphics;
using namespace maths;

//int main()
//{
//    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
//    plog::init(plog::debug, &consoleAppender);
//
//    Window window("Baymax", 800, 600);
////    glClearColor(0.7, 0.2, 0.3, 1.0);
//
//
//    GLfloat vertices[] =    // we are using indices so there is no need
//            {               // to duplicate the points to draw them
//            0, 0, 0,
//            0, 3, 0,
//            8, 0, 0,
//            8, 3, 0
//            };
//
//    GLushort indices[] =
//            {
//            0, 1, 2,
//            0, 2, 3
//            };
//
//    VertexArray vao;                              // vertex array object
//    Buffer* vbo = new Buffer(vertices, 4 * 3, 3); // vertex buffer object
//    IndexBuffer ibo(indices, 6);                  // index buffer object
//
//    vao.addBuffer(vbo, 0);
//
//    matr4 ortho = matr4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
//    Shader shader("/home/bkamenov/Programming/projects/Baymax_v1.0/shaders/basic.vert",
//                  "/home/bkamenov/Programming/projects/Baymax_v1.0/shaders/basic.frag");
//    shader.enable();
//    shader.setUniformMat4("pr_matrix", ortho);
//    shader.setUniformMat4("ml_matrix", matr4::translate(vec3(4, 3, 0)));
//
//    shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
//    shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));
//
//    while(!window.closed())
//    {
//        window.clear();
//
//        double x, y;
//        window.getMousePosition(x, y);
//        shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
//
//        vao.bind();
//        ibo.bind();
//
//        glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
//
//        ibo.unbind();
//        vao.unbind();
//        window.update();
//    }
//
//    return 0;
//}

// glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
int main()
{
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::init(plog::debug, &consoleAppender);

    LOG_ERROR << "ERROR" ;
Window window("Sparky!", 960, 540);

#if 0
GLfloat vertices[] =
	{
		0, 0, 0,
		8, 0, 0,
		0, 3, 0,
		0, 3, 0,
		8, 3, 0,
		8, 0, 0
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
#else
GLfloat vertices[] =
        {
                0, 0, 0,
                0, 3, 0,
                8, 3, 0,
                8, 0, 0
        };

GLushort indices[] =
        {
                0, 1, 2,
                2, 3, 0
        };

GLfloat colorsA[] =
        {
                1, 0, 1, 1,
                1, 0, 1, 1,
                1, 0, 1, 1,
                1, 0, 1, 1
        };

GLfloat colorsB[] =
        {
                0.2f, 0.3f, 0.8f, 1,
                0.2f, 0.3f, 0.8f, 1,
                0.2f, 0.3f, 0.8f, 1,
                0.2f, 0.3f, 0.8f, 1
        };

VertexArray sprite1, sprite2;
IndexBuffer ibo(indices, 6);

sprite1.addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
sprite1.addBuffer(new Buffer(colorsA, 4 * 4, 4), 1);

sprite2.addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
sprite2.addBuffer(new Buffer(colorsB, 4 * 4, 4), 1);

#endif

matr4 ortho = matr4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

Shader shader("/home/bkamenov/Programming/projects/Baymax_v1.0/shaders/basic.vert",
                  "/home/bkamenov/Programming/projects/Baymax_v1.0/shaders/basic.frag");
shader.enable();
shader.setUniformMat4("pr_matrix", ortho);
shader.setUniformMat4("ml_matrix", matr4::translate(vec3(4, 3, 0)));

shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));

while (!window.closed())
{
window.clear();
double x, y;
window.getMousePosition(x, y);
shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
#if 0
glDrawArrays(GL_TRIANGLES, 0, 6);
#else
sprite1.bind();
ibo.bind();
shader.setUniformMat4("ml_matrix", matr4::translate(vec3(4, 3, 0)));
glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
ibo.bind();
sprite1.unbind();

LOG_INFO << window.getHeight() << " " << window.getWidth();

sprite2.bind();
ibo.bind();
shader.setUniformMat4("ml_matrix", matr4::translate(vec3(0, 0, 0)));
glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
ibo.bind();
sprite2.unbind();
#endif
window.update();
}

return 0;
}