#ifndef HEADER_H 
#define HEADER_H

#include<iostream>
#include<string>

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
    vertex **vertexArray;
    edge **edgeArray;
    int getNumberOfVertex();
    vertex *findVertex(char label);
    void inputGraph();
    void createEdgeList();
    int getNumberOfEdges();
    void BFS(char source);
};

#endif //HEADER_H