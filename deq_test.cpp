#include <gtest/gtest.h>
#include "deq.h"

template <typename T>
void fillBack(deq<T> &d, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        d.push_back(i * i);
    }
}

TEST(DeqTestCreate, Trivial)
{
    deq<int> di;

    EXPECT_TRUE(di.empty());
    EXPECT_EQ(0, di.size());
}

TEST(DeqTestPushBack, AfterEmpty)
{
    deq<int> di;

    di.push_back(1);

    EXPECT_FALSE(di.empty());
    EXPECT_EQ(1, di.size());
}

TEST(DeqTestPushBack, AddFew)
{
    deq<int> di;
    size_t s = 10; ///< number of inserted elements
    fillBack(di, s);

    EXPECT_FALSE(di.empty());
    EXPECT_EQ(s, di.size());
}

TEST(DeqTestPushBack, AddMany)
{
    deq<int> di;

    const auto s = 10;  ///< number of inserted elements
    const auto cn = 42; ///< number of cycles
    for (size_t i = 0; i < cn; ++i)
    {
        fillBack(di, s);

        ASSERT_FALSE(di.empty());
        ASSERT_EQ((i + 1) * s, di.size());
    }
}

TEST(DeqTestPopBack, OnlyOne)
{
    deq<int> di;

    di.push_back(42);
    di.pop_back();

    EXPECT_TRUE(di.empty());
    EXPECT_EQ(0, di.size());
}

TEST(DeqTestPopBack, Many)
{
    deq<int> di;

    const auto s = 150;
    fillBack(di, s);

    for (size_t i = s; i > 1; --i)
    {
        di.pop_back();

        ASSERT_FALSE(di.empty());
        ASSERT_EQ(i - 1, di.size());
    }
    di.pop_back();

    EXPECT_TRUE(di.empty());
    EXPECT_EQ(0, di.size());
}

TEST(DeqTestPushPopBack, Many)
{
    const auto nPush1 = 150;
    const auto nPush2 = 99;
    const auto nPop1 = 123;
    const auto nPop2 = 86;

    deq<int> di;

    fillBack(di, nPush1);
    for (size_t i = nPop1; i > 0; --i)
    {
        di.pop_back();
    }

    fillBack(di, nPush2);
    for (size_t i = nPop2; i > 0; --i)
    {
        di.pop_back();
    }

    EXPECT_FALSE(di.empty());
    EXPECT_EQ(nPush1 + nPush2 - nPop1 - nPop2, di.size());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}