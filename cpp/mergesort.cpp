#include <iostream>
using namespace std;

const int MAX_SIZE = 100; 

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int left, int mid, int right, int b[]) {
    int i = left;
    int j = mid + 1;
    int k = left;
    
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            b[k] = arr[i];
            i++;
        } else {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    
    while (i <= mid) {
        b[k] = arr[i];
        i++;
        k++;
    }
    
    while (j <= right) {
        b[k] = arr[j];
        j++;
        k++;
    }
    
    for (int i = left; i <= right; i++) {
        arr[i] = b[i];
    }
}

void mergeSort(int arr[], int s, int e, int b[], int size) {
    if (s >= e) {
        return;
    }
    
    int mid = s + (e - s) / 2;
    
    mergeSort(arr, s, mid, b, size);
    mergeSort(arr, mid + 1, e, b, size);
    
    merge(arr, s, mid, e, b);
    
    cout << "After merging: ";
    printArray(arr, size);
}

int main() {
    int size;
    int arr[MAX_SIZE];
    int b[MAX_SIZE]; 
    
    cout << "Enter the size of array (max " << MAX_SIZE << "): ";
    cin >> size;
    
    if (size > MAX_SIZE) {
        cout << "Size exceeds maximum limit." << endl;
        return 1;
    }
    
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    cout << "Original array: ";
    printArray(arr, size);
    
    cout << "\nSorting process:\n";
    mergeSort(arr, 0, size - 1, b, size);
    
    cout << "\nSorted array: ";
    printArray(arr, size);
    
    return 0;
}
