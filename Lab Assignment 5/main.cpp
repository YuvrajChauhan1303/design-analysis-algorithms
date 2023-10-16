#include "functions/functions.cpp"

/*
    1. Create an Array of Objects for Vertex.
    2. Create an Array of Objects for edges.
    3. Ask data for a vertex
        3.1 input Vertex Label
        3.2 input number of Edges for the vertex
        3.3 initialize edgesArray
        3.4 create an object of class edge. add the same edge to the array of objects for edges
        3.5 input ending vertex for the edge, and update both from and to vertex for the edge in array of object for edge.
*/

// Driver Code
int main()
{
    // Variable Declaration:
    int numberOfVertex;
    int i, j, k = 0; // Loop Variables
    char vertexLabel;
    int numberOfEdges;
    int totalNumberOfEdges;
    std::string edgeLabel;
    char toVertexLabel;
    int toVertexIndex;

    std::cout << "Enter number of Vertices: ";
    std::cin >> numberOfVertex;

    std::cout << "Enter Total Edges in the graph: ";
    std::cin >> totalNumberOfEdges;

    // Create Array of Objects
    vertex vertexArray[numberOfVertex];
    edge edgeList[totalNumberOfEdges];

    for (i = 0; i < numberOfVertex; i++)
    {
        std::cout << "Enter Vertex Label: ";
        std::cin >> vertexLabel;
        vertexArray[i].addLabel(vertexLabel);
    }

    std::cout << std::endl;

    for (i = 0; i < numberOfVertex; i++)
    {
        std::cout << "Enter Number of Edges for Vertex " << vertexArray[i].getLabel() << " : ";
        std::cin >> numberOfEdges;
        vertexArray[i].createEdgesArray(numberOfEdges);

        for (j = 0; j < numberOfEdges; j++)
        {
            // Create Edge for Array of Edges in a Vertex object
            std::cout << "Enter Edge Label: ";
            std::cin >> edgeLabel;

            std::cout << "Enter Ending Vertex: ";
            std::cin >> toVertexLabel;

            toVertexIndex = findVertex(toVertexLabel, vertexArray, numberOfVertex);

            vertexArray[i].edgesArray[j].setEdgeData(edgeLabel, i, toVertexIndex);

            // Create the same Edge for edgeList
            edgeList[k++].setEdgeData(edgeLabel, i, toVertexIndex);
        }
    }

    std::cout << std::endl
              << "The Vertices input by the user is: " << std::endl;

    for (i = 0; i < numberOfVertex; i++)
    {
        std::cout << "Vertex " << vertexArray[i].getLabel() << " : ";
        for (j = 0; j < vertexArray[i].getNumberOfEdges(); j++)
            std::cout << vertexArray[i].edgesArray[j].getEdgeLabel() << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl
              << "The Edges Array created by User is: " << std::endl;

    for (i = 0; i < totalNumberOfEdges; i++)
    {
        std::cout << "Edge Label: " << edgeList[i].getEdgeLabel() << std::endl;
        std::cout << "From Vertex: " << vertexArray[edgeList[i].getFromVertex()].getLabel() << std::endl;
        std::cout << "To Vertex: " << vertexArray[edgeList[i].getToVertex()].getLabel() << std::endl;
        std::cout << std::endl;
    }

    // Variable Declaration for DFS Algorithm
    char source;

    std::cout << "Enter Your Source Vertex: ";
    std::cin >> source;
    DFS(source, vertexArray, numberOfVertex);

    std::cout << "Enter Your Source Vertex: ";
    std::cin >> source;
    BFS(source, vertexArray, numberOfVertex);

    return 0;
}