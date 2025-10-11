#include <iostream>
#include <string>
using namespace std;

#define MAX 100
#define INF 999999

void printMatrix(float mat[MAX][MAX], int n, const string &name) {
    cout << "\n" << name << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == INF) cout << "INF ";
            else cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void printPred(int pred[MAX][MAX], int n, const string &name) {
    cout << "\n" << name << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (pred[i][j] == -1) cout << "NIL ";
            else cout << pred[i][j] << " ";
        }
        cout << endl;
    }
}

void floydWarshall(float graph[MAX][MAX], int n, float dist[MAX][MAX], int pred[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
            if (i == j || graph[i][j] == INF)
                pred[i][j] = -1;
            else
                pred[i][j] = i;
        }
    }

    printMatrix(dist, n, "D(0) (Initial Distance Matrix)");
    printPred(pred, n, "P(0) (Initial Predecessor Matrix)");

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = pred[k][j];
                }
            }
        }

        cout << "\nAfter considering vertex " << k << ":\n";
        printMatrix(dist, n, "Distance Matrix");
        printPred(pred, n, "Predecessor Matrix");
    }
}

void constructPath(int u, int v, int pred[MAX][MAX]) {
    if (pred[u][v] == -1) {
        cout << "No path";
        return;
    }

    int path[MAX];
    int len = 0;
    int cur = v;

    while (cur != u) {
        path[len++] = cur;
        cur = pred[u][cur];
        if (cur == -1) {
            cout << "No path";
            return;
        }
    }
    path[len++] = u;

    for (int i = len - 1; i >= 0; i--) {
        cout << path[i];
        if (i != 0) cout << " -> ";
    }
}

int main() {
    int n;
    float graph[MAX][MAX];
    float dist[MAX][MAX];
    int pred[MAX][MAX];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (" << n << "x" << n << "), use INF for no edge:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string val;
            cin >> val;
            if (val == "INF" || val == "inf" || val == "Inf")
                graph[i][j] = INF;
            else
                graph[i][j] = stof(val);
        }
    }

    floydWarshall(graph, n, dist, pred);

    cout << "\nAll shortest paths:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << " -> " << j << ": ";
            if (dist[i][j] == INF) {
                cout << "No path\n";
            } else {
                constructPath(i, j, pred);
                cout << ", Distance: " << dist[i][j] << endl;
            }
        }
    }

    return 0;
}
