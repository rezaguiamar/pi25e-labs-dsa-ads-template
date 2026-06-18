#pragma once
#include <stdexcept>
#include "DynamicArray.hpp"

template <class T>
class Stack {
    DynamicArray<T> arr_;
public:
    void push(const T& val) { arr_.push_back(val); }

    void pop() {
        if (arr_.empty()) throw std::out_of_range("Stack is empty");
        arr_.pop_back();
    }

    T& top() {
        if (arr_.empty()) throw std::out_of_range("Stack is empty");
        return arr_[arr_.size() - 1];
    }

    bool empty() const { return arr_.empty(); }
    std::size_t size() const { return arr_.size(); }
};
