#ifndef BAYMAX_BUFFER_H
#define BAYMAX_BUFFER_H


#include <GL/glew.h>

namespace baymax {
namespace graphics {

class Buffer
{

public:
    Buffer(GLfloat* data, GLsizei count, GLuint componentCount);

    void bind() const;
    void unbind() const;

    inline GLuint getComponentCount() const { return m_ComponentCount; }

private:
    GLuint m_BufferID;
    GLuint m_ComponentCount;

};

} }

#endif //BAYMAX_BUFFER_H
