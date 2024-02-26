#include<iostream>
using namespace std;

class Animal {
public:
    string name;
    int age;
};

int main() {
    // Declaring a regular object
    Animal suresh;

    // Declaring a pointer to an object of the Animal class
    Animal* sureshPointer = new Animal;

    // Setting values using pointer notation
    sureshPointer->age = 12;
    sureshPointer->name = "sumit";

    return 0;
}
