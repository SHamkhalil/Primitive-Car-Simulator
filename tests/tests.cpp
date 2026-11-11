#include <gtest/gtest.h>
#include <cmath>

#include "sim.hpp"

#define PRECISION 100


namespace{
  
  TEST(ConversionTest, Positive){
    EXPECT_EQ(16.67, (round(speedConvertKPHtoMPS(60) * PRECISION) / PRECISION));
    EXPECT_EQ(50.00, (round(speedConvertKPHtoMPS(180) * PRECISION) / PRECISION));
    EXPECT_EQ(6.45, (round(speedConvertKPHtoMPS(23.21) * PRECISION) / PRECISION));
  }

  TEST(ConversionTest, Negative){
    EXPECT_EQ(-1, (round(speedConvertKPHtoMPS(-60) * PRECISION) / PRECISION));
    EXPECT_EQ(-1, (round(speedConvertKPHtoMPS(-120) * PRECISION) / PRECISION));
    EXPECT_EQ(-1, (round(speedConvertKPHtoMPS(-50) * PRECISION) / PRECISION));
  }
}