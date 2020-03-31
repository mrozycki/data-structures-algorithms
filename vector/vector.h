#pragma once

#include <cstddef>

class vector {
public:
    vector();

    int& operator[](std::size_t index);
    int const& operator[](std::size_t index) const;
    std::size_t length() const { return length_; }
    void push_back(int n);
    int pop_back();

private:
    void resize(std::size_t new_capacity);

    std::size_t capacity_;
    std::size_t length_;
    int* data_;
};

int sum(vector const& v);