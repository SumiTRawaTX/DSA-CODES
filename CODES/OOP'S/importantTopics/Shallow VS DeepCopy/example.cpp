#include<iostream>
using namespace std;

class abc {
    public:
    int x;
    int *y;
    
    abc(int _x, int _y) : y(new int(_y)) {}

    void print() const {
        printf("X:%d\nPTR Y:%p\nContent of Y (*d): %d\n\n", x, y, *y);
    }
};

int main() {

    abc a(1,2);
    cout << "printing a\n";
    a.print();

    //abc b(a)
    abc b = a; // call hota hai, COPY CONSTRUCTOR
    cout << "printing b\n";
    b.print();
    *b.y = 20;
    cout << "printing b\n";
    b.print();

    cout << "printing a\n";
    a.print();

}