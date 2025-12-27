#ifndef MATRIXGRAPH_H
#define MATRIXGRAPH_H

#include "IGraph.h"
#include <vector>

// Реализация IGraph через матрицу смежности.
class MatrixGraph : public IGraph {
public:

    explicit MatrixGraph(int vertices_count);

    explicit MatrixGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<bool>> adjacency_matrix_; // Матрица смежности.
};

#endif