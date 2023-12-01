#include<iostream>
using namespace std;

int factorial(int n) {
    cout << "function is called for n: " << n << endl;

    //base case
    if(n==1) {
        return 1;
    }
    int chotiProblem = factorial(n-1);
    int badiProblem = n * chotiProblem;
    return badiProblem;
}

int main () {

    int n;
    cout << "enter the value of n" << endl;
    cin >> n;

    int ans = factorial(n);

    cout << "answer is: " << ans << endl;

    return 0;
}