#include "ListGraph.h"
#include <cassert>

ListGraph::ListGraph(int vertices_count) : adjacency_lists_(vertices_count) {
    assert(vertices_count >= 0);
}

ListGraph::ListGraph(const IGraph& graph) : adjacency_lists_(graph.VerticesCount()) {
    for (int v = 0; v < graph.VerticesCount(); ++v) {
        auto next_vertices = graph.GetNextVertices(v);
        for (int next_v : next_vertices) {
            AddEdge(v, next_v);
        }
    }
}

void ListGraph::AddEdge(int from, int to) {
    if (from >= 0 && from < adjacency_lists_.size() && to >= 0 && to < adjacency_lists_.size()) {
        adjacency_lists_[from].push_back(to);
    }
}

int ListGraph::VerticesCount() const {
    return static_cast<int>(adjacency_lists_.size());
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacency_lists_.size());
    return std::vector<int>(adjacency_lists_[vertex].begin(), adjacency_lists_[vertex].end());
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacency_lists_.size());
    std::vector<int> prev_vertices;
    for (int v = 0; v < adjacency_lists_.size(); ++v) {
        // Ищем вершину vertex в списке исходящих рёбер из v
        if (std::find(adjacency_lists_[v].begin(), adjacency_lists_[v].end(), vertex) != adjacency_lists_[v].end()) {
            prev_vertices.push_back(v);
        }
    }
    return prev_vertices;
}