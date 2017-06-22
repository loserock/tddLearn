#include <gtest/gtest.h>

#include <math.h>

TEST(MathTest, TwoPlusTwoEqualsFour)
{
    EXPECT_EQ(2 + 2, 4);
}

TEST(MathTest, PowerOf)
{
    double r = std::pow(2.0, 10) - 1;
    EXPECT_EQ(r, 1<<10);
}
