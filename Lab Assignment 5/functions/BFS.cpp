#ifndef BFS_CPP
#define BFS_CPP

#include "header.hpp"
#include "vertex.cpp"
#include "queue.cpp"

void graph::BFS(vertex *source)
{
    for (int i = 0; i < this->getNumberOfVertex(); i++)
    {
        this->vertexArray[i].updateExplore(false);
    }

    int queueSize = getNumberOfVertex();
    queue q1(queueSize);

    std::cout << "BFS traversal from source " << source->getLabel() << ": ";

    for (int i = 0; i < this->getNumberOfVertex(); i++)
    {
        vertex *temp = &this->vertexArray[i];
        if (!temp->checkExplore())
        {
            temp->updateExplore(true);
            std::cout << temp->getLabel() << " -> ";
            q1.enqueue(temp);

            while (!q1.isEmpty())
            {
                vertex *current = q1.dequeue();

                for (int j = 0; j < current->getNumberOfEdges(); j++)
                {
                    vertex *toVertex = current->edgesArray[j].getToVertex();
                    if (!toVertex->checkExplore())
                    {
                        toVertex->updateExplore(true);
                        std::cout << toVertex->getLabel() << " -> ";
                        q1.enqueue(toVertex);
                    }
                }
            }
        }
    }
    std::cout << std::endl;
}

#endif
