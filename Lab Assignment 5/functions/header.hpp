#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>

class vertex;
class edge;
class stack;
class queue;

class graph
{
private:
    char label;
    int numberOfVertex;
    int numberOfEdges;

public:
    graph(int numberOfVertex, int numberOfEdges);
    vertex *vertexArray;
    edge **edgeArray;
    int getNumberOfVertex();
    vertex *findVertex(char label);
    void inputGraph();
    void createEdgeList();
    int getNumberOfEdges();
    void displayVertexList();
    void displayEdgeList();
    void resetExplored();

    // Graph Algorithms
    void BFS(vertex *source);
    void DFS(vertex *source);
};

class vertex
{
private:
    char label;
    int numberOfEdges;
    bool isExplored;

public:
    edge *edgesArray;
    vertex();
    vertex(char label);
    void setLabel(char label);
    void inputEdges(graph *g);
    void setEdges(int n);
    char getLabel();
    int getNumberOfEdges();
    bool checkExplore();
    void updateExplore(bool value);
};

#endif // HEADER_H