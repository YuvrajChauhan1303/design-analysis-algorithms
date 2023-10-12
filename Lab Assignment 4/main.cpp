#include "BFS/bfs.cpp"

int main()
{
    char source;
    char destination;
    int menu;

    inputGraph();
    displayAdjacencyList();
    displayVertexList();

    std::cout << "1. BFS()" << std::endl
              << "2. Shortest Distance" << std::endl
              << "3. Count number of Connected Groups" << std::endl
              << "4. Exit" << std::endl;

    std::cin >> menu;

    switch (menu)
    {
    case 1:
        std::cout << "Enter Source Vertex for BFS: ";
        std::cin >> source;
        BFS(source);
        break;

    case 2:
        std::cout << "Enter Source Vertex for Shortest Path : ";
        std::cin >> source;
        std::cout << "Enter Destination Vertex for r Shortest Path : ";
        std::cin >> destination;
        shortestPath(findVertex(source), findVertex(destination));
        break;

    case 3:
        std::cout << "The Number of Connected Components in the graph is: " << checkConnectivity() << std::endl;
        break;

    case 4:
    default:
        return 0;
    }

    return 0;
}
