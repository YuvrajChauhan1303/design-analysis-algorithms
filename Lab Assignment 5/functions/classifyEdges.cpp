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

    vertex *toVertex;

    for(int i = 0 ; i<source->getNumberOfEdges(); i++)
    {
        toVertex = source->edgesArray[i].getToVertex();

        if(source->getTime() < toVertex->getTime())
            source->edgesArray[i].classifyEdge('f');
        
        if(source->getTime() > toVertex->getTime())
            source->edgesArray[i].classifyEdge('c');

        if(toVertex->checkExplore() == true && toVertex->checkOnStack() == true)
            source->edgesArray[i].classifyEdge('b');

        if(toVertex->checkExplore() == false)
        {
            source->edgesArray[i].classifyEdge('t');
            classifyEdges(toVertex);
            source->falseOnStack();
        }
    }
    
    deleteEdgeArray();
    createEdgeList();
}

#endif