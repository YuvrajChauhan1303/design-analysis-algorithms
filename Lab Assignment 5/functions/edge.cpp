#ifndef EDGE
#define EDGE

#include "header.hpp"
#include "vertex.cpp"

class edge
{
private:
    std::string label;
    vertex *fromVertex;
    vertex *toVertex;
    bool isForward;
    bool isBack;
    bool isTree;
    bool isCross;

public:
    edge();
    edge(const edge &other);
    std::string getLabel();
    void setData(std::string label, vertex *fromVertex, vertex *toVertex);
    vertex *getToVertex();
    void printData();
    void classifyEdge(char c);
    char getEdgeClassification();
};

edge::edge()
{
    this->label = " ";
    this->fromVertex = nullptr;
    this->toVertex = nullptr;
    this->isForward = false;
    this->isBack = false;
    this->isTree = false;
    this->isCross = false;
}

edge::edge(const edge &other)
{
    this->label = other.label;
    this->fromVertex = other.fromVertex;
    this->toVertex = other.toVertex;
    this->isForward = false;
    this->isBack = false;
    this->isTree = false;
    this->isCross = false;
}

std::string edge::getLabel()
{
    return this->label;
}

void edge::setData(std::string label, vertex *fromVertex, vertex *toVertex)
{
    this->label = label;
    this->fromVertex = fromVertex;
    this->toVertex = toVertex;
}

vertex *edge::getToVertex()
{
    return this->toVertex;
}

void edge::printData()
{
    std::cout << this->label << " : " << this->fromVertex->getLabel() << " -> " << this->toVertex->getLabel() << std::endl;
}

void edge::classifyEdge(char c)
{
    switch (c)
    {
    case 'f':
        this->isForward = true;
        break;
    case 'b':
        this->isBack = true;
        break;
    case 't':
        this->isTree = true;
        break;
    case 'c':
        this->isCross = true;
        break;
    }
}
#endif