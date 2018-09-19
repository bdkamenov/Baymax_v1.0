#ifndef BAYMAX_VEC2_H
#define BAYMAX_VEC2_H

#include <iostream>

namespace baymax {
namespace maths{

struct vec2
{
    friend std::ostream& operator<<(std::ostream& out, const vec2& obj);

    vec2();
    vec2(float x, float y);

    vec2& operator+=(const vec2& rhs);
    vec2& operator-=(const vec2& rhs);
    vec2& operator*=(const vec2& rhs);
    vec2& operator/=(const vec2& rhs);
    bool operator==(const vec2& rhs) const;
    bool operator!=(const vec2& rhs) const;

    float _x, _y;
};

vec2 operator+(const vec2& lhs, const vec2& rhs);
vec2 operator-(const vec2& lhs, const vec2& rhs);
vec2 operator*(const vec2& lhs, const vec2& rhs);
vec2 operator/(const vec2& lhs, const vec2& rhs);

} }

#endif //BAYMAX_VEC2_H
