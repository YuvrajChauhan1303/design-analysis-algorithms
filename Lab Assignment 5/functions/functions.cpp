#ifndef FUNCTION_C
#define FUNCTION_C 

#include "functions.hpp"

int findVertex(char label, vertex vertexArray[], int numberOfVertex)
{
    int i;

    for (i = 0; i < numberOfVertex; i++)
        if (vertexArray[i].getLabel() == label)
            break;

    return i;
}

#endif //FUNCTION_C