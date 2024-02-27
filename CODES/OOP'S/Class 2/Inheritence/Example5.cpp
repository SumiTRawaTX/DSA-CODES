#include<iostream>
using namespace std;

class Fruit {
    public:
        string name;
};

class Mango: public Fruit {
    public:
        int weight;
};

class Alphaso: public Mango {
    public:
        int sugarLevel;
};

int main() {
    Alphaso a;
    cout << a.name << " " << a.weight << " " << a.sugarLevel << endl;
}