//
// Created by bkamenov on 12.09.18.
//

#ifndef BAYMAX_VEC3_H
#define BAYMAX_VEC3_H

#include <iostream>

namespace baymax {
namespace maths{

struct vec3
{
    friend std::ostream& operator<<(std::ostream& out, const vec3& obj);

    vec3();
    vec3(float x, float y, float z);

    vec3& operator+=(const vec3& rhs);
    vec3& operator-=(const vec3& rhs);
    vec3& operator*=(const vec3& rhs);
    vec3& operator/=(const vec3& rhs);
    bool operator==(const vec3& rhs);
    bool operator!=(const vec3& rhs);

    float _x, _y, _z;
};

vec3 operator+(const vec3& lhs, const vec3& rhs);
vec3 operator-(const vec3& lhs, const vec3& rhs);
vec3 operator*(const vec3& lhs, const vec3& rhs);
vec3 operator/(const vec3& lhs, const vec3& rhs);

} }
#endif //BAYMAX_VEC3_H
