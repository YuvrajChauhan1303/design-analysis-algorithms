#include "BFS/bfs.cpp"

int main()
{
    inputGraph();
    displayAdjacencyList();
    displayVertexList();

    displayByDistance();
    
    return 0;
}

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

