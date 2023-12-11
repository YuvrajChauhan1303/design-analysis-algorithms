#ifndef GRAPH
#define GRAPH

#include "kruskal.hpp"
#include "vertex.cpp"
#include "disjointSet.cpp"
using namespace std;

class graph
{
public:
    vector<vertex> Vertex;
    int findVertex(int label)
    {
        int i;
        for (i = 0; i < this->Vertex.size(); i++)
        {
            if (this->Vertex[i].getLabel() == label)
                break;
        }

        return i;
    }

    void displayEdgeList()
    {
        cout << "Edge List:\n";
        for (const auto &e : globalList)
        {
            cout << "Label: " << e.getLabel() << ", From: " << e.getFromIndex() << ", To: " << e.getToIndex() << ", Weight: " << e.getWeight() << "\n";
        }
    }

    void displayVertexList()
    {
        cout << "Vertex List:\n";
        for (const auto &v : Vertex)
        {
            cout << "Vertex Label: " << v.getLabel() << "\n";
            for (const auto &edgeIndex : v.getEdgeIndices())
            {
                const edge &e = globalList[edgeIndex];
                cout << "  Edge Label: " << e.getLabel() << ", From: " << e.getFromIndex() << ", To: " << e.getToIndex() << ", Weight: " << e.getWeight() << "\n";
            }
            cout << "\n";
        }
    }

    graph();

    vector<edge> kruskalMST();
};

graph::graph()
{
    int input;
    char label;
    int weight;
    int fromIndex;
    int toIndex;

    do
    {
        cout << "Enter Vertex(-1 Quits): ";
        cin >> input;

        if (input == -1)
            break;

        vertex temp(input);
        this->Vertex.push_back(temp);

    } while (input != -1);



    do
    {
        cout << "Enter Edge Label(! Quits): ";
        cin >> label;

        if (label == '!')
            break;

        cout << "Enter From Vertex: ";
        cin >> fromIndex;

        cout << "Enter To Vertex: ";
        cin >> toIndex;

        cout << "Enter Weight: ";
        cin >> weight;

        edge temp(label, fromIndex, toIndex, weight);

        globalList.push_back(temp);

        int a = findVertex(fromIndex);
        this->Vertex.at(a).addEdge(label, fromIndex, toIndex, weight);

    } while (label != '!'); 
}

vector<edge> graph::kruskalMST()
{
    
    sort(globalList.begin(), globalList.end(),
         [](const edge &a, const edge &b)
         {
             return a.getWeight() < b.getWeight();
         });

    vector<edge> mst;

    DisjointSet ds(Vertex.size());

    for (const auto &e : globalList)
    {
        int fromIndex = e.getFromIndex();
        int toIndex = e.getToIndex();

        int rootFrom = ds.find(fromIndex);
        int rootTo = ds.find(toIndex);

        if (rootFrom != rootTo)
        {
            mst.push_back(e);
            ds.unionOperation(rootFrom, rootTo);
        }
    }

    return mst;
}

#endif