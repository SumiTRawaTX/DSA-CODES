#include<iostream>
#include<limits.h>
using namespace std;

void findmaxi(int arr[], int n, int i, int& maxi) {

    //base case
    if(i>=n) {
        return;
    }

    //1case solve krna hai
    //current elemet ko check karo for max
    if(arr[i]>maxi) {
        maxi = arr[i];
    }

    //baaaki recursion sambhal lega
    findmaxi(arr, n, i+1, maxi);
}

// void findmaxi(int arr[], int n, int i, int maxi) {

//     //base case
//     if(i>=n) {
//         return;
//     }

//     //1case solve krna hai
//     //current elemet ko check karo for max
//     if(arr[i]>maxi) {
//         maxi = arr[i];
//     }

//     //baaaki recursion sambhal lega
//     findmaxi(arr, n, i+1, maxi);
// }

int main () {

    int arr[] ={10,30,21,44,32,17,19,66};
    int n = 0;
    int maxi = INT_MIN;
    int i = 0;

    findmaxi(arr, n, i, maxi);

    cout << "maximum number is: " << maxi << endl;

    return 0;
}