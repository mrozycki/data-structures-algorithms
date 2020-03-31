#include <iostream>
#include <vector>

#include "vector/vector.h"

vector sort(std::vector<int> const& numbers) {
    vector sorted_numbers;

    for (const auto number : numbers) {
        std::size_t place = 0;
        while (place < sorted_numbers.length() && sorted_numbers[place] < number) {
            place++;
        }

        sorted_numbers.push_back(0);
        for (int i = sorted_numbers.length()-1; i > place; --i) {
            sorted_numbers[i] = sorted_numbers[i-1];
        }
        sorted_numbers[place] = number;
    }
    return sorted_numbers;
}

int main() {
    std::vector<int> v;
    int value;
    while (std::cin >> value) {
        v.push_back(value);
    }

    auto sorted_list = sort(v);
    for (std::size_t i = 0; i < sorted_list.length(); ++i) {
        std::cout << sorted_list[i] << " ";
    }
    std::cout << "\n";

    return 0;
}