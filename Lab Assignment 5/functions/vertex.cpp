#ifndef VERTEX
#define VERTEX

#include "graph.cpp"
#include "edge.cpp"

class vertex
{
private:
    char label;
    int numberOfEdges;
    bool isExplored;

public:
    edge *edgesArray;
    vertex(char label, int numberOfEdges);
    void inputEdges(graph *g);
    void setEdges(int n);
    char getLabel();
    int getNumberOfEdges();
    bool checkExplore();
    void updateExplore(bool value);
};

vertex::vertex(char label, int numberOfEdges)
{
    this->label = label;
    this->numberOfEdges = numberOfEdges;
    this->edgesArray = new edge[numberOfEdges];
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

#endif // VERTEX