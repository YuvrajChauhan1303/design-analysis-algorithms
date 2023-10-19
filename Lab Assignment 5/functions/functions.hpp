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
    bool onStack;

public:
    edge *edgesArray;
    vertex();
    void addLabel(char label);
    char getLabel();
    void createEdgesArray(int numberOfEdges);
    void updateExplore();
    bool checkExplore();
    int getNumberOfEdges();
    void trueOnStack();
    void falseOnStack();
    bool getOnStack();
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

/*
    DFS(G,s)
    1. mark s as explored
    2. for every edge(s,v) 
        2.1 if v is 'unexplored'
            2.1.1 DFS(G,v)
*/

void BFS(char sourceLabel, vertex vertexArray[], int numberOfVertex);

/*
    BFS(G,s)
        - Mark s as "explored"
        - Q <- Queue initialized by s
        - while Q != NULL
            - remove from front of Q the vertex v
            - for each edge (v, w)
                - if W is "unexplored"
                    - mark w as explored
                    - Add w to Q
*/

bool cycleDFS(char source, vertex vertexArray[], int numberOfVertex);

/*
    cycleDFS(G,s)
    1. if s is on stack
        1.1 return true
    2. mark s as 'onstack'
    3. mark s as explored
    4. for every edge(s,v) 
        4.1 if v is 'unexplored'
            4.1.1 DFS(G,v)
    5. mark s as 'not on stack'
*/

bool isCycle(vertex vertexArray[], int numberOfVertex);

/*
    isCycle()
    1. for i = 0 to n
        1.1 cycleDFS(G,i);
*/