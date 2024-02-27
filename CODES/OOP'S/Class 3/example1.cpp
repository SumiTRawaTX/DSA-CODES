#include<iostream>
using namespace std;

class Animal {
    public:
        virtual void speak() {
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
    
    // Animal * a = new Animal();
    // a->speak();
    // Dog * b = new Dog();
    // b->speak();


    // UpCasting
    Animal * a = new Dog(); // in this  case always parents function call
    // use virtual on parent's function
    a->speak();


    //DownCasting
    Dog * b = (Dog*)new Animal();
    b->speak();


    // if we applied a virtual function then class function will call

}