#include <iostream>
#include <string>

//Class Declarations

class vertex;
class edge;

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

int findVertex(char label, vertex vertexArray[], int numberOfVertex);