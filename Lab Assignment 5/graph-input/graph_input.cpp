#include "graph_input.hpp"

class vertex
{
    private:
        char label;
        int numberOfEdges;
        edge ** edgesArray;
    public:
        vertex(char label);
        void createEdgesArray(int numberOfEdges);
};

class edge
{
    private:
        std::string label;
        vertex * fromVertex;
        vertex * toVertex;
    public:
        edge(std::string label);
        void createEdge(vertex * from, vertex * to);
};

//Function Declarations for Vertex Class:

vertex::vertex(char label)
{
    this->label = label;
}

void vertex::createEdgesArray(int numberOfEdges = 0)
{
    this->numberOfEdges = numberOfEdges;
    this->edgesArray = new edge * [numberOfEdges];
}

//Function Declarations for Edge Class:

edge::edge(std::string label)
{
    this->label = label;
}