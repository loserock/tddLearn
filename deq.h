#pragma once

#include <type_traits>
#include <array>
#include <vector>

/// Custom Deque class
/** feature list:
 *  - push_back, pop_back: uses the end's flag position
 *  - push_front, pop_front: uses the begin's flag position
 *  - insert, which invalidates the iterators
 *  - begin and end shall works as invariants (like std lib)
 *  - use a predefined bucket size for optimization
 */

template <typename T, size_t N = 16, typename B = std::vector<std::array<T, N> *>>
class deq
{
  public:
    bool empty() const noexcept;
    size_t size() const noexcept;

    void push_back(const T &t);
    void pop_back() /* noexcept */;

  private:
    static const size_t ImplSize = N;

    using impl_t = B;
    using buffer_t = typename std::remove_pointer<typename B::value_type>::type;

    impl_t m_v;
    size_t m_beg = 0; ///< begin position (relative?)
    size_t m_end = 0; ///< end position (relative to the begin of the first bucket)
};

template <typename T, size_t N, typename B>
bool deq<T, N, B>::empty() const noexcept
{
    return 0 == size();
}

template <typename T, size_t N, typename B>
size_t deq<T, N, B>::size() const noexcept
{
    return m_end - m_beg;
}

template <typename T, size_t N, typename B>
void deq<T, N, B>::push_back(const T &t)
{
    const auto bufno = m_end / ImplSize;
    const auto idx = m_end % ImplSize;
    if (bufno >= m_v.size())
    {
        m_v.push_back(new buffer_t);
    }
    (*m_v[bufno])[idx] = t;
    ++m_end;
}

template <typename T, size_t N, typename B>
void deq<T, N, B>::pop_back()
{
    const auto bufno = m_end / ImplSize;
    const auto idx = m_end % ImplSize;
    T _t;
    std::swap((*m_v[bufno])[idx], _t);
    --m_end;
}