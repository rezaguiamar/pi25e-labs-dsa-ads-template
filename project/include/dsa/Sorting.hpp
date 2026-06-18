#pragma once
#include <cstddef>

// ---- Bubble Sort ----
template <class T>
void bubble_sort(T* a, std::size_t n) {
    for (std::size_t i = 0; i < n; ++i)
        for (std::size_t j = 0; j + 1 < n - i; ++j)
            if (a[j] > a[j + 1]) {
                T tmp = a[j]; a[j] = a[j+1]; a[j+1] = tmp;
            }
}

// ---- Quicksort ----
template <class T>
int partition(T* arr, int low, int high) {
    T pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            T tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
        }
    }
    T tmp = arr[i+1]; arr[i+1] = arr[high]; arr[high] = tmp;
    return i + 1;
}

template <class T>
void quicksort(T* arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}
