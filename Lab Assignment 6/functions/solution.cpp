#ifndef SOLUTION
#define SOLUTION

#include "header.hpp"
#include "queue.cpp"

bool solution(vertex *vertexList[], int numberOfVertex)
{
    vertex *source = vertexList[0];
    vertex *dest;

    source->updateColor(1);
    queue q1(100);

    q1.enqueue(source);

    while (!q1.isEmpty())
    {
        vertex *temp = q1.dequeue();
        for (int i = 0; i < temp->getSize(); i++)
        {
            dest = vertexList[temp->edgeArray[i].getEnd()];

            if (dest->getColor() == 0)
            {
                int color = temp->getColor() == 1 ? 2 : 1;
                dest->updateColor(color);
                q1.enqueue(dest);
            }

            else if(dest->getColor() == temp->getColor())
            {
                return false;
            }
        }
    }

    return true;
}

#endif