#ifndef VERTEX
#define VERTEX

#include "graph.cpp"
#include "edge.cpp"

vertex::vertex()
{
    this->isExplored = false;
}

vertex::vertex(char label)
{
    this->label = label;
    this->isExplored = false;
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

#endif // VERTEX