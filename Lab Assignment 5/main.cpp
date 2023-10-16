#include "depth-first-search/dfs.cpp"
#include "graph-input/graph_input.cpp"

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

//Driver Code
int main()
{
    //Variable Declaration:
    int numberOfVertex;
    int i, j; //Loop Variables
    char vertexLabel;
    int numberOfEdges;
    std::string edgeLabel;
    char toVertexLabel;
    vertex * toVertex;

    std::cout << "Enter number of Vertices: " ;
    std::cin >> numberOfVertex;

    vertex vertexArray[numberOfVertex];
    edge * edgeList;

    for(i = 0 ; i < numberOfVertex ; i++)
    {
        std::cout << "Enter Vertex Label: ";
        std::cin >> vertexLabel;
        vertexArray[i].addLabel(vertexLabel);
    }

    for(i = 0 ; i < numberOfVertex ; i++)
    {
        std::cout << "Enter Number of Edges for Vertex " << vertexArray[i].getLabel() << " : ";
        std::cin >> numberOfEdges;
        vertexArray[i].createEdgesArray(numberOfEdges);
        for(j = 0 ; j < numberOfEdges ; j++)
        {
            //Create Edge for Array of Edges in a Vertex object
            std::cout << "Enter Edge Label: ";
            std::cin >> edgeLabel;

            std::cout << "Enter Ending Vertex: ";
            std::cin >> toVertexLabel;

            toVertex = findVertex(toVertexLabel, vertexArray, numberOfVertex);

            vertexArray[i].edgesArray[j].setEdgeData( edgeLabel , &vertexArray[i], toVertex);

            //Add the same edge to List of Edges
            edgeList->addNext(edgeList, edgeLabel, &vertexArray[i], toVertex);
        }
    }
    return 0;
}