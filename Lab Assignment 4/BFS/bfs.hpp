#include "../Graph Input/input.cpp"
#include "../Queue/queue.cpp"
#include<climits>

namespace utilities
{
    void displayDistance()
    {
        Vertex * temp = vertexList;

        while(temp!=nullptr)
        {
            std::cout << temp->distance << std::endl;
            temp = temp->next;
        }
    }

    int numberOfVertices(Vertex * source)
    {
        return (source == nullptr) ?  0 :  1 + numberOfVertices(source->next);
    }
} 

//Problem 1 - BFS
void BFS(char label);

//Problem 2 - Shortest Path for an undirected graph
void setDist(Vertex * v);
int getDistance(Vertex * current, Vertex * neighbour);
inline int min(int a, int b);
void BFS_Distance(char label);
int shortestPath(Vertex * source, Vertex * destination);

//Problem 3 - Undirected Connectivity

int checkConnectivity();
void BFS_NoPrint(char label);