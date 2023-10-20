#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <climits>

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
    void deleteEdgeArray();

    // Graph Algorithms
    void BFS(vertex *source);
    void DFS(vertex *source);
    bool checkCycle();
    bool DFS_Cycle(vertex *source);
    void TopoSort();
    void DFSTopo(vertex *source, stack *s);
    void classifyEdges(vertex *source);
    int diameter();
    void AugmentedBFS(vertex *source);
    int shortestPath(vertex *source, vertex *destination);
    int countPaths(vertex *source, vertex *destination);
    void DFS_for_singlyConnected(vertex *source, vertex *destination, int &count);
    bool isSinglyConnected();
};

class vertex
{
private:
    char label;
    int numberOfEdges;
    bool isExplored;
    bool onStack;
    int topoOrder;
    int distance;
    int time;

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
    void trueOnStack();
    void falseOnStack();
    bool checkOnStack();
    void setTopoOrder(int n);
    int getTopoOrder();
    void setDistance(int n);
    int getDistance();
    int getTime();
    void setTime(int n);
};

#endif // HEADER_H