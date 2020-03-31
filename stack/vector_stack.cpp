#include "vector_stack.h"

void stack::push(int value) {
    elements.push_back(value);
}

int stack::pop() {
    return elements.pop_back();
}

int stack::top() const {
    return elements[elements.length() - 1];
}

bool stack::is_empty() const {
    return elements.length() == 0;
}