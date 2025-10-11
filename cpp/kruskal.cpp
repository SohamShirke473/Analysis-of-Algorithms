#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 50
#define INF 999999

struct Edge {
    int u, v, w;
};

class DS {
    int parent[MAX];
    int rank[MAX];
    int n;

public:
    DS(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }

    void unionSets(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);
        if (s1 != s2) {
            if (rank[s1] < rank[s2])
                parent[s1] = s2;
            else if (rank[s1] > rank[s2])
                parent[s2] = s1;
            else {
                parent[s2] = s1;
                rank[s1]++;
            }
        }
    }
};

void kruskal(int G[MAX][MAX], int n) {
    Edge edges[MAX * MAX];
    int edgeCount = 0;

\
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (G[i][j] != INF) {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].w = G[i][j];
                edgeCount++;
            }
        }
    }

\
    sort(edges, edges + edgeCount, [](Edge a, Edge b) {
        return a.w < b.w;
    });

    DS ds(n);
    int totalWeight = 0;
    cout << "\nMinimum Spanning Tree edges:\n";

    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (ds.find(u) != ds.find(v)) {
            ds.unionSets(u, v);
            cout << u << " -- " << v << "  weight: " << w << endl;
            totalWeight += w;
        }
    }

    cout << "\nTotal weight of MST: " << totalWeight << endl;
}

int main() {
    int n, m;
    int G[MAX][MAX];

    cout << "Enter the number of vertices: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            G[i][j] = INF;

    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Enter each edge in the format: u v weight\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u][v] = w;
        G[v][u] = w;
    }

    kruskal(G, n);
    return 0;
}
