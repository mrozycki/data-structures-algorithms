#include <iostream>

#include "stack/list_stack.h"

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