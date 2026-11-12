#include <gtest/gtest.h>
#include <vector>
#include <cmath>

#include "vec3.hpp"

namespace{
  constexpr double EPSILON = 1e-9;
  
  void expectVecNear(const vec3& expected, const vec3& actual) {
    EXPECT_NEAR(expected.m_x, actual.m_x, EPSILON);
    EXPECT_NEAR(expected.m_y, actual.m_y, EPSILON);
    EXPECT_NEAR(expected.m_z, actual.m_z, EPSILON);
  }

  TEST(Vec3Tests, EqualityOperatorReturnsTrueForEqualVectors){
    EXPECT_EQ(vec3(1, 2, 3), vec3(1, 2, 3));
    EXPECT_EQ(vec3(3, 2, 1), vec3(3, 2, 1));
    EXPECT_EQ(vec3(32.25, 13.35, 24.79), vec3(32.25, 13.35, 24.79));
  }

  TEST(Vec3Tests, IndexOperatorReturnsCorrectComponent){
    std::vector<vec3> _ = {vec3(1, 2, 3), vec3(2, 3, 4), vec3(12, 23, 81), vec3(1.12, 412.12231, 891.1897391)};
    EXPECT_NEAR(1, _[0].m_x, EPSILON);
    EXPECT_NEAR(4, _[1].m_z, EPSILON);
    EXPECT_NEAR(23, _[2].m_y, EPSILON);
    EXPECT_NEAR(412.12231, _[3].m_y, EPSILON); 
    EXPECT_NEAR(891.1897391, _[3].m_z, EPSILON);
  }
  
  TEST(Vec3Tests, AdditionAndSubtractionOperatorsProduceCorrectResults){
    static_assert(vec3(1, 2, 3) + vec3(2, 3, 4) == vec3(3, 5, 7));
    static_assert(vec3(1, 2, 3) - vec3(2, 3, 4) == vec3(-1, -1, -1));

    EXPECT_EQ(vec3(3, 5, 7), vec3(1, 2, 3) + vec3(2, 3, 4));
    EXPECT_EQ(vec3(-119, -19, -21), vec3(-121, -22, 3) + vec3(2, 3, -24));

    vec3  expectedplus(32.25, 13.35, 24.79),
          actualplus(vec3(31.13, 12.23, 23.67) + vec3(1.12, 1.12, 1.12));

    expectVecNear(expectedplus, actualplus);

    // subtraction
    EXPECT_EQ(vec3(-1, -1, -1), vec3(1, 2, 3) - vec3(2, 3, 4));
    EXPECT_EQ(vec3(-123, -25, 27), vec3(-121, -22, 3) - vec3(2, 3, -24));

    vec3  expectedminus(30.01, 11.11, 22.55),
          actualminus(vec3(31.13, 12.23, 23.67) - vec3(1.12, 1.12, 1.12));

    expectVecNear(expectedminus, actualminus);
  }

  TEST(Vec3Tests, ScalarMultiplicationProducesCorrectResult){
    EXPECT_EQ(vec3(2, 4, 6), vec3(1, 2, 3) * 2);
    EXPECT_EQ(vec3(-2, -4, -6), vec3(1, 2, 3) * -2);
    EXPECT_EQ(vec3(0, 0, 0), vec3(1, 2, 3) * 0);

    expectVecNear(vec3(0.56, 206.061155, 445.59486955),
                  vec3(1.12, 412.12231, 891.1897391) * 0.5);
  }

  TEST(Vec3Tests, ScalarDivisionProducesCorrectResults){
    EXPECT_EQ(vec3(1, 2, 3), vec3(2, 4, 6) / 2);
    EXPECT_EQ(vec3(-1, -2, -3), vec3(2, 4, 6) / -2);
    EXPECT_EQ(vec3(0, 0, 0), vec3(0, 0, 0) / 2);

    expectVecNear(vec3(0.5, 1.0, 1.5), vec3(1, 2, 3) / 2);
  }

  TEST(Vec3Tests, VectorNegationCorrectnessCheck){
    std::vector<vec3> expected = {vec3(1, 2, 3), vec3(0, 0, 0), vec3(-1, 2, -3), vec3(1.12, 412.12231, 891.1897391)},
                      actual = {vec3(-1, -2, -3), vec3(0, 0, 0), vec3(1, -2, 3), vec3(-1.12, -412.12231, -891.1897391)};
    
    for (size_t i = 0; i < expected.size(); ++i) {
      expectVecNear(expected[i], -actual[i]);
      expectVecNear(actual[i], -(-actual[i]));
    }

  }

  TEST(Vec3Tests, LengthSquaredReturnsCorrectResult) {
    static_assert(vec3(3, 4, 0).lengthSquared() == 25);

    EXPECT_DOUBLE_EQ(0, vec3(0, 0, 0).lengthSquared());
    EXPECT_DOUBLE_EQ(14, vec3(1, 2, 3).lengthSquared());
    EXPECT_DOUBLE_EQ(25, vec3(3, 4, 0).lengthSquared());
    EXPECT_DOUBLE_EQ(29, vec3(2, 3, 4).lengthSquared());
    EXPECT_DOUBLE_EQ(7234, vec3(12, 23, 81).lengthSquared());

    EXPECT_DOUBLE_EQ(vec3(-1, -2, -3).lengthSquared(),
                     vec3(1, 2, 3).lengthSquared());
  }

  TEST(Vec3Tests, LengthReturnsCorrectMagnitude){
    EXPECT_NEAR(0, vec3(0, 0, 0).length(), EPSILON);
    EXPECT_NEAR(1, vec3(1, 0, 0).length(), EPSILON);
    EXPECT_NEAR(5, vec3(3, 4, 0).length(), EPSILON);
    EXPECT_NEAR(std::sqrt(14.0), vec3(1, 2, 3).length(), EPSILON);
    EXPECT_NEAR(std::sqrt(29.0), vec3(2, 3, 4).length(), EPSILON);
    EXPECT_NEAR(std::sqrt(7234.0), vec3(12, 23, 81).length(), EPSILON);

    EXPECT_NEAR(vec3(1, 2, 3).length(), vec3(-1, -2, -3).length(), EPSILON);
  }

  TEST(Vec3Tests, NormalizationProducesUnitVector){
    std::vector<vec3> _ = {vec3(1, 2, 3), vec3(2, 3, 4), vec3(12, 23, 81), vec3(1.12, 412.12231, 891.1897391), vec3(0, 0, 0)};
    std::vector<vec3> expected = {vec3(0.2672612419, 0.5345224838, 0.8017837257),
                                  vec3(0.3713906764, 0.5570860145, 0.7427813527),
                                  vec3(0.1410886227, 0.2704198601, 0.9523482030),
                                  vec3(0.0011406826, 0.4197328125, 0.9076469936),
                                  vec3(0, 0, 0)};
    std::vector<vec3> actual = {_[0].normalize(), 
                                _[1].normalize(),
                                _[2].normalize(),
                                _[3].normalize(),
                                _[4].normalize()};

    for (size_t i = 0; i < expected.size(); ++i){
      for (size_t j = 0; j < 3; ++j)
        EXPECT_NEAR(expected[i][j], actual[i][j], EPSILON);
    }
      //0.3713906764
  }

  TEST(Vec3Tests, NormalizationDoesNotModifyOriginalVector) {
    const vec3 v(3, 4, 0);

    vec3 normalized = v.normalize();

    EXPECT_EQ(vec3(3, 4, 0), v);
    expectVecNear(vec3(0.6, 0.8, 0), normalized);
  }
}