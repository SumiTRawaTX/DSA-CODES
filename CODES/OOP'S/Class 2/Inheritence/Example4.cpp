#include<iostream>
using namespace std;

class Car {
    public:
        string name;
        int weight;
        int age;

        void speedUp() {
            cout << "speeding up" << endl;
        }

        void breaks() {
            cout << "breaking" << endl;
        }
};

class Scorpio: public Car {

};

int main() {
    
    Scorpio s15;
    s15.speedUp();

}