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

    size_t s = 10;  ///< number of inserted elements
    size_t cn = 42; ///< number of cycles
    for (size_t i = 0; i < cn; ++i)
    {
        fillBack(di, s);

        ASSERT_FALSE(di.empty());
        ASSERT_EQ((i + 1) * s, di.size());
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}