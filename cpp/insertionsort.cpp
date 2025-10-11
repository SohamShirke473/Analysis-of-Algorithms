#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void insertionSort(vector<int>& arr) {
    int size = arr.size();
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        cout << "After pass " << i << ": ";
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
    insertionSort(arr);

    cout << "\nSorted array: ";
    printVector(arr);

    return 0;
}
