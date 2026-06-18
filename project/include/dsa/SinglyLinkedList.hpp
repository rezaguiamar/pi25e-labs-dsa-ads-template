#pragma once
#include <stdexcept>
#include <cstddef>

template <class T>
class SinglyLinkedList {
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

    Node* head_;
    Node* tail_;
    std::size_t size_;

public:
    SinglyLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

    ~SinglyLinkedList() {
        while (head_) {
            Node* tmp = head_;
            head_ = head_->next;
            delete tmp;
        }
    }

    void push_back(const T& val) {
        Node* n = new Node(val);
        if (!tail_) { head_ = tail_ = n; }
        else { tail_->next = n; tail_ = n; }
        ++size_;
    }

    void push_front(const T& val) {
        Node* n = new Node(val);
        n->next = head_;
        head_ = n;
        if (!tail_) tail_ = n;
        ++size_;
    }

    T pop_front() {
        if (!head_) throw std::out_of_range("List is empty");
        T val = head_->data;
        Node* tmp = head_;
        head_ = head_->next;
        if (!head_) tail_ = nullptr;
        delete tmp;
        --size_;
        return val;
    }

    T& front() {
        if (!head_) throw std::out_of_range("List is empty");
        return head_->data;
    }

    bool empty() const { return size_ == 0; }
    std::size_t size() const { return size_; }

    bool find(const T& val) const {
        Node* cur = head_;
        while (cur) {
            if (cur->data == val) return true;
            cur = cur->next;
        }
        return false;
    }

    // Print all elements to stdout (for demo)
    void print() const {
        Node* cur = head_;
        while (cur) {
            std::cout << cur->data;
            if (cur->next) std::cout << " -> ";
            cur = cur->next;
        }
        std::cout << "\n";
    }
};
