#include <iostream>
using namespace std;

#define MAX_SIZE 100


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int low, int high, int size) {
    int pivot = arr[high];
    cout << "Pivot: " << pivot << endl;
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    cout << "After partitioning: ";
    printArray(arr, size);
    
    return i + 1;
}

void quickSort(int arr[], int low, int high, int size) {
    if (low >= high) {
        return;
    }
    
    int q = partition(arr, low, high, size);
    
    quickSort(arr, low, q - 1, size);
    quickSort(arr, q + 1, high, size);
}

int main() {
    int size;
    int arr[MAX_SIZE];
    
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
    quickSort(arr, 0, size - 1, size);
    
    cout << "\nSorted array: ";
    printArray(arr, size);
    
    return 0;
}
