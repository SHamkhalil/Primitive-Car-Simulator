#include <gtest/gtest.h>

#include "sim.hpp"


namespace{
  
  TEST(SpeedConversion, KmhToMpsConvertsExactly){
    EXPECT_NEAR(16.67, speedConvertKPHtoMPS(60), 0.01);
    EXPECT_DOUBLE_EQ(50, speedConvertKPHtoMPS(180));
    EXPECT_NEAR(6.45, speedConvertKPHtoMPS(23.21), 0.01);
  }

  TEST(SpeedConversion, NegativeKmhGivesNegativeMps){
    EXPECT_NEAR(-16.67, speedConvertKPHtoMPS(-60), 0.01);
    EXPECT_NEAR(-33.33, speedConvertKPHtoMPS(-120), 0.01);
    EXPECT_NEAR(-13.89, speedConvertKPHtoMPS(-50), 0.01);
  }
}