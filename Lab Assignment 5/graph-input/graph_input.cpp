#include "graph_input.hpp"

class vertex
{
private:
    char label;
    int numberOfEdges;
    bool isExplored;

public:
    edge *edgesArray;
    vertex();
    void addLabel(char label);
    char getLabel();
    void createEdgesArray(int numberOfEdges);
    void updateExplore();
    bool checkExplore(); 
};

class edge
{
private:
    std::string label;
    vertex *fromVertex;
    vertex *toVertex;

public:
    edge *next;
    edge();
    void setEdgeData(std::string edgeLabel, vertex *fromVertex, vertex *toVertex);
    void addNext(edge *edgeList, std::string edgeLabel, vertex *fromVertex, vertex *toVertex);
};

// Function Declarations for Vertex Class:

vertex::vertex()
{
    this->label = ' ';
    this->numberOfEdges = 0;
    this->edgesArray = nullptr;
    this->isExplored = false;
}

void vertex::addLabel(char label)
{
    this->label = label;
    this->numberOfEdges = 0;
    this->edgesArray = nullptr;
}

char vertex::getLabel()
{
    return this->label;
}

void vertex::createEdgesArray(int numberOfEdges = 0)
{
    this->numberOfEdges = numberOfEdges;
    this->edgesArray = new edge[numberOfEdges];
}

vertex *findVertex(char label, vertex vertexArray[], int numberOfVertex)
{
    for (int i = 0; i < numberOfVertex; i++)
        if (vertexArray[i].getLabel() == label)
            return &vertexArray[i];
}

void vertex::updateExplore()
{
    this->isExplored = true;
}

bool vertex::checkExplore()
{
    return this->isExplored;
}


// Function Declarations for Edge Class:

edge::edge()
{
    this->label = "";
    this->fromVertex = nullptr;
    this->toVertex = nullptr;
}

void edge::setEdgeData(std::string edgeLabel, vertex *fromVertex, vertex *toVertex)
{
    this->label = edgeLabel;
    this->fromVertex = fromVertex;
    this->toVertex = toVertex;
}

void edge::addNext(edge *edgeList, std::string edgeLabel, vertex *fromVertex, vertex *toVertex)
{
    edge *temp = edgeList;

    while (temp->next != nullptr)
        temp = temp->next;

    edge *newEdge = new edge;

    newEdge->next = nullptr;

    newEdge->setEdgeData(edgeLabel, fromVertex, toVertex);

    temp->next = newEdge;
}