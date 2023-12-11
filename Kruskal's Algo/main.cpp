#include "./functions/kruskal.hpp"
#include "./functions/graph.cpp"
using namespace std;

int main()
{
    graph myGraph;
    vector<edge> mst = myGraph.kruskalMST();

    cout << "Minimum Spanning Tree Edges:\n";
    for (const auto &e : mst)
    {
        cout << "Label: " << e.getLabel() << ", From: " << e.getFromIndex() << ", To: " << e.getToIndex() << ", Weight: " << e.getWeight() << "\n";
    }

    return 0;
}
