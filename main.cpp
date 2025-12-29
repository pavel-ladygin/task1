#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void sortAndPrintVector(const std::vector<int>& vec, const std::string& label) {
    std::vector<int> sorted_vec = vec;
    std::sort(sorted_vec.begin(), sorted_vec.end());
    std::cout << label << ": ";
    for (int v : sorted_vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

bool vectorsEqual(const std::vector<int>& v1, const std::vector<int>& v2) {
    if (v1.size() != v2.size()) return false;
    std::vector<int> s_v1 = v1, s_v2 = v2;
    std::sort(s_v1.begin(), s_v1.end());
    std::sort(s_v2.begin(), s_v2.end());
    return std::equal(s_v1.begin(), s_v1.end(), s_v2.begin());
}

template<typename GraphType>
void testGraphImplementation(const std::string& graph_name) {
    std::cout << "=== Testing " << graph_name << " ===" << std::endl;

    GraphType graph(4);

    graph.AddEdge(0, 1);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 0);
    graph.AddEdge(1, 3);

    std::cout << "Vertices count: " << graph.VerticesCount() << std::endl;


    std::cout << "--- GetNextVertices ---" << std::endl;
    for (int v = 0; v < graph.VerticesCount(); ++v) {
        auto next = graph.GetNextVertices(v);
        sortAndPrintVector(next, "From vertex " + std::to_string(v));
    }


    std::cout << "--- GetPrevVertices ---" << std::endl;
    for (int v = 0; v < graph.VerticesCount(); ++v) {
        auto prev = graph.GetPrevVertices(v);
        sortAndPrintVector(prev, "To vertex " + std::to_string(v));
    }


    std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
    GraphType copied_graph(graph);

    std::cout << "Copied graph Vertices count: " << copied_graph.VerticesCount() << std::endl;

    // Проверяем, что копия идентична оригиналу
    bool is_copy_correct = true;
    for (int v = 0; v < copied_graph.VerticesCount(); ++v) {
        auto next_orig = graph.GetNextVertices(v);
        auto next_copy = copied_graph.GetNextVertices(v);
        auto prev_orig = graph.GetPrevVertices(v);
        auto prev_copy = copied_graph.GetPrevVertices(v);

        if (!vectorsEqual(next_orig, next_copy) || !vectorsEqual(prev_orig, prev_copy)) {
            std::cout << "Copy mismatch for vertex " << v << std::endl;
            is_copy_correct = false;
            break; // Нашли ошибку, выходим из цикла
        }
    }

    if (is_copy_correct) {
        std::cout << "Copy constructor test PASSED for " << graph_name << "." << std::endl;
    } else {
        std::cout << "Copy constructor test FAILED for " << graph_name << "." << std::endl;
    }

    std::cout << "Test completed for " << graph_name << "!" << std::endl << std::endl;
}

int main() {
    std::cout << "Starting comprehensive tests for all graph implementations..." << std::endl << std::endl;

    testGraphImplementation<ListGraph>("ListGraph");

    testGraphImplementation<MatrixGraph>("MatrixGraph");

    testGraphImplementation<SetGraph>("SetGraph");

    testGraphImplementation<ArcGraph>("ArcGraph");

    std::cout << "All tests completed successfully!" << std::endl;
    return 0;
}