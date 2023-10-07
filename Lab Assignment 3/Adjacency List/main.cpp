#include <iostream>

// Struct Declaration:
struct edge
{
    int vertex;
    edge* next;
};

struct node
{
    int vertex;
    edge* edges;
};

// Function Declaration:
edge* createEdge(int edgeData);
node* createNode(int vertex);
node* addEdge(node* head, int edgeVertex);
void displayAdjacencyList(node* adjacencyList[], int vertices);

// Driver Code
int main()
{
    // Variable Declaration:
    int vertices;
    int i;
    int j;
    int edges;

    std::cout << "Enter Number of Vertices: ";
    std::cin >> vertices;

    int vertex[vertices];
    struct node* adjacencyList[vertices];

    for (i = 0; i < vertices; i++)
    {
        std::cout << "Enter Vertex: ";
        std::cin >> vertex[i];
        adjacencyList[i] = createNode(vertex[i]);
    }

    for (i = 0; i < vertices; i++)
    {
        std::cout << "Enter Number of Edges for Vertex " << vertex[i] << ": ";
        std::cin >> edges;
        int edgesArray[edges];

        for (j = 0; j < edges; j++)
        {
            std::cout << "Enter Edge connected to the vertex " << vertex[i] << " : ";
            std::cin >> edgesArray[j];
            adjacencyList[i] = addEdge(adjacencyList[i], edgesArray[j]);
        }
    }

    // Display the adjacency list:
    displayAdjacencyList(adjacencyList, vertices);

    return 0;
}

// Function Definition:
edge* createEdge(int edgeData)
{
    edge* newEdge = new edge;
    newEdge->vertex = edgeData;
    newEdge->next = NULL;
    return newEdge;
}

node* createNode(int vertex)
{
    node* newNode = new node;
    newNode->vertex = vertex;
    newNode->edges = NULL;
    return newNode;
}

node* addEdge(node* head, int edgeVertex)
{
    edge* newEdge = createEdge(edgeVertex);
    edge* temp = head->edges;

    if (head->edges == NULL)
        head->edges = newEdge;
    else
    {
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newEdge;
    }

    return head;
}

void displayAdjacencyList(node* adjacencyList[], int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        std::cout << "Adjacency List for Vertex " << adjacencyList[i]->vertex << ": ";
        edge* currentEdge = adjacencyList[i]->edges;

        while (currentEdge != NULL)
        {
            std::cout << currentEdge->vertex << " ";
            currentEdge = currentEdge->next;
        }

        std::cout << std::endl;
    }
}