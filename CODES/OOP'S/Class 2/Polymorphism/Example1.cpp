#include<iostream>
using namespace std;

class Maths {
        public:
        int sum(int a, int b) {
            return a+b;
        }
        int sum(int a, int b, int c) {
            return a+b+c;
        }
        int sum(int a, float b) {
            return a+b+100;
        }
};

int main() {

    Maths obj;
    // cout << obj.sum(2,3);
    // cout << obj.sum(23, 34, 56);  
    cout << obj.sum(25, 50.55f);

}