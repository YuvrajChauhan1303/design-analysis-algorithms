#ifndef DIAMETER
#define DIAMETER

#include "header.hpp"
#include "vertex.cpp"
#include "queue.cpp"

int graph::diameter()
{
    int maxDiameter = 0;

    for (int i = 0; i < this->getNumberOfVertex(); i++)
    {
        AugmentedBFS(&this->vertexArray[i]);
        for (int j = 0; j < this->getNumberOfVertex(); j++)
        {
            int distance = vertexArray[j].getDistance();
            if (distance > maxDiameter)
            {
                maxDiameter = distance;
            }
        }
    }

    return maxDiameter;
}

void graph::AugmentedBFS(vertex *source)
{
    for (int i = 0; i < this->getNumberOfVertex(); i++)
    {
        this->vertexArray[i].updateExplore(false);
        this->vertexArray[i].setDistance(0);
    }

    queue q(numberOfVertex);
    source->setDistance(0);
    source->updateExplore(true);
    q.enqueue(source);

    while (!q.isEmpty())
    {
        vertex *temp = q.dequeue();
        for (int i = 0; i < temp->getNumberOfEdges(); i++)
        {
            vertex *toVertex = temp->edgesArray[i].getToVertex();
            if (!toVertex->checkExplore())
            {
                toVertex->updateExplore(true);
                toVertex->setDistance(temp->getDistance() + 1);
                q.enqueue(toVertex);
            }
        }
    }
}

int graph::shortestPath(vertex *source, vertex *destination)
{
    this->AugmentedBFS(source);

    return destination->getDistance();
}

#endif
