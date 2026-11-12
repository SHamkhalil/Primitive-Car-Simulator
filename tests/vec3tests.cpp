#include <gtest/gtest.h>
#include <vector>

#include "vec3.hpp"

namespace{
  constexpr double EPSILON = 1e-9;
  
  TEST(Vec3Tests, IndexOperatorReturnsCorrectComponent){
    std::vector<vec3> _ = {vec3(1, 2, 3), vec3(2, 3, 4), vec3(12, 23, 81), vec3(1.12, 412.12231, 891.1897391)};
    EXPECT_NEAR(1, _[0].m_x, EPSILON);
    EXPECT_NEAR(4, _[1].m_z, EPSILON);
    EXPECT_NEAR(23, _[2].m_y, EPSILON);
    EXPECT_NEAR(412.12231, _[3].m_y, EPSILON); 
    EXPECT_NEAR(891.1897391, _[3].m_z, EPSILON);
  }

  TEST(Vec3Tests, ScalarMultiplicationProducesCorrectResult){
    std::vector<vec3> _ = {vec3(1, 2, 3), vec3(2, 3, 4), vec3(12, 23, 81), vec3(1.12, 412.12231, 891.1897391)};
    EXPECT_NEAR(1, _[0].m_x *= 1, EPSILON);
    EXPECT_NEAR(1.12, _[0].m_x *= 1.12, EPSILON);
    EXPECT_NEAR(128.673, _[1].m_y *= 42.891, EPSILON);
    EXPECT_NEAR(0.972, _[2].m_z *= 0.012, EPSILON);
    EXPECT_NEAR(2001.26593736, _[3].m_y *= 4.856, EPSILON);
  }

  TEST(Vec3Tests, EqualityOperatorReturnsTrueForEqualVectors){
    EXPECT_EQ(vec3(1, 2, 3), vec3(1, 2, 3));
    EXPECT_EQ(vec3(3, 2, 1), vec3(3, 2, 1));
    EXPECT_EQ(vec3(32.25, 13.35, 24.79), vec3(32.25, 13.35, 24.79));
  }

  TEST(Vec3Tests, AdditionAndSubtractionOperatorsProduceCorrectResults){
    // addition
    EXPECT_EQ(vec3(3, 5, 7), vec3(1, 2, 3) + vec3(2, 3, 4));
    EXPECT_EQ(vec3(-119, -19, -21), vec3(-121, -22, 3) + vec3(2, 3, -24));

    vec3  expectedplus(32.25, 13.35, 24.79),
          actualplus(vec3(31.13, 12.23, 23.67) + vec3(1.12, 1.12, 1.12));

    EXPECT_NEAR(expectedplus.m_x, actualplus.m_x, EPSILON);
    EXPECT_NEAR(expectedplus.m_y, actualplus.m_y, EPSILON);
    EXPECT_NEAR(expectedplus.m_z, actualplus.m_z, EPSILON);

    // subtraction
    EXPECT_EQ(vec3(-1, -1, -1), vec3(1, 2, 3) - vec3(2, 3, 4));
    EXPECT_EQ(vec3(-123, -25, 27), vec3(-121, -22, 3) - vec3(2, 3, -24));

    vec3  expectedminus(30.01, 11.11, 22.55),
          actualminus(vec3(31.13, 12.23, 23.67) - vec3(1.12, 1.12, 1.12));

    EXPECT_NEAR(expectedminus.m_x, actualminus.m_x, EPSILON);
    EXPECT_NEAR(expectedminus.m_y, actualminus.m_y, EPSILON);
    EXPECT_NEAR(expectedminus.m_z, actualminus.m_z, EPSILON);
  }

  TEST(Vec3Tests, NormalizationProducesUnitVector){
    std::vector<vec3> _ = {vec3(1, 2, 3), vec3(2, 3, 4), vec3(12, 23, 81), vec3(1.12, 412.12231, 891.1897391), vec3(0, 0, 0.1231)};
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

  TEST(Vec3Tests, LengthReturnsCorrectMagnitude){
    std::vector<vec3> _ = {vec3(1, 2, 3), vec3(2, 3, 4), vec3(12, 23, 81), vec3(1.12, 412.12231, 891.1897391)};
    EXPECT_NEAR(3.7416573868, _[0].length(), EPSILON);
    EXPECT_NEAR(5.3851648071, _[1].length(), EPSILON);
    EXPECT_NEAR(85.0529246999, _[2].length(), EPSILON);
  }

  TEST(Vec3Tests, VectorNegationCorrectnessCheck){
    std::vector<vec3> expected = {vec3(1, 2, 3), vec3(0, 0, 0), vec3(1.12, 412.12231, 891.1897391)},
                      actual = {vec3(-1, -2, -3), vec3(0, 0, 0), vec3(-1.12, -412.12231, -891.1897391)};
    
    for (size_t j = 0; j < expected.size(); ++j)
      for (size_t i = 0; i < 2; ++i)
        EXPECT_NEAR(expected[j][i], -actual[j][i], EPSILON);

  }
}