#include<iostream>
using namespace std;

class Stack {
    public:

    // properties
    int* arr;
    int top;
    int size;

    // constructor
    Stack(int size) {
        arr = new int [size];
        this->size = size;
        top = -1;
    }

    // funtion/ behaviour
    void push(int data) {
        if(size-top > 1) {
            //space available
            //insert
            top++;
            arr[top] = data;
        }
        else {
            //space not available
            cout << "stack overflow " << endl;
        }
    }

    void pop() {
        if(top == -1) {
            // stack is empty
            cout << "stack is in underflow" << endl;
        }
        else {
            // stack is not empty
            top--;
        }
    }

    int getTop() {
        if(top == -1) {
            // stack is empty
            cout << "there is not element in stack " << endl;
        }
        else {
            // stack is not empty
            return arr[top];
        }
    }

    int getSize() {
        return top + 1;
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {

    Stack s(10);

    //insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while(!s.isEmpty()) {
        cout << s.getTop() << " " ;
        s.pop();
    }
    cout << endl;


    cout << s.getSize() << endl;
}