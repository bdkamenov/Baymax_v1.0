#include "matr4.h"

#include <cstring>
#include <cmath>

#include "mathUtils.h"

namespace baymax {
namespace maths {

matr4::matr4(float diagonal)
{
    memset(elements, 0, SIZE * SIZE * sizeof(float));
    elements[0 + 0 * 4] = diagonal;
    elements[1 + 1 * 4] = diagonal;
    elements[2 + 2 * 4] = diagonal;
    elements[3 + 3 * 4] = diagonal;
}

matr4::matr4(const vec4& row0, const vec4& row1, const vec4& row2, const vec4& row3)
: rows{row0, row1, row2, row3}
{
}

matr4& matr4::operator*=(const matr4& other)
{
    float data[16];
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            float sum = 0.0f;
            for (int e = 0; e < 4; e++)
            {
                sum += elements[e + row * 4] * other.elements[col + e * 4];
            }
            data[col + row * 4] = sum;
        }
    }

    memcpy(elements, data, 4 * 4 * sizeof(float));
    return *this;
}

bool matr4::operator==(const matr4& rhs)
{
    return rows[0] == rhs.rows[0] && rows[1] == rhs.rows[1] &&
           rows[2] == rhs.rows[2] && rows[3] == rhs.rows[3];
}

bool matr4::operator!=(const matr4& rhs)
{
    return !(*this == rhs);
}

matr4 matr4::identity()
{
    return matr4(1.0f);
}

matr4 matr4::orthographic(float left, float right, float bottom, float top, float near, float far)
{
    matr4 result(1.0f);

    result.elements[0 + 0 * 4] = 2.0f / (right - left);

    result.elements[1 + 1 * 4] = 2.0f / (top - bottom);

    result.elements[2 + 2 * 4] = 2.0f / (near - far);

    result.elements[3 + 0 * 4] = (left + right) / (left - right);
    result.elements[3 + 1 * 4] = (bottom + top) / (bottom - top);
    result.elements[3 + 2 * 4] = (far + near) / (far - near);

    return result;}

matr4 matr4::perspective(float fov, float aspectRatio, float near, float far)
{
    matr4 result(1.0f);

    float q = 1.0f / tan(toRadians(0.5f * fov));
    float a = q / aspectRatio;

    float b = (near + far) / (near - far);
    float c = (2.0f * near * far) / (near - far);

    result.elements[0 + 0 * 4] = a;
    result.elements[1 + 1 * 4] = q;
    result.elements[2 + 2 * 4] = b;
    result.elements[2 + 3 * 4] = -1.0f;
    result.elements[3 + 2 * 4] = c;

    return result;
}

matr4 matr4::translate(const vec3& translation)
{
    matr4 result(1.0f);

    result.elements[0 + 3 * 4] = translation._x;
    result.elements[1 + 3 * 4] = translation._y;
    result.elements[2 + 3 * 4] = translation._z;

    return result;}

matr4 matr4::rotate(float angle, const vec3& axis)
{
    matr4 result(1.0f);

    float r = toRadians(angle);
    float c = cos(r);
    float s = sin(r);
    float omc = 1.0f - c;

    float x = axis._x;
    float y = axis._y;
    float z = axis._z;

    result.elements[0 + 0 * 4] = x * x * omc + c;
    result.elements[0 + 1 * 4] = y * x * omc + z * s;
    result.elements[0 + 2 * 4] = x * z * omc - y * s;

    result.elements[1 + 0 * 4] = x * y * omc - z * s;
    result.elements[1 + 1 * 4] = y * y * omc + c;
    result.elements[1 + 2 * 4] = y * z * omc + x * s;

    result.elements[2 + 0 * 4] = x * z * omc + y * s;
    result.elements[2 + 1 * 4] = y * z * omc - x * s;
    result.elements[2 + 2 * 4] = z * z * omc + c;

    return result;}

matr4 matr4::scale(const vec3& scale)
{
    matr4 result(1.0f);

    result.elements[0 + 0 * 4] = scale._x;
    result.elements[1 + 1 * 4] = scale._y;
    result.elements[2 + 2 * 4] = scale._z;

    return result;}

