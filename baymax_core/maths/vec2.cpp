#include "vec2.h"


namespace baymax {
namespace maths
{

std::ostream& operator<<(std::ostream& out, const vec2& obj)
{
    out << "( " << obj._x << ", " << obj._y << " )";
    return out;
}

baymax::maths::vec2::vec2(): _x(0), _y(0)
{

}

baymax::maths::vec2::vec2(float x, float y): _x(x), _y(y)
{

}

vec2& vec2::operator+=(const baymax::maths::vec2& other)
{
    _x += other._x;
    _y += other._y;
    return *this;
}

vec2& vec2::operator-=(const baymax::maths::vec2& other)
{
    _x -= other._x;
    _y -= other._y;
    return *this;
}

vec2& vec2::operator*=(const baymax::maths::vec2& other)
{
    _x *= other._x;
    _y *= other._y;
    return *this;
}

vec2& vec2::operator/=(const baymax::maths::vec2& other)
{
    _x /= other._x;
    _y /= other._y;
    return *this;
}

bool vec2::operator==(const vec2& rhs)
{
    return _x == rhs._x && _y == rhs._y;
}

bool vec2::operator!=(const vec2& rhs)
{
    return !(*this == rhs);
}

vec2 operator+(const vec2& lhs, const vec2& rhs)
{
    vec2 res(lhs);
    return res+=rhs;
}

vec2 operator-(const vec2& lhs, const vec2& rhs)
{
    vec2 res(lhs);
    return res-=rhs;
}

vec2 operator*(const vec2& lhs, const vec2& rhs)
{
    vec2 res(lhs);
    return res*=rhs;
}

vec2 operator/(const vec2& lhs, const vec2& rhs)
{
    vec2 res(lhs);
    return res/=rhs;
}

} }