#include <cstdlib>
#include <ctime>
#include <iostream>

int main(int argc, char** argv) {
    srand(time(nullptr));

    if (argc < 2) {
        std::cerr << "Usage: generate <n>";
        return 1;
    }

    auto n = atoi(argv[1]);

    for (int i = 0; i < n; ++i) {
        std::cout << rand() % 1001 - 500 << " ";
    }
    std::cout << "\n";

    return 0;
}