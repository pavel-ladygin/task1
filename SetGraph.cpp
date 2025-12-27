#include "SetGraph.h"
#include <vector>
#include <unordered_set>
#include <cassert>

SetGraph::SetGraph(int vertices_count) : adjacency_sets_(vertices_count) {
    assert(vertices_count >= 0);
}

SetGraph::SetGraph(const IGraph& graph) : adjacency_sets_(graph.VerticesCount()) {
    for (int v = 0; v < graph.VerticesCount(); ++v) {
        auto next_vertices = graph.GetNextVertices(v);
        for (int next_v : next_vertices) {
            AddEdge(v, next_v);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    if (from >= 0 && from < adjacency_sets_.size() && to >= 0 && to < adjacency_sets_.size()) {
        adjacency_sets_[from].insert(to);
    }
}

int SetGraph::VerticesCount() const {
    return static_cast<int>(adjacency_sets_.size());
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacency_sets_.size());
    return std::vector<int>(adjacency_sets_[vertex].begin(), adjacency_sets_[vertex].end());
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacency_sets_.size());
    std::vector<int> prev_vertices;
    for (int v = 0; v < adjacency_sets_.size(); ++v) {
        if (adjacency_sets_[v].count(vertex)) {
            prev_vertices.push_back(v);
        }
    }
    return prev_vertices;
}