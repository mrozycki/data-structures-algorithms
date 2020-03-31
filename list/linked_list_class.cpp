#include <iostream>

class linked_list_node {
public:
    linked_list_node(int head, linked_list_node* tail)
        : head_(head), tail_(tail) {

    }

    std::size_t length() const {
        std::size_t result = 0;

        linked_list_node const * current = this;
        while (current != nullptr) {
            ++result;
            current = current->tail_;
        }

        return result;
    }

    int sum() const {
        std::size_t result = 0;

        linked_list_node const * current = this;
        while (current != nullptr) {
            result += current->head_;
            current = current->tail_;
        }

        return result;
    }

private:
    int head_;
    linked_list_node* tail_;
};

class linked_list {
public:
    linked_list() : head_(nullptr) {}
    linked_list(int value, linked_list* tail)
        : head_(new linked_list_node(value, tail->head_)) {}

    bool is_empty() const { return head_ == nullptr; }

    std::size_t length() const {
        if (is_empty()) {
            return 0;
        } else {
            return head_->length();
        }
    }

    std::size_t sum() const {
        if (is_empty()) {
            return 0;
        } else {
            return head_->sum();
        }
    }

private:
    linked_list_node* head_;
};

int main() {
    auto list = new linked_list(4, new linked_list(8, new linked_list(15, new linked_list(16, new linked_list()))));
    std::cout << "Dlugosc: " << list->length() << "\n";
    std::cout << "Suma: " << list->sum() << "\n";

    return 0;
}