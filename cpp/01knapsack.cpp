#include <iostream>
using namespace std;

#define MAX_N 20
#define MAX_W 50

void print_selected(string keep[MAX_N + 1][MAX_W + 1], int w[MAX_N], int v[MAX_N], int n,int W) {
    cout << "Selected items (index, value, weight):" << endl;
    int selected[MAX_N], val[MAX_N], wt[MAX_N];
    int count = 0;

    int i = n;
    while (i > 0 && W > 0) {
        if (keep[i][W] == "✅") {
            selected[count] = i;
            val[count] = v[i - 1];
            wt[count] = w[i - 1];
            W -= w[i - 1];
            count++;
        }
        i--;
    }

    for (int j = count - 1; j >= 0; j--) {
        cout << "Item " << selected[j] << ": Value = " << val[j]
             << ", Weight = " << wt[j] << endl;
    }
}

void knapsack(int v[MAX_N], int w[MAX_N], int n, int W) {
    int dp[MAX_N + 1][MAX_W + 1];
    string keep[MAX_N + 1][MAX_W + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = 0;
            keep[i][j] = "";
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (w[i - 1] <= j) {
                if (v[i - 1] + dp[i - 1][j - w[i - 1]] > dp[i - 1][j]) {
                    dp[i][j] = v[i - 1] + dp[i - 1][j - w[i - 1]];
                    keep[i][j] = "✅";
                } else {
                    dp[i][j] = dp[i - 1][j];
                    keep[i][j] = "❌";
                }
            } else {
                dp[i][j] = dp[i - 1][j];
                keep[i][j] = "❌";
            }
        }
    }

    print_selected(keep, w, v, n, W);

    cout << "\nDP Table (Value(Keep)):" << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            cout << dp[i][j] << "(" << keep[i][j] << ")\t";
        }
        cout << endl;
    }

    cout << "\nMaximum value that can be obtained: " << dp[n][W] << endl;
}

int main() {
    int v[MAX_N], w[MAX_N];
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter the values: ";
    for (int i = 0; i < n; i++) cin >> v[i];

    cout << "Enter the weights: ";
    for (int i = 0; i < n; i++) cin >> w[i];

    cout << "Enter the capacity: ";
    cin >> W;

    knapsack(v, w, n, W);

    return 0;
}
