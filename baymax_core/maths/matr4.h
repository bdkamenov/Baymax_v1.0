#ifndef BAYMAX_MATR4_H
#define BAYMAX_MATR4_H

#include "vec3.h"
#include "vec4.h"

namespace baymax {
namespace maths {

const int SIZE = 4;

struct matr4  // using colon major ordering because of OpenGL
{
    matr4() = default;
    matr4(float diagonal);
    matr4(const vec4& row0, const vec4& row1, const vec4& row2, const vec4& row3);


    matr4& invert(const matr4& matrix);
    matr4& operator*=(const matr4& other);
    bool operator==(const matr4& rhs);
    bool operator!=(const matr4& rhs);

    static matr4 identity();

    static matr4 orthographic(float left, float right, float bottom, float top, float near, float far);
    static matr4 perspective(float fov, float aspectRatio, float near, float far);

    static matr4 translate(const vec3& translation);
    static matr4 rotate(float angle, const vec3& axis);
    static matr4 scale(const vec3& scale);

    static matr4 transpose(const matr4& matrix);

    union
    {
        // [row + col * 4]
        float elements[SIZE*SIZE];
        vec4 rows[SIZE];
    };
};

matr4 operator*(const matr4& left, const matr4& right);
std::ostream& operator<<(std::ostream& out, const matr4& matrix);

} }
#endif //BAYMAX_MATR4_H
