#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <iostream>

class vertex;
class edge;
class queue;

class edge
{
private:
    int start;
    int end;

public:
    edge(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
    int getEnd()
    {
        return this->end;
    }
};

class vertex
{
private:
    std::string name;
    int color;
    int size;

public:
    edge *edgeArray;
    vertex()
    {
        this->color = 0;
    }
    vertex(std::string name)
    {
        this->color = 0;
        this->size = 0;
        this->name = name;
    }
    std::string getLabel()
    {
        return this->name;
    }
    void addEdge(int start, int end)
    {
        this->edgeArray = new edge(start, end);
        this->size++;
    }
    void updateColor(int color)
    {
        this->color = color;
    }
    int getColor()
    {
        return this->color;
    }
    int getSize()
    {
        return this->size;
    }
};

int findVertex(std::string name, vertex *vertexArray[], int numberOfVertex)
{
    int index = -1;
    for (int i = 0; i < numberOfVertex; i++)
    {
        if (vertexArray[i]->getLabel() == name)
        {
            index = i;
            break;
        }
    }

    return index;
}

bool solution(vertex *vertexList, int numberOfVertex);

#endif // HEADER_H