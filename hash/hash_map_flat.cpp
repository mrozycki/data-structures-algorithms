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
    bool deleted = false;
};

class hash_map {
public:
    hash_map() : size_(0), tombstones_(0), elements_(4, std::nullopt) {}

    std::optional<std::string> get(std::string const& key) const {
        auto h = hash(key, elements_.size());
        for (int i = 0; i < elements_.size(); ++i) {
            auto const& element = elements_[(h + i) % elements_.size()];
            if (!element) {
                return std::nullopt;
            } else if (element->key == key) {
                if (!element->deleted) {
                    return element->value;
                } else {
                    return std::nullopt;
                }
            }
        }
        return std::nullopt;
    }

    void set(std::string const& key, std::string const& value) {
        if (size_ + tombstones_ == elements_.size()) {
            resize(elements_.size() * 2);
        }
        std::cout << "set(" << key << ", " << value << "): hash = " << hash(key, elements_.size()) << ", ";
        auto h = hash(key, elements_.size());
        for (int i = 0; i < elements_.size(); ++i) {
            auto& element = elements_[(h + i) % elements_.size()];
            if (!element || element->key == key) {
                ++size_;
                if (element->deleted) --tombstones_;
                element = node{key, value, false};
                std::cout << "place = " << (h + i) % elements_.size() << ", ";
                break;
            }
        }
        std::cout << "size = " << size_ << "\n";
    }

    bool del(std::string const& key) {
        auto h = hash(key, elements_.size());
        for (int i = 0; i < elements_.size(); ++i) {
            auto& element = elements_[(h + i) % elements_.size()];
            if (!element) {
                    return false;
            } else if (element->key == key) {
                if (!element->deleted) {
                    element->deleted = true;
                    return true;
                    --size_;
                    ++tombstones_;
                    if (size_ < elements_.size() / 4) {
                        resize(elements_.size() / 2);
                    }
                } else {
                    return false;
                }
            }
        }
        return false;
    }

private:
    void resize(std::size_t new_size) {
        std::vector<std::optional<node>> old_elements = std::move(elements_);
        elements_ = std::vector<std::optional<node>>(new_size, std::nullopt);

        size_ = 0;
        tombstones_ = 0;
        for (auto&& element : old_elements) {
            if (!element->deleted) {
                std::cout << "resize: ";
                set(element->key, element->value);
            }
        }
    }

    std::size_t size_;
    std::size_t tombstones_;
    std::vector<std::optional<node>> elements_;
};

int main() {
    hash_map dict;
    dict.set("dom", "house");
    dict.set("drzwi", "door");
    dict.set("pies", "dog");
    dict.set("kot", "cat");
    dict.set("woda", "water");
    dict.set("ogien", "fire");
    dict.set("ziemia", "earth");
    dict.set("powietrze", "air");

    std::cout << "dict[dom] = " << *dict.get("dom") << "\n";
    std::cout << "dict[drzwi] = " << *dict.get("drzwi") << "\n";
    std::cout << "dict[pies] = " << *dict.get("pies") << "\n";
    std::cout << "dict[powietrze] = " << *dict.get("powietrze") << "\n";

    return 0;
}