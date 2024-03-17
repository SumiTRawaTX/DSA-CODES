#include<iostream>
using namespace std;

class Stack {
    public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size) {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }


    //function
    void push1(int data) {
        if(top2 - top1 == 1) {
            // space not available
            cout << "overflow" << endl;
        }
        else {
            // space available
            top1++;
            arr[top1] = data;
        }
    }

    void pop1 () {
        if(top1 == -1) {
            //stack empty 
            cout << "UNDERFLOW in stack 1" << endl;
        }
        else {
            // stack is not empty
            top1--;
        }
    }

    void push2(int data) {
        if(top2 - top1 == 1) {
            // space not available
            cout << "overflow" << endl;
        }
        else {
            //space available
            top2--;
            arr[top2] = data;
        }

    }

    void pop2() {
        // stack 2 is empty
        if(top2 == size) {
            cout << "UNDERFLOW in stack 2" << endl;
        }

        else {
            // stack 2 is not empty
            top2++;
        }
    }

};


int main() {

}