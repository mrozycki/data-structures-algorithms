#include <iostream>

#include "linked_list.h"

int main() {
    list* l = nullptr;
    list** next = &l;
    int count = 0;
    int n;
    while (std::cin >> n) {
        *next = new list{n, nullptr};
        next = &(*next)->tail;
        ++count;
    }

    std::cout << "Dlugosc: " << count << "\n";
    std::cout << "Suma: " << sum(l) << "\n";

    return 0;
}