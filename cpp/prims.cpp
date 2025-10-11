#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100
#define INF 999999

int G[MAX][MAX];
int key[MAX];
int parent[MAX];
bool vis[MAX];
int n;

struct Node {
    int vertex;
    int key;
};

bool cmp(Node a, Node b) {
    return a.key < b.key;
}

void prims(int start) {
    Node pq[MAX]; 

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        parent[i] = -1;
        vis[i] = false;
        pq[i] = {i, key[i]};
    }

    key[start] = 0;
    pq[start].key = 0;

    for (int count = 0; count < n; count++) {
        sort(pq, pq + n, cmp);


        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!vis[pq[i].vertex]) {
                u = pq[i].vertex;
                break;
            }
        }

        vis[u] = true;

        for (int v = 0; v < n; v++) {
            if (G[u][v] && !vis[v] && G[u][v] < key[v]) {
                key[v] = G[u][v];
                parent[v] = u;
                pq[v].key = key[v]; 
            }
        }
    }

    cout << "\nEdges in MST:\n";
    int totalWeight = 0;
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " : " << G[i][parent[i]] << endl;
        totalWeight += G[i][parent[i]];
    }
    cout << "Total Weight: " << totalWeight << endl;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;
    prims(start);

    return 0;
}

