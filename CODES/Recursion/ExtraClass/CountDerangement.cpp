#include<iostream>
#include<vector>
using namespace std;

int solve(int n) {
    //base case
    if(n==1) {
        return 0;
    }
    if(n==2) {
        return 1;
    }

    int ans = (n-1)*(solve(n-1) + solve(n-2));
}

int main() {

    int n;
    cout << "Input is " << endl;
    cin >> n;

    cout << "Answer is " << solve(n) << endl;

}