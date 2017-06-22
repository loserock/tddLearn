#include <gtest/gtest.h>
#include "minimath.h"

class MiniMathTest : public ::testing::Test
{
    protected:
    MiniMath mm;

    void SetUp()
    {
        std::cout << "Before test" << std::endl;
    }
    void TearDown()
    {
        std::cout << "After test" << std::endl;
    }

};

TEST(FactorialTest, withPositiveNumber)
{
    MiniMath mm;
    EXPECT_EQ(120, mm.factorial(5));
    EXPECT_EQ(6, mm.factorial(3));
}

TEST(FactorialTest, withZero)
{
    MiniMath mm;
    EXPECT_EQ(1, mm.factorial(0));
}

TEST(FactorialTest, withNegative1)
{
    MiniMath mm;
    EXPECT_EXIT(mm.factorial(0), ::testing::ExitedWithCode(1), "");
}

TEST(FactorialTest, withNegative2)
{
    MiniMath mm;
    EXPECT_EXIT(mm.factorial(-1), ::testing::ExitedWithCode(-1), "");
}

TEST(FactorialTest, withNegative3)
{
    MiniMath mm;
    EXPECT_EXIT(mm.factorial(-1), ::testing::ExitedWithCode(1), "Bad input");
}

TEST(FactorialTest, withNegative4)
{
    MiniMath mm;
    EXPECT_EXIT(mm.factorial(-1), ::testing::ExitedWithCode(1), "Negative input");
}

TEST(FactorialTest, throwError)
{
    EXPECT_THROW(
        {
            MiniMath mm(true);
            mm.factorial(-1);
        },
        std::range_error);
}

TEST(DivisionTest, SimpleTest)
{
    MiniMath mm;
    double r = mm.div(5, 3);
    double ex = 1.66;
    // EXPECT_EQ(ex, r);
    // EXPECT_DOUBLE_EQ(ex, r);
    // EXPECT_NEAR(ex, r, 1e-4);
    EXPECT_NEAR(ex, r, 1e-2);
}

TEST(CommonDivisorTest, gcd)
{
    MiniMath mm;
    EXPECT_EQ(1, mm.gcd(9, 16));
    EXPECT_EQ(4, mm.gcd(12, 8));
    EXPECT_EQ(5, mm.gcd(15, 10));
}

TEST(PrimeTest, mutPrime)
{
    EXPECT_TRUE(MiniMath::mutPrime(9, 16));
    EXPECT_FALSE(MiniMath::mutPrime(12, 8));
    EXPECT_TRUE(MiniMath::mutPrime(3 * 5, 2 * 5)); // should fail
}

TEST(PrimeTest, mutPrimePred)
{
    EXPECT_PRED2(MiniMath::mutPrime, 9, 16);
    EXPECT_PRED2(MiniMath::mutPrime, 12, 8); // should fail
    EXPECT_PRED2(MiniMath::mutPrime, 3 * 5, 2 * 5); // should fail
}

TEST_F(MiniMathTest, withPositiveNumbers)
{
    EXPECT_EQ(120, mm.factorial(5));
    EXPECT_EQ(6, mm.factorial(3));
}