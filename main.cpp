#include "ListGraph.h"
#include <iostream>
#include <vector>
#include <cassert>


void printVector(const std::vector<int>& vec, const std::string& label) {
    std::cout << label << ": ";
    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Testing ListGraph...\n";


    ListGraph graph(4);


    graph.AddEdge(0, 1);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 0);
    graph.AddEdge(1, 3);

    std::cout << "Vertices count: " << graph.VerticesCount() << std::endl;


    std::cout << "\n--- GetNextVertices ---" << std::endl;
    for (int v = 0; v < graph.VerticesCount(); ++v) {
        auto next = graph.GetNextVertices(v);
        printVector(next, "From vertex " + std::to_string(v));
    }


    std::cout << "\n--- GetPrevVertices ---" << std::endl;
    for (int v = 0; v < graph.VerticesCount(); ++v) {
        auto prev = graph.GetPrevVertices(v);
        printVector(prev, "To vertex " + std::to_string(v));
    }


    std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
    ListGraph copied_graph(graph);

    std::cout << "Copied graph Vertices count: " << copied_graph.VerticesCount() << std::endl;


    for (int v = 0; v < copied_graph.VerticesCount(); ++v) {
        auto next_orig = graph.GetNextVertices(v);
        auto next_copy = copied_graph.GetNextVertices(v);
        // сравниваем размеры и содержимое 
        std::cout << "Vertex " << v << " next lists match: " << (next_orig == next_copy ? "Yes" : "No") << std::endl;
    }

    std::cout << "Test completed successfully!" << std::endl;
    return 0;
}