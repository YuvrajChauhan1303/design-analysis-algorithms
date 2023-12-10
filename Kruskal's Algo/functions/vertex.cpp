#ifndef VERTEX
#define VERTEX

#include "kruskal.hpp"
#include "edge.cpp" 

using namespace std;

class vertex
{
private:
    int label;
    vector<int> edgeIndices; 

public:
    vertex(int label);

    void addEdge(char label, int fromIndex, int toIndex, int weight);

    int getLabel() const;
    const vector<int>& getEdgeIndices() const;
};

vector<edge> globalList;

vertex::vertex(int label) 
{
    this->label = label;
}

void vertex::addEdge(char label, int fromIndex, int toIndex, int weight)
{
    edge Edge = edge(label, fromIndex, toIndex, weight);

    edgeIndices.push_back(globalList.size() - 1);

    globalList.push_back(Edge);
}

int vertex::getLabel() const
{
    return this->label;
}

const vector<int>& vertex::getEdgeIndices() const
{
    return edgeIndices;
}

#endif
