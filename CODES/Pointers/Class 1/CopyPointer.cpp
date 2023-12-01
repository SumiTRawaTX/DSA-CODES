#include<iostream>
using namespace std;

int main () {

    //COPY POINTER

    int a= 5;
    int *ptr = &a;
    //copy pointer
    int *dusraptr = ptr;

    cout << *ptr << endl;
    cout << *dusraptr << endl;

    return 0;

}