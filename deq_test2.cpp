#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "deq.h"

using ::testing::_;
using ::testing::Invoke;

using vcon_t = std::array<int, 16> *;
using vec_t = std::vector<vcon_t>;

struct MockVector : public vec_t
{
    MOCK_CONST_METHOD0(size, size_t());
    MOCK_METHOD1(push_back, void(vcon_t));
};

//---------------------------------------
// private access c++ hack preparation
#pragma region private access preparation

template <vec_t deq<int>::*PtrValue>
struct private_access
{
    friend vec_t deq<int>::*get() { return PtrValue; }
};

vec_t deq<int>::*get();
template struct private_access<&deq<int>::m_v>;

template <MockVector deq<int, 16, MockVector>::*PtrValue>
struct private_access2
{
    friend MockVector deq<int, 16, MockVector>::*getMock() { return PtrValue; }
};

// TODO
MockVector deq<int, 16, MockVector>::*
getMock();
template struct private_access2<&deq<int, 16, MockVector>::m_v>;
#pragma endregion
//---------------------------------------

/// deq autofill utility function
template <typename T>
void fillBack(deq<T> &d, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        d.push_back(i * i);
    }
}

template <typename C, typename F, typename P, typename X>
::testing::AssertionResult Expect_Throw(C c, F f, P p, X)
{
    try
    {
        (c.*f)(p);
    }
    catch (X)
    {
        return ::testing::AssertionSuccess();
    }
    catch (std::exception &e)
    {
        return ::testing::AssertionFailure() << "Other std::exception, typeinfo = "
                                             << typeid(e).name()
                                             << ", what() = "
                                             << e.what();
    }
    catch (...)
    {
        return ::testing::AssertionFailure() << "Other unknown exception";
    }
    return ::testing::AssertionFailure() << "Does not throw exception";
}

template <typename C, typename F, typename P>
::testing::AssertionResult Expect_No_Throw(C c, F f, P p)
{
    try
    {
        (c.*f)(p);
    }
    catch (std::exception &e)
    {
        return ::testing::AssertionFailure() << "Exception thrown std:exception, typeinfo = "
                                             << typeid(e).name()
                                             << ", what() = "
                                             << e.what();
    }
    catch (...)
    {
        return ::testing::AssertionFailure() << "Exception thrown unknown exception";
    }
    return ::testing::AssertionSuccess(); //  << "Does not throw exception";
}

TEST(DeqTestCreate, Trivial)
{
    deq<int> di;

    EXPECT_TRUE(di.empty());
    EXPECT_EQ(0, di.size());
}

TEST(DeqTestAt, AfterEmpty)
{
    //deq<int, 16, MockVector> di;
    deq<int> di;

    using at_t = int &(deq<int>::*)(size_t);
    using c_at_t = const int &(deq<int>::*)(size_t) const;

    EXPECT_TRUE(Expect_Throw(di, static_cast<at_t>(&deq<int>::at), 0, std::out_of_range("Bad index")));
    EXPECT_TRUE(Expect_Throw(di, static_cast<at_t>(&deq<int>::at), -1, std::out_of_range("Bad index")));
    EXPECT_TRUE(Expect_Throw(di, static_cast<at_t>(&deq<int>::at), std::numeric_limits<size_t>::min(), std::out_of_range("Bad index")));
    EXPECT_TRUE(Expect_Throw(di, static_cast<at_t>(&deq<int>::at), std::numeric_limits<size_t>::max(), std::out_of_range("Bad index")));
    EXPECT_TRUE(Expect_Throw(di, static_cast<at_t>(&deq<int>::at), 1, std::out_of_range("Bad index")));
    EXPECT_TRUE(Expect_Throw(di, static_cast<at_t>(&deq<int>::at), 42, std::out_of_range("Bad index")));
}

TEST(DeqTestAt, AfterPushPopBack)
{
    deq<int> di;
    const auto s = 200;

    using at_t = int &(deq<int>::*)(size_t);
    using c_at_t = const int &(deq<int>::*)(size_t) const;

    fillBack(di, s);

    EXPECT_TRUE(Expect_No_Throw(di, static_cast<at_t>(&deq<int>::at), 0));
    EXPECT_TRUE(Expect_Throw(di, static_cast<at_t>(&deq<int>::at), -1, std::out_of_range("Bad index")));
    EXPECT_TRUE(Expect_No_Throw(di, static_cast<at_t>(&deq<int>::at), std::numeric_limits<size_t>::min()));
    EXPECT_TRUE(Expect_Throw(di, static_cast<at_t>(&deq<int>::at), std::numeric_limits<size_t>::max(), std::out_of_range("Bad index")));
    EXPECT_TRUE(Expect_No_Throw(di, static_cast<at_t>(&deq<int>::at), 1));
    EXPECT_TRUE(Expect_No_Throw(di, static_cast<at_t>(&deq<int>::at), 42));
    EXPECT_TRUE(Expect_Throw(di, static_cast<at_t>(&deq<int>::at), s, std::out_of_range("Bad index")));

    for (size_t i = 0; i < s; ++i)
    {
        ASSERT_EQ(i * i, di.at(i));
    }

    const deq<int> cdi = di;

    for (size_t i = 0; i < s; ++i)
    {
        ASSERT_EQ(i * i, cdi.at(i));
    }

    di.pop_back();
    for (size_t i = 0; i < s - 1; ++i)
    {
        ASSERT_EQ(i * i, di.at(i));
    }
    for (size_t i = 0; i < s; ++i)
    {
        ASSERT_EQ(i * i, cdi.at(i));
    }

    di.push_back(42);

    EXPECT_EQ(42, di.at(s - 1));
    EXPECT_EQ((s - 1) * (s - 1), cdi.at(s - 1));
}

