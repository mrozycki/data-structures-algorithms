#include <iostream>
#include <vector>

class naive_priority_queue
{
public:
    void push(int n)
    {
        elements.push_back(n);
    }

    void pop()
    {
        std::swap(elements.back(), elements.at(max_index()));
        elements.pop_back();
    }

    int top()
    {
        return elements[max_index()];
    }

    bool empty()
    {
        return elements.empty();
    }

private:
    std::size_t max_index()
    {
        auto index = 0;
        for (auto i = 0; i < elements.size(); ++i)
        {
            if (elements[i] > elements[index])
            {
                index = i;
            }
        }
        return index;
    }

    std::vector<int> elements;
};

int main()
{
    naive_priority_queue pq;

    std::size_t i = 0;
    int n;
    while (std::cin >> n)
    {
        pq.push(n);
        if (i % 2 == 1)
        {
            std::cout << pq.top() << "\n";
            pq.pop();
        }
        ++i;
    }

    while (!pq.empty())
    {
        std::cout << pq.top() << "\n";
        pq.pop();
    }
}