#include <iostream>
#include "dsa/DynamicArray.hpp"
#include "dsa/Stack.hpp"
#include "dsa/Queue.hpp"
#include "dsa/SinglyLinkedList.hpp"
#include "dsa/BST.hpp"
#include "dsa/Graph.hpp"
#include "dsa/Sorting.hpp"

// -----------------------------------------------
// Helper: print array
// -----------------------------------------------
void print_array(int* a, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << a[i];
        if (i + 1 < n) std::cout << " ";
    }
    std::cout << "\n";
}

// -----------------------------------------------
// 1. Stack demo
// -----------------------------------------------
void demo_stack() {
    std::cout << "\n=== Stack (LIFO) ===\n";
    Stack<int> s;
    int vals[] = {10, 20, 30, 40, 50};
    std::cout << "Pushing: ";
    for (int v : vals) { std::cout << v << " "; s.push(v); }
    std::cout << "\nPopping: ";
    while (!s.empty()) { std::cout << s.top() << " "; s.pop(); }
    std::cout << "\n";
}

// -----------------------------------------------
// 2. Queue demo
// -----------------------------------------------
void demo_queue() {
    std::cout << "\n=== Queue (FIFO) ===\n";
    Queue<int> q;
    int vals[] = {1, 2, 3, 4, 5};
    std::cout << "Enqueuing: ";
    for (int v : vals) { std::cout << v << " "; q.enqueue(v); }
    std::cout << "\nDequeuing: ";
    while (!q.empty()) { std::cout << q.front() << " "; q.dequeue(); }
    std::cout << "\n";
}

// -----------------------------------------------
// 3. Linked list demo
// -----------------------------------------------
void demo_linked_list() {
    std::cout << "\n=== Singly Linked List ===\n";
    SinglyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_front(5);
    std::cout << "List after push_back(10,20,30) and push_front(5):\n  ";
    list.print();

    std::cout << "Find 20? " << (list.find(20) ? "yes" : "no") << "\n";
    std::cout << "Find 99? " << (list.find(99) ? "yes" : "no") << "\n";

    int removed = list.pop_front();
    std::cout << "pop_front() removed: " << removed << "\n";
    std::cout << "List now: ";
    list.print();
}

// -----------------------------------------------
// 4. BST demo
// -----------------------------------------------
void demo_bst() {
    std::cout << "\n=== Binary Search Tree ===\n";
    BST<int> bst;
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    std::cout << "Inserting: ";
    for (int v : vals) { std::cout << v << " "; bst.insert(v); }
    std::cout << "\nSize: " << bst.size() << ", Height: " << bst.height() << "\n";

    std::cout << "Inorder (sorted): ";
    int* out = new int[bst.size()];
    bst.inorder(out);
    for (std::size_t i = 0; i < bst.size(); ++i) std::cout << out[i] << " ";
    delete[] out;

    std::cout << "\nContains 40? " << (bst.contains(40) ? "yes" : "no") << "\n";
    std::cout << "Contains 99? " << (bst.contains(99) ? "yes" : "no") << "\n";
}

// -----------------------------------------------
// 5. Bubble Sort demo
// -----------------------------------------------
void demo_bubble_sort() {
    std::cout << "\n=== Bubble Sort ===\n";
    int a[] = {64, 25, 12, 22, 11};
    int n = 5;
    std::cout << "Before: "; print_array(a, n);
    bubble_sort(a, (std::size_t)n);
    std::cout << "After:  "; print_array(a, n);
}

// -----------------------------------------------
// 6. Quicksort demo
// -----------------------------------------------
void demo_quicksort() {
    std::cout << "\n=== Quicksort ===\n";
    int a[] = {9, 3, 7, 1, 5, 8, 2, 4, 6};
    int n = 9;
    std::cout << "Before: "; print_array(a, n);
    quicksort(a, 0, n - 1);
    std::cout << "After:  "; print_array(a, n);
}

// -----------------------------------------------
// 7. Graph BFS & DFS demo
// -----------------------------------------------
void visit_node(int v) { std::cout << v << " "; }

void demo_graph() {
    std::cout << "\n=== Graph: BFS and DFS ===\n";
    // Simple undirected graph:
    //   0 - 1 - 2
    //   |       |
    //   3 - 4 - 5
    Graph g(6, false);
    g.add_edge(0, 1); g.add_edge(1, 2);
    g.add_edge(0, 3); g.add_edge(2, 5);
    g.add_edge(3, 4); g.add_edge(4, 5);

    std::cout << "Graph edges: 0-1, 1-2, 0-3, 2-5, 3-4, 4-5\n";
    std::cout << "BFS from 0: "; g.bfs(0, visit_node); std::cout << "\n";
    std::cout << "DFS from 0: "; g.dfs(0, visit_node); std::cout << "\n";
}

// -----------------------------------------------
// 8. DynamicArray demo
// -----------------------------------------------
void demo_dynamic_array() {
    std::cout << "\n=== Dynamic Array ===\n";
    DynamicArray<int> arr;
    for (int i = 1; i <= 6; ++i) arr.push_back(i * 10);
    std::cout << "Elements (size=" << arr.size() << ", cap=" << arr.capacity() << "): ";
    for (std::size_t i = 0; i < arr.size(); ++i) std::cout << arr[i] << " ";
    std::cout << "\n";
    arr.pop_back();
    std::cout << "After pop_back: ";
    for (std::size_t i = 0; i < arr.size(); ++i) std::cout << arr[i] << " ";
    std::cout << "\n";
}

// -----------------------------------------------
// Menu
// -----------------------------------------------
void print_menu() {
    std::cout << "\n=============================\n";
    std::cout << "   Algorithm Playground\n";
    std::cout << "=============================\n";
    std::cout << "1. Test Stack\n";
    std::cout << "2. Test Queue\n";
    std::cout << "3. Test Linked List\n";
    std::cout << "4. Test Binary Search Tree\n";
    std::cout << "5. Test Dynamic Array\n";
    std::cout << "6. Sort with Bubble Sort\n";
    std::cout << "7. Sort with Quicksort\n";
    std::cout << "8. Graph BFS and DFS\n";
    std::cout << "9. Run All Demos\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose: ";
}

int main() {
    int choice;
    do {
        print_menu();
        std::cin >> choice;
        switch (choice) {
            case 1: demo_stack();         break;
            case 2: demo_queue();         break;
            case 3: demo_linked_list();   break;
            case 4: demo_bst();           break;
            case 5: demo_dynamic_array(); break;
            case 6: demo_bubble_sort();   break;
            case 7: demo_quicksort();     break;
            case 8: demo_graph();         break;
            case 9:
                demo_dynamic_array();
                demo_stack();
                demo_queue();
                demo_linked_list();
                demo_bst();
                demo_bubble_sort();
                demo_quicksort();
                demo_graph();
                break;
            case 0: std::cout << "Goodbye!\n"; break;
            default: std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
