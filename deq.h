#pragma once

#include <type_traits>
#include <array>
#include <vector>

// feature list:
//  - push_back, pop_back: uses the end's flag position
//  - push_front, pop_front: uses the begin's flag position
//  - insert, which invalidates the iterators
//  - begin and end shall works as invariants (like std lib)
//  - use a predefined box size for optimization

template <typename T, size_t N = 16, typename B = std::vector<std::array<T, N> *>>
class deq
{
  public:
    bool empty() const noexcept;
    size_t size() const noexcept;

  private:
    static const size_t ImplSize = N;

    using impl_t = B;
    using buffer_t = typename std::remove_pointer<typename B::value_type>::type;

    impl_t m_v;
    size_t m_beg;
    size_t m_end;
};

template <typename T, size_t N, typename B>
bool deq<T, N, B>::empty() const noexcept
{
    return true;
}

template <typename T, size_t N, typename B>
size_t deq<T, N, B>::size() const noexcept
{
    return 0;
}
