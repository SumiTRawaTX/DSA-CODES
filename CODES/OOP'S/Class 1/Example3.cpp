#include<iostream>
using namespace std;

class Animal {
    public:
        string name;
        int age;
        string type;
        int weight;

        // default constructor
        Animal() {
            this->name;
            this->age;
            this->type;
            this->weight;
            cout << "Animal is called " << endl;
        }

        // parameterised Constructor
        Animal(int age) {
            this->age = age; 
            cout << "Parameterised Constructor" << endl;
        }
        Animal(int age, int weight) {
            this->age = age;
            this->weight = weight; 
            cout << "Parameterised Constructor" << endl;
        }

        Animal(int age, int weight, string type) {
            this->age = age;
            this->weight = weight; 
            this->type = type;
            cout << "Parameterised Constructor" << endl;
        }

        // copy constructor
        Animal(Animal &obj) {
            this->age = obj.age;
            this->type = obj.type;
            this->weight = weight;
            cout << "i am inside copy constructor " << endl;
        }
};

int main() {
    Animal aman;

    // parameterised Constructor
    // Animal *b = new Animal(100);
    // Animal *a = new Animal(100, 400);
    // Animal *c = new Animal(100, 400, "abc");


    Animal a(10);
    Animal *b = new Animal(100, 10, "abc"); 

    // object copy
    Animal c = a;
    Animal animal(c);


}