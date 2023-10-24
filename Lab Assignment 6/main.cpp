/*
    Question:
    There are two pairs of guys, cute and handsome, between any pair of guys, there may not be a rivalry. You are given a range of "n" guys and a list of "r" pairs of guys for which there are rivalries. give an O(n+r) algorithm, that determines wether it is possible to designate some of the guys as 'cute' and remaining as 'handsome' such that each rivalry is between a cute and a handsome guy only.
*/

#include "functions/header.hpp"
#include "functions/solution.cpp"
struct rivalry
{
    std::string guy1;
    std::string guy2;
};

int main()
{
    int numberOfVertex;
    std::string vertexLabel;
    int numberOfPairs;
    struct rivalry rivals;

    std::cout << "Enter Number of Vertex: ";
    std::cin >> numberOfVertex;

    std::cout << "Enter Number of Rivalry Pairs: ";
    std::cin >> numberOfPairs;

    vertex *vertexList[numberOfVertex];
    edge *edgeList[numberOfPairs];

    for (int i = 0; i < numberOfVertex; i++)
    {
        std::cout << "Enter Name of Guy: ";
        std::cin >> vertexLabel;

        vertexList[i] = new vertex(vertexLabel);
    }

    for (int i = 0; i < numberOfPairs; i++)
    {
        std::cout << "Enter Guys that have rivalry: ";
        std::cin >> rivals.guy1;
        std::cin >> rivals.guy2;

        int start = findVertex(rivals.guy1, vertexList, numberOfVertex);
        if (start == -1)
        {
            std::cout << "Wrong Input!";
            return 0;
        }
        int end = findVertex(rivals.guy2, vertexList, numberOfVertex);
        if (end == -1)
        {
            std::cout << "Wrong Input!";
            return 0;
        }

        edgeList[i] = new edge(start, end);
        vertexList[i]->addEdge(start, end);
    }

    bool sol = solution(vertexList, numberOfVertex);

    if(sol)
        std::cout << "The pairs can exist" << std::endl;
    else
        std::cout << "The pairs cannot exist" << std::endl;

    return 0;
}

/*
    rough approach:
        1. input the names of guys - Input Vertex
        2. input the pairs of guys having rivalry - Input Edges
        3. now check if a bipartite graph exists
*/