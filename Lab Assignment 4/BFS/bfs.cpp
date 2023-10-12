/*
    Algorithm for BFS:
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

#include "bfs.hpp"

void BFS(char label)
{
    Vertex *source = findVertex(label);
    source->explored = true;

    int level = 0;

    Queue q(100);
    q.enqueue(source->label);
    std::cout << "Level " << level << " : " << std::endl
              << label;
    level++;

    // if (!q.isEmpty())
    //     std::cout << "Not Empty!\n";

    while (!q.isEmpty())
    {
        char currentLabel = q.dequeue();
        Vertex *current = findVertex(currentLabel);

        std::cout << "Level " << level << " : ";

        for (int i = 0; i < current->numberOfEdges; i++)
        {
            if (current->edge[i]->end->explored == false)
            {
                Vertex *neighbor = current->edge[i]->end;
                std::cout << neighbor->label << " ";
                neighbor->explored = true;
                q.enqueue(neighbor->label);
            }
        }

        level++;
    }
}

void setDist(Vertex *v)
{
    Vertex *temp = vertexList;
    while (temp != nullptr)
    {
        if (temp == v)
            temp->distance = 0;
        else
            temp->distance = INT32_MAX;
        temp = temp->next;
    }
}

inline int min(int a, int b)
{
    return a > b ? b : a;
}

int getDistance(Vertex *current, Vertex *neighbour)
{
    return min(neighbour->distance, current->distance + 1);
}

void BFS_Distance(char label)
{
    Vertex *source = findVertex(label);
    setDist(source);
    source->explored = true;

    // utilities::displayDistance();

    Queue q(100);
    q.enqueue(source->label);

    while (!q.isEmpty())
    {
        char currentLabel = q.dequeue();
        Vertex *current = findVertex(currentLabel);

        for (int i = 0; i < current->numberOfEdges; i++)
        {
            if (current->edge[i]->end->explored == false)
            {
                Vertex *neighbor = current->edge[i]->end;
                neighbor->explored = true;
                neighbor->distance = getDistance(current, neighbor);
                q.enqueue(neighbor->label);
            }
        }
    }
    // utilities::displayDistance();
}

int shortestPath(Vertex *source, Vertex *destination)
{
    BFS_Distance(source->label);

    std::cout << std::endl
              << "Shortest Path between " << source->label << " and " << destination->label << " is : " << destination->distance << std::endl;

    return destination->distance;
}