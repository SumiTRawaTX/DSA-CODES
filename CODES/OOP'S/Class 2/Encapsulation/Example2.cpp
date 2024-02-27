#include<iostream>
using namespace std;

class Animal {
    private:
        int age;
        int weight;

    public:
        void eat() {
            cout << "eatting"<< endl;
        }

        int getAge() {
            return this->age;
        }
        void setAge(int n) {
            this->age = age;
        }
};

int main() {

}