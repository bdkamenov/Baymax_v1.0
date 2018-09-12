#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace baymax
{
namespace graphics
{

#define MAX_KEYS          512
#define MAX_MOUSE_BUTTONS 128

class Window
{

    friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    friend void button_callback(GLFWwindow* window, int button, int action, int mods);
    friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

public:
    Window(const char* title, int width, int height);
    ~Window();

    void update();
    void clear() const;
    bool closed() const;

    inline int getWidth() const { return _width; }
    inline int getHeight() const { return _height; }

    /*
     * input methods
     * */
    bool isKeyPressed(unsigned int keycode) const;
    bool isButtonPressed(unsigned int button) const;
    void getMousePosition(double& x, double& y) const;

private:
    bool init();
    void terminate();

private:
    const char* _title;
    int _width, _height;
    GLFWwindow* _window;
    bool _closed;

//      input stuff
    bool _keys[MAX_KEYS];
    bool _buttons[MAX_MOUSE_BUTTONS];
    double _mx, _my;
};
}
}


#endif //WINDOW_H
