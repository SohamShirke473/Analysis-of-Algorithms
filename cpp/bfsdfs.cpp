#include <iostream>
using namespace std;

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int V; 


void BFS(int start) {
    int queue[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    cout << "BFS Traversal starting from vertex " << start << ": ";

    while (front < rear) {
        int node = queue[front++];
        cout << node << " ";

        for (int i = 0; i < V; i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    cout << endl;
}


void DFS(int start) {
    cout << start << " ";
    visited[start] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[start][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1; 
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    BFS(start);

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    cout << "DFS Traversal starting from vertex " << start << ": ";
    DFS(start);
    cout << endl;

    return 0;
}
