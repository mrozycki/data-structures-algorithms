// Kopiec - heap
//           42
//     23          16
//  15    8      4    X

// top() - w czasie stałym, zawsze znajduje się na górze

// push(n) - w czasie logarytmicznym
// push(19)
//           42
//     23          16
//  15    8      4    19

//           42
//     23          19
//  15    8      4    16

// push(64)
//            42
//      23          19
//   15    8      4    16
// 64  X  X X    X X  X  X

//            42
//      23          19
//   64    8      4    16
// 15  X  X X    X X  X  X

//            42
//      64          19
//   23    8      4    16
// 15  X  X X    X X  X  X

//            64
//      42          19
//   23    8      4    16
// 15  X  X X    X X  X  X

// pop() - w czasie logarytmicznym
// pop()
//            15
//      42          19
//   23    8      4    16
// 64  X  X X    X X  X  X

//            15
//      42          19
//   23    8      4    16

//            42
//      15          19
//   23    8      4    16

//               1: 42
//        2: 23         3: 19
//   4: 15    5: 8   6: 4   7: 16

// 42 23 19 15 8 4 16
// w dół w lewo: i * 2
// w dół w prawo: i * 2 + 1
// w górę: i / 2

#include <iostream>
#include <vector>

class heap_priority_queue
{
public:
    heap_priority_queue() : elements(1, 0) {}

    void push(int n)
    {
        elements.push_back(n);
        std::size_t current = elements.size() - 1;
        while (elements[current] > elements[current / 2] && current > 1)
        {
            std::swap(elements[current], elements[current / 2]);
            current = current / 2;
        }
    }

    void pop()
    {
        std::swap(elements[1], elements.back());
        elements.pop_back();

        std::size_t current = 1;
        while (current * 2 < elements.size())
        {
            if (current * 2 + 1 == elements.size())
            {
                if (elements[current * 2] > elements[current])
                {
                    std::swap(elements[current], elements[current * 2]);
                    current = current * 2;
                }
                else
                {
                    break;
                }
            }
            else if (elements[current] < elements[current * 2] || elements[current] < elements[current * 2 + 1])
            {
                if (elements[current * 2] < elements[current * 2 + 1])
                {
                    std::swap(elements[current], elements[current * 2 + 1]);
                    current = current * 2 + 1;
                }
                else
                {
                    std::swap(elements[current], elements[current * 2]);
                    current = current * 2;
                }
            }
            else
            {
                break;
            }
        }
    }

    int top()
    {
        return elements[1];
    }

    bool empty()
    {
        return elements.size() == 1;
    }

private:
    std::vector<int> elements;
};

int main()
{
    heap_priority_queue pq;

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