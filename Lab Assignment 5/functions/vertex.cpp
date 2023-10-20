#ifndef VERTEX
#define VERTEX

#include "graph.cpp"
#include "edge.cpp"

vertex::vertex()
{
    this->isExplored = false;
    this->onStack = false;
}

vertex::vertex(char label)
{
    this->label = label;
    this->isExplored = false;
    this->onStack = false;
}

void vertex::inputEdges(graph *g)
{
    int i;
    std::string edgeLabel;
    char fromLabel = this->label;
    char toLabel;

    std::cout << "Enter Edge Label: ";
    std::cin >> edgeLabel;

    std::cout << "Enter To Label: ";
    std::cin >> toLabel;

    vertex *from = g->findVertex(fromLabel);
    vertex *to = g->findVertex(toLabel);

    for (i = 0; i < this->numberOfEdges; i++)
    {
        this->edgesArray[i].setData(edgeLabel, from, to);
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

#endif // VERTEX