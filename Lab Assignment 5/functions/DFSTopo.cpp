#ifndef DFS_TOPO
#define DFS_TOPO

#include "header.hpp"
#include "vertex.cpp"
#include "stack.cpp"

void graph::TopoSort()
{
    std::cout << "The Topological Ordering of the Graph is as Follows: \n";

    int i = 1;
    int stackSize = this->numberOfVertex;

    stack * s = new stack(stackSize);

    for (int i = 0; i < this->numberOfVertex; i++)
    {
        if (vertexArray[i].checkExplore() == false)
        {
            DFSTopo(&vertexArray[i], s);
        }
    }

    vertex * temp;

    while(!s->isEmpty())
    {
        temp = s->pop();
        temp->setTopoOrder(i++);
        std::cout << temp->getLabel() << " -> ";
    }

    std::cout << std::endl;
}

void graph::DFSTopo(vertex *source, stack *s)
{
    vertex *toVertex;

    source->updateExplore(true);

    for (int i = 0; i < source->getNumberOfEdges(); i++)
    {
        toVertex = source->edgesArray[i].getToVertex();

        if (toVertex->checkExplore() == false)
        {
            DFSTopo(toVertex, s);
        }
    }

    s->push(source);
}

#endif