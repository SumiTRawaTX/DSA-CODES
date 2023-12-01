#include<iostream>
using namespace std;

int main() {

    // size of different data types using pointer

    int a = 5;
    int *p = &a;
    cout << sizeof(p) << endl;

    char ch = 'b';
    char *c = &ch;
    cout << sizeof(c) << endl;

    double dtr = 5.03;
    double *d = &dtr;
    cout << sizeof(d) << endl;

    return 0;

}