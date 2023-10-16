#include "dfs.hpp"

/*
    DFS(G,s)
    - mark s as explored
    - for every edge (s,v)
        - if v is unexplored
        - DFS(G,v)
*/

void DFS(char source, vertex vertexArray[], int numberOfVertex)
{
    int i;
    int j;
    int toIndex;
    char toLabel;

    int sourceIndex = findVertex(source, vertexArray, numberOfVertex);

    // std::cout << "Source Index: " << sourceIndex;

    vertexArray[sourceIndex].updateExplore();

    std::cout << vertexArray[sourceIndex].getLabel() << " -> ";

    if(vertexArray[sourceIndex].getNumberOfEdges() == 0)
        std::cout << std::endl;

    for (j = 0; j < vertexArray[sourceIndex].getNumberOfEdges(); j++)
    {
        
        toIndex = vertexArray[sourceIndex].edgesArray[j].getToVertex();

        // std::cout << "To Index: " << toIndex;

        toLabel = vertexArray[toIndex].getLabel();

        if (vertexArray[toIndex].checkExplore() == false)
            DFS(toLabel, vertexArray, numberOfVertex);
    }
}