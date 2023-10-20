#ifndef UTILS
#define UTILS

#include "header.hpp"
#include "vertex.cpp"
#include "queue.cpp"

void graph::displayVertexList()
{
    for (int i = 0; i < this->numberOfVertex; i++)
        std::cout << this->vertexArray[i].getLabel() << " ";

    std::cout << std::endl;
}
void graph::displayEdgeList()
{
    for (int i = 0; i < this->numberOfEdges; i++)
        this->edgeArray[i]->printData();
}

void graph::resetExplored()
{
    for (int i = 0; i < this->getNumberOfVertex(); i++)
    {
        vertexArray[i].updateExplore(false);
    }
}

char edge::getEdgeClassification()
{
    if (this->isForward)
        return 'f';
    if (this->isBack)
        return 'b';
    if (this->isForward)
        return 'c';

    return 't';
}

#endif
