#include "functions/header.hpp"
#include "functions/graph.cpp"
#include "functions/BFS.cpp"
#include "functions/DFS.cpp"
#include "functions/graphutils.cpp"
#include "functions/checkCycle.cpp"
#include "functions/DFSTopo.cpp"
#include "functions/diameter.cpp"
#include "functions/classifyEdges.cpp"
#include "functions/singlyConnected.cpp"

#define nl std::cout << std::endl

int main()
{
    int numberOfVertex;
    int numberOfEdges;
    char source;
    vertex *sourceVertex;

    std::cout << "Enter Number of Vertex: ";
    std::cin >> numberOfVertex;

    std::cout << "Enter Number of Edges: ";
    std::cin >> numberOfEdges;

    graph *g1 = new graph(numberOfVertex, numberOfEdges);

    g1->inputGraph();
    g1->createEdgeList();

    int choice;
    do
    {
        nl;
        std::cout << "Menu Options:" << std::endl;
        std::cout << "1. Display Vertex List" << std::endl;
        std::cout << "2. Display Edge List" << std::endl;
        std::cout << "3. BFS Traversal" << std::endl;
        std::cout << "4. DFS Traversal" << std::endl;
        std::cout << "5. Check for Cycle" << std::endl;
        std::cout << "6. Topological Sorting" << std::endl;
        std::cout << "7. Calculate Diameter" << std::endl;
        std::cout << "8. Classify Edges" << std::endl;
        std::cout << "9. Check for Singly Connected Graph" << std::endl;
        std::cout << "10. Edge Classification" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            g1->displayVertexList();
            break;
        case 2:
            g1->displayEdgeList();
            break;
        case 3:
            std::cout << "Enter Source Vertex for BFS: ";
            std::cin >> source;
            sourceVertex = g1->findVertex(source);
            g1->BFS(sourceVertex);
            g1->resetExplored();
            break;
        case 4:
            std::cout << "Enter Source Vertex for DFS: ";
            std::cin >> source;
            sourceVertex = g1->findVertex(source);
            g1->DFS(sourceVertex);
            g1->resetExplored();
            break;
        case 5:
            if (g1->checkCycle())
                std::cout << "Graph contains a cycle." << std::endl;
            else
                std::cout << "Graph does not contain a cycle." << std::endl;
            break;
        case 6:
            g1->resetExplored();
            g1->TopoSort();
            break;
        case 7:
            std::cout << "The Diameter of the Graph is: " << g1->diameter() << std::endl;
            break;
        case 8:
            std::cout << "Enter Source Vertex for classifying Edges: ";
            std::cin >> source;
            sourceVertex = g1->findVertex(source);
            g1->classifyEdges(sourceVertex);
            break;
        case 9:
            if (g1->isSinglyConnected())
                std::cout << "The graph is singly connected." << std::endl;
            else
                std::cout << "The graph is not singly connected." << std::endl;
            break;
        case 10:
            char classification;
            std::cout << "Enter the classification (f, b, t, or c): ";
            std::cin >> classification;
            g1->printEdgesByClassification(classification);
            break;

        case 0:
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 0);

    delete g1;

    return 0;
}