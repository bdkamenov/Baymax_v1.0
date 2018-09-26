#ifndef BAYMAX_VERTEXARRAY_H
#define BAYMAX_VERTEXARRAY_H

#include <vector>
#include <GL/glew.h>

#include "buffer.h"

namespace baymax {
namespace graphics {

class VertexArray
{

public:
    VertexArray();
    ~VertexArray();

    void addBuffer(Buffer* buffer, GLuint index);

    void bind() const;
    void unbind() const;

private:
    GLuint m_ArrayID;
    std::vector<Buffer*> m_Buffers;
};

} }


#endif //BAYMAX_VERTEXARRAY_H
