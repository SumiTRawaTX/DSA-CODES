#include<iostream>
using namespace std;

class Animal {

    // parents class
    public:
        int age;
};

// child class
class Dog: protected Animal {
    public:
        void print() {
            cout << this->age;
        }
};

int main() {

    Dog d1;
    d1.print();
    return 0;
}