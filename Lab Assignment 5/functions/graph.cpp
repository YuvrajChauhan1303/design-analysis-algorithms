#ifndef GRAPH
#define GRAPH

#include "header.hpp"
#include "vertex.cpp"
#include "edge.cpp"

graph::graph(int numberOfVertex, int numberOfEdges)
{
    this->label = '\0';
    this->numberOfEdges = numberOfEdges;
    this->numberOfVertex = numberOfVertex;
    this->vertexArray = new vertex *[numberOfVertex];
    this->edgeArray = new edge *[numberOfEdges];
}

int graph::getNumberOfVertex()
{
    return this->numberOfVertex;
}

int graph::getNumberOfEdges()
{
    return this->numberOfEdges;
}

vertex *graph::findVertex(char label)
{
    int i;
    for (i = 0; i < this->getNumberOfVertex(); i++)
    {
        if (this->vertexArray[i]->getLabel() == label)
            return this->vertexArray[i];
    }

    return nullptr;
}
void graph::inputGraph()
{
    int i;
    char vertexLabel;
    int edges;

    for (i = 0; i < this->getNumberOfVertex(); i++)
    {
        std::cout << "Enter Vertex Label: ";
        std::cin >> vertexLabel;

        this->vertexArray[i] = new vertex(vertexLabel, 1);
    }

    for(i = 0; i < this->getNumberOfVertex(); i++)
    {
        std::cout << "Enter Number of Edges for Vertex " << this->vertexArray[i]->getLabel() << " : ";

        std::cin >> edges;
        this->vertexArray[i]->setEdges(edges);
    }

    for (i = 0; i < this->getNumberOfEdges(); i++)
    {
        this->vertexArray[i]->inputEdges(this);
    }
}

void graph::createEdgeList()
{
    for(int i = 0 ; i<this->numberOfVertex ; i++)
    {
        for(int j = 0 ; j<this->vertexArray[i]->getNumberOfEdges();j++)
        {
            this->edgeArray[this->numberOfEdges--] = new edge(this->vertexArray[i]->edgesArray[j]); 
        }
    }
}
#endif