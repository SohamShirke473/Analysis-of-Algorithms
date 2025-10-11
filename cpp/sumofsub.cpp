#include <iostream>
using namespace std;

const int MAX = 100;
int x[MAX];       
int w[MAX];       
int n;            
int m;            


void printSubset() {
    cout << "Subset: { ";
    for (int i = 0; i < n; i++) {
        if (x[i] == 1) {
            cout << w[i] << " ";
        }
    }
    cout << "}  \n";
    cout << "Vector: [ ";
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << "]" << endl;
}


void SumOfSubset(int s, int k, int r) {
    x[k] = 1; 
    if (s + w[k] == m) {
        printSubset();
    } 
    else if (k + 1 < n && s + w[k] + w[k + 1] <= m) {
        SumOfSubset(s + w[k], k + 1, r - w[k]);
    }

    
    x[k] = 0;
    if (k + 1 < n && s + r - w[k] >= m) {
        SumOfSubset(s, k + 1, r - w[k]);
    }
}

int main() {
    int sumR = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements in ascending order: ";
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        sumR += w[i];
    }

    cout << "Enter target sum: ";
    cin >> m;

    cout << "Subsets with sum " << m << " are:\n";
    SumOfSubset(0, 0, sumR);

    return 0;
}
