#include<iostream>
using namespace std;

class p {
    public:
        int val;

        void operator+(p & obj2) {
            int value1 = this->val;
            int value2 = obj2.val;
            cout << (value2-value1);
        }
};

int main() {
    p obj1, obj2;
    obj1.val = 7;
    obj2.val = 3;

    // this should print the difference between them

    obj1 + obj2;

    

}