#pragma once

#include <cstddef>

struct list {
    int head;
    list* tail;
};

bool is_empty(list const *const l);
std::size_t length(list const *const l);
int sum(list const *const l);