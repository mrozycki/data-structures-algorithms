#pragma once

#include "list/linked_list.h"

class stack {
public:
    stack() : elements(nullptr) {}

    void push(int value);
    int pop();
    int top() const;
    bool is_empty() const;

private:
    list* elements;
};