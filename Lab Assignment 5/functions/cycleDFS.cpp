#ifndef CYCLE_DFS   
#define CYCLE_DFS

#include "vertex.cpp"
#include "functions.cpp"

bool cycleDFS(char source, vertex vertexArray[], int numberOfVertex)
{
    int i;
    int j;
    int toIndex;
    char toLabel;
    bool cycle = false; // Initialize to false

    int sourceIndex = findVertex(source, vertexArray, numberOfVertex);

    vertexArray[sourceIndex].trueOnStack();
    vertexArray[sourceIndex].updateExplore();

    for (j = 0; j < vertexArray[sourceIndex].getNumberOfEdges(); j++)
    {
        toIndex = vertexArray[sourceIndex].edgesArray[j].getToVertex();
        toLabel = vertexArray[toIndex].getLabel();

        if (vertexArray[toIndex].checkExplore() && vertexArray[toIndex].getOnStack())
        {
            return true; // Return immediately if a cycle is found
        }
        else if (!vertexArray[toIndex].checkExplore())
        {
            cycle = cycleDFS(toLabel, vertexArray, numberOfVertex);
            if (cycle) // Check if a cycle was found in the recursive call
            {
                return true;
            }
        }
    }

    vertexArray[sourceIndex].falseOnStack();

    return cycle;
}

bool isCycle(vertex vertexArray[], int numberOfVertex)
{
    int i;

    for (i = 0; i < numberOfVertex; i++)
    {
        bool cycle = cycleDFS(vertexArray[i].getLabel(), vertexArray, numberOfVertex);

        if (cycle)
        {
            return true;
        }
    }

    return false;
}

#endif // CYCLE_DFS