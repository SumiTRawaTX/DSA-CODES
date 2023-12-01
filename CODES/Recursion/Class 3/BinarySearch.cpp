#include <iostream>
#include<vector>
using namespace std;

int binarysearch(vector<int> arr, int s, int e, int key) {

  //base case
  //case 1 key not found
  if(s>e) 
    return -1;
  
  int mid = (s+e)/2;
  // case 2 key found
  if(arr[mid]==key) 
    return mid;
  
  //arr[mid] < key  -> right me search kerte hai
  if(arr[mid]<key) {
    return binarysearch(arr, mid+1, e, key);
  }
  //arr[mid] > key -> left me search kerte hai
  else {
    return binarysearch(arr, s, mid-1, key);
  }

}

int main() {
  vector<int> arr{10, 20, 30, 40, 50, 60, 70, 80, 90, 99};

  int target = 99;
  int n = arr.size();

  int s=0;
  int e=n-1;
  int ans = binarysearch(arr, s, e, target);

  cout << "answer is: " << ans << endl;
  return 0;
}