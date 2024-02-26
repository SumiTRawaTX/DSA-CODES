#include<iostream>
using namespace std;

class Animals {
    // state or property
    public:
    int age;
    string name;

    //behaviour
    void eat() {
        cout << "eating" << endl;
    }

    void sleep() {
        cout << "sleeping" << endl;
    }
};

int main() {

    // object creation


    // static
    Animals Ramesh;
    Ramesh.age = 12;
    Ramesh.name = "Lion";
    cout << " ramesh age is " << Ramesh.age << endl;
    cout << "ramesh name is " << Ramesh.name << endl;

    Ramesh.eat();
    Ramesh.sleep();
 
    
}