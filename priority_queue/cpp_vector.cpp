#include <algorithm>
#include <iostream>
#include <vector>

class vector_priority_queue
{
public:
    void push(int n)
    {
        elements.push_back(n);
        std::push_heap(elements.begin(), elements.end());
    }

    void pop()
    {
        std::pop_heap(elements.begin(), elements.end());
        elements.pop_back();
    }

    int top()
    {
        return elements[0];
    }

    bool empty()
    {
        return elements.empty();
    }

private:
    std::vector<int> elements;
};

int main()
{
    // 23 16 15 8 4 42
    // std::push_heap
    // 42 16 23 8 4 15
    std::vector<int> v1{23, 16, 15, 8, 4};
    v1.push_back(42);
    std::push_heap(v1.begin(), v1.end());
    for (auto n : v1)
        std::cout << n << " ";
    std::cout << "\n";

    // 42 16 23 8 4 15
    // std::pop_heap
    // 23 16 15 8 4 42
    std::pop_heap(v1.begin(), v1.end());
    for (auto n : v1)
        std::cout << n << " ";
    std::cout << "\n";
    v1.pop_back();

    // std::make_heap
    // std::sort_heap
}