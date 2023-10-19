#ifndef TOPO_SORT
#define TOPO_SORT 

#include "vertex.cpp"
#include "cycleDFS.cpp"
void TopologicalSort(vertex vertexArray[], int numberOfVertex)
{
    bool checkCycle = isCycle(vertexArray, numberOfVertex);
    if (checkCycle)
    {
        std::cout << "There is a Cycle Present, hence Topological Ordering cannot be Done" << std::endl;
        return;
    }

    int i;
    curLabel = numberOfVertex;

    for (i = 0; i < numberOfVertex; i++)
        vertexArray[i].markAsUnexplored();

    for (i = 0; i < numberOfVertex; i++)
    {
        if (vertexArray[i].checkExplore() == false)
            DFS_Topo(vertexArray[i].getLabel(), vertexArray, numberOfVertex);
    }

    printTopologicalySortedGraph(vertexArray, numberOfVertex);
}
void DFS_Topo(char source, vertex vertexArray[], int numberOfVertex)
{
    int i;
    int j;
    int toIndex;
    char toLabel;

    int sourceIndex = findVertex(source, vertexArray, numberOfVertex);

    vertexArray[sourceIndex].updateExplore();

    for (j = 0; j < vertexArray[sourceIndex].getNumberOfEdges(); j++)
    {

        toIndex = vertexArray[sourceIndex].edgesArray[j].getToVertex();

        toLabel = vertexArray[toIndex].getLabel();

        if (vertexArray[toIndex].checkExplore() == false)
            DFS_Topo(toLabel, vertexArray, numberOfVertex);
    }

    vertexArray[sourceIndex].setTopologicalSortIndex(curLabel--);
}

void printTopologicalySortedGraph(vertex vertexArray[], int numberOfVertex)
{
    int topologicalOrder[numberOfVertex];

    for (int i = 0; i < numberOfVertex; i++)
        topologicalOrder[i] = -1;

    for (int i = 0; i < numberOfVertex; i++)
    {
        int index = vertexArray[i].getTopologicalSortIndex();
        topologicalOrder[index] = i;
    }

    for (int i = 0; i < numberOfVertex; i++)
    {
        int vertexIndex = topologicalOrder[i];
        std::cout << vertexArray[vertexIndex].getLabel() << " ";
    }

    std::cout << std::endl;
}

#endif //TOPO_SORT