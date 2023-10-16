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
    int getNumberOfEdges();
};

class edge
{
private:
    std::string label;
    int fromVertexIndex;
    int toVertexIndex;

public:
    edge();
    void setEdgeData(std::string label, int fromVertex, int toVertex);
    std::string getEdgeLabel();
    int getFromVertex();
    int getToVertex();
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

void vertex::updateExplore()
{
    this->isExplored = true;
}

bool vertex::checkExplore()
{
    return this->isExplored;
}

int vertex::getNumberOfEdges()
{
    return this->numberOfEdges;
}

// Function Declarations for Edge Class:

edge::edge()
{
    this->label = "";
    this->fromVertexIndex = 0;
    this->toVertexIndex = 0;
}
void edge::setEdgeData(std::string label, int fromVertex, int toVertex)
{
    this->label = label;
    this->fromVertexIndex = fromVertex;
    this->toVertexIndex = toVertex;
}

std::string edge::getEdgeLabel()
{
    return this->label;
}

int edge::getFromVertex()
{
    return this->fromVertexIndex;
}
int edge::getToVertex()
{
    return this->toVertexIndex;
}

// Other Function Declarations
int findVertex(char label, vertex vertexArray[], int numberOfVertex)
{
    int i;

    for (i = 0; i < numberOfVertex; i++)
        if (vertexArray[i].getLabel() == label)
            break;

    return i;
}