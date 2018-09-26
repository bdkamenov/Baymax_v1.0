#ifndef BAYMAX_INDEXBUFFER_H
#define BAYMAX_INDEXBUFFER_H

#include <GL/glew.h>

namespace baymax {
namespace graphics {

class IndexBuffer
{

public:
    IndexBuffer(GLushort* data, GLsizei count);

    void bind() const;
    void unbind() const;

    inline GLuint getCount() const { return m_Count; }

private:
    GLuint m_BufferID;
    GLuint m_Count;

};

} }

#endif //BAYMAX_INDEXBUFFER_H
