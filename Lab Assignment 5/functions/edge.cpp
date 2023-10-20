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

public:
    edge();
    edge(const edge &other);
    void setData(std::string label, vertex *fromVertex, vertex *toVertex);
    vertex *getToVertex();
    void printData();
};

edge::edge()
{
    this->label = " ";
    this->fromVertex = nullptr;
    this->toVertex = nullptr;
}

edge::edge(const edge &other)
{
    this->label = other.label;
    this->fromVertex = other.fromVertex;
    this->toVertex = other.toVertex;
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

#endif