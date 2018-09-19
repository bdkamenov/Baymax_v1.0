#include "UnitTestFramework.h"
#include "../baymax_core/maths/maths.h"

using namespace baymax;
using namespace maths;

TEST_CASE("Vec2", vec2_equal_operator_test)
{
    const vec2 v1(2.f, 3.f);
    const vec2 v2(2.0, 3.0);
    Assert::IsTrue(v1 == v2);
    Assert::IsFalse(v1 != v2);

    const vec2 v3(2.3f, 3.3f);
    Assert::IsTrue(v1 != v3);
    Assert::IsFalse(v1 == v3);
}

TEST_CASE("Vec2", vec2_plus_operator_test)
{
    const vec2 v1(2.f, 3.f);
    const vec2 v2(2.0, 3.0);

    vec2 v3 = v1 + v2;
    Assert::IsTrue(v3 == vec2(4.f, 6.f));
}

TEST_CASE("Vec2", vec2_minus_operator_test)
{
    const vec2 v1(2.f, 3.f);
    const vec2 v2(2.0, 3.0);

    vec2 v4 = v1 - v2;
    Assert::IsTrue(v4 == vec2(0.f, 0.f));
}

TEST_CASE("Vec2", vec2_multy_operator_test)
{
    const vec2 v1(2.f, 3.f);
    const vec2 v2(2.0, 3.0);

    vec2 v5 = v1 * v2;
    Assert::IsTrue(v5 == vec2(4.f, 9.f));
}

TEST_CASE("Vec2", vec2_devide_operator_test)
{
    const vec2 v1(2.f, 3.f);
    const vec2 v2(2.0, 3.0);

    vec2 v6 = v1 / v2;
    Assert::IsTrue(v6 == vec2(1.f, 1.f));
}

TEST_CASE("Vec3", vec3_operators_test)
{
    const vec3 v1(2.f, 3.f, 4.f);
    const vec3 v2(2.0, 3.0, 4.f);
    Assert::IsTrue(v1 == v2);

    vec3 v3 = v1 + v2;
    vec3 v4 = v1 - v2;
    vec3 v5 = v1 * v2;
    vec3 v6 = v1 / v2;

    Assert::IsTrue(v3 == vec3(4.f, 6.f, 8.f));
    Assert::IsTrue(v4 == vec3(0.f, 0.f, 0.f));
    Assert::IsTrue(v5 == vec3(4.f, 9.f, 16.f));
    Assert::IsTrue(v6 == vec3(1.f, 1.f, 1.f));
}

TEST_CASE("Vec4", vec4_operators_test)
{
    const vec4 v1(2.f, 3.f, 4.f, 5.f);
    const vec4 v2(2.0, 3.0, 4.f, 5.f);
    Assert::IsTrue(v1 == v2);

    vec4 v3 = v1 + v2;
    vec4 v4 = v1 - v2;
    vec4 v5 = v1 * v2;
    vec4 v6 = v1 / v2;

    Assert::IsTrue(v3 == vec4(4.f, 6.f, 8.f, 10.f));
    Assert::IsTrue(v4 == vec4(0.f, 0.f, 0.f, 0.f));
    Assert::IsTrue(v5 == vec4(4.f, 9.f, 16.f, 25.f));
    Assert::IsTrue(v6 == vec4(1.f, 1.f, 1.f, 1.f));
}


int main()
{
    RunTests();
}