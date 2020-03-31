// push_stack: 4 8 15
//  pop_stack: 16 23

// push_stack: 4 8 15
//  pop_stack: -
// push_stack: -
//  pop_stack: 15 8 4

#include <iostream>

#include "stack/vector_stack.h"

class queue {
public:
    void push(int value) {
        push_stack.push(value);
    }

    int pop() {
        if (pop_stack.is_empty()) {
            while (!push_stack.is_empty()) {
                pop_stack.push(push_stack.pop());
            }
        }

        return pop_stack.pop();
    }

    bool is_empty() const {
        return push_stack.is_empty() && pop_stack.is_empty();
    }

private:
    stack pop_stack;
    stack push_stack;
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