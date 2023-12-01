#include<iostream>
#include<vector>
using namespace std;

bool checkarray(vector<int>& arr, int n, int i) {
    //base case
    if(i=n-1) {
        return true;
    }

    //  1 case solve krna hai
    if(arr[i+1]<arr[i]) {
        return false;
    }

    //baaki recursion dekh lega
    return checkarray(arr, n, i+1);
}

int main () {

    vector<int> v{10, 20, 20, 40, 50};
    int n = v.size();
    int i = 0;

    bool issorted = checkarray(v, n , i);

    if(issorted) {
        cout << "array is sorted" << endl;
    }
    else {
        cout << "array is not sorted" << endl;
    }

}