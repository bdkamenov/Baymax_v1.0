#ifndef BAYMAX_SHADER_H
#define BAYMAX_SHADER_H

#include "../maths/maths.h"

#include <GL/glew.h>

namespace baymax {
namespace graphics {

class Shader
{
public:

    Shader(const char* vertPath, const char* fragPath);
    ~Shader();

    void setUniform1f(const GLchar* name, float value);
    void setUniform1i(const GLchar* name, int value);
    void setUniform2f(const GLchar* name, const maths::vec2& vector);
    void setUniform3f(const GLchar* name, const maths::vec3& vector);
    void setUniform4f(const GLchar* name, const maths::vec4& vector);
    void setUniformMat4(const GLchar* name, const maths::matr4& matrix);

    void enable() const;
    void disable() const;

private:
    GLuint load();
    GLint getUniformLocation(const GLchar* name);

private:
    const char* _vertPath;
    const char* _fragPath;
    GLuint _shaderId;
};


} }
#endif //BAYMAX_SHADER_H
