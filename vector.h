#pragma once

#include <initializer_list>
#include <iostream>
#include <vector>

class Vector
{
public:
    Vector(std::size_t length) : data_(length) {}

    Vector(const std::initializer_list<double>& list)
    {
        data_.reserve(list.size());
        for (auto elt : list)
            data_.push_back(elt);
    }

    std::size_t size() const { return data_.size(); }

    double  operator[](std::size_t i) const { return data_[i]; }
    double& operator[](std::size_t i)       { return data_[i]; }

    template <typename A>
    Vector& operator=(const A& expr)
    {
        data_.resize(expr.size());
        for (std::size_t i = 0; i < size(); ++i)
            data_[i] = expr[i];
        return *this;
    }

private:
    std::vector<double> data_;
};

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
    out << "( ";
    for (std::size_t i = 0; i < v.size(); ++i)
        out << v[i] << ' ';
    out << ")";
    return out;
}
