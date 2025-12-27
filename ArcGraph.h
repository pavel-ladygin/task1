#ifndef ARCGRAPH_H
#define ARCGRAPH_H

#include "IGraph.h"
#include <vector>
#include <utility> 

// Реализация IGraph через список рёбер 
class ArcGraph : public IGraph {
public:

    explicit ArcGraph(int vertices_count);


    explicit ArcGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    int vertices_count_;
    std::vector<std::pair<int, int>> edges_; // Вектор пар для хранения рёбер.
};

#endif // ARCGRAPH_H