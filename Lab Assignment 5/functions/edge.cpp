#ifndef EDGE
#define EDGE

#include "header.hpp"

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
    vertex * getToVertex();
};

edge::edge()
{
    this->label = " ";
    this->fromVertex = nullptr;
    this->toVertex = nullptr;
}

edge::edge(const edge& other) {
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

vertex * edge::getToVertex()
{
    return this->toVertex;
}

#endif