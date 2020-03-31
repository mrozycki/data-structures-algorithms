#include <iostream>

#include "list/linked_list.h"
#include "list_stack.h"

void stack::push(int value) {
    elements = new list{value, elements};
}

int stack::pop() {
    int value = elements->head;
    auto old_head = elements;
    elements = elements->tail;
    delete old_head;
    return value;
}

int stack::top() const {
    return elements->head;
}

bool stack::is_empty() const {
    return ::is_empty(elements);
}