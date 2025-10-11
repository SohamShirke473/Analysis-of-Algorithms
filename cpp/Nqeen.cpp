#include <iostream>
using namespace std;

#define MAX_N 20 
int x[MAX_N];
int z = 0;

void printBoard(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (x[i] == j) cout << "Q ";
            else cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

bool canPlace(int k, int i) {
    for (int j = 0; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

void solveNQueens(int k, int n) {
    for (int i = 0; i < n; i++) {
        if (canPlace(k, i)) {
            z++;
            x[k] = i;
            if (k == n - 1) {
                cout << "Solution: ";
                for (int j = 0; j < n; j++) {
                    cout << x[j]+1 << " ";
                }
                cout << "\n";
                printBoard(n);
            } else {
                solveNQueens(k + 1, n);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of queens (n): ";
    cin >> n;
    
    if (n > MAX_N) {
        cout << "Board size too large. Maximum size is " << MAX_N << endl;
        return 1;
    }
    
    solveNQueens(0, n);
    cout << "Total iterations: " << z << endl;
    
    return 0;
}
