#include "functions.hpp"

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

// Function Declaration for Queue Class:

Queue::Queue(int size)
{
    this->size = size;
    this->arr = new char[size];
    this->rear = -1;
    this->front = -1;
}

void Queue::enqueue(char ch)
{
    if (isFull())
    {
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear = (rear + 1) % size;
    arr[rear] = ch;
}

char Queue::dequeue()
{
    if (isEmpty())
        return '\0';

    char data = arr[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front = (front + 1) % size;

    return data;
}

bool Queue::isFull()
{
    return (front == (rear + 1) % size);
}

bool Queue::isEmpty()
{
    return (front == -1);
}

// Function Definition for DFS

void DFS(char source, vertex vertexArray[], int numberOfVertex)
{
    int i;
    int j;
    int toIndex;
    char toLabel;

    int sourceIndex = findVertex(source, vertexArray, numberOfVertex);

    // std::cout << "Source Index: " << sourceIndex;

    vertexArray[sourceIndex].updateExplore();

    std::cout << vertexArray[sourceIndex].getLabel() << " -> ";

    if (vertexArray[sourceIndex].getNumberOfEdges() == 0)
        std::cout << std::endl;

    for (j = 0; j < vertexArray[sourceIndex].getNumberOfEdges(); j++)
    {

        toIndex = vertexArray[sourceIndex].edgesArray[j].getToVertex();

        // std::cout << "To Index: " << toIndex;

        toLabel = vertexArray[toIndex].getLabel();

        if (vertexArray[toIndex].checkExplore() == false)
            DFS(toLabel, vertexArray, numberOfVertex);
    }
}

// Function Definitions for BFS

// Function Definitions for BFS

void BFS(char sourceLabel, vertex vertexArray[], int numberOfVertex)
{
    int sourceIndex = findVertex(sourceLabel, vertexArray, numberOfVertex);

    if (sourceIndex == -1) {
        std::cout << "Source vertex not found." << std::endl;
        return;
    }

    vertex sourceVertex = vertexArray[sourceIndex];
    sourceVertex.updateExplore();

    Queue vertexQueue(numberOfVertex);
    vertexQueue.enqueue(sourceVertex.getLabel());

    while (!vertexQueue.isEmpty())
    {
        char leadVertexLabel = vertexQueue.dequeue();

        int leadVertexIndex = findVertex(leadVertexLabel, vertexArray, numberOfVertex);
        vertex leadVertex = vertexArray[leadVertexIndex];

        for (int i = 0; i < leadVertex.getNumberOfEdges(); i++)
        {
            int toVertexIndex = leadVertex.edgesArray[i].getToVertex();

            if (!vertexArray[toVertexIndex].checkExplore())
            {
                vertexArray[toVertexIndex].updateExplore();
                vertexQueue.enqueue(vertexArray[toVertexIndex].getLabel());
            }
        }
    }

    // Print the visited nodes after BFS traversal
    std::cout << "BFS traversal starting from vertex " << sourceLabel << " is: ";
    for (int i = 0; i < numberOfVertex; i++) {
        if (vertexArray[i].checkExplore()) {
            std::cout << vertexArray[i].getLabel() << " ";
        }
    }
    std::cout << std::endl;
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