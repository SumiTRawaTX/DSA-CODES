#include<iostream>
using namespace std;

int main() {

    //creation of pointer
    
    int a = 5;
    //pointer create
    int* ptr = &a;
    //acesss the value ptr is pointing to
    cout << *ptr << endl;
    cout << &a << endl;
    cout << ptr << endl;
    cout << &ptr << endl;

    return 0;

}