#ifndef CLASSIFY_EDGE
#define CLASSIFY_EDGE

#include "header.hpp"
#include "vertex.cpp"
#include "edge.cpp"

void graph::classifyEdges(vertex *source)
{
    source->updateExplore(true);
    source->trueOnStack();
    int time = source->getTime();
    time++;
    source->setTime(time);

    int forwardEdges = 0;
    int backwardEdges = 0;
    int crossEdges = 0;
    int treeEdges = 0;

    for (int i = 0; i < source->getNumberOfEdges(); i++)
    {
        edge *currentEdge = &(source->edgesArray[i]);
        vertex *toVertex = currentEdge->getToVertex();

        if (source->getTime() < toVertex->getTime())
        {
            currentEdge->classifyEdge('f');
            forwardEdges++;
        }
        else if (source->getTime() > toVertex->getTime())
        {
            currentEdge->classifyEdge('c');
            backwardEdges++;
        }
        else if (toVertex->checkExplore() == true && toVertex->checkOnStack() == true)
        {
            currentEdge->classifyEdge('b');
            backwardEdges++;
        }
        else
        {
            currentEdge->classifyEdge('t');
            treeEdges++;
            classifyEdges(toVertex);
        }
    }

    source->falseOnStack();

    if (forwardEdges == 0)
    {
        std::cout << "No forward edges from vertex " << source->getLabel() << std::endl;
    }

    if (backwardEdges == 0)
    {
        std::cout << "No backward edges from vertex " << source->getLabel() << std::endl;
    }

    if (crossEdges == 0)
    {
        std::cout << "No cross edges from vertex " << source->getLabel() << std::endl;
    }

    if (treeEdges == 0)
    {
        std::cout << "No tree edges from vertex " << source->getLabel() << std::endl;
    }
}

void graph::printEdgesByClassification(char classification)
{
    for (int i = 0; i < numberOfEdges; i++)
    {
        if (edgeArray[i]->getEdgeClassification() == classification)
        {
            edgeArray[i]->printData();
        }
    }
}

#endif