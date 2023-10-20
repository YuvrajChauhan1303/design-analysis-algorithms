#ifndef CHECK_CYCLE
#define CHECK_CYCLE

#include "header.hpp"
#include "vertex.cpp"

bool graph::checkCycle()
{
    bool result = false;

    for (int i = 0; i < this->numberOfVertex; i++)
    {
        if (vertexArray[i].checkExplore() == false)
        {
            result = DFS_Cycle(&vertexArray[i]);
            if(result)
                break;
        }
    }

    return result;
}

bool graph::DFS_Cycle(vertex *source)
{
    vertex *toVertex;
    bool result;

    source->updateExplore(true);
    source->trueOnStack();

    for (int i = 0; i < source->getNumberOfEdges(); i++)
    {
        toVertex = source->edgesArray[i].getToVertex();

        if(toVertex->checkExplore() == true && toVertex->checkOnStack() == true)
            return true;

        if (toVertex->checkExplore() == false)
        {
            result = DFS_Cycle(toVertex);
            if(result)
                break;
        }
    }

    source->falseOnStack();

    return result;
}

#endif