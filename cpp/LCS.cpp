#include <iostream>
#include <string>
using namespace std;

#define MAX_LEN 100  

void printLCS(string X, char b[][MAX_LEN], int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }
    if (b[i][j] == 'D') {  // Diagonal arrow (↖)
        printLCS(X, b, i - 1, j - 1);
        cout << X[i-1];
    } else if (b[i][j] == 'L') {  // Left arrow (←)
        printLCS(X, b, i, j - 1);
    } else {  // Up arrow (↑)
        printLCS(X, b, i - 1, j);
    }
}

int main() {
    string X, Y;
    cout << "Enter the first string: ";
    cin >> X;
    cout << "Enter the second string: ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();
    
    int c[MAX_LEN][MAX_LEN] = {0};
    char b[MAX_LEN][MAX_LEN] = {' '};

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (X[i] == Y[j]) {
                c[i+1][j+1] = c[i][j] + 1;
                b[i+1][j+1] = 'D'; 
            } else if (c[i+1][j] >= c[i][j+1]) {
                c[i+1][j+1] = c[i+1][j];
                b[i+1][j+1] = 'L';
            } else {
                c[i+1][j+1] = c[i][j+1];
                b[i+1][j+1] = 'U';  
            }
        }
    }

    
    cout << "\nDP Table (c):\n";
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    
    cout << "\nDirection Table (b):\n";
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nLength of LCS: " << c[m][n] << endl;
    cout << "LCS: ";
    printLCS(X, b, m, n);
    cout << endl;

    return 0;
}
