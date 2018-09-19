#include "vec4.h"

#include "mathUtils.h"

namespace baymax {
namespace maths
{

std::ostream& operator<<(std::ostream& out, const vec4& obj)
{
    out << "( " << obj._x << ", " << obj._y << ", " << obj._z << ", " << obj._w << " )";
    return out;
}

baymax::maths::vec4::vec4(): _x(0), _y(0), _z(0), _w(0)
{

}

baymax::maths::vec4::vec4(float x, float y, float z, float w): _x(x), _y(y), _z(z), _w(w)
{

}

vec4& vec4::operator+=(const baymax::maths::vec4& other)
{
    _x += other._x;
    _y += other._y;
    _z += other._z;
    _w += other._w;
    return *this;
}

vec4& vec4::operator-=(const baymax::maths::vec4& other)
{
    _x -= other._x;
    _y -= other._y;
    _z -= other._z;
    _w -= other._w;
    return *this;
}

vec4& vec4::operator*=(const baymax::maths::vec4& other)
{
    _x *= other._x;
    _y *= other._y;
    _z *= other._z;
    _w *= other._w;
    return *this;
}

vec4& vec4::operator/=(const baymax::maths::vec4& other)
{
    _x /= other._x;
    _y /= other._y;
    _z /= other._z;
    _w /= other._w;
    return *this;
}

bool vec4::operator==(const vec4& rhs) const
{
    return areEqual<float>(_x, rhs._x) && areEqual<float>(_y, rhs._y) && areEqual<float>(_z, rhs._z) && areEqual<float>(_w, rhs._w);
}

bool vec4::operator!=(const vec4& rhs) const
{
    return !(*this == rhs);
}

vec4 operator+(const vec4& lhs, const vec4& rhs)
{
    vec4 res(lhs);
    return res+=rhs;
}

vec4 operator-(const vec4& lhs, const vec4& rhs)
{
    vec4 res(lhs);
    return res-=rhs;
}

vec4 operator*(const vec4& lhs, const vec4& rhs)
{
    vec4 res(lhs);
    return res*=rhs;
}

vec4 operator/(const vec4& lhs, const vec4& rhs)
{
    vec4 res(lhs);
    return res/=rhs;
}

} }