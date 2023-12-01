#include <iostream>
using namespace std;

void merge(int *arr, int s, int mid, int e) {
   int len1 = mid - s + 1;
   int len2 = e - mid;

  //creating array 1
  int *left = new int[len1];
  int *right = new int[len2];

  int k = s;
  //copying element
  for(int i=0; i<len1; i++) {
    left[i] = arr[k];
    k++;
  }

  k = mid + 1;
  for(int i=0; i<len2; i++) {
    right[i] = arr[k];
    k++;
  }

  //merge sort
  int leftindex = 0;
  int rightindex = 0;
  int mainArrayindex = s;

  while(leftindex < len1 && rightindex < len2) {
    if(left[leftindex] < right[rightindex]) {
      arr[mainArrayindex] = left[leftindex];
      mainArrayindex++;
      leftindex++;
    }
    else {
      arr[mainArrayindex] = right[rightindex];
      mainArrayindex++;
      rightindex++;
    }
  }

  //copy remaining elements from left and right arrays
  while(leftindex < len1) {
    arr[mainArrayindex] = left[leftindex];
    mainArrayindex++;
    leftindex++;
  }

  while(rightindex < len2) {
    arr[mainArrayindex] = right[rightindex];
    mainArrayindex++;
    rightindex++;
  }

  delete[] left;  // free memory allocated for left array
  delete[] right; // free memory allocated for right array
}

void mergesort(int *arr, int s, int e) {
  //base case
  //s==e -> single element
  //s > e -> invalid array
  if(s >= e) 
    return;
    
  int mid = (s+e)/2;
  //left part kardo recursion bhaiya;
  mergesort(arr, s, mid);

  //right part kardo recursion bhaiya;
  mergesort(arr, mid+1, e);

  //now merge 2 sorted arrays
  merge(arr, s, mid, e);
}

int main() {
  int arr[] = {4,5,13,2,12};
  int n = 5;

  int s = 0;
  int e = n-1;
  mergesort(arr, s, e);

  for(int i=0; i<n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
