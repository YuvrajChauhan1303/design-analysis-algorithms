#include "../graph-input/graph_input.cpp"

/*
    DFS(G,s)
    - mark s as explored
    - for every edge (s,v)
        - if v is unexplored
        - DFS(G,v)
*/

void DFS(char source, vertex vertexArray[], int numberOfVertex);