TEST(DeqTestAt, AfterPushBack)
{
    deq<int> di;
    const auto s = 200;

    using at_t = int &(deq<int>::*)(size_t);
    using c_at_t = const int &(deq<int>::*)(size_t) const;

    fillBack(di, s);
    for (size_t i = 0; i < s; ++i)
    {
        ASSERT_EQ(i * i, di.at(i));
    }

    const deq<int> cdi = di;

    for (size_t i = 0; i < s; ++i)
    {
        ASSERT_EQ(i * i, cdi.at(i));
    }

    di.pop_back();
    for (size_t i = 0; i < s - 1; ++i)
    {
        ASSERT_EQ(i * i, di.at(i));
    }
    for (size_t i = 0; i < s; ++i)
    {
        ASSERT_EQ(i * i, cdi.at(i));
    }

    di.push_back(42);

    EXPECT_EQ(42, di.at(s - 1));
    EXPECT_EQ((s - 1) * (s - 1), cdi.at(s - 1));

    EXPECT_TRUE(Expect_Throw(di, static_cast<at_t>(&deq<int>::at), s, std::out_of_range("Bad index")));
}

TEST(DeqTestIndexOperator, AfterPushBack)
{
    deq<int> di;
    const auto s = 200;

    fillBack(di, s);
    for (size_t i = 0; i < s; ++i)
    {
        ASSERT_EQ(i * i, di[i]);
    }

    const deq<int> cdi = di;

    for (size_t i = 0; i < s; ++i)
    {
        ASSERT_EQ(i * i, cdi[i]);
    }

    di.pop_back();
    for (size_t i = 0; i < s - 1; ++i)
    {
        ASSERT_EQ(i * i, di[i]);
    }
    for (size_t i = 0; i < s; ++i)
    {
        ASSERT_EQ(i * i, cdi[i]);
    }

    di.push_back(42);

    EXPECT_EQ(42, di[s - 1]);
    EXPECT_EQ((s - 1) * (s - 1), cdi[s - 1]);
}

TEST(DeqTestCopy, EmptyAfterCreate)
{
    deq<int> di;
    deq<int> dj = di;

    EXPECT_TRUE(dj.empty());
    EXPECT_EQ(0, dj.size());

    deq<int> dk;
    dk = di;

    EXPECT_TRUE(dk.empty());
    EXPECT_EQ(0, dk.size());
}

TEST(DeqTestCopy, EmptyAfterPushPop)
{
    deq<int> di;
    const auto s = 200;

    fillBack(di, s);
    for (size_t i = s; i > 0; --i)
    {
        di.pop_back();
    }

    deq<int> dj = di;

    EXPECT_TRUE(dj.empty());
    EXPECT_EQ(0, dj.size());

    deq<int> dk;
    dk = di;

    EXPECT_TRUE(dk.empty());
    EXPECT_EQ(0, dk.size());
}

TEST(DeqTestCopy, AfterPushPop)
{
    deq<int> di;
    const auto s1 = 200, s2 = 100;

    fillBack(di, s1);
    for (size_t i = s1; i > s2; --i)
    {
        di.pop_back();
    }

    deq<int> dj = di;
    deq<int> dk;
    dk = di;

    EXPECT_EQ(s2, di.size());
    EXPECT_EQ(s2, dj.size());
    EXPECT_EQ(s2, dk.size());

    for (size_t i = 0; i < s2; ++i)
    {
        di[i] = 100 + i;
        dj[i] = 400 + i;
        dk[i] = 700 + i;
    }

    for (size_t i = 0; i < s2; ++i)
    {
        ASSERT_EQ(100 + i, di[i]);
        ASSERT_EQ(400 + i, dj[i]);
        ASSERT_EQ(700 + i, dk[i]);
    }
}

TEST(DeqTestCopy, SelfAssignAfterPushPop)
{
    deq<int> di;
    const auto s1 = 200, s2 = 100;

    fillBack(di, s1);
    for (size_t i = s1; i > s2; --i)
    {
        di.pop_back();
    }
    for (size_t i = 0; i < s2; ++i)
    {
        di[i] = 100 + i;
    }
    di = di;

    EXPECT_EQ(s2, di.size());

    for (size_t i = 0; i < s2; ++i)
    {
        ASSERT_EQ(100 + i, di[i]);
    }
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
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}