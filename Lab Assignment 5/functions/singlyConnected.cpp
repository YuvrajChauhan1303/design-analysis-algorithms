#ifndef SINGLY_CONNECTED
#define SINGLY_CONNECTED

#include "header.hpp"
#include "vertex.cpp"

bool graph::isSinglyConnected()
{
    int numberOfPaths;

    for (int i = 0; i < this->getNumberOfVertex(); i++)
    {
        for (int j = 0; j < this->getNumberOfVertex(); j++)
        {
            numberOfPaths = countPaths(&this->vertexArray[i], &this->vertexArray[j]);

            if (numberOfPaths > 1)
            {
                break;
                return false;
            }
        }
    }
    return true;
}

int graph::countPaths(vertex *source, vertex *destination)
{
    int count = 0;

    resetExplored();

    vertex *sourceVertex = nullptr;
    for (int i = 0; i < this->numberOfVertex; i++)
    {
        if (&this->vertexArray[i] == source)
        {
            sourceVertex = source;
            break;
        }
    }

    if (sourceVertex)
        DFS_for_singlyConnected(sourceVertex, destination, count);

    return count;
}

void graph::DFS_for_singlyConnected(vertex *source, vertex *destination, int &count)
{
    if (source == destination)
    {
        count++;
        return;
    }

    source->updateExplore(true);
    vertex *toVertex;

    for (int i = 0; i < source->getNumberOfEdges(); i++)
    {
        toVertex = source->edgesArray[i].getToVertex();

        if (!toVertex->checkExplore())
            DFS_for_singlyConnected(toVertex, destination, count);
    }

    source->updateExplore(false);
}

#endif