matr4& matr4::invert(const matr4& matrix)
{
    float temp[16];

    temp[0] = elements[5] * elements[10] * elements[15] -
            elements[5] * elements[11] * elements[14] -
            elements[9] * elements[6] * elements[15] +
            elements[9] * elements[7] * elements[14] +
            elements[13] * elements[6] * elements[11] -
            elements[13] * elements[7] * elements[10];

    temp[4] = -elements[4] * elements[10] * elements[15] +
            elements[4] * elements[11] * elements[14] +
            elements[8] * elements[6] * elements[15] -
            elements[8] * elements[7] * elements[14] -
            elements[12] * elements[6] * elements[11] +
            elements[12] * elements[7] * elements[10];

    temp[8] = elements[4] * elements[9] * elements[15] -
            elements[4] * elements[11] * elements[13] -
            elements[8] * elements[5] * elements[15] +
            elements[8] * elements[7] * elements[13] +
            elements[12] * elements[5] * elements[11] -
            elements[12] * elements[7] * elements[9];

    temp[12] = -elements[4] * elements[9] * elements[14] +
            elements[4] * elements[10] * elements[13] +
            elements[8] * elements[5] * elements[14] -
            elements[8] * elements[6] * elements[13] -
            elements[12] * elements[5] * elements[10] +
            elements[12] * elements[6] * elements[9];

    temp[1] = -elements[1] * elements[10] * elements[15] +
            elements[1] * elements[11] * elements[14] +
            elements[9] * elements[2] * elements[15] -
            elements[9] * elements[3] * elements[14] -
            elements[13] * elements[2] * elements[11] +
            elements[13] * elements[3] * elements[10];

    temp[5] = elements[0] * elements[10] * elements[15] -
            elements[0] * elements[11] * elements[14] -
            elements[8] * elements[2] * elements[15] +
            elements[8] * elements[3] * elements[14] +
            elements[12] * elements[2] * elements[11] -
            elements[12] * elements[3] * elements[10];

    temp[9] = -elements[0] * elements[9] * elements[15] +
            elements[0] * elements[11] * elements[13] +
            elements[8] * elements[1] * elements[15] -
            elements[8] * elements[3] * elements[13] -
            elements[12] * elements[1] * elements[11] +
            elements[12] * elements[3] * elements[9];

    temp[13] = elements[0] * elements[9] * elements[14] -
            elements[0] * elements[10] * elements[13] -
            elements[8] * elements[1] * elements[14] +
            elements[8] * elements[2] * elements[13] +
            elements[12] * elements[1] * elements[10] -
            elements[12] * elements[2] * elements[9];

    temp[2] = elements[1] * elements[6] * elements[15] -
            elements[1] * elements[7] * elements[14] -
            elements[5] * elements[2] * elements[15] +
            elements[5] * elements[3] * elements[14] +
            elements[13] * elements[2] * elements[7] -
            elements[13] * elements[3] * elements[6];

    temp[6] = -elements[0] * elements[6] * elements[15] +
            elements[0] * elements[7] * elements[14] +
            elements[4] * elements[2] * elements[15] -
            elements[4] * elements[3] * elements[14] -
            elements[12] * elements[2] * elements[7] +
            elements[12] * elements[3] * elements[6];

    temp[10] = elements[0] * elements[5] * elements[15] -
            elements[0] * elements[7] * elements[13] -
            elements[4] * elements[1] * elements[15] +
            elements[4] * elements[3] * elements[13] +
            elements[12] * elements[1] * elements[7] -
            elements[12] * elements[3] * elements[5];

    temp[14] = -elements[0] * elements[5] * elements[14] +
            elements[0] * elements[6] * elements[13] +
            elements[4] * elements[1] * elements[14] -
            elements[4] * elements[2] * elements[13] -
            elements[12] * elements[1] * elements[6] +
            elements[12] * elements[2] * elements[5];

    temp[3] = -elements[1] * elements[6] * elements[11] +
            elements[1] * elements[7] * elements[10] +
            elements[5] * elements[2] * elements[11] -
            elements[5] * elements[3] * elements[10] -
            elements[9] * elements[2] * elements[7] +
            elements[9] * elements[3] * elements[6];

    temp[7] = elements[0] * elements[6] * elements[11] -
            elements[0] * elements[7] * elements[10] -
            elements[4] * elements[2] * elements[11] +
            elements[4] * elements[3] * elements[10] +
            elements[8] * elements[2] * elements[7] -
            elements[8] * elements[3] * elements[6];

    temp[11] = -elements[0] * elements[5] * elements[11] +
            elements[0] * elements[7] * elements[9] +
            elements[4] * elements[1] * elements[11] -
            elements[4] * elements[3] * elements[9] -
            elements[8] * elements[1] * elements[7] +
            elements[8] * elements[3] * elements[5];

    temp[15] = elements[0] * elements[5] * elements[10] -
            elements[0] * elements[6] * elements[9] -
            elements[4] * elements[1] * elements[10] +
            elements[4] * elements[2] * elements[9] +
            elements[8] * elements[1] * elements[6] -
            elements[8] * elements[2] * elements[5];

    float determinant = elements[0] * temp[0] + elements[1] * temp[4] + elements[2] * temp[8] + elements[3] * temp[12];
    determinant = 1.0f / determinant;

    for (int i = 0; i < 4 * 4; i++)
        elements[i] = temp[i] * determinant;

    return *this;
}

matr4 matr4::transpose(const matr4& matrix)
{
    return matr4(
            vec4(matrix.rows[0]._x, matrix.rows[1]._x, matrix.rows[2]._x, matrix.rows[3]._x),
            vec4(matrix.rows[0]._y, matrix.rows[1]._y, matrix.rows[2]._y, matrix.rows[3]._y),
            vec4(matrix.rows[0]._z, matrix.rows[1]._z, matrix.rows[2]._z, matrix.rows[3]._z),
            vec4(matrix.rows[0]._w, matrix.rows[1]._w, matrix.rows[2]._w, matrix.rows[3]._w)
    );
}

matr4 operator*(const matr4& lhs, const matr4& rhs)
{
    matr4 res(lhs);
    res *= rhs;
    return res;
}

std::ostream& operator<<(std::ostream& out, const matr4& matrix)
{
    out << matrix.rows[0] << std::endl
        << matrix.rows[1] << std::endl
        << matrix.rows[2] << std::endl
        << matrix.rows[3] << std::endl;

    return out;
}

} }
