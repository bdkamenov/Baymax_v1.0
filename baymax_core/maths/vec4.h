//
// Created by bkamenov on 12.09.18.
//

#ifndef BAYMAX_VEC4_H
#define BAYMAX_VEC4_H

#include <iostream>

namespace baymax {
namespace maths{

struct vec4
{
    friend std::ostream& operator<<(std::ostream& out, const vec4& obj);

    vec4();
    vec4(float x, float y, float z, float w);

    vec4& operator+=(const vec4& rhs);
    vec4& operator-=(const vec4& rhs);
    vec4& operator*=(const vec4& rhs);
    vec4& operator/=(const vec4& rhs);
    bool operator==(const vec4& rhs) const;
    bool operator!=(const vec4& rhs) const;

    float _x, _y, _z, _w;
};

vec4 operator+(const vec4& lhs, const vec4& rhs);
vec4 operator-(const vec4& lhs, const vec4& rhs);
vec4 operator*(const vec4& lhs, const vec4& rhs);
vec4 operator/(const vec4& lhs, const vec4& rhs);

} }

#endif //BAYMAX_VEC4_H
