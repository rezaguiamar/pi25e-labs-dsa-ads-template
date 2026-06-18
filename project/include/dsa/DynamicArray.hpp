#pragma once
#include <stdexcept>
#include <cstddef>

template <class T>
class DynamicArray {
    T* data_;
    std::size_t size_;
    std::size_t cap_;

    void grow() {
        std::size_t newCap = cap_ == 0 ? 2 : cap_ * 2;
        T* tmp = new T[newCap];
        for (std::size_t i = 0; i < size_; ++i) tmp[i] = data_[i];
        delete[] data_;
        data_ = tmp;
        cap_ = newCap;
    }

public:
    DynamicArray() : data_(nullptr), size_(0), cap_(0) {}
    ~DynamicArray() { delete[] data_; }

    std::size_t size() const { return size_; }
    std::size_t capacity() const { return cap_; }
    bool empty() const { return size_ == 0; }

    T& operator[](std::size_t i) { return data_[i]; }
    const T& operator[](std::size_t i) const { return data_[i]; }

    T& at(std::size_t i) {
        if (i >= size_) throw std::out_of_range("index out of range");
        return data_[i];
    }

    void push_back(const T& val) {
        if (size_ == cap_) grow();
        data_[size_++] = val;
    }

    void pop_back() {
        if (size_ > 0) --size_;
    }
};
