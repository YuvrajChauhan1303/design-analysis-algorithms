#include <iostream>
#include <string>

// Class Declarations

class vertex;
class edge;
class Queue;
/*
    Algorithm to input Graph
        1. Create an Array of Objects for Vertex.
        2. Create an Array of Objects for edges.
        3. Ask data for a vertex
            3.1 input Vertex Label
            3.2 input number of Edges for the vertex
            3.3 initialize edgesArray
            3.4 create an object of class edge. add the same edge to the array of objects for edges
            3.5 input ending vertex for the edge, and update both from and to vertex for the edge in array of object for edge.
*/

//Class Definitions

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

class Queue
{
    private:
        int size;
        int front;
        int rear;
        char * arr;

    public:
        Queue(int size);
        void enqueue(char ch);
        char dequeue();
        bool isFull();
        bool isEmpty();
};

//Function Declarations

int findVertex(char label, vertex vertexArray[], int numberOfVertex);
void DFS(char source, vertex vertexArray[], int numberOfVertex);
void BFS(char sourceLabel, vertex vertexArray[], int numberOfVertex);