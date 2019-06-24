#pragma once

#include <cassert>
#include <cstddef>

template <typename A, typename B>
class Sum
{
public:
    explicit Sum(const A& a, const B& b) : a_(a), b_(b) { assert(a.size() == b.size()); }

    std::size_t size() const { return a_.size(); }

    double operator[](std::size_t i) const { return a_[i] + b_[i]; }

private:
    const A& a_;
    const B& b_;
};

template <typename A, typename B>
Sum<A, B> operator+(const A& a, const B& b)
{
    return Sum<A, B>(a, b);
}
