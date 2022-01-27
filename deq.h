#pragma once

#include <type_traits>
#include <array>
#include <vector>
#include <string>
#include <stdexcept>

/// Custom Deque class
/** feature list:
 *  - push_back, pop_back: uses the end's flag position
 *  - push_front, pop_front: uses the begin's flag position
 *  - insert, which invalidates the iterators
 *  - begin and end shall works as invariants (like std lib)
 *  - use a predefined bucket size for optimization
 */

template <typename T, size_t N = 16, typename B = std::vector<std::array<T, N> * > >
class deq
{
  public:
    deq() = default;
    deq(const deq &rhs);
    deq &operator=(const deq &rhs);

    bool empty() const noexcept;
    size_t size() const noexcept;

    void push_back(const T &t);
    void pop_back() /* noexcept */;

    T &operator[](size_t ind) noexcept;
    const T &operator[](size_t) const noexcept;

    T &at(size_t idx);
    const T &at(size_t idx) const;

  private:
    static const size_t ImplSize = N;

    using impl_t = B;
    using buffer_t = typename std::remove_pointer<typename B::value_type>::type;

    impl_t m_v;
    size_t m_beg = 0; ///< begin position (relative?)
    size_t m_end = 0; ///< end position (relative to the begin of the first bucket)

    void checkIndex(size_t idx) const;
};

template <typename T, size_t N, typename B>
deq<T, N, B>::deq(const deq &rhs)
{
    m_v.reserve(rhs.m_v.size());
    for (size_t i = 0; i < rhs.size(); ++i)
    {
        push_back(rhs[i]);
    }
}

template <typename T, size_t N, typename B>
deq<T, N, B> &deq<T, N, B>::operator=(const deq &rhs)
{
    deq tmp(rhs);
    m_v.swap(tmp.m_v);
    m_beg = tmp.m_beg;
    m_end = tmp.m_end;
    return *this;
}

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

template <typename T, size_t N, typename B>
T &deq<T, N, B>::operator[](size_t idx) noexcept
{
    const auto bufno = idx / ImplSize;
    const auto i = idx % ImplSize;
    return (*m_v[bufno])[i];
}

template <typename T, size_t N, typename B>
const T &deq<T, N, B>::operator[](size_t idx) const noexcept
{
    const auto bufno = idx / ImplSize;
    const auto i = idx % ImplSize;
    return (*m_v[bufno])[i];
}

template <typename T, size_t N, typename B>
T &deq<T, N, B>::at(size_t idx)
{
    checkIndex(idx);
    return operator[](idx);
}

template <typename T, size_t N, typename B>
const T &deq<T, N, B>::at(size_t idx) const
{
    checkIndex(idx);
    return operator[](idx);
}

template <typename T, size_t N, typename B>
void deq<T, N, B>::checkIndex(size_t idx) const
{
    if (0 > idx || idx >= size())
    {
        std::string e = "Bad index: " + std::to_string(idx);
        throw std::out_of_range(e.c_str());
    }
}
