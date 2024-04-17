#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int index = i;
    int leftIndex = 2 * i + 1;
    int rightIndex = 2 * i + 2;
    int largest = index;

    if(leftIndex < n && arr[largest] < arr[leftIndex]) {
        largest = leftIndex;
    }
    if(rightIndex < n && arr[largest] < arr[rightIndex]) {
        largest = rightIndex;
    }

    if(index != largest) {
        swap(arr[index], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    for(int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {12, 56, 43, 6, 78, 87, 5, 44, 3, 23, 32};
    int n = sizeof(arr)/sizeof(arr[0]);
    buildHeap(arr, n);

    cout << "Heap: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);

    cout << "Sorted Array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
