#include<iostream>
using namespace std;

int fastExpo(int a, int b) {
    int ans = 1;
    while(b>0) {
        if(b&a) {
            ans=ans*a;
        }
        a=a*a;
        b>>1;
    }
    return ans;
}
int main () {
    cout << fastExpo(5, 4)<< endl;
}