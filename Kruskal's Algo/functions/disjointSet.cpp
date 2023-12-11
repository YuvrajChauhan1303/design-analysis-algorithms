#ifndef DSET
#define DSET

#include "kruskal.hpp"

class DisjointSet
{
private:
    vector<int> parent, size;

public:
    DisjointSet(int n) : parent(n), size(n, 1)
    {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u)
    {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unionOperation(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV)
        {
            if (size[rootU] > size[rootV])
            {
                parent[rootV] = rootU;
                size[rootU] += size[rootV];
            }
            else
            {
                parent[rootU] = rootV;
                size[rootV] += size[rootU];
            }
        }
    }
};

#endif
