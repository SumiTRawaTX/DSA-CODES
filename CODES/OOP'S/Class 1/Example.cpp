#include<iostream>
using namespace std;

class Animal {
    public:
        string name;
        int age;
        int weight;
        string type;

        Animal() {
            this->name;
            this->age;
            this->type;
            this->weight;
            cout << "Animal is called " << endl;
        }

        ~Animal() {
            cout << "I am destructor " << endl;
        }
};


int main() {

    // Animal aman;

    // Animal a;
    // a.age = 5;


    // manually defaulter

    cout << "a obj creation" << endl;
    Animal a;
    a.age = 5;

    cout << "b obj creation" << endl;
    Animal *b = new Animal();
    b->age = 12;

    // manually
    delete b;

}