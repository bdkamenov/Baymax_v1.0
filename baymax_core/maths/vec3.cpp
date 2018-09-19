#include "vec3.h"

#include "mathUtils.h"

namespace baymax {
namespace maths
{

std::ostream& operator<<(std::ostream& out, const vec3& obj)
{
    out << "( " << obj._x << ", " << obj._y << ", " << obj._z << " )";
    return out;
}

baymax::maths::vec3::vec3(): _x(0), _y(0), _z(0)
{

}

baymax::maths::vec3::vec3(float x, float y, float z): _x(x), _y(y), _z(z)
{

}

vec3& vec3::operator+=(const baymax::maths::vec3& other)
{
    _x += other._x;
    _y += other._y;
    _z += other._z;
    return *this;
}

vec3& vec3::operator-=(const baymax::maths::vec3& other)
{
    _x -= other._x;
    _y -= other._y;
    _z -= other._z;
    return *this;
}

vec3& vec3::operator*=(const baymax::maths::vec3& other)
{
    _x *= other._x;
    _y *= other._y;
    _z *= other._z;
    return *this;
}

vec3& vec3::operator/=(const baymax::maths::vec3& other)
{
    _x /= other._x;
    _y /= other._y;
    _z /= other._z;
    return *this;
}

bool vec3::operator==(const vec3& rhs) const
{
    return areEqual<float>(_x, rhs._x) && areEqual<float>(_y, rhs._y) && areEqual<float>(_z, rhs._z);
}

bool vec3::operator!=(const vec3& rhs) const
{
    return !(*this == rhs);
}

vec3 operator+(const vec3& lhs, const vec3& rhs)
{
    vec3 res(lhs);
    return res+=rhs;
}

vec3 operator-(const vec3& lhs, const vec3& rhs)
{
    vec3 res(lhs);
    return res-=rhs;
}

vec3 operator*(const vec3& lhs, const vec3& rhs)
{
    vec3 res(lhs);
    return res*=rhs;
}

vec3 operator/(const vec3& lhs, const vec3& rhs)
{
    vec3 res(lhs);
    return res/=rhs;
}

} }