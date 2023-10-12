#include "input.hpp"

// Struct Definition
struct Vertex
{
    char label;
    int distance;
    bool explored;
    int numberOfEdges;
    Edge **edge;
    Vertex *next;
};

struct Edge
{
    std::string label;
    Vertex *start;
    Vertex *end;
    Edge *next;
};

// Function Definition:
struct Vertex *createVertex()
{
    struct Vertex *newVertex = new Vertex;
    newVertex->next = nullptr;

    return newVertex;
}

struct Vertex *addVertex(char label)
{
    if (findVertex(label) != nullptr)
        return findVertex(label);

    struct Vertex *temp = vertexList;

    struct Vertex *newVertex = createVertex();
    newVertex->label = label;

    if (temp == nullptr)
    {
        vertexList = newVertex;
        return vertexList;
    }

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newVertex;
    return vertexList;
}

struct Vertex *findVertex(char label)
{
    struct Vertex *temp = vertexList;

    while (temp != nullptr && temp->label != label)
        temp = temp->next;

    if (temp == nullptr)
        return nullptr;

    return temp;
}

struct Edge *createEdge()
{
    struct Edge *newEdge = new Edge;
    newEdge->next = nullptr;
    return newEdge;
}

struct Edge *addEdge(std::string label)
{
    struct Edge *temp = adjacencyList;
    struct Edge *newEdge = createEdge();
    newEdge->label = label;

    if (temp == nullptr)
    {
        adjacencyList = newEdge;
        return adjacencyList;
    }

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newEdge;
    return adjacencyList;
}

struct Edge *findEdge(std::string label)
{
    struct Edge *temp = adjacencyList;

    while (temp != nullptr && temp->label != label)
        temp = temp->next;

    if (temp == nullptr)
        return nullptr;

    return temp;
}

struct Vertex *inputEdge(char label)
{
    int numberOfEdges;
    int i;
    std::string edgeLabel;
    char endLabel;
    struct Edge *edgePointer = nullptr;
    struct Vertex *endPointer = nullptr;

    struct Vertex *temp = vertexList;
    temp = findVertex(label);

    if (temp == nullptr)
        vertexList = addVertex(label);

    std::cout << "Enter Number of Edges: ";
    std::cin >> numberOfEdges;
    temp->numberOfEdges = numberOfEdges;
    temp->edge = new Edge *[numberOfEdges];

    for (i = 0; i < numberOfEdges; i++)
    {
        std::cout << "Enter Edge Label: ";
        std::cin >> edgeLabel;

        edgePointer = findEdge(edgeLabel);

        if (edgePointer == nullptr)
            adjacencyList = addEdge(edgeLabel);

        temp->edge[i] = findEdge(edgeLabel);
        edgePointer = findEdge(edgeLabel);
        edgePointer->start = findVertex(label);

        std::cout << "Enter Ending Vertex: ";
        std::cin >> endLabel;

        endPointer = findVertex(endLabel);

        if (endPointer == nullptr)
        {
            vertexList = addVertex(endLabel);
            endPointer = findVertex(endLabel);
        }

        edgePointer->end = endPointer;
    }

    return vertexList;
}

void displayVertexList()
{
    struct Vertex *temp = vertexList;

    if (temp == nullptr)
    {
        std::cout << "Vertex list is empty." << std::endl;
        return;
    }

    std::cout << std::endl
              << std::endl
              << "Vertex List:" << std::endl;

    while (temp != nullptr)
    {
        std::cout << "Vertex Label: " << temp->label << std::endl;

        if (temp->edge != nullptr)
        {
            std::cout << "Edges:";

            for (int i = 0; i < temp->numberOfEdges; i++)
                if (temp->edge[i] != nullptr)
                    std::cout << " " << temp->edge[i]->label;

            std::cout << std::endl;
        }

        temp = temp->next;
    }
}

void displayAdjacencyList()
{
    struct Edge *temp = adjacencyList;

    if (temp == nullptr)
    {
        std::cout << "Adjacency list is empty." << std::endl;
        return;
    }

    std::cout << std::endl
              << std::endl
              << "Adjacency List:" << std::endl;

    while (temp != nullptr)
    {
        std::cout << "Edge Label: " << temp->label << std::endl;
        std::cout << "Start Vertex: " << temp->start->label << std::endl;
        std::cout << "End Vertex: " << temp->end->label << std::endl;

        temp = temp->next;
    }
}

void inputGraph()
{
    //Variable Initialization
    char label;
    int numberOfVertices;

    std::cout << "Enter number of Vertices: ";
    std::cin >> numberOfVertices;

    for(int i = 0 ; i < numberOfVertices ; i++)
    {
        std::cout << "Enter Vertex Label: ";
        std::cin >> label;

        Vertex * temp = addVertex(label);
        inputEdge(label);
    }
}