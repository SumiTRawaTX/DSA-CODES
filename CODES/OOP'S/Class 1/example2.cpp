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
    Animal* suresh = new Animal;

    // Setting values using pointer notation
    suresh->age = 12;
    suresh->name = "sumit";



    return 0;
}