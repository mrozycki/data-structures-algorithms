#pragma once

#include "vector/vector.h"

class stack {
public:
    void push(int value);
    int pop();
    int top() const;
    bool is_empty() const;

private:
    vector elements;
};