//
// Created by bkamenov on 16.09.18.
//

#ifndef BAYMAX_MATHUTILS_H
#define BAYMAX_MATHUTILS_H

#include <cmath>
#include <limits>

namespace baymax {
namespace maths {

const float PI = 3.14159265358f;


inline float toRadians(float degrees)
{
    return (float)(degrees*(PI/180.0f));
}

inline float toDegrees(float radians)
{
    return (float)(radians*(180.0f/PI));
}

template<typename T>
inline bool areEqual(T a, T b)
{
    return std::abs(a - b) <= std::numeric_limits<T>::epsilon();
}

} }
#endif //BAYMAX_MATHUTILS_H
