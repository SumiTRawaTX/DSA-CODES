#include<iostream>
using namespace std;

class Animal {

    // parents class
    public:
        int age;
};

// child class
class Dog: private Animal {
    public:
        void print() {
            cout << this->age;
        }
};

int main() {

    Dog d1;
    cout << d1.age; // cannot accesseble
    return 0;

}