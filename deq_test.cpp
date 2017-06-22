#include <gtest/gtest.h>
#include "deq.h"

TEST(DeqTestCreate, Trivial)
{
    deq<int> di;

    EXPECT_TRUE(di.empty());
    EXPECT_EQ(0, di.size());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}