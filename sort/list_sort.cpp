#include <iostream>
#include <vector>

#include "list/linked_list.h"

list* sort(std::vector<int> const& numbers) {
    list* sorted_list = nullptr;
    for (const auto number : numbers) {
        list** current_element = &sorted_list;
        while (*current_element != nullptr && (*current_element)->head < number) {
            current_element = &((*current_element)->tail);
        }
        *current_element = new list{number, *current_element};
    }
    return sorted_list;
}

int main() {
    std::vector<int> v;
    int value;
    while (std::cin >> value) {
        v.push_back(value);
    }

    auto sorted_list = sort(v);
    while (sorted_list != nullptr) {
        std::cout << sorted_list->head << " ";
        sorted_list = sorted_list->tail;
    }
    std::cout << "\n";

    return 0;
}