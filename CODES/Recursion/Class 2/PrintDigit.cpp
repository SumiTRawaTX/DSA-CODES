#include <iostream>
using namespace std;

void printdigits(int n){
  //base case
  if(n==0) {
    return ; 
     }

  // case main solve kerunga
  int digit = n % 10;
  cout << digit << " ";
  int newvalueofn = n/10;

  //baaki recursion handle ker lega
  printdigits(newvalueofn);
}

int main() {
      int n = 647;
      printdigits(n);
  return 0;
}