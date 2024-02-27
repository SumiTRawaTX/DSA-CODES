#include<iostream>
using namespace std;

class Animal {
    public:
        void speak() {
            cout << "speaking" << endl;
        }
};

class Dog: public Animal {
    public:
        // overRiding
        void speak() {
            cout << "barking" << endl;
        }
};

int main() {
    
    Animal a;
    a.speak();

    Dog d;
    d.speak();
}