#include "linked_list.h"

bool is_empty(list const *const l) {
    return l == nullptr;
}

std::size_t length(list const *const l) {
    list const * current = l;
    std::size_t result = 0;
    while (current != nullptr) {
        ++result;
        current = current->tail;
    }
    return result;
}

int sum(list const *const l) {
    list const * current = l;
    std::size_t result = 0;
    while (current != nullptr) {
        result += current->head;
        current = current->tail;
    }
    return result;
}