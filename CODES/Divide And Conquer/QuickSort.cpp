#include <iostream>
using namespace std;

int partition(int arr[], int s, int e) {
  // Step 1: Choose pivot element
  int pivotindex = s;
  int pivotelement = arr[s];

  // Step 2: Find right position for pivot element and place it there

  int count = 0;
  for(int i = s; i <= e; i++) {
    if(arr[i] <= pivotelement) {
      count++;
    }
  }
  // When the main loop is exited, we have the index of the pivot's right position ready
  int rightindex = s + count;
  swap(arr[pivotindex], arr[rightindex]);
  pivotindex = rightindex;

  // Step 3: Left me chhote and right me bade element
  int i = s;
  int j = e;

  while(i < pivotindex && j > pivotindex) {
    while(arr[i] <= pivotelement) {
      i++;
    }
    while(arr[j] > pivotelement) {
      j--;
    }

    // Two cases:
    // A -> You found the element to swap
    // B -> No need to swap
    if(i < pivotindex && j > pivotindex) 
      swap(arr[i], arr[j]);
  }
  return pivotindex;
}

void quicksort(int arr[], int s, int e) {
  // Base case
  if(s >= e) {
    return;
  }

  // Partition logic
  int p = partition(arr, s, e);

  // Recursive call
  // Left
  quicksort(arr, s, p - 1);

  // Right
  quicksort(arr, p + 1, e);
}

int main() {
  int arr[] = {8, 1, 3, 4, 20, 50, 30};
  int n = 7;

  int s = 0;
  int e = n - 1;
  quicksort(arr, s, e);

  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}


