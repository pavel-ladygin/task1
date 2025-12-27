#include "ArcGraph.h"
#include <vector>
#include <utility>
#include <cassert>

ArcGraph::ArcGraph(int vertices_count) : vertices_count_(vertices_count) {
    assert(vertices_count >= 0);
}

ArcGraph::ArcGraph(const IGraph& graph) : vertices_count_(graph.VerticesCount()) {
    for (int v = 0; v < graph.VerticesCount(); ++v) {
        auto next_vertices = graph.GetNextVertices(v);
        for (int next_v : next_vertices) {
            AddEdge(v, next_v);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    if (from >= 0 && from < vertices_count_ && to >= 0 && to < vertices_count_) {
        edges_.push_back({from, to});
    }
}

int ArcGraph::VerticesCount() const {
    return vertices_count_;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < vertices_count_);
    std::vector<int> next_vertices;
    for (const auto& edge : edges_) {
        if (edge.first == vertex) {
            next_vertices.push_back(edge.second);
        }
    }
    return next_vertices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < vertices_count_);
    std::vector<int> prev_vertices;
    for (const auto& edge : edges_) {
        if (edge.second == vertex) {
            prev_vertices.push_back(edge.first);
        }
    }
    return prev_vertices;
}