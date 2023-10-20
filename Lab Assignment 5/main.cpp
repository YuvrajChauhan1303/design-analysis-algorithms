#include "functions/header.hpp"
#include "functions/graph.cpp"
#include "functions/BFS.cpp"
#include "functions/DFS.cpp"
#include "functions/graphutils.cpp"
#include "functions/checkCycle.cpp"
#include "functions/DFSTopo.cpp"
#include "functions/diameter.cpp"

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

    nl;
    nl;

    bool isCycle = g1->checkCycle();

    isCycle ? std::cout << "Is a Cycle" : std::cout << "Is NOT a Cycle"; nl; 
    g1->resetExplored();
    g1->TopoSort();

    nl; nl;

    g1->resetExplored();
    std::cout << "The Diameter of the Graph is: " <<g1->diameter(); nl;

    return 0;
}