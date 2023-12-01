#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string &s, int start, int end) {
  //base case
  if(start >= end) {
    return true;
  }

  //one case solution
  if(s[start] != s[end]) {
    return false;
  }

  //recurison dekh lega
  isPalindrome(s, start+1, end -1);
}

int main() {
  
  string s;
  cin >> s;
  cout << isPalindrome(s, 0, s.size()) << endl;

  return 0;
}