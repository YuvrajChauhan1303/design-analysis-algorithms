#ifndef VERTEX
#define VERTEX  

#include "functions.hpp"

vertex::vertex()
{
    this->label = ' ';
    this->numberOfEdges = 0;
    this->edgesArray = nullptr;
    this->isExplored = false;
    this->onStack = false;
    this->topologicalSortIndex = 0;
}

void vertex::addLabel(char label)
{
    this->label = label;
    this->numberOfEdges = 0;
    this->edgesArray = nullptr;
}

char vertex::getLabel()
{
    return this->label;
}

void vertex::createEdgesArray(int numberOfEdges = 0)
{
    this->numberOfEdges = numberOfEdges;
    this->edgesArray = new edge[numberOfEdges];
}

void vertex::updateExplore()
{
    this->isExplored = true;
}

bool vertex::checkExplore()
{
    return this->isExplored;
}

int vertex::getNumberOfEdges()
{
    return this->numberOfEdges;
}

void vertex::trueOnStack()
{
    this->onStack = true;
}
void vertex::falseOnStack()
{
    this->onStack = false;
}
bool vertex::getOnStack()
{
    return this->onStack;
}

void vertex::markAsUnexplored()
{
    this->isExplored = false;
}

void vertex::setTopologicalSortIndex(int n)
{
    this->topologicalSortIndex = n;
}

int vertex::getTopologicalSortIndex()
{
    return this->topologicalSortIndex;
}

#endif // VERTEX