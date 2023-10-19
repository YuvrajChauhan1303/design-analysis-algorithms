#include "functions/header.hpp"
#include "functions/graph.cpp"
#include "functions/BFS.cpp"

int main()
{
    int numberOfVertex;
    int numberOfEdges;
    char source;

    std::cout << "Enter Number of Vertex: ";
    std::cin >> numberOfVertex;

    std::cout << "Enter Number of Edges: ";
    std::cin >> numberOfEdges;

    graph * g1 = new graph(numberOfVertex, numberOfEdges);
    g1->inputGraph();
    g1->createEdgeList();

    std::cout << "Enter Source Vertex for BFS: ";
    std::cin >> source;

    g1->BFS(source);

    return 0;
}
