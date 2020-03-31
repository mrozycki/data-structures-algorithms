#include <cstdlib>
#include <iostream>

class queue {
public:
    queue() : capacity_(8), data_(new int[capacity_]), front_(0), back_(0), size_(0) {}

    void push(int value) {
        if (size_ == capacity_) {
            resize(2 * capacity_);
        }
        data_[back_++] = value;
        back_ %= capacity_;
        ++size_;
    }

    int pop() {
        if (size_ - 1 <= capacity_ / 4) {
            resize(capacity_ / 2);
        }
        auto value_to_return = data_[front_++];
        front_ %= capacity_;
        --size_;
        return value_to_return;
    }

    bool is_empty() const {
        return size_ == 0;
    }

private:
    void resize(std::size_t new_capacity) {
        auto new_data = new int[new_capacity];
        for (auto i = 0; i < size_; ++i) {
            new_data[i] = data_[(front_ + i) % capacity_];
        }
        auto old_data = data_;
        data_ = new_data;
        capacity_ = new_capacity;
        front_ = 0;
        back_ = size_;
        delete[] old_data;
    }

    std::size_t capacity_;
    int* data_;
    std::size_t front_;
    std::size_t back_;
    std::size_t size_;
};

int main() {
    queue q;
    for (std::size_t i = 0; i < 10000000; ++i) {
        q.push(rand() % 201 - 100);
    }

    while (!q.is_empty()) {
        q.pop();
    }

    return 0;
}