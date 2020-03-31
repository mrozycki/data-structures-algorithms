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

class hash_map {
public:
    hash_map() : size_(16), elements_(size_, std::nullopt) {}

    std::optional<std::string> get(std::string const& key) const {
        return elements_[hash(key, size_)];
    }

    void set(std::string const& key, std::string const& value) {
        std::cout << "set(" << key << ", " << value << "): hash = " << hash(key, size_) << "\n";
        elements_[hash(key, size_)] = value;
    }

    bool del(std::string const& key) {
        if (elements_[hash(key, size_)]) {
            elements_[hash(key, size_)] = {};
            return true;
        } else {
            return false;
        }

    }

private:
    std::size_t size_;
    std::vector<std::optional<std::string>> elements_;
};

int main() {
    hash_map dict;
    dict.set("dom", "house");
    dict.set("drzwi", "door");
    dict.set("pies", "dog");
    dict.set("kot", "cat");

    std::cout << "dict[dom] = " << *dict.get("dom") << "\n";

    return 0;
}