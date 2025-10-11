#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }  
    cout << endl;
}

void selectionSort(vector<int>& arr) {
    int size = arr.size();
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
        
        cout << "After pass " << i + 1 << ": ";
        printVector(arr);
    }
}

int main() {
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    printVector(arr);

    cout << "\nSorting process:\n";
    selectionSort(arr);

    cout << "\nSorted array: ";
    printVector(arr);

    return 0;
}
