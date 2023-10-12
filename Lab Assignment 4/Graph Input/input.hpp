#include <iostream>
#include <string>

// Struct Declaration
struct Vertex;
struct Edge;

// Global Linked Lists
Vertex *vertexList;
Edge *adjacencyList;

// Function Declaration:
Vertex *createVertex();
Vertex *addVertex(char label);
Vertex *findVertex(char label);
Edge *createEdge();
Edge *addEdge(std::string label);
Edge *findEdge(std::string label);
Vertex *inputEdge(char label);
void displayVertexList();
void displayAdjacencyList();
void inputGraph();