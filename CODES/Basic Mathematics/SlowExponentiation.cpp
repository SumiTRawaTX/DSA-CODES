#include<iostream>
using namespace std;

int slowExpo(int a, int b) {
    int ans = 1;
    for(int i=0; i<b; i++) {
        ans=ans*a;
    }
    return ans;
} 

int main () {
    cout << slowExpo(5, 4) << endl;
    return 0;
}