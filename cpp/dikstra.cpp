#include <iostream>
#include <queue>
using namespace std;

#define MAX 100
#define INF 999999

int g[MAX][MAX];
int d[MAX];
int pi[MAX];
bool vis[MAX];
int n, m;

void relax(int u, int v, int w, queue<int> &q) {
    if (w != INF && d[v] > d[u] + w) {
        d[v] = d[u] + w;
        pi[v] = u;
        q.push(v);
    }
}

void Dijkstra(int start) {
    for (int i = 0; i < n; i++) {
        d[i] = INF;
        pi[i] = -1;
        vis[i] = false;
    }

    d[start] = 0;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (int v = 0; v < n; v++) {
            relax(u, v, g[u][v], q);
        }
    }
}

void print_path(int v) {
    int path[MAX];
    int idx = 0;
    while (v != -1) {
        path[idx++] = v;
        v = pi[v];
    }
    for (int i = idx - 1; i >= 0; i--) {
        cout << path[i];
        if (i != 0) cout << " -> ";
    }
    cout << endl;
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = INF;

    cout << "Enter the number of edges: ";
    cin >> m;
    cout << "Enter each edge in the format: u v weight" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = w;
        g[v][u] = w;
    }

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    Dijkstra(start);

    cout << "\nShortest distances and paths from vertex " << start << ":\n";
    for (int i = 0; i < n; i++) {
        if (d[i] == INF) {
            cout << "Vertex " << i << " : Unreachable\n";
        } else {
            cout << "Vertex " << i << " : Distance = " << d[i] << ", Path = ";
            print_path(i);
        }
    }

    return 0;
}
