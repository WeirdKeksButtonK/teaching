#include <memory>
#include <string>

template<typename T>
class Vector {
public:
    using value_type = T;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = pointer;
    using const_iterator = const_pointer;

    Vector() = default;

    void clear() noexcept {
        // use std::destroy_n
    }

    void reserve(size_t size) {
        if (capacity_ >= size) {
            return;
        }
        const auto count = size_;
        pointer data = reinterpret_cast<value_type*>(new char[size * sizeof(value_type)]);
        std::uninitialized_move_n(begin(), size_, data);
        // for (size_t i = 0; i < size; ++i) {
        //     new (data[i]) value_type(std::move(data_[i]));
        // }
        delete_data();
        data_ = data;
        size_ = count;
        capacity_ = size;
    }

    void pop_back() noexcept {
        std::destroy_at(end() - 1);
        --size_;
    }

    iterator begin() {
        return data_;
    }

    const_iterator begin() const {
        return data_;
    }

    iterator end() {
        return data_;
    }

    const_iterator end() const {
        return data_;
    }

private:
    const static size_t expanding_factor_{2};

    void delete_data() {
        clear();
        free_storage();
    }

    void free_storage() {
        free_memory(data_);
        capacity_ = 0;
    }

    static void free_memory(pointer data) {
        operator delete[](data);
    }

    pointer data_{nullptr};
    size_t size_{0};
    size_t capacity_{0};
};


int main() {
    Vector<std::string> v;

    return 0;
}
