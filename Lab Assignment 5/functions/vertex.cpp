#ifndef VERTEX
#define VERTEX

#include "graph.cpp"
#include "edge.cpp"

vertex::vertex()
{
    this->isExplored = false;
    this->onStack = false;
    this->distance = INT32_MAX;
    this->time = 0;
}

vertex::vertex(char label)
{
    this->label = label;
    this->isExplored = false;
    this->onStack = false;
    this->distance = INT32_MAX;
    this->time = 0;
}

void vertex::inputEdges(graph *g)
{
    std::string edgeLabel;
    char fromLabel = this->label;
    char toLabel;

    for (int i = 0; i < this->numberOfEdges; i++)
    {
        std::cout << "Enter Edge Label for vertex " << this->label << ": ";
        std::cin >> edgeLabel;

        std::cout << "Enter To Label for edge " << edgeLabel << ": ";
        std::cin >> toLabel;

        vertex *from = g->findVertex(fromLabel);
        vertex *to = g->findVertex(toLabel);

        if (!to)
        {
            to = new vertex(toLabel);
        }

        if (from)
        {
            this->edgesArray[i].setData(edgeLabel, from, to);
        }
        else
        {
            std::cout << "Error: Invalid vertex label entered. Edge not set." << std::endl;
            i--;
        }
    }
}

void vertex::setEdges(int n)
{
    this->numberOfEdges = n;
    this->edgesArray = new edge[n];
}

char vertex::getLabel()
{
    return this->label;
}

int vertex::getNumberOfEdges()
{
    return this->numberOfEdges;
}

bool vertex::checkExplore()
{
    return this->isExplored;
}

void vertex::updateExplore(bool value)
{
    this->isExplored = value;
}

void vertex::setLabel(char label)
{
    this->label = label;
}

void vertex::trueOnStack()
{
    this->onStack = true;
}
void vertex::falseOnStack()
{
    this->onStack = false;
}
bool vertex::checkOnStack()
{
    return this->onStack;
}

void vertex::setTopoOrder(int n)
{
    this->topoOrder = n;
}
int vertex::getTopoOrder()
{
    return this->topoOrder;
}

void vertex::setDistance(int n)
{
    this->distance = n;
}

int vertex::getDistance()
{
    return this->distance;
}

int vertex::getTime()
{
    return this->time;
}
void vertex::setTime(int n)
{
    this->time = n;
}

#endif // VERTEX