#include "array.h"

vector::vector()
    : capacity_(8)
    , length_(0)
    , data_(new int[capacity_]) {}

int& vector::operator[](std::size_t index) {
    return data_[index];
}

int const& vector::operator[](std::size_t index) const {
    return data_[index];
}

void vector::push_back(int n) {
    if (length_ + 1 > capacity_) {
        resize(capacity_ * 2);
    }

    data_[length_++] = n;
}

int vector::pop_back() {
    auto result = data_[--length_];
    if (length_ < capacity_ / 4) {
        resize(capacity_ / 2);
    }
    return result;
}

void vector::resize(std::size_t new_capacity) {
    auto old_data = data_;
    data_ = new int[new_capacity];
    for (int i = 0; i < length_; i++) {
        data_[i] = old_data[i];
    }
    capacity_ = new_capacity;
    delete [] old_data;
}

int sum(vector const& v) {
    int result = 0;
    for (auto i = 0; i < v.length(); ++i) {
        result += v[i];
    }
    return result;
}
