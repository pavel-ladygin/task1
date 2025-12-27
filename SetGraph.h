#ifndef SETGRAPH_H
#define SETGRAPH_H

#include "IGraph.h"
#include <vector>
#include <unordered_set>

// Реализация IGraph через хэш-таблицы для списков смежности.
class SetGraph : public IGraph {
public:

    explicit SetGraph(int vertices_count);

    explicit SetGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::unordered_set<int>> adjacency_sets_; // Вектор unordered_set для хранения исходящих рёбер.
};

#endif 