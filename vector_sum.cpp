#include <iostream>

#include "vector/vector.h"

int main() {
    vector v;

    int n;
    while (std::cin >> n) {
        v.push_back(n);
    }

    std::cout << "Dlugosc: " << v.length() << "\n";
    std::cout << "Suma: " << sum(v) << "\n";

    return 0;
}