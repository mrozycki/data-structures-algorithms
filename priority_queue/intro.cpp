// Kolejki priorytetowe
// push(v) - umieszczamy element na kolejce
// pop() - usuwa największy element na kolejce

// empty() - sprawdza czy kolejka jest pusta
// top() - zwraca największy element na kolejce, bez usuwania

// W C++ mamy `priority_queue`
#include <iostream>
#include <queue>

int main()
{
    std::priority_queue<int> pq;

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