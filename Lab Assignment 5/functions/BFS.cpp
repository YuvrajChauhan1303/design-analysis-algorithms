#ifndef BFS_H
#define BFS_H

#include "functions.cpp"
#include "queue.cpp"
#include "vertex.cpp"
#include "edge.cpp"

void BFS(char sourceLabel, vertex vertexArray[], int numberOfVertex)
{
    int sourceIndex = findVertex(sourceLabel, vertexArray, numberOfVertex);

    if (sourceIndex == -1)
    {
        std::cout << "Source vertex not found." << std::endl;
        return;
    }

    vertex sourceVertex = vertexArray[sourceIndex];
    sourceVertex.updateExplore();

    Queue vertexQueue(numberOfVertex);
    vertexQueue.enqueue(sourceVertex.getLabel());

    while (!vertexQueue.isEmpty())
    {
        char leadVertexLabel = vertexQueue.dequeue();

        int leadVertexIndex = findVertex(leadVertexLabel, vertexArray, numberOfVertex);
        vertex leadVertex = vertexArray[leadVertexIndex];

        for (int i = 0; i < leadVertex.getNumberOfEdges(); i++)
        {
            int toVertexIndex = leadVertex.edgesArray[i].getToVertex();

            if (!vertexArray[toVertexIndex].checkExplore())
            {
                vertexArray[toVertexIndex].updateExplore();
                vertexQueue.enqueue(vertexArray[toVertexIndex].getLabel());
            }
        }
    }

    // Print the visited nodes after BFS traversal
    std::cout << "BFS traversal starting from vertex " << sourceLabel << " is: ";
    for (int i = 0; i < numberOfVertex; i++)
    {
        if (vertexArray[i].checkExplore())
        {
            std::cout << vertexArray[i].getLabel() << " ";
        }
    }
    std::cout << std::endl;
}

#endif // BFS_H