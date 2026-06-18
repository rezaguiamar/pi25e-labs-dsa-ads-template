#pragma once
#include <stdexcept>
#include <cstddef>

template <class T>
class BST {
    struct Node {
        T key;
        Node* left;
        Node* right;
        Node(const T& k) : key(k), left(nullptr), right(nullptr) {}
    };

    Node* root_;
    std::size_t size_;

    void destroy(Node* n) {
        if (!n) return;
        destroy(n->left);
        destroy(n->right);
        delete n;
    }

    Node* insert(Node* n, const T& key) {
        if (!n) { ++size_; return new Node(key); }
        if (key < n->key) n->left = insert(n->left, key);
        else if (key > n->key) n->right = insert(n->right, key);
        return n;
    }

    bool contains(Node* n, const T& key) const {
        if (!n) return false;
        if (key == n->key) return true;
        if (key < n->key) return contains(n->left, key);
        return contains(n->right, key);
    }

    void inorder(Node* n, T* out, std::size_t& idx) const {
        if (!n) return;
        inorder(n->left, out, idx);
        out[idx++] = n->key;
        inorder(n->right, out, idx);
    }

    int height(Node* n) const {
        if (!n) return 0;
        int l = height(n->left), r = height(n->right);
        return 1 + (l > r ? l : r);
    }

public:
    BST() : root_(nullptr), size_(0) {}
    ~BST() { destroy(root_); }

    void insert(const T& key) { root_ = insert(root_, key); }
    bool contains(const T& key) const { return contains(root_, key); }
    std::size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }
    int height() const { return height(root_); }

    void inorder(T* out) const {
        std::size_t idx = 0;
        inorder(root_, out, idx);
    }
};
