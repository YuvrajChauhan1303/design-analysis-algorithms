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

int BFS(char label)
{
    Vertex *source = findVertex(label);
    source->explored = true;

    int distanceCounter = 0;

    Queue q(100);
    q.enqueue(source->label);

    // if (!q.isEmpty())
    //     std::cout << "Not Empty!\n";

    source->distance = distanceCounter;
    distanceCounter++;

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
                neighbor->distance = distanceCounter;
                q.enqueue(neighbor->label);
            }
        }

        if(current->numberOfEdges != 0)
            distanceCounter++;
    }

    return distanceCounter;
}

void displayByDistance()
{
    char sourceLabel;
    std::cout << "Enter Source Vertex: ";
    std::cin >> sourceLabel;

    Vertex *temp = vertexList;

    int distance = BFS(sourceLabel);

    for (int i = 0; i < distance; i++)
    {
        std::cout << std::endl
                  << "For Distance " << i << " : " << std::endl;

        temp = vertexList;
        while (temp != nullptr)
        {
            if (temp->distance == i)
                std::cout << temp->label << " ";
            temp = temp->next;
        }

        std::cout << std::endl;
    }
}