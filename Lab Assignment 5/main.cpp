#include "functions/header.hpp"
#include "functions/graph.cpp"
#include "functions/BFS.cpp"
#include "functions/DFS.cpp"
#include "functions/graphutils.cpp"

#define nl std::cout<<std::endl 

int main()
{
    int numberOfVertex;
    int numberOfEdges;
    char source;

    std::cout << "Enter Number of Vertex: ";
    std::cin >> numberOfVertex;

    std::cout << "Enter Number of Edges: ";
    std::cin >> numberOfEdges;

    graph *g1 = new graph(numberOfVertex, numberOfEdges);

    g1->inputGraph();
    g1->createEdgeList();

    g1->displayVertexList();
    g1->displayEdgeList();

    std::cout << "Enter Source Vertex for BFS: ";
    std::cin >> source;

    vertex *sourceVertex = g1->findVertex(source);
    nl;
    nl;

    g1->BFS(sourceVertex);
    g1->resetExplored();
    nl;
    nl;
    
    g1->DFS(sourceVertex);
    g1->resetExplored();

    return 0;
}