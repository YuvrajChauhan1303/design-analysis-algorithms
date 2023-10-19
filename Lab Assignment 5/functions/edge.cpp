#ifndef EDGE
#define EDGE

#include "functions.hpp"


edge::edge()
{
    this->label = "";
    this->fromVertexIndex = 0;
    this->toVertexIndex = 0;
}
void edge::setEdgeData(std::string label, int fromVertex, int toVertex)
{
    this->label = label;
    this->fromVertexIndex = fromVertex;
    this->toVertexIndex = toVertex;
}

std::string edge::getEdgeLabel()
{
    return this->label;
}

int edge::getFromVertex()
{
    return this->fromVertexIndex;
}
int edge::getToVertex()
{
    return this->toVertexIndex;
}

#endif // EDGE