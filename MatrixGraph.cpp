#include "MatrixGraph.h"
#include <vector>
#include <cassert>

MatrixGraph::MatrixGraph(int vertices_count) : adjacency_matrix_(vertices_count, std::vector<bool>(vertices_count, false)) {
    assert(vertices_count >= 0);
}

MatrixGraph::MatrixGraph(const IGraph& graph) : adjacency_matrix_(graph.VerticesCount(), std::vector<bool>(graph.VerticesCount(), false)) {
    for (int v = 0; v < graph.VerticesCount(); ++v) {
        auto next_vertices = graph.GetNextVertices(v);
        for (int next_v : next_vertices) {
            AddEdge(v, next_v);
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    if (from >= 0 && from < adjacency_matrix_.size() && to >= 0 && to < adjacency_matrix_[0].size()) {
        adjacency_matrix_[from][to] = true;
    }
}

int MatrixGraph::VerticesCount() const {
    return static_cast<int>(adjacency_matrix_.size());
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacency_matrix_.size());
    std::vector<int> next_vertices;
    for (int i = 0; i < adjacency_matrix_[vertex].size(); ++i) {
        if (adjacency_matrix_[vertex][i]) {
            next_vertices.push_back(i);
        }
    }
    return next_vertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacency_matrix_.size());
    std::vector<int> prev_vertices;
    for (int i = 0; i < adjacency_matrix_.size(); ++i) {
        if (adjacency_matrix_[i][vertex]) {
            prev_vertices.push_back(i);
        }
    }
    return prev_vertices;
}