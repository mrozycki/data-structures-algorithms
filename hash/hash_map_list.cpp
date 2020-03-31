#include <iostream>
#include <optional>
#include <string>
#include <vector>

std::size_t hash(std::string const& key, std::size_t ceiling) {
    std::size_t sum = 0;
    for (char c : key) {
        sum += c;
    }
    return sum % ceiling;
}

struct node {
    std::string key;
    std::string value;
    node* next;
};

class hash_map {
public:
    hash_map() : size_(0), elements_(4, nullptr) {}

    std::optional<std::string> get(std::string const& key) const {
        auto current = elements_[hash(key, elements_.size())];
        while (current) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return std::nullopt;
    }

    void set(std::string const& key, std::string const& value) {
        if (size_ == elements_.size()) {
            resize(2 * size_);
        }
        std::cout << "set(" << key << ", " << value << "): hash = " << hash(key, elements_.size()) << "\n";
        auto h = hash(key, elements_.size());
        elements_[h] = new node{key, value, elements_[h]};
        ++size_;
    }

    std::string& operator[](std::string const& key) {
        auto h = hash(key, elements_.size());
        auto current = elements_[h];
        while (current) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }

        if (size_ == elements_.size()) {
            resize(2 * size_);
        }
        ++size_;
        elements_[h] = new node{key, {}, elements_[h]};
        return elements_[h]->value;
    }

    bool del(std::string const& key) {
        if (size_ < elements_.size() / 4) {
            resize(elements_.size() / 2);
        }
        node** current = &elements_[hash(key, elements_.size())];
        while (*current) {
            if ((*current)->key == key) {
                auto to_delete = *current;
                *current = (*current)->next;
                delete to_delete;
                --size_;
                return true;
            }
            current = &((*current)->next);
        }
        return false;
    }

private:
    void resize(std::size_t new_size) {
        std::vector<node*> old_elements;
        for (auto& element : elements_) {
            while (element) {
                old_elements.push_back(element);
                auto new_next = element->next;
                element->next = nullptr;
                element = new_next;
            }
        }
        elements_.resize(new_size);
        for (auto& element: old_elements) {
            // set(element->key, element->value);
            auto h = hash(element->key, new_size);
            std::cout << "resize: set(" << element->key << ", " << element->value << "): "
                << "hash = " << h << "\n";
            element->next = elements_[h];
            elements_[h] = element;
        }
    }

    std::size_t size_;
    std::vector<node*> elements_;
};

int main() {
    hash_map dict;
    dict["dom"] = "house";
    dict["drzwi"] = "door";
    dict["pies"] = "dog";
    dict["kot"] = "cat";
    dict["woda"] = "water";
    dict["ogien"] = "fire";
    dict["ziemia"] = "earth";
    dict["powietrze"] = "air";

    std::cout << "dict[dom] = " << dict["dom"] << "\n";
    std::cout << "dict[drzwi] = " << dict["drzwi"] << "\n";
    std::cout << "dict[pies] = " << dict["pies"] << "\n";
    std::cout << "dict[powietrze] = " << dict["powietrze"] << "\n";

    dict["dom"] = "home";

    std::cout << "dict[dom] = " << dict["dom"] << "\n";

    return 0;
}