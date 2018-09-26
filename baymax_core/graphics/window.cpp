#include "window.h"

#include <plog/Log.h>

namespace baymax
{
namespace graphics {

// callback friend functions

void window_resize(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    Window* win = (Window*) glfwGetWindowUserPointer(window);
    win->_keys[key] = action != GLFW_RELEASE;
}

void button_callback(GLFWwindow* window, int button, int action, int mods)
{
    Window* win = (Window*) glfwGetWindowUserPointer(window);
    win->_buttons[button] = action != GLFW_RELEASE;
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    Window* win = (Window*) glfwGetWindowUserPointer(window);
    win->_mx = xpos;
    win->_my = ypos;
}

Window::Window(const char *title, int width, int height):
                                            _title(title), _width(width),
                                            _height(height), _window(nullptr),
                                            _closed(false)
{
    LOG_VERBOSE << __PRETTY_FUNCTION__;

    if(!init())
    {
        terminate();
    }

    memset(_keys, 0, MAX_KEYS * sizeof(bool));
    memset(_buttons, 0, MAX_MOUSE_BUTTONS * sizeof(bool));
}

Window::~Window()
{
    LOG_VERBOSE << __PRETTY_FUNCTION__;

    terminate();
}

void Window::update()
{
    GLenum error = glGetError();
    if(error != GL_NO_ERROR)
    {
        LOG_ERROR << "OpenGL error: " << error;
    }
    glfwPollEvents();
    glfwSwapBuffers(_window);
}

bool Window::init()
{
    LOG_VERBOSE << __PRETTY_FUNCTION__;

    if(!glfwInit())
    {
        LOG_ERROR << "Graphics Error: Failed to init GLFW!";
        return false;
    }
    else
    {
        LOG_INFO << "Graphics: GLFW successfully init!";
    }

    _window = glfwCreateWindow(_width, _height, _title, nullptr, nullptr);

    if(!_window)
    {
        LOG_ERROR << "Graphics Error: GLFW could not create a window!";
        terminate();
        return false;
    }

    glfwMakeContextCurrent(_window);
    glfwSetWindowUserPointer(_window, this);
    glfwSetWindowSizeCallback(_window, window_resize);
    glfwSetKeyCallback(_window, key_callback);
    glfwSetMouseButtonCallback(_window, button_callback);
    glfwSetCursorPosCallback(_window, cursor_position_callback);

    if(glewInit() != GLEW_OK)   // glew init MUST be after making context
    {
        LOG_ERROR << "Graphics Error: Failed to init GLEW!";
        return false;
    }

    LOG_INFO << "OpenGL: " << glGetString(GL_VERSION);

    return true;
}

bool Window::closed() const
{
    return glfwWindowShouldClose(_window);
}

void Window::clear() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::terminate()
{
    LOG_VERBOSE << __PRETTY_FUNCTION__;

    glfwTerminate();

    LOG_INFO << "Graphics: GLFW successfully terminated!";
}

bool Window::isKeyPressed(unsigned int keycode) const
{
    if(keycode >= MAX_KEYS)
    {
        LOG_ERROR << "Input Error: Keyboard code is out of range!";
        return false;
    }
    else
    {
        return _keys[keycode];
    }
}

bool Window::isButtonPressed(unsigned int button) const
{
    if(button >= MAX_MOUSE_BUTTONS)
    {
        LOG_ERROR << "Input Error: Mousebutton code is out of range!";
        return false;
    }
    else
    {
        return _buttons[button];
    }
}

void Window::getMousePosition(double& x, double& y) const
{
    x = _mx;
    y = _my;
}

}}