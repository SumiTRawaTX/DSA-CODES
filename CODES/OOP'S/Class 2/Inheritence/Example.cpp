#include<iostream>
using namespace std;

class Animal {

    // parents class
    public:
        int age;
        int weight;

        void eat() {
            cout << "Eating" << endl;
        }
};

// child class
class Dog: public Animal {

};

int main() {

    Dog d1;
    d1.eat();
    return 0;
}