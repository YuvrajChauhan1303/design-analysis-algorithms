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
} 


// Set Distance of all nodes accept source Node as ♾️
void BFS(char label);
void setDist(Vertex * v);
int getDistance(Vertex * current, Vertex * neighbour);
inline int min(int a, int b);
void BFS_Distance(char label);
int shortestPath(Vertex * source, Vertex * destination);