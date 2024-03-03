#include<iostream>
using namespace std;

int x = 2;

int main() {
    x = 4;
    int x = 20;
    cout << x << endl;
    cout << ::x << endl; // accessing Global with ::


    {
        int x = 50;
        cout << x << endl;
        cout << ::x << endl;
    }
}