#pragma once
#include <stdexcept>
#include <cstddef>

template <class T>
class Queue {
    T* data_;
    std::size_t cap_;
    std::size_t head_, tail_, size_;

    void grow() {
        std::size_t newCap = cap_ == 0 ? 4 : cap_ * 2;
        T* tmp = new T[newCap];
        for (std::size_t i = 0; i < size_; ++i)
            tmp[i] = data_[(head_ + i) % cap_];
        delete[] data_;
        data_ = tmp;
        head_ = 0;
        tail_ = size_;
        cap_ = newCap;
    }

public:
    Queue() : data_(nullptr), cap_(0), head_(0), tail_(0), size_(0) {}
    ~Queue() { delete[] data_; }

    void enqueue(const T& val) {
        if (size_ == cap_) grow();
        data_[tail_] = val;
        tail_ = (tail_ + 1) % cap_;
        ++size_;
    }

    void dequeue() {
        if (size_ == 0) throw std::out_of_range("Queue is empty");
        head_ = (head_ + 1) % cap_;
        --size_;
    }

    T& front() {
        if (size_ == 0) throw std::out_of_range("Queue is empty");
        return data_[head_];
    }

    bool empty() const { return size_ == 0; }
    std::size_t size() const { return size_; }
};
