#include <iostream>

#include "linked_list.h"

class stack {
public:
    stack() : elements(nullptr) {}

    void push(int value) {
        elements = new list{value, elements};
    }

    int pop() {
        int value = elements->head;
        auto old_head = elements;
        elements = elements->tail;
        delete old_head;
        return value;
    }

    int top() const {
        return elements->head;
    }

    bool is_empty() const {
        return ::is_empty(elements);
    }

private:
    list* elements;
};

int main() {
    stack s;
    int n;
    while (std::cin >> n) {
        s.push(n);
    }

    int count = 0;
    while (!s.is_empty()) {
        ++count;
        s.pop();
    }

    std::cout << "Dlugosc: " << count << "\n";

    return 0;
}