#include <iostream>
using namespace std;

class Animals {
private:
    int weight;

public:
    // Getter method
    int getWeight() {
        return weight;
    }

    // Setter method
    void setWeight(int w) {
        weight = w;
    }
};

int main() {
    Animals Ramesh;
    Ramesh.setWeight(101);
    cout << "Weight: " << Ramesh.getWeight() << endl;
    return 0;
    
}
