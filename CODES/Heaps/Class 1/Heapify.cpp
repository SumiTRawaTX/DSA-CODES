#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int index = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;
    int largest = index;

    if(leftIndex <= n && arr[largest] < arr[leftIndex]) {
        largest = leftIndex;
    }
    if(rightIndex <= n && arr[largest] < arr[rightIndex]) {
        largest = rightIndex;
    }

    if(index != largest) {
        // left ya right child me se koi greater hogya currNode se
        swap(arr[index], arr[largest]);
        index = largest;
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    for(int i = n/2; i > 0; i--) {
        heapify(arr, n, i);
    }
}

int main() {
    int arr[] = {12, 56, 43, 6, 78, 87, 5, 44, 3, 23, 32};

    int n = 11;
    buildHeap(arr, n);

    cout << "printing the heap" << endl;

    for(int i=0; i<=n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
