#ifndef BFS_CPP
#define BFS_CPP

#include "header.hpp"
#include "vertex.cpp"
#include "queue.cpp"

void graph::BFS(vertex * source)
{
    int queueSize = getNumberOfVertex();
    queue q1(queueSize);

    source->updateExplore(true);

    std::cout << "BFS traversal from source " << source->getLabel() << ": ";
    std::cout << source->getLabel() << " -> ";

    q1.enqueue(source);

    while (!q1.isEmpty())
    {
        vertex *temp = q1.dequeue();

        for (int i = 0; i < temp->getNumberOfEdges(); i++)
        {
            vertex *toVertex = temp->edgesArray[i].getToVertex();
            if (!toVertex->checkExplore())
            {
                toVertex->updateExplore(true);
                std::cout << toVertex->getLabel() << " -> ";
                q1.enqueue(toVertex);
            }
        }
    }

    std::cout << std::endl;
}

#endif
