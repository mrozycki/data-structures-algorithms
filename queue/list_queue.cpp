#include <cstdlib>
#include <iostream>

struct node {
    int value;
    node* next;
};

class queue {
public:
    queue() : front(nullptr), back(nullptr) {}

    void push(int value) {
        auto new_node = new node{value, nullptr};
        if (back == nullptr) {
            front = new_node;
            back = new_node;
        } else {
            back->next = new_node;
            back = back->next;
        }
    }

    int pop() {
        auto node_to_remove = front;
        front = front->next;
        if (front == nullptr) {
            back = nullptr;
        }

        auto value_to_return = node_to_remove->value;
        delete node_to_remove;
        return value_to_return;
    }

    bool is_empty() const {
        return front == nullptr;
    }

private:
    node* front;
    node* back;
};

int main() {
    queue q;
    for (std::size_t i = 0; i < 10000000; ++i) {
        q.push(rand() % 201 - 100);
    }

    while (!q.is_empty()) {
        q.pop();
    }

    return 0;
}
