#ifndef DFS_CPP
#define DFS_CPP

#include "header.hpp"
#include "vertex.cpp"
#include "queue.cpp"

void graph::DFS(vertex * source)
{
    vertex *toVertex;

    source->updateExplore(true);

    std::cout << "Visiting vertex: " << source->getLabel() << std::endl;

    for (int i = 0; i < source->getNumberOfEdges(); i++)
    {
        toVertex = source->edgesArray[i].getToVertex();

        if (toVertex->checkExplore() == false)
        {
            std::cout << "Exploring edge to vertex: " << toVertex->getLabel() << std::endl;
            DFS(toVertex);
        }
    }
}
#endif
