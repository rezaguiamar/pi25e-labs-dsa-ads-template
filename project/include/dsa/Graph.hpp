#pragma once
#include <cstddef>
#include "DynamicArray.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

class Graph {
    int V_;
    bool directed_;
    DynamicArray<int>* adj_;  // array of adjacency lists

public:
    Graph(int vertices, bool directed = false)
        : V_(vertices), directed_(directed) {
        adj_ = new DynamicArray<int>[V_];
    }

    ~Graph() { delete[] adj_; }

    void add_edge(int u, int v) {
        adj_[u].push_back(v);
        if (!directed_) adj_[v].push_back(u);
    }

    int vertex_count() const { return V_; }

    void bfs(int start, void (*visit)(int)) {
        bool* visited = new bool[V_]();
        Queue<int> q;
        visited[start] = true;
        q.enqueue(start);
        while (!q.empty()) {
            int node = q.front(); q.dequeue();
            visit(node);
            for (std::size_t i = 0; i < adj_[node].size(); ++i) {
                int nb = adj_[node][i];
                if (!visited[nb]) {
                    visited[nb] = true;
                    q.enqueue(nb);
                }
            }
        }
        delete[] visited;
    }

    void dfs(int start, void (*visit)(int)) {
        bool* visited = new bool[V_]();
        dfs_helper(start, visited, visit);
        delete[] visited;
    }

private:
    void dfs_helper(int node, bool* visited, void (*visit)(int)) {
        visited[node] = true;
        visit(node);
        for (std::size_t i = 0; i < adj_[node].size(); ++i) {
            int nb = adj_[node][i];
            if (!visited[nb]) dfs_helper(nb, visited, visit);
        }
    }
};
